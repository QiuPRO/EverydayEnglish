# include"PassageParser.h"
PassageParser* PassageParser::parser = nullptr;
PassageParser &PassageParser::getParser()
{
    if (parser == nullptr)
        parser = new PassageParser();
    return *parser;
}

void PassageParser::parsePassage()
{
	_res.clear();
    QStringList words = _passage.split(" ");
	int sentenceCount = 0;
    QHash<QString, QVector<int>> hash;
	_wordCount = 0;
	int flag = 0;
    for (int i = 0; i < words.size(); i++)
	{
		flag = 0;
		if (words[i] == "")
			continue;
		if (words[i].back() == '.')
		{
			words[i].replace(".", "");
			sentenceCount++;
			flag = 1;
		}
		else if (words[i].back() == ',')
			words[i].replace(",", "");
		hash[words[i].toLower()].push_back(sentenceCount - flag);
		_wordCount++;
	}
    for (QHash<QString, QVector<int>>::iterator i = hash.begin(); i != hash.end(); i++)
        _res.push_back(QPair<QString, QVector<int>>(i.key(), i.value()));
    qSort(_res.begin(), _res.end(), [](const QPair<QString, QVector<int>>& p1, const QPair<QString, QVector<int>>& p2){ return p1.second.size() > p2.second.size(); });
}

QStringList& PassageParser::getSentences()
{
	return _sentences;
}

QVector<QPair<QString, QVector<int>>>& PassageParser::getWordSet()
{
	return _res;
}

void PassageParser::setPassagePath(QString path)
{
	_path = path;
	_passage = readPassage();
	_passage = _passage.replace("\r\n", " ");
	parsePassage();
	_sentences = _passage.split(".");
	for (int i = 0; i < _sentences.size(); i++)
	{
		if (_sentences[i][0] == ' ')
			_sentences[i] = _sentences[i].simplified();
		_sentences[i].append('.');

	}
}

QString& PassageParser::getPassagePath()
{
	return _path;
}

int PassageParser::getWordCount()
{
	return _wordCount;
}

QString PassageParser::readPassage()
{
	QFile file(_path);
	bool isOpen = file.open(QIODevice::ReadOnly);
	if (isOpen) 
	{
		QTextStream txtInput(&file);
		return txtInput.readAll();
	}
	return "";
		
}

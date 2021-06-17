#include "WordList.h"
int WordList::readTXT(QString path)
{
	QFile file(path);
	bool isOpen = file.open(QIODevice::ReadOnly);
	QTextStream txtInput(&file);
	QString lineStr;
	lineStr = txtInput.readLine();  //读取数据
	int status = isOpen;
	if (lineStr == QString("$root$"))
		status = ReadFileStatus::ROOT_FILE;
	else
	{
		QStringList qsl = lineStr.split(" ");
		if (qsl.size() == 3)
		{
			Word word(qsl[0], qsl[1], qsl[2]);
			wordList.push_back(word);
		}
	}

	while (!txtInput.atEnd())
	{
		lineStr = txtInput.readLine();  //读取数据
		QStringList qsl = lineStr.split(" ");
		if (qsl.size() != 3)
			continue;
		else 
		{
			Word word(qsl[0], qsl[1], qsl[2]);
			wordList.push_back(word);
		}
	}
	file.close();
	_size = wordList.size();
	return status;
}

int WordList::size()
{
	return _size;
}

int WordList::count()
{
	return _count;
}

void WordList::clear()
{
	wordList.clear();
}

bool Word::operator==(Word & word)
{
	return eng == word.eng;
}

QDataStream& operator>>(QDataStream& din, WordList& wl)
{
	din >> wl._size;
	din >> wl._count;
	wl.wordList.clear();
	wl.wordList.resize(wl._size);
	for (int i = 0; i < wl._size; i++) 
	{
		din >> wl.wordList[i].eng;
		din >> wl.wordList[i].pro;
		din >> wl.wordList[i].chi;
	}
	return din;
}
QDataStream& operator<<(QDataStream& dout, WordList& wl)
{
	dout << wl._size;
	dout << wl._count;
	for (int i = 0; i < wl.wordList.size(); i++) 
	{
		dout << wl.wordList[i].eng;
		dout << wl.wordList[i].pro;
		dout << wl.wordList[i].chi;
	}

	return dout;
}

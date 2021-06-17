#include "ShuffleWordList.h"
	

Word ShuffleWordList::shuffleWord()
{
	// ��˳�����
	if (!_isSequence) {
		// ���ʱ�Ϊ�գ���ʼ����
		if (_count < wordList.size() && wordList.size() > 0)
		{
			int randNum = rand();// % (_size - _count);
			randNum %= (_size - _count);
			Word tmp = wordList[_count];
			wordList[_count] = wordList[randNum + _count];
			wordList[randNum + _count] = tmp;
			return wordList[_count++];
		}
		else if (_count == wordList.size())
			return Word(QString("You have finished!"), QString("[]"), QString("���ѱ���ȫ������"));
		else
			return Word(QString("Please open file first"), QString("[]"), QString("���ȴ��ļ�"));
	}
	else
	{
		if (_count == wordList.size())
			return Word(QString("You have finished!"), QString("[]"), QString("���ѱ���ȫ������"));
		return wordList[_count++];
	}

}

void ShuffleWordList::setSequential(bool isTrue)
{
	_isSequence = isTrue;
}

QStringList ShuffleWordList::get4Chi(QString chi)
{
	QStringList ret;
	int tmp[4] = { -1, -1, -1, -1 };
	bool rep = false;
	for (int i = 0; i < 4; i++)
	{
		int r = rand() % _size;
		tmp[i] = r;
		for (int j = 0; j < 4; j++)
		{
			if (j == i)
				continue;
			if (tmp[j] == r)
			{
				rep = true;
				break;
			}
		}
		if (rep || wordList[r].chi == chi)
		{
			rep = false;
			i -= 1;
			continue;
		}
		ret.push_back(wordList[r].chi);
	}
	return ret;
}

QStringList ShuffleWordList::get4Eng(QString eng)
{
	QStringList ret;
	int tmp[4] = { -1, -1, -1, -1 };
	bool rep = false;
	for (int i = 0; i < 4; i++)
	{
		int r = rand() % _size;
		tmp[i] = r;
		for (int j = 0; j < 4; j++)
		{
			if (j == i)
				continue;
			if (tmp[j] == r)
			{
				rep = true;
				break;
			}
		}
		if (rep || wordList[r].eng == eng)
		{
			rep = false;
			i -= 1;
			continue;
		}
		ret.push_back(wordList[r].eng);
	}
	return ret;
}

void ShuffleWordList::setIsSequence(bool isSequence)
{
	_isSequence = isSequence;
}



void ShuffleWordList::clearCount()
{
	_count = 0;
}

void ShuffleWordList::setSize(int size)
{
	this->_size = size;
}

int ShuffleWordList::getSize()
{
	return _size;
}

void ShuffleWordList::setCount(int count)
{
	this->_count = count;
}

void ShuffleWordList::readFromFile(QString path)
{
	QFile file(path);
	bool isOpen = file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	in >> *this;
	file.close();
}

QVector<Word>& ShuffleWordList::getWordList()
{
	return wordList;
}

bool ShuffleWordList::isSequential()
{
	return _isSequence;
}

QDataStream& operator>>(QDataStream& din, ShuffleWordList& swl)
{
	int tmp;
	din >> tmp;
	swl.setSize(tmp);
	din >> tmp;
	swl.setCount(tmp);
	QVector<Word> wl = swl.getWordList();
	wl.clear();
	wl.resize(swl.getSize());
	for (int i = 0; i < swl.getSize(); i++)
	{
		din >> wl[i].eng;
		din >> wl[i].pro;
		din >> wl[i].chi;
	}
	return din;
}
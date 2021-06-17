#include "WrongWordList.h"
const QString WrongWordList::WRONG_WORD_LIST_ROOT_PATH = "wrong_list_root.dat";
const QString WrongWordList::WRONG_WORD_LIST_PATH = "wrong_list.dat";

void WrongWordList::add2WrongWordList(Word word)
{
	wordList.push_back(word);
	_size = wordList.size();
}

//void WrongWordList::writeToFile(QString path)
//{
//	QFile file(path);
//	bool isOpen = file.open(QIODevice::WriteOnly);
//	QTextStream out(&file);
//	out.setGenerateByteOrderMark(true);
//	for (int i = 0; i < wordList.size(); i++)
//	{
//		out << wordList[i].eng << " " << wordList[i].pro << " " << wordList[i].chi << "\n";
//	}
//	file.close();
//}
void WrongWordList::writeToFile(QString path)
{
	QFile file(path);
	bool isOpen = file.open(QIODevice::WriteOnly);
	QDataStream out(&file);
	out << *this;
	file.close();
}

void WrongWordList::readFromFile(QString path)
{
	QFile file(path);
	bool isOpen = file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	in >> *this;
	file.close();
}

void WrongWordList::removeWord(Word word)
{
	for (int i = 0; i < wordList.size(); i++)
		if (word == wordList[i])
		{
			wordList.remove(i);
			break;
		}
	_size = wordList.size();
}


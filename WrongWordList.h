#pragma once
#include "WordList.h"
class WrongWordList :
	public WordList
{
public:
	void add2WrongWordList(Word word);
	void writeToFile(QString path);
	void removeWord(Word word);
	void readFromFile(QString path);
	friend QDataStream& operator>>(QDataStream&, WordList&);
	static const QString WRONG_WORD_LIST_ROOT_PATH;
	static const QString WRONG_WORD_LIST_PATH;
};


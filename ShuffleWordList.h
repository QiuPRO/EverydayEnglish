#pragma once
#include "WordList.h"
class ShuffleWordList :
	public WordList
{
private:
	bool _isSequence = true;// ÊÇ·ñËæ»ú±³µ¥´Ê
public:
	ShuffleWordList() 
	{
		srand((unsigned)time(NULL));
	};
	Word shuffleWord();
	QStringList get4Chi(QString chi);
	QStringList get4Eng(QString eng);
	void setIsSequence(bool isSequence);
	void setSequential(bool isTrue);
	void clearCount();
	void setSize(int size);
	int getSize();
	void setCount(int count);
	void readFromFile(QString path);
	QVector<Word>& getWordList();
	bool isSequential();
	friend QDataStream& operator>>(QDataStream&, WordList&);


};


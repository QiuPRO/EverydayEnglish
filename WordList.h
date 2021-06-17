#pragma once
#include "qstring.h"
#include "qvector.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qdatastream.h"
struct Word
{
	QString eng;	// 英文词义
	QString pro;	// 音标
	QString chi;	// 中文词义
	Word() {}
	Word(QString english, QString pronounce, QString chinese) : eng(english), pro(pronounce), chi(chinese) {}
	bool operator==(Word &word);
};
enum ReadFileStatus
{
	FAIL = 0, SUCCESS = 1, ROOT_FILE = 2
};
class WordList
{
protected:
	QVector<Word> wordList;
	int _size = 0;
	int _count = 0;			// 当前背了多少个单词

public:
	int readTXT(QString path);
	int size();
	int count();
	virtual void clear();
	void setFromWordList(WordList *src) {
		wordList = QVector<Word>(src->wordList.size());
		for (int i = 0; i < src->wordList.size(); i++)
			wordList[i] = src->wordList[i];
		//wordList = src->wordList;
		_size = src->_size;
		_count = src->_count;
	}
	friend QDataStream& operator>>(QDataStream&, WordList&);
	friend QDataStream& operator<<(QDataStream&, WordList&);
};



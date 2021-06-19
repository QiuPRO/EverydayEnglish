#pragma once

#include <qvector.h>
#include <qpair.h>
#include <qhash.h>
#include "qalgorithms.h"
#include "qfile.h"
#include "qtextstream.h"

class PassageParser
{
public:
    static PassageParser &getParser();
	QStringList& getSentences();
	QVector<QPair<QString, QVector<int>>>& getWordSet();
	void setPassagePath(QString);
	QString& getPassagePath();
	int getWordCount();
private:
	int _wordCount = 0;
    PassageParser() {}
	QString _path;
	QString _passage;
	QStringList _sentences;
	QVector<QPair<QString, QVector<int>>> _res;
	QString readPassage();
	void parsePassage();
    static PassageParser *parser;
};
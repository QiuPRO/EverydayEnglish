#pragma once
#include <iostream>
#include "QtWidgets/QMainWindow"
#include "ui_VocabularyIncreaser.h"
#include "QString.h"
#include "MyButton.h"
#include "qfiledialog.h"
#include "WordList.h"
#include "ShuffleWordList.h"
#include "WrongWordList.h"
#include "qmessagebox.h"
#include "qtextcodec.h"
#include "qsignalmapper.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "TitleBar.h"
#include "PassageParser.h"
#include "qtableview.h"
#include "qtablewidget.h"
#include "qdesktopservices.h"
#include "qheaderview.h"
#include "qscrollbar.h"
#include "qtextedit.h"

class VocabularyIncreaser : public QMainWindow
{
    Q_OBJECT

private:
    //Ui::VocabularyIncreaserClass ui;
	MyButton* mBtnWord;			// 主页面按钮，跳转至背单词页面
	MyButton* mBtnBook;			// 主页面按钮，跳转至读课本页面
	MyButton* mBtnDict;			// 背单词页面按钮，跳转至听写功能
	MyButton* mBtnChi2Eng;		// 背单词页面按钮，跳转至中译英功能
	MyButton* mBtnEng2Chi;		// 背单词页面按钮，跳转至英译中功能
	MyButton* mBtnWordRoot;		// 背单词页面按钮，跳转至背词根页面
	MyButton* mBtnReturnWord;	// 背单词子页面按钮，返回背单词页面
	MyButton* mBtnReturnHome;	// 背单词页面按钮，返回主页面
	MyButton* mBtnOpenWordList;	// 背单词页面按钮，打开词库按钮
	MyButton* mBtnOpenWrongWordList;
	MyButton* mBtnSequential;	// 背单词页面按钮，顺序背单词
	MyButton* mBtnRandomly;		// 背单词页面按钮，乱序背单词
	MyButton* mBtnDictSubmit;	// 听写页面按钮，提交已填写内容
	MyButton* mBtnHelp;
	MyButton* mBtnHelpDetail;	// 帮助信息
	MyButton* mBtnPassage;		// 主页面按钮，跳转至查文章页面
	MyButton* mBtnReadPassage;	
	MyButton* mBtnCloseWordSet;
	MyButton* mBtnReturnTable;	// 关闭查看句子

	QLabel *lblQuestion;
	QLabel *lblPro;
	QLabel *lblLeftCounter;
	QLabel *lblCurWordList;
	QLabel *lblCurSequence;
	//QLabel *lblLeftCounter;

	QPushButton *btnChoices[4];
	QSignalMapper *btnMapper;
	QString fileName;
	QLineEdit* leDictInput;
	QLineEdit* leSentencesDisplayer;
	QTextEdit* teSentencesDisplayer;
	QTableWidget* tblWordCount;
	const int BTN_X_ORI = 230;
	const int BTN_Y_ORI = 500;
	const int BTN_WIDTH = 250;
	const int BTN_HEIGHT = 56;
	const int BTN_INTERVAL_X = 64;
	const int BTN_INTERVAL_Y = 50;
	const int TABLE_HEIGHT = 480;
	const int TABLE_WIDTH = 716;
	const int WIDGET_HEIGHT = 768;
	const int WIDGET_WIDTH = 1024;

	int curRightAnswer;
	Word curWord;

	bool isEng2Chi;
	bool isRoot = false;

	ShuffleWordList *curWordList = nullptr;		// 当前打开的单词表
	WrongWordList *wrongWordList = nullptr;		// 错词表
	WrongWordList *wrongWordListRoot = nullptr;

	QTextCodec *codec = QTextCodec::codecForName("GBK");


public:
	VocabularyIncreaser(QWidget *parent = Q_NULLPTR);
	void homepageInit();
	void wordPageInit();
	void passagePageInit();
	void eng2ChiPageInit();
	void chi2EngPageInit();
	void WordRootPageInit();
	void dictationPageInit();
	void tablePageInit();

	void setBackground(QString route);
	
	void hideHomePageButtons();
	void hideWordPageButtons();
	void hideWordSubPageObj();
	void hideWordPageObj();
	void hidePassagePageObj();
	void hideWordSetPageObj();

	void showBtnChoices();
	void hideBtnChoices();
	bool checkHasWordList();

	void showEng2ChiNextWord();
	void showChi2EngNextWord();
	void reCount();
	void tableInit(QStringList header, int rowCount, int ColumnCount);
	bool readWordList(QString fileName);
	QLabel* qlabelInit(
		QString color, 
		QString font, int fontSize, 
		int posX, int posY, 
		bool isCentral, int sizeX, int sizeY);
	QLineEdit* qLineEditInit(
		int width, int height, int posX, int posY,
		QString placeholderText, QString backgroundColor,
		QString font, int fontSize, bool isCentral=true);
	QTextEdit* qTextEditInit(
		int width, int height, int posX, int posY,
		QString placeholderText, QString backgroundColor,
		QString font, int fontSize, bool isCentral = true);


public slots:
	void mBtnWordClicked();
	void mBtnBookClicked();
	void mBtnDictClicked();
	void mBtnChi2EngClicked();
	void mBtnEng2ChiClicked();
	void mBtnReturnHomeClicked();
	void mBtnReturnWordClicked();
	void mBtnOpenWordListClicked();
	void mBtnOpenWrongWordListClicked();
	void mBtnSequentialClicked();
	void mBtnRandomlyClicked();
	void mBtnDictSubmitClicked();
	void mBtnWordRootClicked();
	void mBtnHelpClicked();
	void mBtnHelpDetailClicked();
	void mBtnPassageClicked();
	void mBtnReadPassageClicked();
	void mBtnCloseWordSetClicked();
	void mBtnReturnTableClicked();
	void getAnswer(int i);
	void tblWordCountItemClicked(int row, int col);
};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VocabularyIncreaser.h"
#include <QString.h>
#include "MyButton.h"
#include "qfiledialog.h"
#include "WordList.h"
#include "ShuffleWordList.h"
#include "WrongWordList.h"
#include <qmessagebox.h>
#include <qtextcodec.h>
#include <qsignalmapper.h>
#include <qlabel.h>
#include <memory>
#include "qlineedit.h"

class VocabularyIncreaser : public QMainWindow
{
    Q_OBJECT

private:
    //Ui::VocabularyIncreaserClass ui;
	MyButton* mBtnWord;			// ��ҳ�水ť����ת��������ҳ��
	MyButton* mBtnBook;			// ��ҳ�水ť����ת�����α�ҳ��
	MyButton* mBtnDict;			// ������ҳ�水ť����ת����д����
	MyButton* mBtnChi2Eng;		// ������ҳ�水ť����ת������Ӣ����
	MyButton* mBtnEng2Chi;		// ������ҳ�水ť����ת��Ӣ���й���
	MyButton* mBtnWordRoot;		// ������ҳ�水ť����ת�����ʸ�ҳ��
	MyButton* mBtnReturnWord;	// ��������ҳ�水ť�����ر�����ҳ��
	MyButton* mBtnReturnHome;	// ������ҳ�水ť��������ҳ��
	MyButton* mBtnOpenWordList;	// ������ҳ�水ť���򿪴ʿⰴť
	MyButton* mBtnOpenWrongWordList;
	MyButton* mBtnSequential;	// ������ҳ�水ť��˳�򱳵���
	MyButton* mBtnRandomly;		// ������ҳ�水ť�����򱳵���
	MyButton* mBtnDictSubmit;	// ��дҳ�水ť���ύ����д����
	MyButton* mBtnHelp;
	MyButton* mBtnHelpDetail;	// ������Ϣ

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
	const int BTN_X_ORI = 230;
	const int BTN_Y_ORI = 500;
	const int BTN_WIDTH = 250;
	const int BTN_HEIGHT = 56;
	const int BTN_INTERVAL_X = 64;
	const int BTN_INTERVAL_Y = 50;

	int curRightAnswer;
	Word curWord;

	bool isEng2Chi;
	bool isRoot = false;

	ShuffleWordList *curWordList = nullptr;		// ��ǰ�򿪵ĵ��ʱ�
	WrongWordList *wrongWordList = nullptr;		// ��ʱ�
	WrongWordList *wrongWordListRoot = nullptr;

	QTextCodec *codec = QTextCodec::codecForName("GBK");


public:
	VocabularyIncreaser(QWidget *parent = Q_NULLPTR);
	void homepageInit();
	void wordPageInit();
	void eng2ChiPageInit();
	void chi2EngPageInit();
	void WordRootPageInit();
	void dictationPageInit();

	void setBackground(QString route);
	void hideHomePageButtons();
	void hideWordPageButtons();
	void hideWordSubPageObj();
	void hideWordPageObj();

	void showBtnChoices();
	void hideBtnChoices();

	bool checkHasWordList();

	void showEng2ChiNextWord();
	void showChi2EngNextWord();
	void reCount();
	bool readWordList(QString fileName);
	QLabel* qlabelInit(QString color, QString font, int fontSize, int posX, int posY, bool isCentral, int sizeX, int sizeY);

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
	void getAnswer(int i);
};

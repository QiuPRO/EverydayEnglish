#include "VocabularyIncreaser.h"

VocabularyIncreaser::VocabularyIncreaser(QWidget *parent) : QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setFixedSize(1024, 768);

	//setWindowTitle("Custom Window");


	mBtnBook = new MyButton(this,
		":/VocabularyIncreaser/source/book_nor.png",
		":/VocabularyIncreaser/source/book_hov.png",
		":/VocabularyIncreaser/source/book_pre.png",
		193, 145, 226, 312);
	mBtnWord = new MyButton(this,
		":/VocabularyIncreaser/source/word_nor.png",
		":/VocabularyIncreaser/source/word_hov.png",
		":/VocabularyIncreaser/source/word_pre.png",
		193, 145, 415, 312);
	mBtnPassage = new MyButton(this,
		":/VocabularyIncreaser/source/passage_nor.png",
		":/VocabularyIncreaser/source/passage_hov.png",
		":/VocabularyIncreaser/source/passage_pre.png",
		193, 145, 604, 312);
	mBtnReadPassage = new MyButton(this,
		":/VocabularyIncreaser/source/readpassage_nor.png",
		":/VocabularyIncreaser/source/readpassage_hov.png",
		":/VocabularyIncreaser/source/readpassage_pre.png",
		193, 145, 415, 240);
	mBtnEng2Chi = new MyButton(this,
		":/VocabularyIncreaser/source/eng2chi_nor.png",
		":/VocabularyIncreaser/source/eng2chi_hov.png",
		":/VocabularyIncreaser/source/eng2chi_pre.png",
		193, 145, 226, 440);
	mBtnChi2Eng = new MyButton(this,
		":/VocabularyIncreaser/source/chi2eng_nor.png",
		":/VocabularyIncreaser/source/chi2eng_hov.png",
		":/VocabularyIncreaser/source/chi2eng_pre.png",
		193, 145, 415, 440);
	mBtnDict = new MyButton(this,
		":/VocabularyIncreaser/source/dictation_nor.png",
		":/VocabularyIncreaser/source/dictation_hov.png",
		":/VocabularyIncreaser/source/dictation_pre.png",
		193, 145, 604, 440);
	mBtnWordRoot = new MyButton(this,
		":/VocabularyIncreaser/source/wordroot_nor.png",
		":/VocabularyIncreaser/source/wordroot_hov.png",
		":/VocabularyIncreaser/source/wordroot_pre.png",
		193, 145, 415, 440);

	mBtnReturnWord = new MyButton(this,
		":/VocabularyIncreaser/source/return_nor.png",
		":/VocabularyIncreaser/source/return_hov.png",
		":/VocabularyIncreaser/source/return_pre.png",
		193, 145, 831, 623);
	mBtnReturnHome = new MyButton(this,
		":/VocabularyIncreaser/source/return_nor.png",
		":/VocabularyIncreaser/source/return_hov.png",
		":/VocabularyIncreaser/source/return_pre.png",
		193, 145, 831, 623);
	mBtnOpenWordList = new MyButton(this,
		":/VocabularyIncreaser/source/readlist_nor.png",
		":/VocabularyIncreaser/source/readlist_hov.png",
		":/VocabularyIncreaser/source/readlist_pre.png",
		193, 145, 415, 240);
	mBtnOpenWrongWordList = new MyButton(this,
		":/VocabularyIncreaser/source/review_nor.png",
		":/VocabularyIncreaser/source/review_hov.png",
		":/VocabularyIncreaser/source/review_pre.png",
		193, 145, 615, 240);
	mBtnRandomly = new MyButton(this,
		":/VocabularyIncreaser/source/ran_nor.png",
		":/VocabularyIncreaser/source/ran_hov.png",
		":/VocabularyIncreaser/source/ran_pre.png",
		193, 145, 321, 340);
	mBtnSequential = new MyButton(this,
		":/VocabularyIncreaser/source/seq_nor.png",
		":/VocabularyIncreaser/source/seq_hov.png",
		":/VocabularyIncreaser/source/seq_pre.png",
		193, 145, 510, 340);
	mBtnDictSubmit = new MyButton(this,
		":/VocabularyIncreaser/source/dictsub_nor.png",
		":/VocabularyIncreaser/source/dictsub_hov.png",
		":/VocabularyIncreaser/source/dictsub_pre.png",
		193, 145, 550, 520);
	mBtnCloseWordSet = new MyButton(this,
		":/VocabularyIncreaser/source/return_nor.png",
		":/VocabularyIncreaser/source/return_hov.png",
		":/VocabularyIncreaser/source/return_pre.png",
		193, 145, 831, 623);

	lblQuestion = qlabelInit("<font color=white>Test</font>", "SimHei", 32, 0, 250, true, 1024, 100);
	lblPro = qlabelInit("<font color=grey>啊啊啊</font>", "SimHei", 24, 0, 330, true, 1024, 100);
	lblLeftCounter = qlabelInit("<font color=white>" + codec->toUnicode("进度：") 
		+ QString::number(0) + "/" + QString::number(0) 
		+ "</font>", "SimHei", 10, 20, 45, false, 1024, 20);
	lblCurWordList = qlabelInit("<font color=white>" + codec->toUnicode("当前词库：") + "</font>", "SimHei", 10, 20, 65, false, 1024, 20);
	lblCurSequence = qlabelInit("<font color=white>" + codec->toUnicode("当前排序：顺序")  + "</font>", "SimHei", 10, 20, 85, false, 1024, 20);

	leDictInput = qLineEditInit(1024, 100, 0, 450,
		codec->toUnicode("请在此输入您的答案"),
		"#ffffff", "SimHei", 24);

	wrongWordList = new WrongWordList();
	wrongWordListRoot = new WrongWordList();
	btnMapper = new QSignalMapper(this);
	mBtnHelp = new MyButton(this,
		":/VocabularyIncreaser/source/help_nor_.png",
		":/VocabularyIncreaser/source/help_hov_.png",
		":/VocabularyIncreaser/source/help_pre_.png",
		30, 30, 919, 7);
	mBtnHelpDetail = new MyButton(this, ":/VocabularyIncreaser/source/help.png", "", "", 1024, 768, 0, 0);
	mBtnReturnTable = new MyButton(this, ":/VocabularyIncreaser/source/returntable.png", "", "", WIDGET_WIDTH, WIDGET_HEIGHT, 0, 0);
	tblWordCount = new QTableWidget(this);
	tblWordCount->hide();
	teSentencesDisplayer = qTextEditInit(
		TABLE_WIDTH, TABLE_HEIGHT,
		(WIDGET_WIDTH - TABLE_WIDTH) / 2, 240,
		"", "#ffffff", "SimHei", 12, false);
	TitleBar *pTitleBar = new TitleBar(this);
	installEventFilter(pTitleBar);
	pTitleBar->setParent(this);
	pTitleBar->show();
	for (int i = 0; i < 4; i++)
	{
		btnChoices[i] = new QPushButton(this);
		btnChoices[i]->setFont(QFont("SimHei", 12));
		btnChoices[i]->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
		btnChoices[i]->move(BTN_X_ORI + (i % 2) * (BTN_INTERVAL_X + BTN_WIDTH),
							BTN_Y_ORI + (i / 2) * (BTN_INTERVAL_Y + BTN_HEIGHT));
		btnChoices[i]->hide();
		btnChoices[i]->setStyleSheet("background-color: rgb(81, 187, 222);");
		connect(btnChoices[i], SIGNAL(clicked()), btnMapper, SLOT(map()));
		btnMapper->setMapping(btnChoices[i], i);
	}
	connect(btnMapper, SIGNAL(mapped(int)), this, SLOT(getAnswer(int)));
	connect(tblWordCount, SIGNAL(cellClicked(int, int)), this, SLOT(tblWordCountItemClicked(int, int)));

	connect(&mBtnBook->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnBookClicked()));
	connect(&mBtnWord->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnWordClicked()));
	connect(&mBtnPassage->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnPassageClicked()));
	connect(&mBtnReadPassage->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnReadPassageClicked()));
	connect(&mBtnDict->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnDictClicked()));
	connect(&mBtnWordRoot->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnWordRootClicked()));
	connect(&mBtnChi2Eng->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnChi2EngClicked()));
	connect(&mBtnEng2Chi->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnEng2ChiClicked()));
	connect(&mBtnReturnHome->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnReturnHomeClicked()));
	connect(&mBtnReturnWord->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnReturnWordClicked()));
	connect(&mBtnOpenWordList->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnOpenWordListClicked()));
	connect(&mBtnOpenWrongWordList->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnOpenWrongWordListClicked()));
	connect(&mBtnRandomly->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnRandomlyClicked()));
	connect(&mBtnSequential->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnSequentialClicked()));
	connect(&mBtnDictSubmit->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnDictSubmitClicked()));
	connect(&mBtnHelp->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnHelpClicked()));
	connect(&mBtnHelpDetail->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnHelpDetailClicked()));
	connect(&mBtnCloseWordSet->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnCloseWordSetClicked()));
	connect(&mBtnReturnTable->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnReturnTableClicked()));




	homepageInit();


}
// Init.
void VocabularyIncreaser::homepageInit()
{
	this->setBackground(":/VocabularyIncreaser/source/homepage.png");
	mBtnBook->show();
	mBtnWord->show();
	mBtnPassage->show();
}

void VocabularyIncreaser::wordPageInit()
{
	this->setBackground(":/VocabularyIncreaser/source/wordreci.png");

	mBtnHelp->show();
	mBtnReturnHome->show();
	mBtnOpenWordList->show();
	mBtnOpenWrongWordList->show();
	mBtnHelp->setDisabled(false);
	mBtnRandomly->setDisabled(false);
	mBtnSequential->setDisabled(false);

	lblLeftCounter->show();
	lblCurWordList->show();
	lblCurSequence->show();
	if (curWordList == nullptr)
		return;
	mBtnSequential->show();
	mBtnRandomly->show();
	if (isRoot) 
	{
		mBtnChi2Eng->setDisabled(true);
		mBtnEng2Chi->setDisabled(true);
		mBtnDict->setDisabled(true);
		mBtnWordRoot->setDisabled(false);

		mBtnChi2Eng->hide();
		mBtnEng2Chi->hide();
		mBtnDict->hide();
		mBtnWordRoot->show();

		if (wrongWordListRoot->size() > 0)
			wrongWordListRoot->writeToFile(WrongWordList::WRONG_WORD_LIST_ROOT_PATH);
	}
	else 
	{
		mBtnChi2Eng->show();
		mBtnEng2Chi->show();
		mBtnDict->show();
		mBtnWordRoot->hide();

		mBtnChi2Eng->setDisabled(false);
		mBtnEng2Chi->setDisabled(false);
		mBtnDict->setDisabled(false);
		mBtnWordRoot->setDisabled(true);

		if (wrongWordList->size() > 0)
			wrongWordList->writeToFile(WrongWordList::WRONG_WORD_LIST_PATH);
	}

}

void VocabularyIncreaser::passagePageInit()
{
	mBtnReturnHome->show();
	mBtnReadPassage->show();
	lblLeftCounter->setText("<font color=white>" + codec->toUnicode("本文词数：") + "</font>");
	lblLeftCounter->show();
	lblCurWordList->setText("<font color=white>" + codec->toUnicode("当前文章：") + "</font>");
	lblCurWordList->show();
	this->setBackground(":/VocabularyIncreaser/source/passage.png");

}

void VocabularyIncreaser::eng2ChiPageInit()
{
	//hideWordPageButtons();
	this->setBackground(":/VocabularyIncreaser/source/eng2chipage.png");
	mBtnReturnWord->show();
	showBtnChoices();
	lblQuestion->show();
	lblPro->show();
	lblCurWordList->show();
	lblCurSequence->show();
	lblLeftCounter->show();

	showEng2ChiNextWord();
	isEng2Chi = 1;
}

void VocabularyIncreaser::chi2EngPageInit()
{
	//hideWordPageButtons();
	this->setBackground(":/VocabularyIncreaser/source/chi2engpage.png");
	mBtnReturnWord->show();
	showBtnChoices();
	lblQuestion->show();
	lblLeftCounter->show();
	lblCurWordList->show();
	lblCurSequence->show();
	//lblPro->show();
	showChi2EngNextWord();
	isEng2Chi = 0;
}

void VocabularyIncreaser::WordRootPageInit()
{
	this->setBackground(":/VocabularyIncreaser/source/wordroot.png");
	mBtnReturnWord->show();
	showBtnChoices();
	lblQuestion->show();
	lblPro->show();
	lblLeftCounter->show();
	lblCurWordList->show();
	lblCurSequence->show();
	showEng2ChiNextWord();
}

void VocabularyIncreaser::dictationPageInit()
{
	hideWordPageButtons();
	this->setBackground(":/VocabularyIncreaser/source/dictationpage.png");
	mBtnReturnWord->show();
	mBtnDictSubmit->show();

	lblQuestion->show();
	lblLeftCounter->show();
	lblCurWordList->show();
	lblCurSequence->show();
	leDictInput->show();
	showChi2EngNextWord();
}

void VocabularyIncreaser::tablePageInit()
{
	lblLeftCounter->setText("<font color=white>" + codec->toUnicode("本文词数：") + QString::number(PassageParser::getParser().getWordCount()) + "</font>");
	lblLeftCounter->show();
	lblCurWordList->setText("<font color=white>" + codec->toUnicode("当前文章：") + PassageParser::getParser().getPassagePath() +"</font>");
	lblCurWordList->show();
	mBtnCloseWordSet->show();
}

// Dealing with the jumping between the page.
void VocabularyIncreaser::setBackground(QString route)
{
	QPixmap pixmap;
	QPalette palette(this->palette());
	pixmap = QPixmap(route).scaled(this->size());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
}

QLabel* VocabularyIncreaser::qlabelInit(QString color, QString font, int fontSize, int posX, int posY, bool isCentral, int sizeX, int sizeY)
{
	QLabel* lbl = new QLabel(color, this);
	lbl->setFont(QFont(font, fontSize));
	lbl->move(posX, posY);
	if (isCentral)
		lbl->setAlignment(Qt::AlignCenter);
	lbl->setFixedSize(sizeX, sizeY);
	lbl->hide();
	return lbl;
}

QLineEdit* VocabularyIncreaser::qLineEditInit(int width, int height, int posX, int posY, QString placeholderText, QString backgroundColor, QString font, int fontSize, bool isCentral)
{
	QLineEdit* le = new QLineEdit();
	le->setFixedSize(width, height);
	le->setParent(this);
	le->move(posX, posY);
	if (isCentral)
		le->setAlignment(Qt::AlignCenter);
	le->setPlaceholderText(placeholderText);
	le->setStyleSheet("QLineEdit{border-top:0px solid #e8f3f9; background:transparent;color:" + backgroundColor +";}");
	le->setFont(QFont(font, fontSize));
	le->hide();
	return le;
}

QTextEdit * VocabularyIncreaser::qTextEditInit(int width, int height, int posX, int posY, QString placeholderText, QString backgroundColor, QString font, int fontSize, bool isCentral)
{
	QTextEdit* te = new QTextEdit();
	te->setReadOnly(true);
	te->setFixedSize(width, height);
	te->setParent(this);
	te->move(posX, posY);
	if (isCentral)
		te->setAlignment(Qt::AlignCenter);
	te->setPlaceholderText(placeholderText);
	te->setStyleSheet("QLineEdit{border-top:0px solid #e8f3f9; background:transparent;color:" + backgroundColor + ";}");
	te->setFont(QFont(font, fontSize));
	te->hide();
	return te;
}

void VocabularyIncreaser::hideHomePageButtons()
{
	mBtnBook->hide();
	mBtnWord->hide();
	mBtnPassage->hide();
}

void VocabularyIncreaser::hideWordPageButtons()
{
	mBtnHelp->hide();
	mBtnDict->hide();
	mBtnChi2Eng->hide();
	mBtnEng2Chi->hide();
	mBtnWordRoot->hide();
	mBtnReturnHome->hide();
	mBtnOpenWordList->hide();
	mBtnOpenWrongWordList->hide();
	mBtnSequential->hide();
	mBtnRandomly->hide();
	//
	lblCurWordList->hide();
	lblCurSequence->hide();
	lblLeftCounter->hide();

}

void VocabularyIncreaser::hideWordPageObj()
{
	mBtnReturnHome->hide();
	hideWordPageButtons();
}

void VocabularyIncreaser::hidePassagePageObj()
{
	mBtnReturnHome->hide();
	mBtnReadPassage->hide();
	tblWordCount->hide();
}

void VocabularyIncreaser::hideWordSetPageObj()
{
	tblWordCount->hide();
	mBtnCloseWordSet->hide();
	lblCurWordList->hide();
	lblLeftCounter->hide();
}

void VocabularyIncreaser::hideWordSubPageObj()
{
	mBtnReturnWord->hide();
	hideBtnChoices();
	lblPro->hide();
	lblQuestion->hide();
	lblLeftCounter->hide();
	lblCurWordList->hide();
	lblCurSequence->hide();
	leDictInput->hide();
	mBtnDictSubmit->hide();
}




void VocabularyIncreaser::showBtnChoices()
{
	for (int i = 0; i < 4; i++)
		btnChoices[i]->show();
}

void VocabularyIncreaser::hideBtnChoices()
{
	for (int i = 0; i < 4; i++)
		btnChoices[i]->hide();
}

bool VocabularyIncreaser::checkHasWordList()
{
	return curWordList != nullptr;
}

void VocabularyIncreaser::showEng2ChiNextWord()
{
	Word word = curWordList->shuffleWord();
	curWord = word;
	QStringList ans = curWordList->get4Chi(curWord.chi);
	curRightAnswer = rand() % 4;
	ans[curRightAnswer] = word.chi;
	for (int i = 0; i < 4; i++)
	{
		btnChoices[i]->setText(ans[i]);
	}
	lblLeftCounter->setText("<font color=white>" + codec->toUnicode("进度：") +
		QString::number(curWordList->count()) + "/" +
		QString::number(curWordList->size()) + "</font>");
	lblQuestion->setText("<font color=white>" + word.eng + "</font>");
	lblPro->setText("<font color=grey>" + word.pro + "</font>");
	if (word.eng == "You have finished!")
	{
		hideWordSubPageObj();
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("您已经完成了当前词库！"), QMessageBox::Ok, QMessageBox::Ok);
		wordPageInit();
		return;
	}
}

void VocabularyIncreaser::showChi2EngNextWord()
{
	Word word = curWordList->shuffleWord();
	QStringList ans = curWordList->get4Eng(word.eng);
	curRightAnswer = rand() % 4;
	curWord = word;
	ans[curRightAnswer] = word.eng;
	for (int i = 0; i < 4; i++)
	{
		btnChoices[i]->setText(ans[i]);
	}
	lblQuestion->setText("<font color=white>" + word.chi + "</font>");
	lblLeftCounter->setText("<font color=white>" + codec->toUnicode("进度：") +
		QString::number(curWordList->count()) + "/" +
		QString::number(curWordList->size()) + "</font>");
	if (word.eng == "You have finished!")
	{
		hideWordSubPageObj();
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("您已经完成了当前词库！"), QMessageBox::Ok, QMessageBox::Ok);
		wordPageInit();
		return;
	}
}

void VocabularyIncreaser::reCount()
{
	if (curWordList->count() != 0) 
	{
		if (curWordList->count() == curWordList->size())
		{
			QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("已完成当前词库，自动设为重新开始！"), QMessageBox::Ok, QMessageBox::Ok);
			curWordList->clearCount();
			return;
		}
		int click = QMessageBox::warning(this, 
			codec->toUnicode("提示"), 
			codec->toUnicode("当前已背") + QString::number(curWordList->count()) + codec->toUnicode("词，是否继续背诵？"), 
			QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
		if (click == QMessageBox::No) 
			curWordList->clearCount();
	}
}

void VocabularyIncreaser::tableInit(QStringList header, int rowCount, int ColumnCount)
{
	tblWordCount->setFixedSize(TABLE_WIDTH, TABLE_HEIGHT);
	tblWordCount->move((WIDGET_WIDTH - TABLE_WIDTH) / 2, 240);
	tblWordCount->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	tblWordCount->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tblWordCount->setStyleSheet("background-color:rgba(220, 220, 220, 220);");

	tblWordCount->setColumnCount(ColumnCount);
	tblWordCount->setRowCount(rowCount);
	tblWordCount->setHorizontalHeaderLabels(header);
	tblWordCount->setColumnWidth(0, (TABLE_WIDTH - 24) / 2);
	tblWordCount->setColumnWidth(1, (TABLE_WIDTH - 24) / 2);
	tblWordCount->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tblWordCount->setSelectionMode(QAbstractItemView::SingleSelection);
	tblWordCount->setStyleSheet("QTableWidget::item{background:rgba(154, 218, 255, 200);}");
	QHeaderView* headerView = tblWordCount->verticalHeader();//m_ItemTable为QTableWidget
	headerView->setHidden(true);//隐藏tablewidget自带行号列
	headerView = tblWordCount->horizontalHeader();
	headerView->setDisabled(true);
	headerView->setStyleSheet("QHeaderView::section {"
		"background:rgb(60, 153, 186);color: black;padding-left: 4px;border: 1px solid #6c6ccc;}");        // 整个标题头区域背景色
	headerView->setFixedHeight(42);
	headerView->setFont(QFont("SimHei", 14, 1));

	tblWordCount->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"        //垂直滑块整体
		"background:#EEEEFF;"  //背景色
		"padding-top:20px;"    //上预留位置（放置向上箭头）
		"padding-bottom:20px;" //下预留位置（放置向下箭头）
		"padding-left:2px;"    //左预留位置（美观）
		"padding-right:2px;"   //右预留位置（美观）
		"border-left:1px solid #d7d7d7;}"//左分割线
		"QScrollBar::handle:vertical{"//滑块样式
		"background:#91a0bb;"  //滑块颜色
		"border-radius:6px;"   //边角圆润
		"min-height:80px;}"    //滑块最小高度
		"QScrollBar::handle:vertical:hover{"//鼠标触及滑块样式
		"background:#a1b0cc;}" //滑块颜色
		"QScrollBar::add-line:vertical{"//向下箭头样式
		"background:url(:/VocabularyIncreaser/source/down.png) center no-repeat;}"
		"QScrollBar::sub-line:vertical{"//向上箭头样式
		"background:url(:/VocabularyIncreaser/source/up.png) center no-repeat;}"

	);
	tblWordCount->setFocusPolicy(Qt::NoFocus);
}

bool VocabularyIncreaser::readWordList(QString fileName)
{
	if (fileName == "")
		return false;
	QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("词库加载成功！"), QMessageBox::Ok, QMessageBox::Ok);

	if (curWordList == nullptr)
	{
		curWordList = new ShuffleWordList();
	}
	curWordList->clear();
	curWordList->clearCount();
	int status = curWordList->readTXT(fileName);
	if (status == ReadFileStatus::ROOT_FILE) 
	{
		isRoot = true;
		mBtnChi2Eng->setDisabled(true);
		mBtnEng2Chi->setDisabled(true);
		mBtnDict->setDisabled(true);
		mBtnWordRoot->setDisabled(false);
		return true;
	}
	else if (status == ReadFileStatus::SUCCESS) {
		isRoot = false;
		mBtnChi2Eng->setDisabled(false);
		mBtnEng2Chi->setDisabled(false);
		mBtnDict->setDisabled(false);
		mBtnWordRoot->setDisabled(true);
		return true;
	}
	else
		return false;
}


// Slots are inplied here.
void VocabularyIncreaser::mBtnBookClicked() 
{
	QString path = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("pdf(*.pdf)"));
	QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}


void VocabularyIncreaser::mBtnWordClicked()
{
	hideHomePageButtons();
	wordPageInit();
}

void VocabularyIncreaser::mBtnPassageClicked()
{
	hideHomePageButtons();
	passagePageInit();
}

void VocabularyIncreaser::mBtnReadPassageClicked()
{
	mBtnCloseWordSet->show();
	QString passagePath = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("TXT(*.txt)"));
	if (passagePath == "")
		return;
	PassageParser::getParser().setPassagePath(passagePath);
	QVector<QPair<QString, QVector<int>>> vct = PassageParser::getParser().getWordSet();
	QStringList header;
	header << codec->toUnicode("单词") << codec->toUnicode("出现次数");
	tableInit(header, vct.size(), 2);
	//int totalWord = 0;
	for (int i = 0; i < vct.size(); i++)
	{
		vct[i].first[0] == '\t' ?
			tblWordCount->setItem(i, 0, new QTableWidgetItem(vct[i].first.split("\t")[1])) : 
			tblWordCount->setItem(i, 0, new QTableWidgetItem(vct[i].first));
		tblWordCount->setItem(i, 1, new QTableWidgetItem(QString::number(vct[i].second.size())));
		//totalWord += vct[i].second.size();
	}
	lblLeftCounter->setText("<font color=white>" + codec->toUnicode("本文词数：") + QString::number(PassageParser::getParser().getWordCount()) + "</font>");
	lblLeftCounter->show();
	lblCurWordList->setText("<font color=white>" + codec->toUnicode("当前文章：") + passagePath + "</font>");
	lblCurWordList->show();
	hidePassagePageObj();
	tblWordCount->show();


}

void VocabularyIncreaser::mBtnCloseWordSetClicked()
{
	hideWordSetPageObj();
	passagePageInit();
}

void VocabularyIncreaser::mBtnReturnTableClicked()
{
	mBtnReturnTable->hide();
	teSentencesDisplayer->hide();
	tablePageInit();
	tblWordCount->show();
}

void VocabularyIncreaser::mBtnDictClicked()
{
	if (!checkHasWordList())
	{
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("请先选择一个词库"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	reCount();
	hideWordPageButtons();
	dictationPageInit();
}

void VocabularyIncreaser::mBtnChi2EngClicked()
{
	if (!checkHasWordList())
	{
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("请先选择一个词库"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	reCount();
	hideWordPageButtons();
	chi2EngPageInit();

}

void VocabularyIncreaser::mBtnEng2ChiClicked()
{
	if (!checkHasWordList())
	{
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("请先选择一个词库"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	reCount();
	hideWordPageButtons();
	eng2ChiPageInit();
}

void VocabularyIncreaser::mBtnWordRootClicked()
{
	if (!checkHasWordList())
	{
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("请先打开词根词库"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	isRoot = true;
	reCount();
	hideWordPageButtons();
	WordRootPageInit();
}

void VocabularyIncreaser::mBtnHelpClicked()
{
	hideWordPageObj();
	mBtnHelpDetail->show();
}

void VocabularyIncreaser::mBtnHelpDetailClicked()
{
	mBtnHelpDetail->hide();
	wordPageInit();
}


void VocabularyIncreaser::mBtnReturnHomeClicked()
{
	hideWordPageObj();
	hidePassagePageObj();
	homepageInit();
}


void VocabularyIncreaser::mBtnReturnWordClicked()
{
	hideWordSubPageObj();
	wordPageInit();
}

void VocabularyIncreaser::mBtnOpenWordListClicked()
{
	fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("text(*.txt)"));
	if (readWordList(fileName)) {
		//QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("词库加载成功！"), QMessageBox::Ok, QMessageBox::Ok);
		lblCurWordList->setText("<font color=white>" + codec->toUnicode("当前词库：") + fileName + "</font>");
		lblLeftCounter->setText("<font color=white>" + codec->toUnicode("进度：") +
			QString::number(curWordList->count()) + "/" +
			QString::number(curWordList->size()) + "</font>");
	}
	else 
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("词库加载失败，请重新打开！"), QMessageBox::Ok, QMessageBox::Ok);
	wordPageInit();

}

void VocabularyIncreaser::mBtnOpenWrongWordListClicked()
{
	/*if (curWordList)
		delete curWordList;*/
	QString fName;
	if (!isRoot)
		fName = WrongWordList::WRONG_WORD_LIST_PATH;
	else
		fName = WrongWordList::WRONG_WORD_LIST_ROOT_PATH;
	ShuffleWordList *swl = new ShuffleWordList();
	swl->readFromFile(fName);
	if (swl->size() < 5)
	{
		QMessageBox::warning(this, codec->toUnicode("提示"), codec->toUnicode("错词本中的单词太少啦！多背一些再来吧~"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	if (curWordList == nullptr)
	{
		curWordList = new ShuffleWordList();
	}
	curWordList->clear();
	curWordList->clearCount();
	curWordList->readFromFile(fName);

	//curWordList->setFromWordList(wrongWordList);
	QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("错词本加载成功！"), QMessageBox::Ok, QMessageBox::Ok);
	lblCurWordList->setText("<font color=white>" + codec->toUnicode("当前词库：错词本") + "</font>");
	lblLeftCounter->setText("<font color=white>" + codec->toUnicode("进度：") +
		QString::number(curWordList->count()) + "/" +
		QString::number(curWordList->size()) + "</font>");
	wordPageInit();
}

void VocabularyIncreaser::mBtnSequentialClicked()
{
	if (!checkHasWordList())
	{
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("请先选择一个词库"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	if (!curWordList->isSequential()) 
	{
		readWordList(fileName);
		lblLeftCounter->setText("<font color=white>" + codec->toUnicode("进度：") +
			QString::number(curWordList->count()) + "/" +
			QString::number(curWordList->size()) + "</font>");
	}
	curWordList->setSequential(true);
	mBtnSequential->setDisabled(true);
	mBtnRandomly->setDisabled(true);
	QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("已设置为顺序模式。"), QMessageBox::Ok, QMessageBox::Ok);
	lblCurSequence->setText("<font color=white>" + codec->toUnicode("当前排序：顺序") + "</font>");

}

void VocabularyIncreaser::mBtnRandomlyClicked()
{
	if (!checkHasWordList())
	{
		QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("请先选择一个词库"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	if (curWordList->isSequential()) {
		curWordList->clearCount();
		lblLeftCounter->setText("<font color=white>" + codec->toUnicode("进度：") +
			QString::number(curWordList->count()) + "/" +
			QString::number(curWordList->size()) + "</font>");
	}
	curWordList->setSequential(false);
	mBtnSequential->setDisabled(true);
	mBtnRandomly->setDisabled(true);
	QMessageBox::information(this, codec->toUnicode("提示"), codec->toUnicode("已设置为乱序模式。"), QMessageBox::Ok, QMessageBox::Ok);
	lblCurSequence->setText("<font color=white>" + codec->toUnicode("当前排序：乱序") + "</font>");

}

void VocabularyIncreaser::mBtnDictSubmitClicked()
{
	QString leDictInputText = leDictInput->text();
	if (curWord.eng == leDictInputText) 
	{
		QMessageBox::information(this, codec->toUnicode("恭喜"), codec->toUnicode("回答正确！"), QMessageBox::Ok, QMessageBox::Ok);
		wrongWordList->removeWord(curWord);
	}
	else
	{
		QMessageBox::warning(this, codec->toUnicode("提示"), codec->toUnicode("回答错误！正确答案是【") + curWord.eng + codec->toUnicode("】"), QMessageBox::Ok, QMessageBox::Ok);
		wrongWordList->removeWord(curWord);
		wrongWordList->add2WrongWordList(curWord);
	}
	showChi2EngNextWord();
	leDictInput->setText("");
}


void VocabularyIncreaser::getAnswer(int i)
{
	//QMessageBox::information(this, codec->toUnicode("提示"), QString::number(i), QMessageBox::Ok, QMessageBox::Ok);
	if (i == curRightAnswer)
	{
		QMessageBox::information(this, codec->toUnicode("恭喜"), codec->toUnicode("回答正确！"), QMessageBox::Ok, QMessageBox::Ok);
		if (!isRoot)
			wrongWordList->removeWord(curWord);
		else
			wrongWordListRoot->removeWord(curWord);
	}
	else
	{
		QMessageBox::warning(this, codec->toUnicode("提示"), codec->toUnicode("回答错误！正确答案是【") + (isEng2Chi ? curWord.chi : curWord.eng) + codec->toUnicode("】"), QMessageBox::Ok, QMessageBox::Ok);
		if (!isRoot)
		{
			wrongWordList->removeWord(curWord);
			wrongWordList->add2WrongWordList(curWord);
		}
		else
		{
 			wrongWordListRoot->removeWord(curWord);
			wrongWordListRoot->add2WrongWordList(curWord);
		}

	}
	isEng2Chi ? showEng2ChiNextWord() : showChi2EngNextWord();
}
#include "qdebug.h"
void VocabularyIncreaser::tblWordCountItemClicked(int row, int col)
{
	if (col != 0)
		return;
	hideWordSetPageObj();

	mBtnReturnTable->show();
	lblCurWordList->show();
	lblLeftCounter->show();
	//leSentencesDisplayer
	int pre = -1; // 维护是否和前一个句子相同
	QString displayString = "";
	QString tmp = "";
	for (int i = 0; i < PassageParser::getParser().getWordSet()[row].second.size(); i++) 
	{
		if (pre != PassageParser::getParser().getWordSet()[row].second[i])
		{
			pre = PassageParser::getParser().getWordSet()[row].second[i];
			displayString += codec->toUnicode("第") + QString::number(pre + 1) + codec->toUnicode("句： ") + "<br>";
			tmp = PassageParser::getParser().getSentences()[pre];
			qDebug() << tmp.split(" ")[0].split(",")[0].toLower();
			qDebug() << PassageParser::getParser().getWordSet()[row].first;

			if ((tmp.split(" ")[0].split(",")[0].toLower() == PassageParser::getParser().getWordSet()[row].first) 
				|| ((PassageParser::getParser().getWordSet()[row].first.split("\t")[0] == "" )
				&& (tmp.split(" ")[0].split(",")[0].toLower() == PassageParser::getParser().getWordSet()[row].first.split("\t")[1]))) 
			{
				displayString += "<font color=#007acc>" + tmp.mid(0, PassageParser::getParser().getWordSet()[row].first.size()) + "</font>";
				tmp = tmp.mid(PassageParser::getParser().getWordSet()[row].first.size());
			}
			tmp.replace(
					" " + PassageParser::getParser().getWordSet()[row].first + " ",
					" <font color=#007acc>" + PassageParser::getParser().getWordSet()[row].first + "</font> ");
			tmp.replace(
				" " + PassageParser::getParser().getWordSet()[row].first + ",",
				" <font color=#007acc>" + PassageParser::getParser().getWordSet()[row].first + "</font>,");
			tmp.replace(
				" " + PassageParser::getParser().getWordSet()[row].first + ".",
				" <font color=#007acc>" + PassageParser::getParser().getWordSet()[row].first + "</font>.");
			displayString += tmp;
			if (i != PassageParser::getParser().getWordSet()[row].second.size() - 1)
				displayString += "<br>";
		}
	}
	teSentencesDisplayer->setText(displayString);
	teSentencesDisplayer->show();
}



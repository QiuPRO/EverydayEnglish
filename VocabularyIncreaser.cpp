#include "VocabularyIncreaser.h"

VocabularyIncreaser::VocabularyIncreaser(QWidget *parent) : QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowFlags(Qt::CustomizeWindowHint);
	setFixedSize(1024, 768);
	mBtnBook = new MyButton(this,
		":/VocabularyIncreaser/source/book_nor.png",
		":/VocabularyIncreaser/source/book_hov.png",
		":/VocabularyIncreaser/source/book_pre.png",
		193, 145, 321, 312);
	mBtnWord = new MyButton(this,
		":/VocabularyIncreaser/source/word_nor.png",
		":/VocabularyIncreaser/source/word_hov.png",
		":/VocabularyIncreaser/source/word_pre.png",
		193, 145, 510, 312);

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

	lblQuestion = qlabelInit("<font color=white>Test</font>", "SimHei", 32, 0, 250, true, 1024, 100);
	lblPro = qlabelInit("<font color=grey>啊啊啊</font>", "SimHei", 24, 0, 330, true, 1024, 100);
	lblLeftCounter = qlabelInit("<font color=white>" + codec->toUnicode("进度：") 
		+ QString::number(0) + "/" + QString::number(0) 
		+ "</font>", "SimHei", 10, 20, 20, false, 1024, 100);
	lblCurWordList = qlabelInit("<font color=white>" + codec->toUnicode("当前词库：") + "</font>", "SimHei", 10, 20, 40, false, 1024, 100);
	lblCurSequence = qlabelInit("<font color=white>" + codec->toUnicode("当前排序：顺序")  + "</font>", "SimHei", 10, 20, 60, false, 1024, 100);
	leDictInput = new QLineEdit();
	leDictInput->setFixedSize(1024, 100);
	leDictInput->setParent(this);
	leDictInput->move(0, 450);
	leDictInput->setAlignment(Qt::AlignCenter);
	leDictInput->setPlaceholderText(codec->toUnicode("请在此输入您的答案"));
	//leDictInput->setStyleSheet("color: white; background-color: rgba(255, 255, 255, 0)");
	leDictInput->setStyleSheet("QLineEdit{border-top:0px solid #e8f3f9; background:transparent;color:#ffffff;}");

	leDictInput->setFont(QFont("SimHei", 24));
	leDictInput->hide();

	wrongWordList = new WrongWordList();
	wrongWordListRoot = new WrongWordList();
	btnMapper = new QSignalMapper(this);
	mBtnHelp = new MyButton(this,
		":/VocabularyIncreaser/source/help_nor.png",
		":/VocabularyIncreaser/source/help_hov.png",
		":/VocabularyIncreaser/source/help_pre.png",
		101, 101, 903, 20);
	mBtnHelpDetail = new MyButton(this,
		":/VocabularyIncreaser/source/help.png",
		"", "",	1024, 768, 0, 0);
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


	connect(&mBtnBook->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnBookClicked()));
	connect(&mBtnWord->getQButton(), SIGNAL(clicked()), this, SLOT(mBtnWordClicked()));
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




	homepageInit();


}
// Init.
void VocabularyIncreaser::homepageInit()
{
	this->setBackground(":/VocabularyIncreaser/source/homepage.png");
	mBtnBook->show();
	mBtnWord->show();
}

void VocabularyIncreaser::wordPageInit()
{
	this->setBackground(":/VocabularyIncreaser/source/wordreci.png");

	//mBtnChi2Eng->setDisabled(false);
	//mBtnEng2Chi->setDisabled(false);
	//mBtnDict->setDisabled(false);
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
	// TODO:
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

void VocabularyIncreaser::hideHomePageButtons()
{
	mBtnBook->hide();
	mBtnWord->hide();
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

void VocabularyIncreaser::hideWordPageObj()
{
	mBtnReturnHome->hide();
	hideWordPageButtons();
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


#include <qdesktopservices.h>
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



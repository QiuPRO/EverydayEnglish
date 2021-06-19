#include "VocabularyIncreaser.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/VocabularyIncreaser/source/icon.png"));
    VocabularyIncreaser w;
    w.show();
    return a.exec();
}

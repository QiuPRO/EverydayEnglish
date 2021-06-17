#include "MyButton.h"
MyButton::MyButton(QWidget *parent, QString route1, QString route2, QString route3, int heightX, int heightY, int posX, int posY) {
	btn.setParent(parent);
	btn.move(posX, posY);
	btn.setFixedSize(heightX, heightY);
	QString tmp1, tmp2, tmp3;
	tmp1 = "QPushButton{border-image: url(" + route1 + ");}";
	if (route2 != "")
		tmp2 = "QPushButton:hover{border-image: url(" + route2 + ");}";
	if (route3 != "")
		tmp3 = "QPushButton:pressed{border-image: url(" + route3 + ")}";
	btn.setStyleSheet(tmp1 + tmp2 + tmp3);
	btn.hide();
}
void MyButton::show()
{
	btn.show();
}

void MyButton::hide()
{
	btn.hide();
}

void MyButton::setDisabled(bool isTrue) 
{
	btn.setDisabled(isTrue);
}

QPushButton& MyButton::getQButton()
{
	return btn;
}



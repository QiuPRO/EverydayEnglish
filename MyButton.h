#pragma once

#include "qpushbutton.h"
#include "qstring.h"
#include "qpushbutton.h"
class MyButton 
{
public:
	MyButton(QWidget *parent, QString route1, QString route2, QString route3, int heightX, int heightY, int posX, int posY);
	void show();
	void hide();
	void setDisabled(bool isTrue);
	QPushButton& getQButton();
	// inline void setParent(QWidget* parent);
	/* void MyButton::setParent(QWidget* parent)
	{
		btn.setParent(parent);
	} 
	*/
	~MyButton() {};
private:
	QPushButton btn;
};


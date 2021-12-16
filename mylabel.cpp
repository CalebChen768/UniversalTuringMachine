#include "mylabel.h"

MyLabel::MyLabel(QMainWindow *parent)
{
    label=new QLabel(parent);
    QFont font ("Microsoft YaHei",20,75);
    label->setFont(font);
    label->setFixedSize(40,55);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(236, 170, 201);background-color: rgb(255, 20, 20);");
}

MyLabel::MyLabel(QMainWindow *parent,QString text)
{
    label=new QLabel(parent);
    label->setText(text);

}

MyLabel::~MyLabel()
{
    delete label;
}

void MyLabel::setGeometry(int ax,int ay,int aw,int ah)
{
    label->setGeometry(ax,ay,aw,ah);
}

void MyLabel::setText(QString text)
{
    label->setText(text);
}

void MyLabel::hide()
{
    label->hide();
}

void MyLabel::show()
{
    label->show();
}

void MyLabel::setPos(int x,int y)
{
    label->setGeometry(x,y,40,55);
}

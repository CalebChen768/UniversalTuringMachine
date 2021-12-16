#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QString>
#include <QMainWindow>
#include <QFont>
#include <QFrame>

class MyLabel
{
public:
    MyLabel(QMainWindow *parent);
    MyLabel(QMainWindow *parent,QString text);
    ~MyLabel();
    void setText(QString text);
    void setGeometry(int ax,int ay,int aw,int ah);
    void hide();
    void show();
    void setPos(int x,int y);
private:
    QLabel *label;


};

#endif // MYLABEL_H

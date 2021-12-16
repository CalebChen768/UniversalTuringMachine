#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QString>
#include <QMainWindow>
#include <QFont>
#include <QFrame>
#include <QSize>
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
    void setStyleSheet(QString sheet);
    void setFixedSize(int x,int y);
    QSize pos();
private:
    QLabel *label;
};

#endif // MYLABEL_H

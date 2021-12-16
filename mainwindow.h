#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QList>
#include "mylabel.h"
#include <QFont>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadFileList();
    void append(QStringList* list,QString in);
    void update(int move_q);
public slots:
    void nextStep();
    void importFile();
    void startSimulate();

private:
    Ui::MainWindow *ui;
    QLabel *label_k,*label_sigma,*label_gamma,*label_q0,*label_B,*label_F;
    QLineEdit *line_k,*line_sigma,*line_gamma,*line_q0,*line_B,*line_F;
    QLineEdit *line_str;
    QVBoxLayout *layout_label,*layout_line;
    QLabel *label_str;
    QHBoxLayout *layout_1;
    QGroupBox *group_1;
    QListWidget *list_file,*list_func;
    QPushButton *btn_import,*btn_confirm,*btn_step;
    QString str;
    MyLabel* label[25];
    MyLabel* label_now;
    QLabel* label_fun;
};
#endif // MAINWINDOW_H

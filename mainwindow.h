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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void nextStep();
    void importFile();
    void startSimulate();
private:
    Ui::MainWindow *ui;
    QLabel *label_k,*label_sigma,*label_gama,*label_q0,*label_B,*label_F;
    QLineEdit *line_k,*line_sigma,*line_gama,*line_q0,*line_B,*line_F;
    QLineEdit *line_str;
    QVBoxLayout *layout_label,*layout_line;
    QLabel *label_str;
    QHBoxLayout *layout_1;
    QGroupBox *group_1;
    QListWidget *list_file,*list_func;
    QPushButton *btn_import,*btn_confirm,*btn_step;

};
#endif // MAINWINDOW_H

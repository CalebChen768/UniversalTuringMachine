#include "mainwindow.h"
#include "ui_mainwindow.h"
#define START_X 40
#define START_Y 40
#define DELTA_Y 50
#define LABEL_X 50
#define LABEL_Y 40
#define LINE_X 200
#define LINE_Y 30

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 700);
    this->setWindowTitle("Universal Turing Machine");

    label_k = new QLabel(this);
    label_k->setGeometry(START_X, START_Y+DELTA_Y*0, LABEL_X, LABEL_Y);
    label_k->setText("K");

    label_sigma = new QLabel(this);
    label_sigma->setGeometry(START_X, START_Y+DELTA_Y*1, LABEL_X, LABEL_Y);
    label_sigma->setText("sigma");

    label_gama = new QLabel(this);
    label_gama->setGeometry(START_X, START_Y+DELTA_Y*2, LABEL_X, LABEL_Y);
    label_gama->setText("gama");

    label_q0 = new QLabel(this);
    label_q0->setGeometry(START_X, START_Y+DELTA_Y*3, LABEL_X, LABEL_Y);
    label_q0->setText("q0");

    label_B = new QLabel(this);
    label_B->setGeometry(START_X, START_Y+DELTA_Y*4, LABEL_X, LABEL_Y);
    label_B->setText("B");

    label_F = new QLabel(this);
    label_F->setGeometry(START_X, START_Y+DELTA_Y*5, LABEL_X, LABEL_Y);
    label_F->setText("F");

    line_k = new QLineEdit(this);
    line_k->setFixedSize(LINE_X,LINE_Y);
    line_sigma = new QLineEdit(this);
    line_sigma->setFixedSize(LINE_X,LINE_Y);
    line_gama = new QLineEdit(this);
    line_gama->setFixedSize(LINE_X,LINE_Y);
    line_q0 = new QLineEdit(this);
    line_q0->setFixedSize(LINE_X,LINE_Y);
    line_B = new QLineEdit(this);
    line_B->setFixedSize(LINE_X,LINE_Y);
    line_F = new QLineEdit(this);
    line_F->setFixedSize(LINE_X,LINE_Y);

    layout_label = new QVBoxLayout(this);
    layout_label->addWidget(label_k);
    layout_label->addWidget(label_sigma);
    layout_label->addWidget(label_gama);
    layout_label->addWidget(label_q0);
    layout_label->addWidget(label_B);
    layout_label->addWidget(label_F);

    layout_line = new QVBoxLayout(this);
    layout_line->addWidget(line_k);
    layout_line->addWidget(line_sigma);
    layout_line->addWidget(line_gama);
    layout_line->addWidget(line_q0);
    layout_line->addWidget(line_B);
    layout_line->addWidget(line_F);

    layout_1=new QHBoxLayout(this);
    layout_1->addLayout(layout_label);
    layout_1->addLayout(layout_line);

    group_1=new QGroupBox(this);
    group_1->setGeometry(40, 40, 300, 400);
    group_1->setLayout(layout_1);

    //配置文件引入窗
    list_file = new QListWidget(this);
    list_file->setGeometry(380, 40, 280, 220);

    btn_import = new QPushButton(this);
    btn_import->setGeometry(380, 280, 280, 40);
    btn_import->setText("导入文件");

    //状态转移函数框
    list_func = new QListWidget(this);
    list_func->setGeometry(700, 40, 280, 300);

    //输入纸带
    label_str = new QLabel(this);
    label_str->setGeometry(380, 365, 60, 30);
    label_str->setText("输入纸带:");

    line_str = new QLineEdit(this);
    line_str->setGeometry(440,360,420,40);

    btn_confirm = new QPushButton(this);
    btn_confirm->setGeometry(870, 360, 50, 40);
    btn_confirm->setText("确认");

    btn_step = new QPushButton(this);
    btn_step->setGeometry(930, 360, 50, 40);
    btn_step->setText("下一步");

    QObject::connect(btn_import, SIGNAL(clicked()), this, SLOT(importFile()));
    QObject::connect(btn_confirm, SIGNAL(clicked()), this, SLOT(startSimulate()));
    QObject::connect(btn_step, SIGNAL(clicked()), this, SLOT(nextStep()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::importFile()
{

}
void MainWindow::startSimulate()
{

}

void MainWindow::nextStep()
{


}

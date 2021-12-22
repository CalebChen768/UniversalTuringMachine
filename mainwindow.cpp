#include "mainwindow.h"
#include "ui_mainwindow.h"
#define START_X 40
#define START_Y 40
#define DELTA_Y 40
#define LABEL_X 20
#define LABEL_Y 30
#define LINE_X 200
#define LINE_Y 30
#define X 30
#define Y 500
#define SIZE 100
 
QString filepath="";
QStringList K;
QStringList Sigma;
QStringList Q0;
QStringList B;
QStringList F;

QString function[SIZE][5];

QString q;
int now;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 700);
    this->setWindowTitle("Universal Turing Machine");

    qDebug()<<filepath;

    label_k = new QLabel(this);
    label_k->setGeometry(START_X, START_Y+DELTA_Y*0, LABEL_X, LABEL_Y);
    label_k->setAlignment(Qt::AlignCenter);
    label_k->setText("\n   状态集合:");

    label_sigma = new QLabel(this);
    label_sigma->setGeometry(START_X, START_Y+DELTA_Y*1, LABEL_X, LABEL_Y);
    label_sigma->setAlignment(Qt::AlignCenter);
    label_sigma->setText("\n   带上符号:");

    label_q0 = new QLabel(this);
    label_q0->setGeometry(START_X, START_Y+DELTA_Y*3, LABEL_X, LABEL_Y);
    label_q0->setAlignment(Qt::AlignCenter);
    label_q0->setText("   开始状态:");

    label_B = new QLabel(this);
    label_B->setGeometry(START_X, START_Y+DELTA_Y*4, LABEL_X, LABEL_Y);
    label_B->setAlignment(Qt::AlignVCenter);
    label_B->setText("   空白符:\n");

    label_F = new QLabel(this);
    label_F->setGeometry(START_X, START_Y+DELTA_Y*5, LABEL_X, LABEL_Y);
    label_F->setAlignment(Qt::AlignVCenter);
    label_F->setText("   终止状态:\n");

    line_k = new QLineEdit(this);
    line_k->setFixedSize(LINE_X,LINE_Y);
    line_sigma = new QLineEdit(this);
    line_sigma->setFixedSize(LINE_X,LINE_Y);
    line_q0 = new QLineEdit(this);
    line_q0->setFixedSize(LINE_X,LINE_Y);
    line_B = new QLineEdit(this);
    line_B->setFixedSize(LINE_X,LINE_Y);
    line_F = new QLineEdit(this);
    line_F->setFixedSize(LINE_X,LINE_Y);

    layout_label = new QVBoxLayout(this);
    layout_label->addWidget(label_k);
    layout_label->addWidget(label_sigma);
    layout_label->addWidget(label_q0);
    layout_label->addWidget(label_B);
    layout_label->addWidget(label_F);

    layout_line = new QVBoxLayout(this);
    layout_line->addWidget(line_k);
    layout_line->addWidget(line_sigma);
    layout_line->addWidget(line_q0);
    layout_line->addWidget(line_B);
    layout_line->addWidget(line_F);

    layout_1=new QHBoxLayout(this);
    layout_1->addLayout(layout_label);
    layout_1->addLayout(layout_line);

    group_1=new QGroupBox(this);
    group_1->setGeometry(40, 50, 300, 390);
    group_1->setLayout(layout_1);

    //配置文件引入窗
    list_file = new QListWidget(this);
    list_file->setGeometry(380, 50, 220, 240);

    loadFileList();

    btn_import = new QPushButton(this);
    btn_import->setGeometry(380, 320, 220, 40);
    btn_import->setText("导入文件");

    //状态转移函数框
    list_func = new QListWidget(this);
    list_func->setGeometry(640, 50, 340, 300);
    list_func->setWrapping(true);

    //输入纸带
    label_str = new QLabel(this);
    label_str->setGeometry(380, 395, 60, 30);
    label_str->setText("输入纸带:");

    line_str = new QLineEdit(this);
    line_str->setGeometry(440,390,420,40);

    btn_confirm = new QPushButton(this);
    btn_confirm->setGeometry(870, 390, 50, 40);
    btn_confirm->setText("确认");

    btn_step = new QPushButton(this);
    btn_step->setGeometry(930, 390, 50, 40);
    btn_step->setText("下一步");

    //纸带
    for(int i=0;i<25;i++)
    {
        label[i]=new MyLabel(this);
        label[i]->setPos(X+40*i,Y);
        label[i]->hide();
    }

    label_now=new MyLabel(this);
    label_now->setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(236, 255, 251);background-color: rgb(20, 250, 20);");
    label_now->setFixedSize(40,35);
    label_now->hide();

    label_fun = new QLabel(this);
    label_fun->setGeometry(X+50,Y-40, 500,30);
    label_fun->setAlignment(Qt::AlignCenter);
    label_fun->setText("状态转移函数：");

    //connect
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
    qDebug()<<"import1";
    K.clear();
    Sigma.clear();
    Q0.clear();
    B.clear();
    F.clear();
    int row=list_file->currentRow();
    list_func->clear();
    QFile file(filepath  + QString::number(row) + ".txt");
      qDebug()<<"import3";
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString temp;
        int i=0;
        while(1)
        {
            temp=in.readLine();
            if(temp.size()==0)
                break;       
                        qDebug()<<"import1";
            QStringList list = temp.split(" ");
                        qDebug()<<"import2";
            list[0]="q"+list[0];
            if(list.size()>2)
                list[2]="q"+list[2];
            qDebug()<<"import3";
            if(list.contains("#"))
            {
                function[i][0]=list[0];
                function[i][1]=list[1];
            }
            else
                for(int j=0;j<5;j++)
                    function[i][j]=list[j];
qDebug()<<"import4";
            if(list.contains("#"))
                append(&F,list[0]);
            else
            {
                qDebug()<<"import6";
                list_func->addItem("       δ("+list[0]+","+list[1]+")=("+list[2]+","+list[3]+","+list[4]+")           ");
                append(&K,list[0]);
                append(&Sigma,list[1]);
                qDebug()<<"import7";
            }
              qDebug()<<"import5"<<i;
            i++;
        }
    }
    file.close();
    QString k,sigma,q0,b,f;
      qDebug()<<"import126";

    q0="q0";
    for(int i=0;i<K.size();i++)
         k+=(K[i]+" ");
    for(int i=0;i<Sigma.size();i++)
         sigma+=(Sigma[i]+" ");
    for(int i=0;i<F.size();i++)
         f+=(F[i]+" ");
    b="B";
    Q0.append("q0");

    line_k->setText(k);
    line_sigma->setText(sigma);
    line_q0->setText(q0);
    line_B->setText(b);
    line_F->setText(f);

    line_k->setEnabled(false);
    line_sigma->setEnabled(false);
    line_q0->setEnabled(false);
    line_B->setEnabled(false);
    line_F->setEnabled(false);

    qDebug()<<"import12";
}

void MainWindow::startSimulate()
{
    for(int i=0;i<25;i++)
        label[i]->hide();
    //qDebug()<<"1";
    if(line_str->text().length()==0)
        return;
    str="BBB"+line_str->text()+"BB";
    label[2]->setText("B");
    label[2]->show();
//    for(int i=3;i<str.length();i++)
//    {
//        label[i]->setText(str[i]);
//        label[i]->show();
//    }

    now = 3;
    label_now->setPos(X+40*3,Y+55);
    label_now->show();

    q=Q0[0];
    label_now->setText(q);

     update(0);
}

void MainWindow::nextStep()
{
    bool flag=false;
    QChar c = str[now];
    QString comp;
    qDebug()<<"next0";
    comp+=c;
    qDebug()<<"next1";
    for(int i=0;i<SIZE;i++)
    {
        qDebug()<<"next2";
        qDebug()<<q<<function[i][0];
        if(function[i][0]==q&&function[i][1]==comp)
        {
            flag=true;
              qDebug()<<"next3";
            q=function[i][2];
            str[now]=function[i][3][0];
             label_fun->setText("δ("+function[i][0]+","+function[i][1]+")=("+function[i][2]+","+function[i][3]+","+function[i][4]+")");
            qDebug()<<("δ("+function[i][0]+","+function[i][1]+")=("+function[i][2]+","+function[i][3]+","+function[i][4]+")");
            if(comp=="B" && now==str.length()-1)
            {
                str+="B";
            }

            if(function[i][4]=="R"){
                now++;
                update(1);
            }else if(function[i][4]=="L"){
                now--;
                update(-1);
            }else{
                update(0);
            }
            break;
        }

        if(function[i][0].length()==0)
            break;
    }
    if(flag==false)
        QMessageBox::warning(0 , "     失败！     ", "     失败！     ",QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape );

    if(F.contains(q))
    {
        QMessageBox::information(0 , "     成功！     ","      成功！     ", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape );
        //终止状态
    }
}

void MainWindow::loadFileList()
{
    QFile file(filepath+"filelist.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString temp;
        while(1)
        {
            temp=in.readLine();
            if(temp.size()==0)
                break;
            QStringList list = temp.split(" ");
            list_file->addItem(list[1]);
        }
    }
}

void MainWindow::append(QStringList* list,QString in)
{
    int flag=0;
    for(int i=0;i<list->size();i++)
    {
        if(list->contains(in))
            return;
    }
    if(flag==0)
        list->append(in);
}

void MainWindow::update(int move_q)
{

    label_now->setPos(label_now->pos().width()+move_q*40,label_now->pos().height());
    label_now->setText(q);
    qDebug()<<"update"<<move_q;
    for(int i=0;i<str.length();i++)
    {
        label[i]->setText(str[i]);
        label[i]->show();
         if(i<=2&&str[i]=='B'&&str[i+1]=='B')
             label[i]->hide();
         if(i==str.length()-2&&str[i]=='B')
         {
             label[i]->setText(str[i+1]);
             label[i]->show();
             break;
         }
    }

        qDebug()<<"ipdate2";
}

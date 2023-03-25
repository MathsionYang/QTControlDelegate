#include "widget.h"
#include "ui_widget.h"
#include "qtoolboxnew.h"
#include "test.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QToolBoxNew* tbox = new QToolBoxNew(this);
    Test* test = new Test(this);

    tbox->addWidget(QString(u8"Test1"),test);

    Test* test1 = new Test(this);

    tbox->addWidget(QString(u8"Test2"),test1);

    Test* test2 = new Test(this);

    tbox->addWidget(QString(u8"Test3"),test2);
}

Widget::~Widget()
{
    delete ui;
}


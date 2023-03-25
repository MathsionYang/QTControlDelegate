#include "qtoolboxnew.h"
#include "ui_qtoolboxnew.h"
#include "qtoolpage.h"
#include <QVBoxLayout>
QToolBoxNew::QToolBoxNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QToolBoxNew),m_pContentVBoxLayout(nullptr)
{
    ui->setupUi(this);

    QWidget *widget = new QWidget(this);
    m_pContentVBoxLayout = new QVBoxLayout;
    m_pContentVBoxLayout->setContentsMargins(0, 0, 0, 0);
    m_pContentVBoxLayout->setSpacing(2);

    QVBoxLayout *vBoxLayout = new QVBoxLayout(widget);
    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->addLayout(m_pContentVBoxLayout);
    vBoxLayout->addStretch(1);

    ui->scrollArea->setWidget(widget);
}

QToolBoxNew::~QToolBoxNew()
{
    delete ui;
}

void QToolBoxNew::addWidget(const QString &title, QWidget *widget)
{
    QToolPage *page = new QToolPage(this);
    page->addWidget(title, widget);
    m_pContentVBoxLayout->addWidget(page);
}

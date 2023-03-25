#include "qtoolpage.h"
#include "ui_qtoolpage.h"
#include <QFormLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QFile>
#include <QCoreApplication>
QToolPage::QToolPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QToolPage),
    m_bIsExpanded(true),
    m_pLabel(nullptr)
{
    ui->setupUi(this);

    ui->widgetContent->setAttribute(Qt::WA_StyledBackground);
    m_pLabel = new QLabel(this);
    m_pLabel->setFixedSize(20, 20);
    QString icon = QCoreApplication::applicationDirPath() + "/img/down.png";
    m_pLabel->setPixmap(QPixmap(icon).scaled(m_pLabel->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    QHBoxLayout *layout = new QHBoxLayout(ui->pushButtonFold);
    layout->setContentsMargins(0, 0, 5, 0);
    layout->addStretch(1);
    layout->addWidget(m_pLabel);
    connect(ui->pushButtonFold, &QPushButton::clicked, this, &QToolPage::onPushButtonFoldClicked);


}

QToolPage::~QToolPage()
{
    delete ui;
}

void QToolPage::addWidget(const QString &title, QWidget *widget)
{
    ui->pushButtonFold->setText(title);
    ui->verticalLayoutContent->addWidget(widget);
}

void QToolPage::expand()
{
    ui->widgetContent->show();
    m_bIsExpanded = true;
    QString icon = QCoreApplication::applicationDirPath() + "/img/down.png";
    m_pLabel->setPixmap(QPixmap(icon).scaled(m_pLabel->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

}

void QToolPage::collapse()
{

    ui->widgetContent->hide();
    m_bIsExpanded = false;
    QString icon = QCoreApplication::applicationDirPath() + "/img/right.png";
    m_pLabel->setPixmap(QPixmap(icon).scaled(m_pLabel->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}


void QToolPage::onPushButtonFoldClicked()
{
    if (m_bIsExpanded) {
        collapse();
    } else {
        expand();
    }
}

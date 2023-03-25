#ifndef QTOOLBOXNEW_H
#define QTOOLBOXNEW_H

#include <QWidget>
class QVBoxLayout;
namespace Ui {
class QToolBoxNew;
}

class QToolBoxNew : public QWidget
{
    Q_OBJECT

public:
    explicit QToolBoxNew(QWidget *parent = nullptr);
    ~QToolBoxNew();
     void addWidget(const QString &title, QWidget *widget);
private:
    Ui::QToolBoxNew *ui;
    QVBoxLayout *m_pContentVBoxLayout;
};

#endif // QTOOLBOXNEW_H

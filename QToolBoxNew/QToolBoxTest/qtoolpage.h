#ifndef QTOOLPAGE_H
#define QTOOLPAGE_H

#include <QWidget>

namespace Ui {
class QToolPage;
}
class QFormLayout;
class QLabel;
class QToolPage : public QWidget
{
    Q_OBJECT

public:
    explicit QToolPage(QWidget *parent = nullptr);
    ~QToolPage();

public slots:
    void addWidget(const QString &title, QWidget *widget);
    void expand();
    void collapse();
private slots:
    void onPushButtonFoldClicked();


private:
    Ui::QToolPage *ui;
    bool m_bIsExpanded;
    QLabel *m_pLabel;
};

#endif // QTOOLPAGE_H

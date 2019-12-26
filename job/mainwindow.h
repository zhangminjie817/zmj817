#ifndef GUIONE_H
#define GUIONE_H

#include <QObject>
#include <DMainWindow>
#include <DLabel>
#include <QFont>
#include <QToolButton>
#include <QVBoxLayout>
#include <QFrame>
#include <DToolButton>
#include <QStackedWidget>
#include <QTimer>

#include "page.h"
#include "pageother.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void Uishow();
    ~MainWindow();
private:
    QWidget *Widget;

    QImage *Img;
    DLabel *Img_Lab;
    DLabel *Txt_Lab;
    QToolButton *Help_Bt;
    QToolButton *Helps_Bt;
    QVBoxLayout *VB_layout;

signals:

public slots:

private:
    QStackedWidget *m_pStackedWidget;
    page *m_pPage;
    pageother *m_pPageOther;
};

#endif // GUIONE_H

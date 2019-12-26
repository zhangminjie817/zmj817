#ifndef PAGE_H
#define PAGE_H

#include <DMainWindow>
#include <QObject>
#include <DLabel>
#include <QFont>
#include <QToolButton>
#include <QFrame>
#include <DWidget>
#include <DSpinner>
#include <DTitlebar>
#include <DSuggestButton>
#include <QTimer>
#include <QDebug>
#include <QClipboard>
#include <QRandomGenerator>
#include <QApplication>
#include <QVBoxLayout>
#include <QtDebug>
#include <QStackedWidget>
#include <QClipboard>

DWIDGET_USE_NAMESPACE

class page : public DWidget
{
    Q_OBJECT
public:
    explicit page(QWidget *parent = nullptr);
    void Inui();
    QString getRandomNumber();
    QTimer *m_pTimer;
    ~page();
private:
    QWidget *Widget;
    QVBoxLayout *VB_layout;
    DSuggestButton *m_suggestButton;
//1
    DSpinner *Img;
    DLabel *Img_Lab;
    DLabel *Lod_Lab;
//2
    QWidget *Widget_one;
    QVBoxLayout *VB_layout_one;
    DLabel *Password_Lab;
    DLabel *Txt_Lab;

//3
    QWidget *Widget_two;
    QVBoxLayout *VB_layout_two;
    DLabel *Success_Lab;
    DLabel *Wait_Lab;

    QStackedWidget *m_pStackedWidget;
    QVBoxLayout *m_mainVLayout;

    QClipboard *Tailoring;

public slots:
    void change_one();
    void change_two();

signals:
    void backMainwindow();
};

#endif // PAGE_H

#ifndef PAGEOTHER_H
#define PAGEOTHER_H

#include <DWidget>
#include <DLabel>
#include <QLineEdit>
#include <DSuggestButton>
#include <QGridLayout>
#include <QString>
#include <QTimer>
#include <QApplication>
#include <QClipboard>
#include <QString>
#include <DSpinner>
#include <QVBoxLayout>
#include <QStackedWidget>

DWIDGET_USE_NAMESPACE

class pageother : public DWidget
{
    Q_OBJECT

public:
    explicit pageother(QWidget *parent = nullptr);
    void Inui();
    ~pageother();
//    QTimer *Five_Time;
private:
    DSuggestButton *Page_bt;
//sacnf
    QWidget *Scan_Widget;
    QVBoxLayout *VB_layout;
    QLineEdit *Scan_Ed;
    DLabel *Txt_Lab;

//Compar
    QVBoxLayout *VB_layout_1;
    QWidget *Compar_Widget;
    QClipboard *Tailoring;
    DSpinner *Img;
    DLabel *Img_Lab;
    DLabel *Wait_Lab;
    QString Str_password;
    QString Str_scan;
//success
    QVBoxLayout *VB_layout_2;
    QWidget *Success_Widget;
    DLabel *Lod_Lab;
    DLabel *Existence_Lab;
//fail
    QVBoxLayout *VB_layout_3;
    QWidget *Fail_Widget;
    DLabel *Fial_Lab;
    DLabel *Instable_Lab;

    QStackedWidget *Stacked_Page;
    QVBoxLayout *MainVb_layout;

signals:
    void RtMainwindow();

public slots:
    void change_one();
    void Success();
    void Fail();
private:
    QTimer *m_pTimer;
};

#endif // PAGEOTHER_H

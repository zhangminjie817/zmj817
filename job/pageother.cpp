#include "pageother.h"
#include <QDebug>

pageother::pageother(QWidget *parent) : DWidget(parent)
{
    Inui();
    change_one();
    Success();
    Fail();

    Stacked_Page = new QStackedWidget;
    MainVb_layout = new QVBoxLayout;
    Page_bt = new DSuggestButton(this);
    Page_bt->setText("cancel");

    Stacked_Page->addWidget(Scan_Widget);
    Stacked_Page->addWidget(Compar_Widget);
    Stacked_Page->addWidget(Success_Widget);
    Stacked_Page->addWidget(Fail_Widget);

    Stacked_Page->setCurrentWidget(Scan_Widget);
    MainVb_layout->addWidget(Stacked_Page);
    MainVb_layout->addWidget(Page_bt,0,Qt::AlignHCenter);
    setLayout(MainVb_layout);

    m_pTimer = new QTimer;
    connect(m_pTimer, &QTimer::timeout, this,
            [=]()
    {
        Str_password = Scan_Ed->text();
        Tailoring = QApplication::clipboard();
        Str_scan = Tailoring->text();
        if(m_pTimer->isActive())
            m_pTimer->stop();
           //compare
           if(Str_password == Str_scan)
           {
               Page_bt->setText(" back ");
               Stacked_Page->setCurrentWidget(Success_Widget);
           }
           else
           {
               Page_bt->setText(" again ");
               Stacked_Page->setCurrentWidget(Fail_Widget);
           }
    });
    connect(Page_bt, &DSuggestButton::clicked, this,
            [=]()
    {
        if(m_pTimer->isActive())
            m_pTimer->stop();
        Scan_Ed->setText("");
        Stacked_Page->setCurrentWidget(Scan_Widget);
        if((Page_bt->text().compare(" back ") == 0) ||(Page_bt->text().compare("cancel") == 0) )
        {
            Page_bt->setText("cancel");
//            Stacked_Page->setCurrentWidget(Scan_Widget);
            emit RtMainwindow();
        }

        if(Page_bt->text().compare("connect") == 0)
        {
            Page_bt->setText("cancel");
            Stacked_Page->setCurrentWidget(Compar_Widget);
            m_pTimer->start(5000);
        }
        if(Page_bt->text().compare(" again ") == 0)
        {
            Page_bt->setText("cancel");
            Stacked_Page->setCurrentWidget(Scan_Widget);
        }
    });

}

void pageother::Inui()
{
    Scan_Widget = new QWidget;

    VB_layout = new QVBoxLayout(this);

    Scan_Ed = new QLineEdit(this);
    class QValidator *validator=new QIntValidator(0,999999,this);
    Scan_Ed->setValidator(validator);
    QFont font;
    font.setPointSize(10);
    font.setLetterSpacing(QFont::AbsoluteSpacing,18);
    font.setPointSize(35);
    Scan_Ed->setFont(font);
    Scan_Ed->setAlignment(Qt::AlignHCenter);

    connect(Scan_Ed,&QLineEdit::textChanged,this,[=](){
            if(Scan_Ed->text().count() == 6)
                Page_bt->setText(tr("connect"));
        });

    Txt_Lab = new DLabel(this);
    Txt_Lab = new DLabel(tr("请在上方输入你想帮助的人提供给你的验证码,\n完成后点击连接开始协助对方\n"));
    QFont font_two;//字号
    font_two.setPointSize(9);
    Txt_Lab->setFont(font_two);
    Txt_Lab->setAlignment(Qt::AlignHCenter);

    VB_layout->addWidget(Scan_Ed,0,Qt::AlignCenter);
    VB_layout->addWidget(Txt_Lab,0,Qt::AlignCenter);
    Scan_Widget->setLayout(VB_layout);
}

void pageother::change_one()
{
    Compar_Widget = new QWidget;
    VB_layout_1 = new QVBoxLayout(this);
    Wait_Lab = new DLabel;

    Img = new DSpinner;
    Img_Lab = new DLabel;
    Img->start();
    Img->setFixedSize(65,65);

    QFont font;
    font.setPointSize(12);
    Wait_Lab->setFont(font);
    Wait_Lab->setText(tr("正在建立连接，请稍候..."));

    VB_layout_1->addWidget(Img,0,Qt::AlignCenter);
    VB_layout_1->addWidget(Wait_Lab,0,Qt::AlignCenter);

//    Str_password = Scan_Ed->text();
//    Tailoring = QApplication::clipboard();
//    Str_scan = Tailoring->text();
    Compar_Widget->setLayout(VB_layout_1);
}

void pageother::Success()
{
    Success_Widget = new QWidget;
    VB_layout_2 = new QVBoxLayout(this);

    Lod_Lab = new DLabel(this);
    QFont font;
    font.setPointSize(12);
    Lod_Lab->setFont(font);
    Lod_Lab->setText(tr("您正在进行远程操作"));
//    Lod_Lab ->setStyleSheet("color:red;");
    Lod_Lab->setAlignment(Qt::AlignHCenter);

    Existence_Lab = new DLabel(this);
    QFont font_two;
    font_two.setPointSize(8);
    Existence_Lab->setFont(font_two);
    Existence_Lab->setText(tr("当前已经有一个连接对话，如果您想建立新的连接，请先断开"));
    Existence_Lab->setAlignment(Qt::AlignHCenter);

    VB_layout_2->addWidget(Lod_Lab,0,Qt::AlignCenter);
    VB_layout_2->addWidget(Existence_Lab,0,Qt::AlignCenter);
    Success_Widget->setLayout(VB_layout_2);
}

void pageother::Fail()
{
    Fail_Widget = new QWidget;
    VB_layout_3 = new QVBoxLayout(this);

    Fial_Lab = new DLabel(this);
    QFont font;
    font.setPointSize(18);
    Fial_Lab->setFont(font);
    Fial_Lab->setText(tr("连接失败"));
    Fial_Lab ->setStyleSheet("color:red;");
    Fial_Lab->setAlignment(Qt::AlignHCenter);

    Instable_Lab = new DLabel(this);
    QFont font_two;
    font_two.setPointSize(10);
    Instable_Lab->setFont(font_two);
    Instable_Lab->setText(tr("网络连接状态不是很稳定，点击重试按钮再次尝试连接"));
    Instable_Lab->setAlignment(Qt::AlignHCenter);

    VB_layout_3->addWidget(Fial_Lab,0,Qt::AlignCenter);
    VB_layout_3->addWidget(Instable_Lab,0,Qt::AlignCenter);
    Fail_Widget->setLayout(VB_layout_3);
}

pageother::~pageother()
{

}


#include "mainwindow.h"

#define TIME (2*1000)

MainWindow::MainWindow(QWidget *parent) : DMainWindow(parent)
{
    Uishow();
    connect(Help_Bt,&DToolButton::clicked,
                [=](){
            m_pPage->m_pTimer->start(TIME);
            m_pStackedWidget->setCurrentWidget(m_pPage);}
    );
    connect(Helps_Bt,&DToolButton::clicked,
                [=](){
            m_pStackedWidget->setCurrentWidget(m_pPageOther);}
    );

    connect(m_pPage,&page::backMainwindow,this,
                [=](){
            m_pStackedWidget->setCurrentWidget(Widget);}
    );

    connect(m_pPageOther,&pageother::RtMainwindow,this,
                [=](){
            m_pStackedWidget->setCurrentWidget(Widget);}
    );

}

void MainWindow::Uishow()//主页面
{
    Widget = new QWidget;
    VB_layout = new QVBoxLayout(this);
    Img_Lab = new DLabel;
    Img = new QImage;
    Img->load("://images/help.jpeg");
    Img_Lab->setPixmap(QPixmap::fromImage(*Img));
    Img_Lab->setScaledContents(true);
    Img_Lab->setFixedSize(100,100);

    Txt_Lab = new DLabel;
    QString Str = ("这是由deepin团队开发的远程协助应用，"
                  "如果您在\n使用的过程中遇到困难，或者有人求助于你，"
                  "请点\n\t击下方的我要求助或帮助别人。");//随后根据需求更改英文语句定稿
    Txt_Lab->setText(Str);
    QFont font;//字号
    font.setPointSize(9);
    Txt_Lab->setFont(font);
    Txt_Lab->setAlignment(Qt::AlignHCenter);

    Help_Bt = new DToolButton(this);
    Help_Bt->setFixedSize(100,45);
    Help_Bt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    Help_Bt->setText(tr("我要求助"));
    Help_Bt->setIcon(QPixmap("://images/shou.jpeg"));

    Helps_Bt = new DToolButton(this);
    Helps_Bt->setFixedSize(100,45);
    Helps_Bt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    Helps_Bt->setText(tr("帮助别人"));
    Helps_Bt->setIcon(QPixmap("://images/xin.jpg"));

    VB_layout->addWidget(Img_Lab,0,Qt::AlignCenter);
    VB_layout->addWidget(Txt_Lab,0,Qt::AlignCenter);
    VB_layout->addWidget(Help_Bt,0,Qt::AlignCenter);
    VB_layout->addWidget(Helps_Bt,0,Qt::AlignCenter);

    Widget->setLayout(VB_layout);

    m_pPage = new page;
    m_pPageOther = new pageother;
    m_pStackedWidget = new QStackedWidget;

    m_pStackedWidget->addWidget(Widget);
    m_pStackedWidget->addWidget(m_pPage);
    m_pStackedWidget->addWidget(m_pPageOther);

    m_pStackedWidget->setCurrentWidget(Widget);
    setCentralWidget(m_pStackedWidget);
}

MainWindow::~MainWindow()
{

}

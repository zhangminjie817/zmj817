#include "page.h"

page::page(QWidget *parent) : DWidget(parent)
{
    Inui();
    change_one();
    change_two();

    Tailoring = QApplication::clipboard();

    m_pStackedWidget = new QStackedWidget(this);
    m_mainVLayout = new QVBoxLayout;
    m_suggestButton = new DSuggestButton(this);
    m_suggestButton->setText("cancel");

    m_pStackedWidget->addWidget(Widget);
    m_pStackedWidget->addWidget(Widget_one);
    m_pStackedWidget->addWidget(Widget_two);
    m_pStackedWidget->setCurrentWidget(Widget);
    m_mainVLayout->addWidget(m_pStackedWidget);
    m_mainVLayout->addWidget(m_suggestButton, 0, Qt::AlignCenter);
    setLayout(m_mainVLayout);

    m_pTimer = new QTimer;

    connect(m_pTimer, &QTimer::timeout, this,
            [=]()
    {
        QString str = getRandomNumber();
        Password_Lab->setText(str);
        Tailoring->setText(str);
        m_suggestButton->setText("copy");
        if(m_pTimer->isActive())
            m_pTimer->stop();
        m_pStackedWidget->setCurrentWidget(Widget_one);
    });

    connect(m_suggestButton, &DSuggestButton::pressed, this,
            [=]()
    {
        if(m_pTimer->isActive())
            m_pTimer->stop();
        if((m_suggestButton->text().compare("back") == 0) ||(m_suggestButton->text().compare("cancel") == 0) )
        {
            m_suggestButton->setText("cancel");
            m_pStackedWidget->setCurrentWidget(Widget);
            emit backMainwindow();
        }

        if(m_suggestButton->text().compare("copy") == 0)
        {
            m_suggestButton->setText("back");
             m_pStackedWidget->setCurrentWidget(Widget_two);
        }
    });
}

void page::Inui()//
{
    Widget = new QWidget;
    VB_layout = new QVBoxLayout(this);

    Img = new DSpinner(this);
    Img_Lab = new DLabel(this);
    Img->start();
    Img->setFixedSize(65,65);

    Lod_Lab = new DLabel(this);
    Lod_Lab->setText(tr("正在生成请求验证码，请稍后...\n"));
    Lod_Lab->setAlignment(Qt::AlignHCenter);

    VB_layout->addWidget(Img,0,Qt::AlignCenter);
    VB_layout->addWidget(Lod_Lab,0,Qt::AlignCenter);
    Widget->setLayout(VB_layout);
}

void page::change_one()
{
    Widget_one = new QWidget;
    VB_layout_one = new QVBoxLayout(this);
    Password_Lab = new DLabel(this);

    QFont font;//字号
    font.setPointSize(25);
    Password_Lab->setFont(font);
    Password_Lab->setAlignment(Qt::AlignHCenter);

    Txt_Lab = new DLabel(this);
    Txt_Lab->setText(tr("要开始共享您的桌面，请将上面的验证码提供给协助您的人员,\n他们输入验证码后，您的共享会话会立即开始\n"));
    QFont font_two;//字号
    font_two.setPointSize(8);
    Txt_Lab->setFont(font_two);
    Txt_Lab->setAlignment(Qt::AlignHCenter);

    VB_layout_one->addWidget(Password_Lab,0,Qt::AlignCenter);
    VB_layout_one->addWidget(Txt_Lab,0,Qt::AlignCenter);
    Widget_one->setLayout(VB_layout_one);
}

void page::change_two()
{
    Widget_two = new QWidget;
    VB_layout_two = new QVBoxLayout(this);
    Success_Lab = new DLabel(this);
    Success_Lab->setText(tr("成功复制到剪切板"));
    QFont font;//字号
    font.setPointSize(18);
    Success_Lab->setFont(font);
    Success_Lab->setAlignment(Qt::AlignHCenter);

    Wait_Lab = new DLabel(this);
    Wait_Lab->setText(tr("正在等待连接，请稍后....\n连接成功后，此界面会自动隐藏到任务栏"));
    QFont font_two;//字号
    font_two.setPointSize(10);
    Wait_Lab->setFont(font_two);
    Wait_Lab->setAlignment(Qt::AlignHCenter);

    VB_layout_two->addWidget(Success_Lab,0,Qt::AlignCenter);
    VB_layout_two->addWidget(Wait_Lab,0,Qt::AlignCenter);

    Widget_two->setLayout(VB_layout_two);

}

QString page::getRandomNumber()
{
    return QString::number(QRandomGenerator::global()->bounded(900000)+100000);
}
page::~page()
{

}




















#include "View/QFunctionWidget.h"
#include <QPainter>



/**************************SUBPAGE****************************/

QBaseFun::QBaseFun(QWidget* parent):QWidget(parent)
{
   m_con = new QVBoxLayout();
   m_con->setSpacing(0);
   m_tab = new QTabWidget();
   m_con->addWidget(m_tab);
   m_tab->setStyleSheet("QTabWidget::pane{border: 1px solid rgb(136,179,213);}");
   m_tab->setStyleSheet("QTabWidget::tab-bar{border:none;}");
   this->setLayout(m_con);
//
  // AddPage(new QWidget(),"1");
}

QBaseFun::~QBaseFun()
{

}

void QBaseFun::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}
void QBaseFun::AddPage(QWidget *widget,const QString& title)
{
    m_tab->addTab(widget,title);
}

//######################################################

ShowSplitWidget::ShowSplitWidget(QWidget* parent):QWidget(parent)
{


}

ShowSplitWidget::~ShowSplitWidget()
{

}

void ShowSplitWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}


EffectSwitch::EffectSwitch(QWidget* parent):QWidget(parent)
{
    m_con = new QGridLayout();
    m_group = new QButtonGroup();
    m_effect.resize(13);
    for(int i=0;i<m_effect.size();i++)
    {
        m_effect[i] = new QPushButton();
        m_effect[i]->setCheckable(true);
        m_group->addButton(m_effect[i],i);
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            m_con->addWidget(m_effect[i*4+j],i,j);
        }
    }

    this->setLayout(m_con);

}

EffectSwitch::~EffectSwitch()
{
   for(int i=0;i<m_effect.size();i++)
   {
       delete m_effect[i];
   }
   delete m_group;
   m_effect.clear();
   delete m_con;
   m_con = NULL;
}

void EffectSwitch::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));

}



QEffectFun::QEffectFun(QBaseFun* parent):QBaseFun(parent)
{
   splitWidget = new ShowSplitWidget();
   effectWidget = new EffectSwitch();
   AddPage(splitWidget,tr("Split"));
   AddPage(effectWidget,tr("Effect"));

}

QEffectFun::~QEffectFun()
{
    delete splitWidget;
    delete effectWidget;
}

//######################################################

SubTitleWidget::SubTitleWidget(QWidget* parent):QWidget(parent)
{

}

SubTitleWidget::~SubTitleWidget()
{

}

void SubTitleWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}

VoiceWidget::VoiceWidget(QWidget* parent):QWidget(parent)
{

}

VoiceWidget::~VoiceWidget()
{

}

void VoiceWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}

QVideoFun::QVideoFun(QBaseFun* parent):QBaseFun(parent)
{
    m_subtitle = new SubTitleWidget();
    m_voice = new VoiceWidget();
    AddPage(m_subtitle,tr("Subtitle"));
    AddPage(m_voice,tr("Voice"));
}

QVideoFun::~QVideoFun()
{
    delete m_subtitle;
    delete m_voice;
}

//#####################################################

IndexWidget::IndexWidget(QWidget* parent):QWidget(parent)
{

}
IndexWidget::~IndexWidget()
{

}

void IndexWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}

OSDWidget::OSDWidget(QWidget* parent):QWidget(parent)
{

}
OSDWidget::~OSDWidget()
{

}

void OSDWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}


TimerWidget::TimerWidget(QWidget* parent):QWidget(parent)
{

}
TimerWidget::~TimerWidget()
{

}

void TimerWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}

AttachOSDWidget::AttachOSDWidget(QWidget* parent):QWidget(parent)
{

}
AttachOSDWidget::~AttachOSDWidget()
{

}
void AttachOSDWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}
QLuboFun::QLuboFun(QBaseFun* parent):QBaseFun(parent)
{
    indexWidget = new IndexWidget();
    osdWidget = new OSDWidget();
    timerWidget = new TimerWidget();
    attachWidget = new AttachOSDWidget();
    AddPage(indexWidget,tr("index"));
    AddPage(osdWidget,tr("OSD"));
    AddPage(timerWidget,tr("time"));
    AddPage(attachWidget,tr("attach"));
}
QLuboFun::~QLuboFun()
{
    delete indexWidget;
    delete osdWidget;
    delete timerWidget;
    delete attachWidget;
}

void QLuboFun::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}

//#####################################################

StateWidget::StateWidget(QWidget* parent):QWidget(parent)
{
    m_con = new QGridLayout();
    m_state.resize(8);
    for(int i=0;i<m_state.size();i++)
    {
        m_state[i] = new QPushButton();
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
          m_con->addWidget(m_state[i*2+j],i,j);
        }
    }
}
StateWidget::~StateWidget()
{

}

void StateWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}

QStateFun::QStateFun(QBaseFun* parent):QBaseFun(parent)
{
   m_state = new StateWidget();
   AddPage(m_state,tr("State"));
}

QStateFun::~QStateFun()
{

}

/**********************************************************/





QFunctionWidget::QFunctionWidget(QWidget *parent) :
    QWidget(parent)
{
    m_con = new QHBoxLayout();
    m_effectFunWidget = new QEffectFun();
    m_videoFunWidget = new QVideoFun();
    m_luboFunWidget = new QLuboFun();
    m_stateFunWidget = new QStateFun();

    m_con->addWidget(m_effectFunWidget);
    m_con->addWidget(m_videoFunWidget);
    m_con->addWidget(m_luboFunWidget);
    m_con->addWidget(m_stateFunWidget);
    m_con->setSpacing(0);
    m_con->setMargin(0);
    this->setLayout(m_con);
}

void QFunctionWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}

#include "TipDialog.h"

TipDialog::TipDialog(QDialog *parent) :
    QDialog(parent),code(0),canMove(false)
{
    m_btnOK = new QPushButton(tr("Ok"));
    m_btnCannel= new QPushButton(tr("Cannel"));
    m_btnExit= new QPushButton(tr("Exit"));

    m_con = new QVBoxLayout();
    m_btnLay = new QHBoxLayout();

    m_title = new QLabel("title");
    m_title->setAlignment(Qt::AlignCenter);
    m_txt = new QLabel("subject");
    m_txt->setAlignment(Qt::AlignLeft);
    m_txt->setWordWrap(true);
    m_btnLay->addWidget(m_btnOK);
    m_btnLay->addWidget(m_btnCannel);
    m_btnLay->addWidget(m_btnExit);

    m_con->addWidget(m_title,1,Qt::AlignCenter);
    m_con->addWidget(m_txt,10,Qt::AlignCenter);
    m_con->addLayout(m_btnLay,1);
    m_con->setMargin(5);
    this->setLayout(m_con);
    this->resize(230,160);
    this->setWindowFlags(Qt::FramelessWindowHint);

    //205,102,29
    m_txt->setStyleSheet("QLabel{color:white;}");
    m_title->setStyleSheet("QLabel{color:rgb(205,102,29);}");
    m_btnOK->setStyleSheet("QPushButton{border-radius:3px;background:rgb(50,205,50);}");
    m_btnOK->setFixedHeight(25);
    m_btnOK->setObjectName("Tip_OK");
    m_btnCannel->setStyleSheet("QPushButton{border-radius:3px;background:rgb(218,165,32);}");
    m_btnCannel->setFixedHeight(25);
    m_btnExit->setStyleSheet("QPushButton{border-radius:3px;background:rgb(227,89,42);}");
    m_btnExit->setFixedHeight(25);

    //
    connect(m_btnOK,SIGNAL(clicked()),this,SLOT(clickedOK()));
    connect(m_btnCannel,SIGNAL(clicked()),this,SLOT(clickedCannel()));
    connect(m_btnExit,SIGNAL(clicked()),this,SLOT(clickedExit()));
}

TipDialog::TipDialog(int btnStyle,QDialog *parent) :
    TipDialog(parent)
{
    setBtnEnabled(btnStyle);
}

TipDialog::~TipDialog()
{
    delete m_btnOK;
    delete m_btnCannel;
    delete m_btnExit;
    delete m_btnLay;
    delete m_title;
    delete m_txt;
    delete m_con;
}
void TipDialog::setBtnEnabled(int btnStyle)
{
    if(btnStyle<0)
    {
        btnStyle*=-1;
    }
    m_btnOK->setVisible(!!(btnStyle&OK));
    m_btnCannel->setVisible(!!(btnStyle&Cannel));
    m_btnExit->setVisible(!!(btnStyle&Exit));

}

void TipDialog::setTipTitle(const QString &title)
{
    m_title->setText(title);
}

void TipDialog::setTipInfoText(const QString &txt)
{
    QString str=txt;
//    for(int i=0;i<str.size();i++)
//    {
//        if(i%100==0&&i!=0)
//        {
//          str.insert(i,'\n');
//        }
//    }
    m_txt->setText(str);
}

void TipDialog::loadMovie(const QString &fileName)
{

}
int TipDialog::showDialog()
{
   this->exec();
    return getCode();
}

int TipDialog::getCode()
{
    return code;
}


void TipDialog::clickedOK()
{
    code = OK;
    this->close();
}

void TipDialog::clickedCannel()
{
    code =Cannel;
    this->close();
}

void TipDialog::clickedExit()
{
    code =Exit;
    this->close();
}

void TipDialog::paintEvent(QPaintEvent *e)
{
   QPainter p(this);
   p.fillRect(rect(),QColor(48,48,48));
   QRect r=rect();
   r.setHeight(25);
   p.fillRect(r,QColor(64,64,64));
   QPainterPath path;
   path.addRoundRect(rect(),8,6);
   QPolygon polygon= path.toFillPolygon().toPolygon();
   QRegion region(polygon);
   setMask(region);
}


void TipDialog::mousePressEvent(QMouseEvent *e)
{
    if(e->buttons()==Qt::LeftButton && e->pos().y()<25)
    {
        canMove =true;
        oldPoint = e->globalPos()-pos();
    }
}

void TipDialog::mouseReleaseEvent(QMouseEvent *e)
{
    canMove = false;
}

void TipDialog::mouseMoveEvent(QMouseEvent *e)
{
    if(canMove)
    {
        move(e->globalPos()-oldPoint);
        oldPoint = e->globalPos()-pos();
    }
}

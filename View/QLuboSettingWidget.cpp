#include "QLuboSettingWidget.h"

#include <QMessageBox>

OneKeySetting::OneKeySetting(QWidget* parent):QWidget(parent)
{
  m_movieMode = new QCheckBox(tr("Movie Mode"));
  m_movieMode2 = new QCheckBox(tr("Movie Mode2"));
  m_stream = new QCheckBox(tr("P-Stream"));
  m_stream2 = new QCheckBox(tr("P-Stream"));
  m_director = new QCheckBox(tr("Director"));
  m_resRecord = new QCheckBox(tr("Res-Record"));

  m_group = new QGroupBox(tr("One-Key Mode"));
  m_lay = new QGridLayout();
  m_con = new QHBoxLayout();

  //layout
  m_lay->addWidget(m_movieMode,0,0);
  m_lay->addWidget(m_stream,0,1);
  m_lay->addWidget(m_director,0,2);

  m_lay->addWidget(m_movieMode2,1,0);
  m_lay->addWidget(m_stream2,1,1);
  m_lay->addWidget(m_resRecord,1,2);
  m_group->setLayout(m_lay);
  m_con->addWidget(m_group);
  this->setLayout(m_con);

  //event

  connect(m_movieMode,SIGNAL(stateChanged(int)),this,SLOT(selectdMode1(int)));
  connect(m_movieMode2,SIGNAL(stateChanged(int)),this,SLOT(selectedMode2(int)));
  connect(m_stream,SIGNAL(stateChanged(int)),this,SLOT(selectedStream1(int)));
  connect(m_stream2,SIGNAL(stateChanged(int)),this,SLOT(selectedStream2(int)));
  connect(m_director,SIGNAL(stateChanged(int)),this,SLOT(selecteddirector(int)));
  connect(m_resRecord,SIGNAL(stateChanged(int)),this,SLOT(selectedResRecord(int)));
}

OneKeySetting::~OneKeySetting()
{
    delete m_movieMode;
    delete m_movieMode2;
    delete m_stream;
    delete m_stream2;
    delete m_director;
    delete m_resRecord;
    delete m_lay;
    delete m_group;
    delete m_con;
}

void OneKeySetting::selectdMode1(int state)
{
    switch(state)
    {
    case Qt::Unchecked:
        QMessageBox::warning(0,"","Unchecked",0,0);
        break;
    case Qt::Checked:
        QMessageBox::warning(0,"","checked",0,0);
        break;
    }
}

void OneKeySetting::selectedMode2(int state)
{
    switch(state)
    {
    case Qt::Unchecked:
        QMessageBox::warning(0,"","Unchecked",0,0);
        break;
    case Qt::Checked:
        QMessageBox::warning(0,"","checked",0,0);
        break;
    }
}

void OneKeySetting::selectedStream1(int state)
{
    switch(state)
    {
    case Qt::Unchecked:
        QMessageBox::warning(0,"","Unchecked",0,0);
        break;
    case Qt::Checked:
        QMessageBox::warning(0,"","checked",0,0);
        break;
    }
}
void OneKeySetting::selectedStream2(int state)
{
    switch(state)
    {
    case Qt::Unchecked:
        QMessageBox::warning(0,"","Unchecked",0,0);
        break;
    case Qt::Checked:
        QMessageBox::warning(0,"","checked",0,0);
        break;
    }
}

void OneKeySetting::selecteddirector(int state)
{
    switch(state)
    {
    case Qt::Unchecked:
        QMessageBox::warning(0,"","Unchecked",0,0);
        break;
    case Qt::Checked:
        QMessageBox::warning(0,"","checked",0,0);
        break;
    }
}
void OneKeySetting::selectedResRecord(int state)
{
    switch(state)
    {
    case Qt::Unchecked:
        QMessageBox::warning(0,"","Unchecked",0,0);
        break;
    case Qt::Checked:
        QMessageBox::warning(0,"","checked",0,0);
        break;
    }
}




/*****************************************************************************/
CodingSetting::CodingSetting(QWidget* parent):QWidget(parent)
{
    m_mainResolution1 = new QComboBox();
    m_mainResolution2 = new QComboBox();
    m_subResolution1 = new QComboBox();
    m_subResolution2 = new QComboBox();

    m_mainCoding1 = new QComboBox();
    m_mainCoding2 = new QComboBox();
    m_subCoding1 = new QComboBox();
    m_subCoding2 = new QComboBox();

    m_mainFrameRate1 = new QSpinBox();
    m_mainFrameRate2 = new QSpinBox();
    m_subFrameRate1 = new QSpinBox();
    m_subFrameRate2 = new QSpinBox();

    m_mainCodeRate1 = new QSpinBox();
    m_mainCodeRate1->setSuffix("kbps");
    m_mainCodeRate2 = new QSpinBox();
    m_mainCodeRate2->setSuffix("kbps");
    m_subCodeRate1 = new QSpinBox();
    m_subCodeRate1->setSuffix("kbps");
    m_subCodeRate2 = new QSpinBox();
    m_subCodeRate2->setSuffix("kbps");

    m_mainFrameSpacing1 = new QSpinBox();
    m_mainFrameSpacing2 = new QSpinBox();

    m_form1 = new QFormLayout();
    m_form1->addRow(tr("Resolution"),m_mainResolution1);
    m_form1->addRow(tr("Coding"),m_mainCoding1);
    m_form1->addRow(tr("Frame Rate"),m_mainFrameRate1);
    m_form1->addRow(tr("Code Rate"),m_mainCodeRate1);
    m_form1->addRow(tr("I-Frame Spacing"),m_mainFrameSpacing1);

    m_form2 = new QFormLayout();
    m_form2->addRow(tr("Resolution"),m_mainResolution2);
    m_form2->addRow(tr("Coding"),m_mainCoding2);
    m_form2->addRow(tr("Frame Rate"),m_mainFrameRate2);
    m_form2->addRow(tr("Code Rate"),m_mainCodeRate2);
    m_form2->addRow(tr("I-Frame Spacing"),m_mainFrameSpacing2);

    m_form3 = new QFormLayout();
    m_form3->addRow(tr("Resolution"),m_subResolution1);
    m_form3->addRow(tr("Coding"),m_subCoding1);
    m_form3->addRow(tr("Frame Rate"),m_subFrameRate1);
    m_form3->addRow(tr("Code Rate"),m_subCodeRate1);

    m_form4 = new QFormLayout();
    m_form4->addRow(tr("Resolution"),m_subResolution2);
    m_form4->addRow(tr("Coding"),m_subCoding2);
    m_form4->addRow(tr("Frame Rate"),m_subFrameRate2);
    m_form4->addRow(tr("Code Rate"),m_subCodeRate2);

    m_maincode1 = new QGroupBox(tr("Main Coding"));
    m_maincode1->setLayout(m_form1);
    m_maincode2 = new QGroupBox(tr("Main Coding"));
    m_maincode2->setLayout(m_form2);
    m_subcode1 = new QGroupBox(tr("Sub Coding"));
    m_subcode1->setLayout(m_form3);
    m_subcode2 = new QGroupBox(tr("Sub Coding"));
    m_subcode2->setLayout(m_form4);
    m_lay1 = new QVBoxLayout();
    m_lay1->addWidget(m_maincode1);
    m_lay1->addWidget(m_subcode1);
    m_lay2 = new QVBoxLayout();
    m_lay2->addWidget(m_maincode2);
    m_lay2->addWidget(m_subcode2);
    m_movieMode1 = new QGroupBox(tr("Movie Mode"));
    m_movieMode1->setLayout(m_lay1);
    m_movieMode2 = new QGroupBox(tr("Movie Mode 2"));
    m_movieMode2->setLayout(m_lay2);

    m_con = new QHBoxLayout();
    m_con->addWidget(m_movieMode1);
    m_con->addWidget(m_movieMode2);
    this->setLayout(m_con);

}

CodingSetting::~CodingSetting()
{
    delete m_mainResolution1;
    delete m_mainResolution2;
    delete m_subResolution1;
    delete m_subResolution2;
    delete m_mainCoding1;
    delete m_mainCoding2;
    delete m_subCoding1;
    delete m_subCoding2;
    delete m_mainFrameRate1;
    delete m_mainFrameRate2;
    delete m_subFrameRate1;
    delete m_subFrameRate2;
    delete m_mainCodeRate1;
    delete m_mainCodeRate2;
    delete m_subCodeRate1;
    delete m_subCodeRate2;
    delete m_mainFrameSpacing1;
    delete m_mainFrameSpacing2;

    delete m_form1;
    delete m_form2;
    delete m_form3;
    delete m_form4;

    delete m_movieMode1;
    delete m_movieMode2;
    delete m_maincode1;
    delete m_maincode2;
    delete m_subcode1;
    delete m_subcode2;

    delete m_con;

}


/*****************************************************************************/
AudioSetting::AudioSetting(QWidget* parent):QWidget(parent)
{
   m_channel = new QComboBox();
   m_frequency = new QComboBox();
   m_bit = new QComboBox();
   m_rate = new QSpinBox();

   m_con = new QFormLayout();
   m_con->addRow(tr("Channel"),m_channel);
   m_con->addRow(tr("Frequency"),m_frequency);
   m_con->addRow(tr("Bit"),m_bit);
   m_con->addRow(tr("Rate"),m_rate);
   this->setLayout(m_con);
}

AudioSetting::~AudioSetting()
{
    delete m_channel;
    delete m_frequency;
    delete m_bit;
    delete m_rate;
    delete m_con;
}

/*****************************************************************************/
RecordSetting::RecordSetting(QWidget* parent):QWidget(parent)
{

}

RecordSetting::~RecordSetting()
{

}

/*****************************************************************************/
TimerRecordSetting::TimerRecordSetting(QWidget* parent):QWidget(parent)
{

}

TimerRecordSetting::~TimerRecordSetting()
{

}

/*****************************************************************************/
RTMPSetting::RTMPSetting(QWidget* parent):QWidget(parent)
{

}

RTMPSetting::~RTMPSetting()
{

}

/*****************************************************************************/
TSSetting::TSSetting(QWidget* parent):QWidget(parent)
{

}

TSSetting::~TSSetting()
{

}

/*****************************************************************************/
AutoTrackSetting::AutoTrackSetting(QWidget* parent):QWidget(parent)
{
    mv_Labfirst.resize(11);
    mv_comSecond.resize(11);
    mv_comMac.resize(3);
    mv_track.resize(3);
    mv_editLong.resize(11);
    mv_editdelay.resize(8);
    mv_delay.resize(8);

    for(int i=0;i<mv_Labfirst.size();i++)
    {
        mv_Labfirst[i] = new QLabel();
        mv_comSecond[i] = new QComboBox();
        mv_editLong[i] = new QLineEdit();
        if(i<3)
        {
             mv_comMac[i] = new QComboBox();
             mv_track[i] = new QLabel(tr("Track Host"));
        }
        if(i<8)
        {
            mv_delay[i] = new QLabel(tr("Delay"));
            mv_editdelay[i] = new QLineEdit();
        }
    }

    mv_Labfirst[0]->setText(tr("Auto"));
    mv_Labfirst[1]->setText(tr("Handle"));
    mv_Labfirst[2]->setText(tr("Semi-Auto"));
    mv_Labfirst[3]->setText(tr("SDI 1"));
    mv_Labfirst[4]->setText(tr("SDI 2"));
    mv_Labfirst[5]->setText(tr("SDI 3"));
    mv_Labfirst[6]->setText(tr("SDI 4"));
    mv_Labfirst[7]->setText(tr("SDI 5"));
    mv_Labfirst[8]->setText(tr("SDI 6"));
    mv_Labfirst[9]->setText(tr("DVI-I"));
    mv_Labfirst[10]->setText(tr("DVI-II"));


    m_con = new QGridLayout();
    for(int i=0;i<mv_Labfirst.size();i++)
    {
        m_con->addWidget(mv_Labfirst[i],i,0);
        m_con->addWidget(mv_comSecond[i],i,1);
        if(i<3)
        {
            m_con->addWidget(mv_track[i],i,2,Qt::AlignRight);
            m_con->addWidget(mv_comMac[i],i,3);
            m_con->addWidget(mv_editLong[i],i,4);
        }
        if(i>=3)
        {
            m_con->addWidget(mv_editLong[i],i,2);
            m_con->addWidget(mv_delay[i-3],i,3,Qt::AlignRight);
            m_con->addWidget(mv_editdelay[i-3],i,4);
        }
    }
    this->setLayout(m_con);

    //event

}

AutoTrackSetting::~AutoTrackSetting()
{

}

/*****************************************************************************/
SwitchPolicy::SwitchPolicy(QWidget* parent):QWidget(parent)
{

}

SwitchPolicy::~SwitchPolicy()
{

}

/*****************************************************************************/
FollowMachineSetting::FollowMachineSetting(QWidget* parent):QWidget(parent)
{
    m_IP = new QLineEdit();
    m_port = new QLineEdit();
    m_con = new QFormLayout();
    m_con->setMargin(60);
    m_con->addRow(tr("IP"),m_IP);
    m_con->addRow(tr("Port"),m_port);
    this->setLayout(m_con);
}

FollowMachineSetting::~FollowMachineSetting()
{
    delete m_IP;
    delete m_port;
    delete m_con;
}
/*****************************************************************************/
QLuboSettingWidget::QLuboSettingWidget(QSettingWidget* parent):QSettingWidget(parent)
{
    m_onekeyWidget = new OneKeySetting();
    m_codingWidget = new CodingSetting();
    m_audioWidget = new AudioSetting();
    m_recordWidget = new RecordSetting();
    m_timerRecordWidget = new TimerRecordSetting();
    m_rtmpWidget = new RTMPSetting();
    m_tsWidget = new TSSetting();
    m_autoWidget = new AutoTrackSetting();
    m_switchWidget = new SwitchPolicy();
    m_followWidget = new FollowMachineSetting();

    this->AddPage(m_onekeyWidget,tr("One-key"));
    this->AddPage(m_codingWidget,tr("Coding"));
    this->AddPage(m_audioWidget,tr("Audio"));
    this->AddPage(m_recordWidget,tr("Record"));
    this->AddPage(m_timerRecordWidget,tr("TimerRecord"));
    this->AddPage(m_rtmpWidget,tr("RTMP"));
    this->AddPage(m_tsWidget,tr("TS"));
    this->AddPage(m_autoWidget,tr("AutoTrack"));
    this->AddPage(m_switchWidget,tr("Switch"));
    this->AddPage(m_followWidget,tr("Follow-M"));
    this->SetTitle(tr("Lubo Setting"));

}

QLuboSettingWidget::~QLuboSettingWidget()
{

    delete m_onekeyWidget;
    delete m_codingWidget;
    delete m_audioWidget;
    delete m_recordWidget;
    delete m_timerRecordWidget;
    delete m_rtmpWidget;
    delete m_tsWidget;
    delete m_autoWidget;
    delete m_switchWidget;
    delete m_followWidget;

}

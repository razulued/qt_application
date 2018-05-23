#include "settings.h"
#include "ui_settings.h"
#include <QDebug>
#include <QDir>
#include "configuration.h"
#include <QProcess>
#include <QDir>
#include <QScroller>
#include "parameters.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    QFont font_1("Typo Square Ligth Demo",18,1);

    this->setObjectName("SettingsWindow");
    this->setStyleSheet("settings#SettingsWindow{"
                        "border-style: solid;"
                        "border-width: 6px;"
                        "border-radius: 6px;"
                        "border-color: gray;"
                        "color: white;"
                        "}");

    QString filename="config.ini";
    config_file = new QFile(filename);

    active_text_edit = ui->textEdit;

    if(!config_file->exists())
    {
        qDebug() << "No existe el archivo";
    }
    else
    {
        qDebug() << "Archivo encontrado";
    }

    QString line;
    active_text_edit->clear();

    if(config_file->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(config_file);
        while(!stream.atEnd())
        {
            line = stream.readLine();
            active_text_edit->setText(active_text_edit->toPlainText()+line+"\n");
        }
    }


    QScroller *scroller = QScroller::scroller(ui->scrollArea);
    QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    //Scrolling Gesture
    scroller->grabGesture(ui->scrollArea,QScroller::LeftMouseButtonGesture);

    synch_calibrations();

    this->show();

}

settings::~settings()
{
    delete ui;
}

void settings::sync_regulador_IDs()
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Regulador");

    const QStringList regulador_keys = conf.childKeys();
    QList<int> regulador_IDs;
    foreach(const QString &regulador_key, regulador_keys)
    {
        regulador_IDs << conf.value(regulador_key).toInt();
    }
    conf.endGroup();

    int i = 0;
    for(i = 0; i < regulador_keys.size(); i++)
    {
        qDebug() << regulador_keys[i] << ": " << regulador_IDs[i];
    }
}

void settings::on_settings_accepted()
{
//    saveSettings("Regulador", ui->regulador_ND_label->text(), ui->ID_regulador_ND->text().toInt());
    QTextStream stream(config_file);
    config_file->resize(0);
    stream << active_text_edit->toPlainText();
    config_file->flush();
    config_file->close();
}

void settings::on_settings_rejected()
{
    config_file->close();
}


void saveSettings(const QString &group, const QString &key, const QVariant &value)
{
    QSettings S;

    S.beginGroup(group);
    S.setValue(key, value);
    S.endGroup();
}

void settings::on_buttonBox_accepted()
{

}
void settings::on_key_0_clicked() {active_text_edit->insertPlainText("0");}
void settings::on_key_1_clicked() {active_text_edit->insertPlainText("1");}
void settings::on_key_2_clicked() {active_text_edit->insertPlainText("2");}
void settings::on_key_3_clicked() {active_text_edit->insertPlainText("3");}
void settings::on_key_4_clicked() {active_text_edit->insertPlainText("4");}
void settings::on_key_5_clicked() {active_text_edit->insertPlainText("5");}
void settings::on_key_6_clicked() {active_text_edit->insertPlainText("6");}
void settings::on_key_7_clicked() {active_text_edit->insertPlainText("7");}
void settings::on_key_8_clicked() {active_text_edit->insertPlainText("8");}
void settings::on_key_9_clicked() {active_text_edit->insertPlainText("9");}
void settings::on_key_Q_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("Q");}else{active_text_edit->insertPlainText("q");}}
void settings::on_key_W_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("W");}else{active_text_edit->insertPlainText("w");}}
void settings::on_key_E_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("E");}else{active_text_edit->insertPlainText("e");}}
void settings::on_key_R_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("R");}else{active_text_edit->insertPlainText("r");}}
void settings::on_key_T_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("T");}else{active_text_edit->insertPlainText("t");}}
void settings::on_key_Y_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("Y");}else{active_text_edit->insertPlainText("y");}}
void settings::on_key_U_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("U");}else{active_text_edit->insertPlainText("u");}}
void settings::on_key_I_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("I");}else{active_text_edit->insertPlainText("i");}}
void settings::on_key_O_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("O");}else{active_text_edit->insertPlainText("o");}}
void settings::on_key_P_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("P");}else{active_text_edit->insertPlainText("p");}}
void settings::on_key_A_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("A");}else{active_text_edit->insertPlainText("a");}}
void settings::on_key_S_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("S");}else{active_text_edit->insertPlainText("s");}}
void settings::on_key_D_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("D");}else{active_text_edit->insertPlainText("d");}}
void settings::on_key_F_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("F");}else{active_text_edit->insertPlainText("f");}}
void settings::on_key_G_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("G");}else{active_text_edit->insertPlainText("g");}}
void settings::on_key_H_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("H");}else{active_text_edit->insertPlainText("h");}}
void settings::on_key_J_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("J");}else{active_text_edit->insertPlainText("j");}}
void settings::on_key_K_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("K");}else{active_text_edit->insertPlainText("k");}}
void settings::on_key_L_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("L");}else{active_text_edit->insertPlainText("l");}}
void settings::on_key_Z_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("Z");}else{active_text_edit->insertPlainText("z");}}
void settings::on_key_X_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("X");}else{active_text_edit->insertPlainText("x");}}
void settings::on_key_C_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("C");}else{active_text_edit->insertPlainText("c");}}
void settings::on_key_V_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("V");}else{active_text_edit->insertPlainText("v");}}
void settings::on_key_B_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("B");}else{active_text_edit->insertPlainText("b");}}
void settings::on_key_N_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("N");}else{active_text_edit->insertPlainText("n");}}
void settings::on_key_M_clicked(){if(ui->key_mayus->isChecked()){active_text_edit->insertPlainText("M");}else{active_text_edit->insertPlainText("m");}}

void settings::on_key_up_clicked()    {active_text_edit->moveCursor(QTextCursor::Up);}
void settings::on_key_down_clicked()  {active_text_edit->moveCursor(QTextCursor::Down);}
void settings::on_key_left_clicked()  {active_text_edit->moveCursor(QTextCursor::Left);}
void settings::on_key_right_clicked() {active_text_edit->moveCursor(QTextCursor::Right);}

void settings::on_key_guion_clicked() {active_text_edit->insertPlainText("-");}
void settings::on_key_equal_clicked() {active_text_edit->insertPlainText("=");}
void settings::on_key_space_clicked() {active_text_edit->insertPlainText(" ");}

void settings::on_key_back_clicked()
{
    active_text_edit->textCursor().deletePreviousChar();
}
void settings::on_key_enter_clicked() {active_text_edit->insertPlainText("\n");}

void settings::synch_calibrations()
{
    ui->control_3400->setValue(getParamValue(0x3400).toDouble());
    ui->control_3401->setValue(getParamValue(0x3401).toDouble());
    ui->control_3402->setValue(getParamValue(0x3402).toDouble());
    ui->control_3403->setValue(getParamValue(0x3403).toDouble());
    ui->control_3501->setValue(getParamValue(0x3501).toDouble());

    ui->control_4400->setValue(getParamValue(0x4400).toDouble());
    ui->control_4401->setValue(getParamValue(0x4401).toDouble());
    ui->control_4501->setValue(getParamValue(0x4501).toDouble());
    ui->control_4502->setValue(getParamValue(0x4502).toDouble());
    ui->control_4540->setValue(getParamValue(0x4540).toDouble());
    ui->control_4541->setValue(getParamValue(0x4541).toDouble());

    ui->control_5400->setValue(getParamValue(0x5400).toDouble());
    ui->control_5401->setValue(getParamValue(0x5401).toDouble());

    ui->control_9400->setValue(getParamValue(0x9400).toDouble());
    ui->control_9401->setValue(getParamValue(0x9401).toDouble());
    ui->control_9402->setValue(getParamValue(0x9402).toDouble());
    ui->control_9403->setValue(getParamValue(0x9403).toDouble());
    ui->control_9501->setValue(getParamValue(0x9501).toDouble());
    ui->control_9502->setValue(getParamValue(0x9502).toDouble());
}

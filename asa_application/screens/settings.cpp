#include "settings.h"
#include "ui_settings.h"
#include <QDebug>
#include <QDir>
#include "configuration/configuration.h"
#include <QProcess>
#include <QDir>
#include <QScroller>
#include "parameters.h"
#include "protocol/asa_conf_string.h"
#include "QKeyEvent"
#include "build_settings.h"
#include "protocol/asa_protocol.h"

#define VERSION_MAJOR   (0)
#define VERSION_MID     (1)
#define VERSION_MINOR   (1)
#define VERSION_FIX     ("a0320")
const QString SW_VERSION = QString::number(VERSION_MAJOR).append(".")\
        .append(QString::number(VERSION_MID)).append(".")\
        .append(QString::number(VERSION_MINOR).append("-"))\
        .append(VERSION_FIX);

settings::settings(bool super_user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    QFont font_1("Typo Square Ligth Demo",18,1);

    // SET SW Version.
    ui->label_version->setText(tr("APP Version: ")+ SW_VERSION + "\r\n"
                               + tr("Fecha de compilación: ") + __DATE__ + " " + __TIME__ + "\r\n\r\n"
                               + tr("EARM Version: ") + getParamValue(0x0006));

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

    QScroller *scroller_2 = QScroller::scroller(ui->scrollArea_2);
    QScrollerProperties properties_2 = QScroller::scroller(scroller_2)->scrollerProperties();
    QVariant overshootPolicy_2 = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties_2.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy_2);
    scroller_2->setScrollerProperties(properties_2);
    //Scrolling Gesture
    scroller_2->grabGesture(ui->scrollArea_2,QScroller::LeftMouseButtonGesture);

    QScroller *scroller_3 = QScroller::scroller(ui->scrollArea_3);
    QScrollerProperties properties_3 = QScroller::scroller(scroller_3)->scrollerProperties();
    QVariant overshootPolicy_3 = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties_3.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy_3);
    scroller_3->setScrollerProperties(properties_3);
    //Scrolling Gesture
    scroller_3->grabGesture(ui->scrollArea_3,QScroller::LeftMouseButtonGesture);

    // Hide super user tab
    if(super_user == false)
    {
        ui->tabWidget->removeTab(6);
    }

    synch_calibrations();
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
    release_lock();
    config_file->close();
}

void settings::on_settings_rejected()
{
    release_lock();
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
    //Display calibrations
    uint mode_4600;
    QString calibrations;

    calibrations += "0D03:2";
    calibrations += "|0D04:2";
    calibrations += "|3400:" + invese_getParamValue(0x3400, ui->control_3400->value());
    calibrations += "|3401:" + invese_getParamValue(0x3401, ui->control_3401->value());
    calibrations += "|3402:" + invese_getParamValue(0x3402, ui->control_3402->value());
    calibrations += "|3403:" + invese_getParamValue(0x3403, ui->control_3403->value());
    calibrations += "|3501:" + invese_getParamValue(0x3501, ui->control_3501->value());
    calibrations += "|3502:" + invese_getParamValue(0x3502, ui->control_3502->value());
    calibrations += "|2403:" + invese_getParamValue(0x2403, ui->control_2403->value());


    calibrations += "|3C00:" + invese_getParamValue(0x3C00, ui->control_3C00->value());
    calibrations += "|3C01:" + invese_getParamValue(0x3C01, ui->control_3C01->value());
    calibrations += "|3C02:" + invese_getParamValue(0x3C02, ui->control_3C02->value());
    calibrations += "|3C03:" + invese_getParamValue(0x3C03, ui->control_3C03->value());
    calibrations += "|3D01:" + invese_getParamValue(0x3D01, ui->control_3D01->value());
    calibrations += "|3D02:" + invese_getParamValue(0x3D02, ui->control_3D02->value());
    calibrations += "|2402:" + invese_getParamValue(0x2402, ui->control_2402->value());

    calibrations += "|4400:" + invese_getParamValue(0x4400, ui->control_4400->value());
    calibrations += "|4401:" + invese_getParamValue(0x4401, ui->control_4401->value());
    calibrations += "|4501:" + invese_getParamValue(0x4501, ui->control_4501->value());
    calibrations += "|4502:" + invese_getParamValue(0x4502, ui->control_4502->value());
    calibrations += "|4540:" + invese_getParamValue(0x4540, ui->control_4540->value());
    calibrations += "|4541:" + invese_getParamValue(0x4541, ui->control_4541->value());

    if(true == ui->radioButton->isChecked())
    {
        // por tiempos
        calibrations += "|4600:2";
        mode_4600 = 2;
    }
    else
    {
        // por oxigeno
        calibrations += "|4600:1";
        mode_4600 = 1;
    }

    calibrations += "|9400:" + invese_getParamValue(0x9400, ui->control_9400->value());
    calibrations += "|9401:" + invese_getParamValue(0x9401, ui->control_9401->value());
    calibrations += "|9402:" + invese_getParamValue(0x9402, ui->control_9402->value());
    calibrations += "|9403:" + invese_getParamValue(0x9403, ui->control_9403->value());
    calibrations += "|9404:" + invese_getParamValue(0x9404, ui->control_9404->value());

    calibrations += "|9500:" + invese_getParamValue(0x9500, ui->control_9500->value());
    calibrations += "|9501:" + invese_getParamValue(0x9501, ui->control_9501->value());
    calibrations += "|9502:" + invese_getParamValue(0x9502, ui->control_9502->value());
    calibrations += "|9503:" + invese_getParamValue(0x9503, ui->control_9503->value());
    calibrations += "|9504:" + invese_getParamValue(0x9504, ui->control_9504->value());


    ///carcamo
    calibrations += "|1006:" + invese_getParamValue(0x1006, ui->control_1006->value());
    calibrations += "|1007:" + invese_getParamValue(0x1007, ui->control_1007->value());
    calibrations += "|1008:" + invese_getParamValue(0x1008, ui->control_1008->value());
    calibrations += "|1009:" + invese_getParamValue(0x1009, ui->control_1009->value());
    calibrations += "|100A:" + invese_getParamValue(0x100A, ui->control_100A->value());
    calibrations += "|100B:" + invese_getParamValue(0x100B, ui->control_100B->value());
    ///regulador
    calibrations += "|1126:" + invese_getParamValue(0x1126, ui->control_1126->value());
    calibrations += "|1127:" + invese_getParamValue(0x1127, ui->control_1127->value());
    calibrations += "|1128:" + invese_getParamValue(0x1128, ui->control_1128->value());
    calibrations += "|1129:" + invese_getParamValue(0x1129, ui->control_1129->value());
    calibrations += "|112A:" + invese_getParamValue(0x112A, ui->control_112A->value());
    calibrations += "|112B:" + invese_getParamValue(0x112B, ui->control_112B->value());

    ///carcamo
    calibrations += "|101E:" + invese_getParamValue(0x101E, ui->control_101E->value());
    calibrations += "|101F:" + invese_getParamValue(0x101F, ui->control_101F->value());
    calibrations += "|1020:" + invese_getParamValue(0x1020, ui->control_1020->value());
    calibrations += "|1021:" + invese_getParamValue(0x1021, ui->control_1021->value());
    calibrations += "|1022:" + invese_getParamValue(0x1022, ui->control_1022->value());
    calibrations += "|1023:" + invese_getParamValue(0x1023, ui->control_1023->value());
    ///regulador
    calibrations += "|113E:" + invese_getParamValue(0x113E, ui->control_113E->value());
    calibrations += "|113F:" + invese_getParamValue(0x113F, ui->control_113F->value());
    calibrations += "|1140:" + invese_getParamValue(0x1140, ui->control_1140->value());
    calibrations += "|1141:" + invese_getParamValue(0x1141, ui->control_1141->value());
    calibrations += "|1142:" + invese_getParamValue(0x1142, ui->control_1142->value());
    calibrations += "|1143:" + invese_getParamValue(0x1143, ui->control_1143->value());

    calibrations += "|103C:" + invese_getParamValue(0x103C, ui->control_103C->value());
    calibrations += "|103D:" + invese_getParamValue(0x103D, ui->control_103D->value());
    calibrations += "|103E:" + invese_getParamValue(0x103E, ui->control_103E->value());
    calibrations += "|103F:" + invese_getParamValue(0x103F, ui->control_103F->value());
    calibrations += "|1040:" + invese_getParamValue(0x1040, ui->control_1040->value());
    calibrations += "|1041:" + invese_getParamValue(0x1041, ui->control_1041->value());

    calibrations += "|1042:" + invese_getParamValue(0x1042, ui->control_1042->value());
    calibrations += "|1043:" + invese_getParamValue(0x1043, ui->control_1043->value());
    calibrations += "|1044:" + invese_getParamValue(0x1044, ui->control_1044->value());
    calibrations += "|1045:" + invese_getParamValue(0x1045, ui->control_1045->value());
    calibrations += "|1046:" + invese_getParamValue(0x1046, ui->control_1046->value());
    calibrations += "|1047:" + invese_getParamValue(0x1047, ui->control_1047->value());

    calibrations += "|1048:" + invese_getParamValue(0x1048, ui->control_1048->value());
    calibrations += "|1049:" + invese_getParamValue(0x1049, ui->control_1049->value());
    calibrations += "|104A:" + invese_getParamValue(0x104A, ui->control_104A->value());
    calibrations += "|104B:" + invese_getParamValue(0x104B, ui->control_104B->value());
    calibrations += "|104C:" + invese_getParamValue(0x104C, ui->control_104C->value());
    calibrations += "|104D:" + invese_getParamValue(0x104D, ui->control_104D->value());

    calibrations += "|1060:" + invese_getParamValue(0x1060, ui->control_1060->value());
    calibrations += "|1061:" + invese_getParamValue(0x1061, ui->control_1061->value());
    calibrations += "|1062:" + invese_getParamValue(0x1062, ui->control_1062->value());
    calibrations += "|1063:" + invese_getParamValue(0x1063, ui->control_1063->value());
    calibrations += "|1064:" + invese_getParamValue(0x1064, ui->control_1064->value());
    calibrations += "|1065:" + invese_getParamValue(0x1065, ui->control_1065->value());

    calibrations += "|1090:" + invese_getParamValue(0x1090, ui->control_1090->value());
    calibrations += "|1091:" + invese_getParamValue(0x1091, ui->control_1091->value());
    calibrations += "|1092:" + invese_getParamValue(0x1092, ui->control_1092->value());
    calibrations += "|1093:" + invese_getParamValue(0x1093, ui->control_1093->value());
    calibrations += "|1094:" + invese_getParamValue(0x1094, ui->control_1094->value());
    calibrations += "|1095:" + invese_getParamValue(0x1095, ui->control_1095->value());

    calibrations += "|109C:" + invese_getParamValue(0x109C, ui->control_109C->value());
    calibrations += "|109D:" + invese_getParamValue(0x109D, ui->control_109D->value());
    calibrations += "|109E:" + invese_getParamValue(0x109E, ui->control_109E->value());
    calibrations += "|109F:" + invese_getParamValue(0x109F, ui->control_109F->value());
    calibrations += "|10A0:" + invese_getParamValue(0x10A0, ui->control_10A0->value());
    calibrations += "|10A1:" + invese_getParamValue(0x10A1, ui->control_10A1->value());

    //Filtro
    calibrations += "|10A2:" + invese_getParamValue(0x10A2, ui->control_10A2->value());
    calibrations += "|10A3:" + invese_getParamValue(0x10A3, ui->control_10A3->value());
    calibrations += "|10A4:" + invese_getParamValue(0x10A4, ui->control_10A4->value());
    calibrations += "|10A5:" + invese_getParamValue(0x10A5, ui->control_10A5->value());
    calibrations += "|10A6:" + invese_getParamValue(0x10A6, ui->control_10A6->value());
    calibrations += "|10A7:" + invese_getParamValue(0x10A7, ui->control_10A7->value());

    calibrations += "|10A8:" + invese_getParamValue(0x10A8, ui->control_10A8->value());
    calibrations += "|10A9:" + invese_getParamValue(0x10A9, ui->control_10A9->value());
    calibrations += "|10AA:" + invese_getParamValue(0x10AA, ui->control_10AA->value());
    calibrations += "|10AB:" + invese_getParamValue(0x10AB, ui->control_10AB->value());
    calibrations += "|10AC:" + invese_getParamValue(0x10AC, ui->control_10AC->value());
    calibrations += "|10AD:" + invese_getParamValue(0x10AD, ui->control_10AD->value());

    calibrations += "|10AE:" + invese_getParamValue(0x10AE, ui->control_10AE->value());
    calibrations += "|10AF:" + invese_getParamValue(0x10AF, ui->control_10AF->value());
    calibrations += "|10B0:" + invese_getParamValue(0x10B0, ui->control_10B0->value());
    calibrations += "|10B1:" + invese_getParamValue(0x10B1, ui->control_10B1->value());
    calibrations += "|10B2:" + invese_getParamValue(0x10B2, ui->control_10B2->value());
    calibrations += "|10B3:" + invese_getParamValue(0x10B3, ui->control_10B3->value());

    calibrations += "|10B4:" + invese_getParamValue(0x10B4, ui->control_10B4->value());
    calibrations += "|10B5:" + invese_getParamValue(0x10B5, ui->control_10B5->value());
    calibrations += "|10B6:" + invese_getParamValue(0x10B6, ui->control_10B6->value());
    calibrations += "|10B7:" + invese_getParamValue(0x10B7, ui->control_10B7->value());
    calibrations += "|10B8:" + invese_getParamValue(0x10B8, ui->control_10B8->value());
    calibrations += "|10B9:" + invese_getParamValue(0x10B9, ui->control_10B9->value());

    calibrations += "|10D8:" + invese_getParamValue(0x10D8, ui->control_10D8->value());
    calibrations += "|10D9:" + invese_getParamValue(0x10D9, ui->control_10D9->value());
    calibrations += "|10DA:" + invese_getParamValue(0x10DA, ui->control_10DA->value());
    calibrations += "|10DB:" + invese_getParamValue(0x10DB, ui->control_10DB->value());
    calibrations += "|10DC:" + invese_getParamValue(0x10DC, ui->control_10DC->value());
    calibrations += "|10DD:" + invese_getParamValue(0x10DD, ui->control_10DD->value());

    calibrations += "|10DE:" + invese_getParamValue(0x10DE, ui->control_10DE->value());
    calibrations += "|10DF:" + invese_getParamValue(0x10DF, ui->control_10DF->value());
    calibrations += "|10E0:" + invese_getParamValue(0x10E0, ui->control_10E0->value());
    calibrations += "|10E1:" + invese_getParamValue(0x10E1, ui->control_10E1->value());
    calibrations += "|10E2:" + invese_getParamValue(0x10E2, ui->control_10E2->value());
    calibrations += "|10E3:" + invese_getParamValue(0x10E3, ui->control_10E3->value());

    calibrations += "|10EA:" + invese_getParamValue(0x10EA, ui->control_10EA->value());
    calibrations += "|10EB:" + invese_getParamValue(0x10EB, ui->control_10EB->value());
    calibrations += "|10EC:" + invese_getParamValue(0x10EC, ui->control_10EC->value());
    calibrations += "|10ED:" + invese_getParamValue(0x10ED, ui->control_10ED->value());
    calibrations += "|10EE:" + invese_getParamValue(0x10EE, ui->control_10EE->value());
    calibrations += "|10EF:" + invese_getParamValue(0x10EF, ui->control_10EF->value());

    calibrations += "|10F0:" + invese_getParamValue(0x10F0, ui->control_10F0->value());
    calibrations += "|10F1:" + invese_getParamValue(0x10F1, ui->control_10F1->value());
    calibrations += "|10F2:" + invese_getParamValue(0x10F2, ui->control_10F2->value());
    calibrations += "|10F3:" + invese_getParamValue(0x10F3, ui->control_10F3->value());
    calibrations += "|10F4:" + invese_getParamValue(0x10F4, ui->control_10F4->value());
    calibrations += "|10F5:" + invese_getParamValue(0x10F5, ui->control_10F5->value());

    calibrations += "|10FC:" + invese_getParamValue(0x10FC, ui->control_10FC->value());
    calibrations += "|10FD:" + invese_getParamValue(0x10FD, ui->control_10FD->value());
    calibrations += "|10FE:" + invese_getParamValue(0x10FE, ui->control_10FE->value());
    calibrations += "|10FF:" + invese_getParamValue(0x10FF, ui->control_10FF->value());
    calibrations += "|1100:" + invese_getParamValue(0x1100, ui->control_1100->value());
    calibrations += "|1101:" + invese_getParamValue(0x1101, ui->control_1101->value());

    calibrations += "|1102:" + invese_getParamValue(0x1102, ui->control_1102->value());
    calibrations += "|1103:" + invese_getParamValue(0x1103, ui->control_1103->value());
    calibrations += "|1104:" + invese_getParamValue(0x1104, ui->control_1104->value());
    calibrations += "|1105:" + invese_getParamValue(0x1105, ui->control_1105->value());
    calibrations += "|1106:" + invese_getParamValue(0x1106, ui->control_1106->value());
    calibrations += "|1107:" + invese_getParamValue(0x1107, ui->control_1107->value());

    set_calibration(calibrations);

    qDebug() << calibrations;

    // Save 4600
    write_parameter("mode4600.bin", mode_4600);

    //Save language and units settings
    save_language_and_units();
}


void settings::on_key_0_clicked() {keyboard_handler("0");}
void settings::on_key_1_clicked() {keyboard_handler("1");}
void settings::on_key_2_clicked() {keyboard_handler("2");}
void settings::on_key_3_clicked() {keyboard_handler("3");}
void settings::on_key_4_clicked() {keyboard_handler("4");}
void settings::on_key_5_clicked() {keyboard_handler("5");}
void settings::on_key_6_clicked() {keyboard_handler("6");}
void settings::on_key_7_clicked() {keyboard_handler("7");}
void settings::on_key_8_clicked() {keyboard_handler("8");}
void settings::on_key_9_clicked() {keyboard_handler("9");}
void settings::on_key_Q_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Q");}else{keyboard_handler("q");}}
void settings::on_key_W_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("W");}else{keyboard_handler("w");}}
void settings::on_key_E_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("E");}else{keyboard_handler("e");}}
void settings::on_key_R_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("R");}else{keyboard_handler("r");}}
void settings::on_key_T_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("T");}else{keyboard_handler("t");}}
void settings::on_key_Y_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Y");}else{keyboard_handler("y");}}
void settings::on_key_U_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("U");}else{keyboard_handler("u");}}
void settings::on_key_I_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("I");}else{keyboard_handler("i");}}
void settings::on_key_O_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("O");}else{keyboard_handler("o");}}
void settings::on_key_P_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("P");}else{keyboard_handler("p");}}
void settings::on_key_A_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("A");}else{keyboard_handler("a");}}
void settings::on_key_S_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("S");}else{keyboard_handler("s");}}
void settings::on_key_D_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("D");}else{keyboard_handler("d");}}
void settings::on_key_F_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("F");}else{keyboard_handler("f");}}
void settings::on_key_G_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("G");}else{keyboard_handler("g");}}
void settings::on_key_H_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("H");}else{keyboard_handler("h");}}
void settings::on_key_J_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("J");}else{keyboard_handler("j");}}
void settings::on_key_K_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("K");}else{keyboard_handler("k");}}
void settings::on_key_L_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("L");}else{keyboard_handler("l");}}
void settings::on_key_Z_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Z");}else{keyboard_handler("z");}}
void settings::on_key_X_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("X");}else{keyboard_handler("x");}}
void settings::on_key_C_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("C");}else{keyboard_handler("c");}}
void settings::on_key_V_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("V");}else{keyboard_handler("v");}}
void settings::on_key_B_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("B");}else{keyboard_handler("b");}}
void settings::on_key_N_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("N");}else{keyboard_handler("n");}}
void settings::on_key_M_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("M");}else{keyboard_handler("m");}}

void settings::on_key_up_clicked()    {active_text_edit->moveCursor(QTextCursor::Up);}
void settings::on_key_down_clicked()  {active_text_edit->moveCursor(QTextCursor::Down);}
void settings::on_key_left_clicked()  {active_text_edit->moveCursor(QTextCursor::Left);}
void settings::on_key_right_clicked() {active_text_edit->moveCursor(QTextCursor::Right);}

void settings::on_key_guion_clicked() {keyboard_handler("-");}
void settings::on_key_equal_clicked() {keyboard_handler("=");}
void settings::on_key_space_clicked() {keyboard_handler(" ");}
void settings::on_key_L_corchete_clicked() {keyboard_handler("[");}
void settings::on_key_R_corchete_clicked() {keyboard_handler("]");}
void settings::on_key_comma_clicked() {keyboard_handler(",");}
void settings::on_key_dot_clicked() {keyboard_handler(".");}
void settings::on_key_slash_clicked() {keyboard_handler("/");}
void settings::on_key_minus_clicked() {keyboard_handler("-");}
void settings::on_key_plus_clicked() {keyboard_handler("+");}

void settings::on_key_back_clicked()
{
    keyboard_handler("back");
}
void settings::on_key_enter_clicked() {keyboard_handler("\n");}

void settings::keyboard_handler(QString key)
{
    QWidget * fw = QApplication::focusWidget();

    QString object = fw->metaObject()->className();
    if(object == "QDoubleSpinBox")
    {
        QDoubleSpinBox* spin_ptr = (QDoubleSpinBox*)fw;
        bool ok;
        double num = key.toDouble(&ok);

        if(ok)
        {
            spin_ptr->setValue((spin_ptr->value()*10)+num);
        }
        else
        {
            spin_ptr->setValue(0);
        }
    }
    else if(object ==  "QTextEdit")
    {
        QTextEdit *text_ptr = (QTextEdit *)fw;
        if(key == "back")
        {
            text_ptr->textCursor().deletePreviousChar();
        }
        else
        {
            text_ptr->insertPlainText(key);
        }
    }
}

void settings::synch_calibrations()
{   
    ui->control_3400->setValue(getParamValue_base_units(0x3400).toDouble());
    ui->control_3401->setValue(getParamValue_base_units(0x3401).toDouble());
    ui->control_3402->setValue(getParamValue_base_units(0x3402).toDouble());
    ui->control_3403->setValue(getParamValue_base_units(0x3403).toDouble());
    ui->control_3501->setValue(getParamValue_base_units(0x3501).toDouble());
    ui->control_3502->setValue(getParamValue_base_units(0x3502).toDouble());
    ui->control_2403->setValue(getParamValue_base_units(0x2403).toDouble());

    ui->control_3C00->setValue(getParamValue_base_units(0x3C00).toDouble());
    ui->control_3C01->setValue(getParamValue_base_units(0x3C01).toDouble());
    ui->control_3C02->setValue(getParamValue_base_units(0x3C02).toDouble());
    ui->control_3C03->setValue(getParamValue_base_units(0x3C03).toDouble());
    ui->control_3D01->setValue(getParamValue_base_units(0x3D01).toDouble());
    ui->control_3D02->setValue(getParamValue_base_units(0x3D02).toDouble());
    ui->control_2402->setValue(getParamValue_base_units(0x2402).toDouble());

    ui->control_4400->setValue(getParamValue_base_units(0x4400).toDouble());
    ui->control_4401->setValue(getParamValue_base_units(0x4401).toDouble());
    ui->control_4501->setValue(getParamValue_base_units(0x4501).toDouble());
    ui->control_4502->setValue(getParamValue_base_units(0x4502).toDouble());
    ui->control_4540->setValue(getParamValue_base_units(0x4540).toDouble());
    ui->control_4541->setValue(getParamValue_base_units(0x4541).toDouble());

//    ui->control_5400->setValue(getParamValue_base_units(0x5400).toDouble());
//    ui->control_5401->setValue(getParamValue_base_units(0x5401).toDouble());

    ui->control_9400->setValue(getParamValue_base_units(0x9400).toDouble());
    ui->control_9401->setValue(getParamValue_base_units(0x9401).toDouble());
    ui->control_9402->setValue(getParamValue_base_units(0x9402).toDouble());
    ui->control_9403->setValue(getParamValue_base_units(0x9403).toDouble());
    ui->control_9404->setValue(getParamValue_base_units(0x9404).toDouble());
    ui->control_9500->setValue(getParamValue_base_units(0x9500).toDouble());
    ui->control_9501->setValue(getParamValue_base_units(0x9501).toDouble());
    ui->control_9502->setValue(getParamValue_base_units(0x9502).toDouble());
    ui->control_9503->setValue(getParamValue_base_units(0x9503).toDouble());
    ui->control_9504->setValue(getParamValue_base_units(0x9504).toDouble());

    // ALARMAS
    // carcamo
    ui->control_1006->setValue(getParamValue_base_units(0x1006).toDouble());
    ui->control_1007->setValue(getParamValue_base_units(0x1007).toDouble());
    ui->control_1008->setValue(getParamValue_base_units(0x1008).toDouble());
    ui->control_1009->setValue(getParamValue_base_units(0x1009).toDouble());
    ui->control_100A->setValue(getParamValue_base_units(0x100A).toDouble());
    ui->control_100B->setValue(getParamValue_base_units(0x100B).toDouble());
    // regulador
    ui->control_1126->setValue(getParamValue_base_units(0x1126).toDouble());
    ui->control_1127->setValue(getParamValue_base_units(0x1127).toDouble());
    ui->control_1128->setValue(getParamValue_base_units(0x1128).toDouble());
    ui->control_1129->setValue(getParamValue_base_units(0x1129).toDouble());
    ui->control_112A->setValue(getParamValue_base_units(0x112A).toDouble());
    ui->control_112B->setValue(getParamValue_base_units(0x112B).toDouble());

    //carcamo
    ui->control_101E->setValue(getParamValue_base_units(0x101E).toDouble());
    ui->control_101F->setValue(getParamValue_base_units(0x101F).toDouble());
    ui->control_1020->setValue(getParamValue_base_units(0x1020).toDouble());
    ui->control_1021->setValue(getParamValue_base_units(0x1021).toDouble());
    ui->control_1022->setValue(getParamValue_base_units(0x1022).toDouble());
    ui->control_1023->setValue(getParamValue_base_units(0x1023).toDouble());
    // carcamo
    ui->control_113E->setValue(getParamValue_base_units(0x113E).toDouble());
    ui->control_113F->setValue(getParamValue_base_units(0x113F).toDouble());
    ui->control_1140->setValue(getParamValue_base_units(0x1140).toDouble());
    ui->control_1141->setValue(getParamValue_base_units(0x1141).toDouble());
    ui->control_1142->setValue(getParamValue_base_units(0x1142).toDouble());
    ui->control_1143->setValue(getParamValue_base_units(0x1143).toDouble());

    ui->control_103C->setValue(getParamValue_base_units(0x103C).toDouble());
    ui->control_103D->setValue(getParamValue_base_units(0x103D).toDouble());
    ui->control_103E->setValue(getParamValue_base_units(0x103E).toDouble());
    ui->control_103F->setValue(getParamValue_base_units(0x103F).toDouble());
    ui->control_1040->setValue(getParamValue_base_units(0x1040).toDouble());
    ui->control_1041->setValue(getParamValue_base_units(0x1041).toDouble());

    ui->control_1042->setValue(getParamValue_base_units(0x1042).toDouble());
    ui->control_1043->setValue(getParamValue_base_units(0x1043).toDouble());
    ui->control_1044->setValue(getParamValue_base_units(0x1044).toDouble());
    ui->control_1045->setValue(getParamValue_base_units(0x1045).toDouble());
    ui->control_1046->setValue(getParamValue_base_units(0x1046).toDouble());
    ui->control_1047->setValue(getParamValue_base_units(0x1047).toDouble());

    ui->control_1048->setValue(getParamValue_base_units(0x1048).toDouble());
    ui->control_1049->setValue(getParamValue_base_units(0x1049).toDouble());
    ui->control_104A->setValue(getParamValue_base_units(0x104A).toDouble());
    ui->control_104B->setValue(getParamValue_base_units(0x104B).toDouble());
    ui->control_104C->setValue(getParamValue_base_units(0x104C).toDouble());
    ui->control_104D->setValue(getParamValue_base_units(0x104D).toDouble());

    ui->control_1060->setValue(getParamValue_base_units(0x1060).toDouble());
    ui->control_1061->setValue(getParamValue_base_units(0x1061).toDouble());
    ui->control_1062->setValue(getParamValue_base_units(0x1062).toDouble());
    ui->control_1063->setValue(getParamValue_base_units(0x1063).toDouble());
    ui->control_1064->setValue(getParamValue_base_units(0x1064).toDouble());
    ui->control_1065->setValue(getParamValue_base_units(0x1065).toDouble());

    ui->control_1090->setValue(getParamValue_base_units(0x1090).toDouble());
    ui->control_1091->setValue(getParamValue_base_units(0x1091).toDouble());
    ui->control_1092->setValue(getParamValue_base_units(0x1092).toDouble());
    ui->control_1093->setValue(getParamValue_base_units(0x1093).toDouble());
    ui->control_1094->setValue(getParamValue_base_units(0x1094).toDouble());
    ui->control_1095->setValue(getParamValue_base_units(0x1095).toDouble());

    ui->control_109C->setValue(getParamValue_base_units(0x109C).toDouble());
    ui->control_109D->setValue(getParamValue_base_units(0x109D).toDouble());
    ui->control_109E->setValue(getParamValue_base_units(0x109E).toDouble());
    ui->control_109F->setValue(getParamValue_base_units(0x109F).toDouble());
    ui->control_10A0->setValue(getParamValue_base_units(0x10A0).toDouble());
    ui->control_10A1->setValue(getParamValue_base_units(0x10A1).toDouble());

    //Filtro
    ui->control_10A2->setValue(getParamValue_base_units(0x10A2).toDouble());
    ui->control_10A3->setValue(getParamValue_base_units(0x10A3).toDouble());
    ui->control_10A4->setValue(getParamValue_base_units(0x10A4).toDouble());
    ui->control_10A5->setValue(getParamValue_base_units(0x10A5).toDouble());
    ui->control_10A6->setValue(getParamValue_base_units(0x10A6).toDouble());
    ui->control_10A7->setValue(getParamValue_base_units(0x10A7).toDouble());

    ui->control_10A8->setValue(getParamValue_base_units(0x10A8).toDouble());
    ui->control_10A9->setValue(getParamValue_base_units(0x10A9).toDouble());
    ui->control_10AA->setValue(getParamValue_base_units(0x10AA).toDouble());
    ui->control_10AB->setValue(getParamValue_base_units(0x10AB).toDouble());
    ui->control_10AC->setValue(getParamValue_base_units(0x10AC).toDouble());
    ui->control_10AD->setValue(getParamValue_base_units(0x10AD).toDouble());

    ui->control_10AE->setValue(getParamValue_base_units(0x10AE).toDouble());
    ui->control_10AF->setValue(getParamValue_base_units(0x10AF).toDouble());
    ui->control_10B0->setValue(getParamValue_base_units(0x10B0).toDouble());
    ui->control_10B1->setValue(getParamValue_base_units(0x10B1).toDouble());
    ui->control_10B2->setValue(getParamValue_base_units(0x10B2).toDouble());
    ui->control_10B3->setValue(getParamValue_base_units(0x10B3).toDouble());

    ui->control_10B4->setValue(getParamValue_base_units(0x10B4).toDouble());
    ui->control_10B5->setValue(getParamValue_base_units(0x10B5).toDouble());
    ui->control_10B6->setValue(getParamValue_base_units(0x10B6).toDouble());
    ui->control_10B7->setValue(getParamValue_base_units(0x10B7).toDouble());
    ui->control_10B8->setValue(getParamValue_base_units(0x10B8).toDouble());
    ui->control_10B9->setValue(getParamValue_base_units(0x10B9).toDouble());

    ui->control_10D8->setValue(getParamValue_base_units(0x10D8).toDouble());
    ui->control_10D9->setValue(getParamValue_base_units(0x10D9).toDouble());
    ui->control_10DA->setValue(getParamValue_base_units(0x10DA).toDouble());
    ui->control_10DB->setValue(getParamValue_base_units(0x10DB).toDouble());
    ui->control_10DC->setValue(getParamValue_base_units(0x10DC).toDouble());
    ui->control_10DD->setValue(getParamValue_base_units(0x10DD).toDouble());

    ui->control_10DE->setValue(getParamValue_base_units(0x10DE).toDouble());
    ui->control_10DF->setValue(getParamValue_base_units(0x10DF).toDouble());
    ui->control_10E0->setValue(getParamValue_base_units(0x10E0).toDouble());
    ui->control_10E1->setValue(getParamValue_base_units(0x10E1).toDouble());
    ui->control_10E2->setValue(getParamValue_base_units(0x10E2).toDouble());
    ui->control_10E3->setValue(getParamValue_base_units(0x10E3).toDouble());

    ui->control_10EA->setValue(getParamValue_base_units(0x10EA).toDouble());
    ui->control_10EB->setValue(getParamValue_base_units(0x10EB).toDouble());
    ui->control_10EC->setValue(getParamValue_base_units(0x10EC).toDouble());
    ui->control_10ED->setValue(getParamValue_base_units(0x10ED).toDouble());
    ui->control_10EE->setValue(getParamValue_base_units(0x10EE).toDouble());
    ui->control_10EF->setValue(getParamValue_base_units(0x10EF).toDouble());

    ui->control_10F0->setValue(getParamValue_base_units(0x10F0).toDouble());
    ui->control_10F1->setValue(getParamValue_base_units(0x10F1).toDouble());
    ui->control_10F2->setValue(getParamValue_base_units(0x10F2).toDouble());
    ui->control_10F3->setValue(getParamValue_base_units(0x10F3).toDouble());
    ui->control_10F4->setValue(getParamValue_base_units(0x10F4).toDouble());
    ui->control_10F5->setValue(getParamValue_base_units(0x10F5).toDouble());

    ui->control_10FC->setValue(getParamValue_base_units(0x10FC).toDouble());
    ui->control_10FD->setValue(getParamValue_base_units(0x10FD).toDouble());
    ui->control_10FE->setValue(getParamValue_base_units(0x10FE).toDouble());
    ui->control_10FF->setValue(getParamValue_base_units(0x10FF).toDouble());
    ui->control_1100->setValue(getParamValue_base_units(0x1100).toDouble());
    ui->control_1101->setValue(getParamValue_base_units(0x1101).toDouble());

    ui->control_1102->setValue(getParamValue_base_units(0x1102).toDouble());
    ui->control_1103->setValue(getParamValue_base_units(0x1103).toDouble());
    ui->control_1104->setValue(getParamValue_base_units(0x1104).toDouble());
    ui->control_1105->setValue(getParamValue_base_units(0x1105).toDouble());
    ui->control_1106->setValue(getParamValue_base_units(0x1106).toDouble());
    ui->control_1107->setValue(getParamValue_base_units(0x1107).toDouble());

    read_languaje_and_units();
}

void settings::read_languaje_and_units(void)
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Lang");
    ui->combobox_idioma->setCurrentIndex(conf.value("App_text").toInt());
    conf.endGroup();

    conf.sync();
    conf.beginGroup("Units");
    ui->combobox_longitud->setCurrentIndex(conf.value("longitud").toInt());
    ui->combobox_presion->setCurrentIndex(conf.value("presion").toInt());
    ui->combobox_caudal->setCurrentIndex(conf.value("caudal").toInt());
    ui->combobox_tiempo->setCurrentIndex(conf.value("tiempo").toInt());
    conf.endGroup();

    // Read Demo mode
    conf.sync();
    conf.beginGroup("Demo");
    if(0 == conf.value("demo_mode").toInt())
    {
        ui->checkBox->setChecked(false);
    }
    else
    {
        ui->checkBox->setChecked(true);
    }
    conf.endGroup();

}

void settings::save_language_and_units(void)
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Lang");
    conf.setValue("App_text",ui->combobox_idioma->currentIndex());
    conf.endGroup();

    conf.sync();
    conf.beginGroup("Units");
    conf.setValue("longitud",ui->combobox_longitud->currentIndex());
    conf.setValue("presion",ui->combobox_presion->currentIndex());
    conf.setValue("caudal",ui->combobox_caudal->currentIndex());
    conf.setValue("tiempo",ui->combobox_tiempo->currentIndex());
    conf.endGroup();
}

void settings::on_borrar_DB_clicked()
{
    output_op_mode("1FFF", "1012");
    QTimer::singleShot(2000, this, SLOT(remove_db()));

}

void settings::on_pushButton_clicked()
{
    QProcess::execute("sudo reboot");
}

void settings::remove_db()
{
    QProcess::execute("sudo rm /home/pi/rutinas.db");
    output_op_mode("1FFF", "0");
}

void settings::on_checkBox_clicked()
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Demo");
    if(ui->checkBox->isChecked())
    {
        conf.setValue("demo_mode",1);
    }
    else
    {
        conf.setValue("demo_mode",0);
    }
    conf.endGroup();

    update_conf();

}

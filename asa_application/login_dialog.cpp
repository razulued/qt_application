#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "token_auth.h"
#include "asa_conf_string.h"
#include <QFont>
#include <QDebug>
#include <QLabel>
login_dialog::login_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_dialog)
{
    ui->setupUi(this);

    QFont font("Typo Square Ligth Demo",20,1);
//    ui->textedit->setFont(font);

    input_password = "";

//    ui->horizontalLayout->setSpacing(0);
//    ui->horizontalLayout->setMargin(0);
//    ui->horizontalLayout->setContentsMargins(30,30,30,30);

    this->setStyleSheet("background-color:black;"
                        "color:white"
                        );

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->move(parent->pos());
    this->show();
}

login_dialog::~login_dialog()
{
    delete ui;
}

void login_dialog::on_key_Q_clicked(){if(ui->key_mayus->isChecked()){input_password+="Q";}else{input_password+="q";}add_punto();}
void login_dialog::on_key_W_clicked(){if(ui->key_mayus->isChecked()){input_password+="W";}else{input_password+="w";}add_punto();}
void login_dialog::on_key_E_clicked(){if(ui->key_mayus->isChecked()){input_password+="E";}else{input_password+="e";}add_punto();}
void login_dialog::on_key_R_clicked(){if(ui->key_mayus->isChecked()){input_password+="R";}else{input_password+="r";}add_punto();}
void login_dialog::on_key_T_clicked(){if(ui->key_mayus->isChecked()){input_password+="T";}else{input_password+="t";}add_punto();}
void login_dialog::on_key_Y_clicked(){if(ui->key_mayus->isChecked()){input_password+="Y";}else{input_password+="y";}add_punto();}
void login_dialog::on_key_U_clicked(){if(ui->key_mayus->isChecked()){input_password+="U";}else{input_password+="u";}add_punto();}
void login_dialog::on_key_I_clicked(){if(ui->key_mayus->isChecked()){input_password+="I";}else{input_password+="i";}add_punto();}
void login_dialog::on_key_O_clicked(){if(ui->key_mayus->isChecked()){input_password+="O";}else{input_password+="o";}add_punto();}
void login_dialog::on_key_P_clicked(){if(ui->key_mayus->isChecked()){input_password+="P";}else{input_password+="p";}add_punto();}
void login_dialog::on_key_A_clicked(){if(ui->key_mayus->isChecked()){input_password+="A";}else{input_password+="a";}add_punto();}
void login_dialog::on_key_S_clicked(){if(ui->key_mayus->isChecked()){input_password+="S";}else{input_password+="s";}add_punto();}
void login_dialog::on_key_D_clicked(){if(ui->key_mayus->isChecked()){input_password+="D";}else{input_password+="d";}add_punto();}
void login_dialog::on_key_F_clicked(){if(ui->key_mayus->isChecked()){input_password+="F";}else{input_password+="f";}add_punto();}
void login_dialog::on_key_G_clicked(){if(ui->key_mayus->isChecked()){input_password+="G";}else{input_password+="g";}add_punto();}
void login_dialog::on_key_H_clicked(){if(ui->key_mayus->isChecked()){input_password+="H";}else{input_password+="h";}add_punto();}
void login_dialog::on_key_J_clicked(){if(ui->key_mayus->isChecked()){input_password+="J";}else{input_password+="j";}add_punto();}
void login_dialog::on_key_K_clicked(){if(ui->key_mayus->isChecked()){input_password+="K";}else{input_password+="k";}add_punto();}
void login_dialog::on_key_L_clicked(){if(ui->key_mayus->isChecked()){input_password+="L";}else{input_password+="l";}add_punto();}
void login_dialog::on_key_Z_clicked(){if(ui->key_mayus->isChecked()){input_password+="Z";}else{input_password+="z";}add_punto();}
void login_dialog::on_key_X_clicked(){if(ui->key_mayus->isChecked()){input_password+="X";}else{input_password+="x";}add_punto();}
void login_dialog::on_key_C_clicked(){if(ui->key_mayus->isChecked()){input_password+="C";}else{input_password+="c";}add_punto();}
void login_dialog::on_key_V_clicked(){if(ui->key_mayus->isChecked()){input_password+="V";}else{input_password+="v";}add_punto();}
void login_dialog::on_key_B_clicked(){if(ui->key_mayus->isChecked()){input_password+="B";}else{input_password+="b";}add_punto();}
void login_dialog::on_key_N_clicked(){if(ui->key_mayus->isChecked()){input_password+="N";}else{input_password+="n";}add_punto();}
void login_dialog::on_key_M_clicked(){if(ui->key_mayus->isChecked()){input_password+="M";}else{input_password+="m";}add_punto();}
void login_dialog::on_key_space_clicked(){input_password +=" ";add_punto();}


void login_dialog::on_key_0_clicked(){input_password +="0";add_punto();}
void login_dialog::on_key_1_clicked(){input_password +="1";add_punto();}
void login_dialog::on_key_2_clicked(){input_password +="2";add_punto();}
void login_dialog::on_key_3_clicked(){input_password +="3";add_punto();}
void login_dialog::on_key_4_clicked(){input_password +="4";add_punto();}
void login_dialog::on_key_5_clicked(){input_password +="5";add_punto();}
void login_dialog::on_key_6_clicked(){input_password +="6";add_punto();}
void login_dialog::on_key_7_clicked(){input_password +="7";add_punto();}
void login_dialog::on_key_8_clicked(){input_password +="8";add_punto();}
void login_dialog::on_key_9_clicked(){input_password +="9";add_punto();}

void login_dialog::on_key_enter_clicked()
{
    qDebug() << "Password is " << input_password;
    if(true == check_user_password(input_password))
    {
        synch_config_string();
        synch_output_state();

        validate_token(true);
    }
    else
    {
        validate_token(false);
//        ui->textedit->clear();
    }
    this->close();
}


void login_dialog::on_key_back_clicked()
{
    if(input_password.length() > 0)
    {
        input_password = input_password.left(input_password.length()-1);
    }

    if(input_password.length() >= 0)
    {
//        ui->horizontalLayout->removeItem(ui->horizontalLayout->itemAt(input_password.length()));
        QLayoutItem *item = ui->horizontalLayout->takeAt(input_password.length());

        if(item != 0)
        {
//            item->widget()->setParent(NULL);
//            delete item;
//            ui->horizontalLayout->removeItem(item);
            item->widget()->close();
            delete item;
        }
    }
    this->update();
}

void login_dialog::add_punto()
{
    QLabel *label = new QLabel();
    label->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Punto contrasena.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
//    label->setGeometry(label->x(),label->y(),40,40);

//    ui->horizontalLayout->setAlignment(Qt::AlignLeft);
    ui->horizontalLayout->addWidget(label);
}

void login_dialog::on_asa_logo_clicked()
{
    this->close();
}

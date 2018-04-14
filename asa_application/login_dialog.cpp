#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "token_auth.h"
#include <QFont>
login_dialog::login_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_dialog)
{
    ui->setupUi(this);

    QFont font("Typo Square Ligth Demo",20,1);
    ui->textedit->setFont(font);

    this->show();
}

login_dialog::~login_dialog()
{
    delete ui;
}

void login_dialog::on_key_0_clicked(){ui->textedit->insertPlainText("0");}
void login_dialog::on_key_1_clicked(){ui->textedit->insertPlainText("1");}
void login_dialog::on_key_2_clicked(){ui->textedit->insertPlainText("2");}
void login_dialog::on_key_3_clicked(){ui->textedit->insertPlainText("3");}
void login_dialog::on_key_4_clicked(){ui->textedit->insertPlainText("4");}
void login_dialog::on_key_5_clicked(){ui->textedit->insertPlainText("5");}
void login_dialog::on_key_6_clicked(){ui->textedit->insertPlainText("6");}
void login_dialog::on_key_7_clicked(){ui->textedit->insertPlainText("7");}
void login_dialog::on_key_8_clicked(){ui->textedit->insertPlainText("8");}
void login_dialog::on_key_9_clicked(){ui->textedit->insertPlainText("9");}

void login_dialog::on_key_enter_clicked()
{
    if(true == check_user_password(ui->textedit->toPlainText()))
    {
        validate_token(true);
        this->close();
    }
    else
    {
        validate_token(false);
        ui->textedit->clear();
    }
}

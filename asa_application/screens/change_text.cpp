#include "change_text.h"
#include "ui_change_text.h"

change_text::change_text(QString initial_text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_text)
{
    ui->setupUi(this);

    QFont font("Typo Square Ligth Demo",20,1);
//    ui->textedit->setFont(font);

    this->setStyleSheet("background-color:black;"
                        "color:white"
                        );

    ui->textEdit->setFont(font);
    ui->textEdit->setText(initial_text);
    ui->textEdit->moveCursor(QTextCursor::EndOfLine);

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->move(parent->pos());
    this->show();
}

change_text::~change_text()
{
    delete ui;
}

void change_text::on_key_0_clicked() {ui->textEdit->insertPlainText("0");}
void change_text::on_key_1_clicked() {ui->textEdit->insertPlainText("1");}
void change_text::on_key_2_clicked() {ui->textEdit->insertPlainText("2");}
void change_text::on_key_3_clicked() {ui->textEdit->insertPlainText("3");}
void change_text::on_key_4_clicked() {ui->textEdit->insertPlainText("4");}
void change_text::on_key_5_clicked() {ui->textEdit->insertPlainText("5");}
void change_text::on_key_6_clicked() {ui->textEdit->insertPlainText("6");}
void change_text::on_key_7_clicked() {ui->textEdit->insertPlainText("7");}
void change_text::on_key_8_clicked() {ui->textEdit->insertPlainText("8");}
void change_text::on_key_9_clicked() {ui->textEdit->insertPlainText("9");}

void change_text::on_key_Q_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("Q");}else{ui->textEdit->insertPlainText("q");}}
void change_text::on_key_W_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("W");}else{ui->textEdit->insertPlainText("w");}}
void change_text::on_key_E_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("E");}else{ui->textEdit->insertPlainText("e");}}
void change_text::on_key_R_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("R");}else{ui->textEdit->insertPlainText("r");}}
void change_text::on_key_T_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("T");}else{ui->textEdit->insertPlainText("t");}}
void change_text::on_key_Y_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("Y");}else{ui->textEdit->insertPlainText("y");}}
void change_text::on_key_U_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("U");}else{ui->textEdit->insertPlainText("u");}}
void change_text::on_key_I_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("I");}else{ui->textEdit->insertPlainText("i");}}
void change_text::on_key_O_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("O");}else{ui->textEdit->insertPlainText("o");}}
void change_text::on_key_P_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("P");}else{ui->textEdit->insertPlainText("p");}}
void change_text::on_key_A_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("A");}else{ui->textEdit->insertPlainText("a");}}
void change_text::on_key_S_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("S");}else{ui->textEdit->insertPlainText("s");}}
void change_text::on_key_D_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("D");}else{ui->textEdit->insertPlainText("d");}}
void change_text::on_key_F_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("F");}else{ui->textEdit->insertPlainText("f");}}
void change_text::on_key_G_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("G");}else{ui->textEdit->insertPlainText("g");}}
void change_text::on_key_H_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("H");}else{ui->textEdit->insertPlainText("h");}}
void change_text::on_key_J_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("J");}else{ui->textEdit->insertPlainText("j");}}
void change_text::on_key_K_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("K");}else{ui->textEdit->insertPlainText("k");}}
void change_text::on_key_L_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("L");}else{ui->textEdit->insertPlainText("l");}}
void change_text::on_key_Z_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("Z");}else{ui->textEdit->insertPlainText("z");}}
void change_text::on_key_X_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("X");}else{ui->textEdit->insertPlainText("x");}}
void change_text::on_key_C_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("C");}else{ui->textEdit->insertPlainText("c");}}
void change_text::on_key_V_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("V");}else{ui->textEdit->insertPlainText("v");}}
void change_text::on_key_B_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("B");}else{ui->textEdit->insertPlainText("b");}}
void change_text::on_key_N_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("N");}else{ui->textEdit->insertPlainText("n");}}
void change_text::on_key_M_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("M");}else{ui->textEdit->insertPlainText("m");}}
void change_text::on_key_comma_clicked(){ui->textEdit->insertPlainText(",");}
void change_text::on_key_space_clicked(){ui->textEdit->insertPlainText(" ");}
void change_text::on_key_dot_clicked(){ui->textEdit->insertPlainText(".");}
void change_text::on_key_plus_clicked(){ui->textEdit->insertPlainText("+");}
void change_text::on_key_minus_clicked(){ui->textEdit->insertPlainText("-");}
void change_text::on_key_slash_clicked(){ui->textEdit->insertPlainText("/");}
void change_text::on_key_back_clicked()
{
    ui->textEdit->textCursor().deletePreviousChar();
}

void change_text::on_key_enter_clicked()
{
    if("" != ui->textEdit->toPlainText())
    {
        update_text(ui->textEdit->toPlainText());
    }
    this->close();
}

void change_text::on_asa_logo_clicked()
{
    this->close();
}

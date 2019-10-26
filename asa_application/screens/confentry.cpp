#include "confentry.h"
#include "ui_confentry.h"

confentry::confentry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confentry)
{
    ui->setupUi(this);
    QDoubleValidator *int32decimalValidator = new QDoubleValidator(-214748.3647,-214748.3648,4);
    QDoubleValidator *raw32Validator = new QDoubleValidator(0,4294967295,0);


    ui->value_ID->setInputMask("HHHH");
    ui->value_minShow->setValidator(int32decimalValidator);
    ui->value_maxShow->setValidator(int32decimalValidator);
    ui->value_minRaw->setValidator(raw32Validator);
    ui->value_maxRaw->setValidator(raw32Validator);
    ui->value_DataSize->setValidator(raw32Validator);

    ui->value_const1->setValidator(int32decimalValidator);
    ui->value_const2->setValidator(int32decimalValidator);
    ui->value_const3->setValidator(int32decimalValidator);


    ui->value_ID->clear();

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    this->show();
}

confentry::~confentry()
{
    delete ui;
}

void confentry::set_Values(QStringList values)
{   
    int i = 0;
    ui->value_ID->setText(values.at(i++));
    ui->value_Name->setText(values.at(i++));
    ui->value_Type->setCurrentIndex(ui->value_Type->findText(values.at(i++)));
    ui->value_Units->setText(values.at(i++));

    ui->value_minShow->setText(values.at(i++));
    ui->value_maxShow->setText(values.at(i++));
    ui->value_minRaw->setText(values.at(i++));
    ui->value_maxRaw->setText(values.at(i++));
    ui->value_DataSize->setText(values.at(i++));

    ui->value_CalcType->setCurrentIndex(ui->value_Type->findText(values.at(i++)));
    ui->value_const1->setText(values.at(i++));
    ui->value_const2->setText(values.at(i++));
    ui->value_const3->setText(values.at(i++));
}

QString confentry::get_Name(){return ui->value_Name->text();}
QString confentry::get_ID(){return ui->value_ID->text();}
QString confentry::get_Type(){return ui->value_Type->currentText();}
QString confentry::get_Units(){return ui->value_Units->text();}

/* Function to return updated or new values*/
QStringList confentry::get_AllValues()
{
    QStringList ret;

    ret.append(get_ID());
    ret.append(get_Name());
    ret.append(get_Type());
    ret.append(get_Units());

    ret.append(ui->value_minShow->text());
    ret.append(ui->value_maxShow->text());
    ret.append(ui->value_minRaw->text());
    ret.append(ui->value_maxRaw->text());
    ret.append(ui->value_DataSize->text());

    ret.append(ui->value_CalcType->currentText());
    ret.append(ui->value_const1->text());
    ret.append(ui->value_const2->text());
    ret.append(ui->value_const3->text());
    return ret;
}

void confentry::on_key_0_clicked() {keyboard_handler("0");}
void confentry::on_key_1_clicked() {keyboard_handler("1");}
void confentry::on_key_2_clicked() {keyboard_handler("2");}
void confentry::on_key_3_clicked() {keyboard_handler("3");}
void confentry::on_key_4_clicked() {keyboard_handler("4");}
void confentry::on_key_5_clicked() {keyboard_handler("5");}
void confentry::on_key_6_clicked() {keyboard_handler("6");}
void confentry::on_key_7_clicked() {keyboard_handler("7");}
void confentry::on_key_8_clicked() {keyboard_handler("8");}
void confentry::on_key_9_clicked() {keyboard_handler("9");}
void confentry::on_key_Q_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Q");}else{keyboard_handler("q");}}
void confentry::on_key_W_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("W");}else{keyboard_handler("w");}}
void confentry::on_key_E_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("E");}else{keyboard_handler("e");}}
void confentry::on_key_R_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("R");}else{keyboard_handler("r");}}
void confentry::on_key_T_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("T");}else{keyboard_handler("t");}}
void confentry::on_key_Y_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Y");}else{keyboard_handler("y");}}
void confentry::on_key_U_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("U");}else{keyboard_handler("u");}}
void confentry::on_key_I_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("I");}else{keyboard_handler("i");}}
void confentry::on_key_O_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("O");}else{keyboard_handler("o");}}
void confentry::on_key_P_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("P");}else{keyboard_handler("p");}}
void confentry::on_key_A_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("A");}else{keyboard_handler("a");}}
void confentry::on_key_S_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("S");}else{keyboard_handler("s");}}
void confentry::on_key_D_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("D");}else{keyboard_handler("d");}}
void confentry::on_key_F_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("F");}else{keyboard_handler("f");}}
void confentry::on_key_G_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("G");}else{keyboard_handler("g");}}
void confentry::on_key_H_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("H");}else{keyboard_handler("h");}}
void confentry::on_key_J_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("J");}else{keyboard_handler("j");}}
void confentry::on_key_K_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("K");}else{keyboard_handler("k");}}
void confentry::on_key_L_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("L");}else{keyboard_handler("l");}}
void confentry::on_key_Z_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Z");}else{keyboard_handler("z");}}
void confentry::on_key_X_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("X");}else{keyboard_handler("x");}}
void confentry::on_key_C_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("C");}else{keyboard_handler("c");}}
void confentry::on_key_V_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("V");}else{keyboard_handler("v");}}
void confentry::on_key_B_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("B");}else{keyboard_handler("b");}}
void confentry::on_key_N_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("N");}else{keyboard_handler("n");}}
void confentry::on_key_M_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("M");}else{keyboard_handler("m");}}

void confentry::on_key_equal_clicked() {keyboard_handler("=");}
void confentry::on_key_space_clicked() {keyboard_handler(" ");}
void confentry::on_key_L_corchete_clicked() {keyboard_handler("[");}
void confentry::on_key_R_corchete_clicked() {keyboard_handler("]");}
void confentry::on_key_comma_clicked() {keyboard_handler(",");}
void confentry::on_key_dot_clicked() {keyboard_handler(".");}
void confentry::on_key_slash_clicked() {keyboard_handler("/");}
void confentry::on_key_minus_clicked() {keyboard_handler("-");}
void confentry::on_key_plus_clicked() {keyboard_handler("+");}

void confentry::on_key_back_clicked()
{
    keyboard_handler("back");
}
void confentry::on_key_enter_clicked() {this->focusNextChild();/*keyboard_handler("\n");*/}

void confentry::keyboard_handler(QString key)
{
    QWidget * fw = QApplication::focusWidget();

    QString object = fw->metaObject()->className();
    if(object == "QDoubleSpinBox")
    {
        bool ok;
        //QDoubleSpinBox* spin_ptr = (QDoubleSpinBox*)fw;
        //double num = key.toDouble(&ok);

        if(ok)
        {
            //spin_ptr->setValue((spin_ptr->value()*10)+num);
        }
        else
        {
            //spin_ptr->setValue(0);
        }
    }
    else if(object ==  "QLineEdit")
    {
        QLineEdit *text_ptr = (QLineEdit *)fw;
        if(key == "back")
        {
            text_ptr->backspace();
//            text_ptr->textCursor().deletePreviousChar();
        }
        else
        {
            text_ptr->insert(key);
//            text_ptr->insertPlainText(key);
        }
    }
}

void confentry::on_closeButton_clicked()
{
    this->reject();
}

void confentry::on_acceptButton_clicked()
{
    this->accept();
}

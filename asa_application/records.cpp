#include "records.h"
#include "ui_records.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QFileInfo>
#include <QLabel>
#include "clickeablelabel.h"
#include <QTextEdit>
#include <QRadioButton>
#include <QSignalMapper>

records::records(const QString &path, uint record_id, uint from_id, uint time, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::records)
{
    ui->setupUi(this);
    current_type = NO_TYPE_SELECTED;

    db_path = path;

    if(!QSqlDatabase::isDriverAvailable("QSQLITE"))
    {
        qDebug() << "Driver not available";
    }
    else
    {
        if((true == QFileInfo(db_path).exists()) && (QFileInfo(db_path).isFile()))
        {
            qDebug() << "Ya existe la DB";
            QSqlQuery q;
            if(!q.prepare("SELECT * FROM rutinas WHERE id = :id_found")) qDebug() << "Failed to prepare";
            q.bindValue(":id_found",from_id);
            if(!q.exec()) qDebug() << "Failed to execute: records";

            while (q.next())
            {
                qDebug() << q.value("id").toInt();
                qDebug() << q.value("nombre").toString();
                qDebug() << q.value("periodo").toInt();
                qDebug() << q.value("origen").toInt();
                qDebug() << q.value("next_event").toInt();

                log__rutina_id = q.value("id").toInt();
                log__date = time;
                log__rutina_text = q.value("nombre").toString();
            }

        }
        else
        {
            m_db = QSqlDatabase::addDatabase("QSQLITE");
            m_db.setDatabaseName(db_path);

            if (!m_db.open())
            {
               qDebug() << "Error: connection with database fail";
            }
            else
            {
               qDebug() << "Database: connection ok";
            }

            qDebug() << "ALV NO HAY TABLA";
        }


        this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
        this->setAttribute(Qt::WA_TranslucentBackground);

//        ui->frame->setStyleSheet("border-style: solid;"
//                                 "border-color: gray;"
//                                 "border-width: 3px;"
//                                 "border-radius: 15px;"
//                                 "background-color: black");

        clickeablelabel *alphabackground = new clickeablelabel(this);
        alphabackground->setGeometry(this->geometry());
        alphabackground->setStyleSheet("background-color: rgb(0,0,0,180);");
        alphabackground->lower();
        format_everything();

        load_to_table(record_id);

        if(parent != NULL)
        {
            this->move(parent->pos());
        }
        this->show();
    }
}

records::~records()
{
    delete ui;
}

void records::load_to_table(uint id)
{
    qDebug() << "****RECORDS**** " << id;
    QSqlQuery q;

    //SELECT body FROM tbl_index WHERE id = 937
    if(!q.prepare("SELECT * FROM records WHERE id = :id_found"))
    {
        qDebug() << "Failed to prepare";
    }
    else
    {
        q.bindValue(":id_found",id);

        if(!q.exec())
        {
            qDebug() << "Failed to execute: records load_to_table()";
        }
        else
        {
            while (q.next())
            {
                qDebug() << q.value("id").toInt();
                qDebug() << q.value("name").toString();
                qDebug() << q.value("type").toString();
                qDebug() << q.value("field_1").toString();
                qDebug() << q.value("field_2").toString();
                qDebug() << q.value("field_3").toString();

                log__record_id = q.value("id").toInt();
                log__record_text = q.value("name").toString();

                if(q.value("type").toString() == "NUMBER")
                {
                    input_numeric(q.value("name").toString(), q.value("field_1").toString());
                }
                else if(q.value("type").toString() == "CHOICE")
                {
                    input_choice(q.value("name").toString(),
                                       q.value("field_1").toString(),
                                       q.value("field_2").toString(),
                                       q.value("field_3").toString());
                }

            }
            qDebug() << "****RECORDS DONE**** ";
        }
    }

}

void records::input_numeric(QString name, QString units)
{
    current_type = TYPE_NUMERIC;

    ui->opt_text_name_label->setText(name);
    ui->opt_text_units_label->setText(units);
    ui->tabWidget->setCurrentIndex(0);
}

void records::input_choice(QString name, QString opt_1, QString opt_2, QString opt_3 )
{
    QFont font("Typo Square Bold Demo",16,1);

    current_type = TYPE_CHOICE;
    QRadioButton *choice;
    QSignalMapper *out_choiceMapper = new QSignalMapper(this);

    ui->opt_ch_name_label->setText(name);

    if(opt_1 != "")
    {
        choice = new QRadioButton(opt_1);
        choice->setStyleSheet("QRadioButton{"
                                          "color: white;"
                                          "font-size: 18px;"
                                          "}"
                                          "QRadioButton::indicator{"
                                          "width: 50px;"
                                          "height: 50px;"
                                        "}"
                            );
        choice->setFont(font);
        choice->setFocusPolicy(Qt::NoFocus);

        ui->horizontalLayout->addWidget(choice);
        connect(choice, SIGNAL(clicked(bool)), out_choiceMapper, SLOT(map()));
        out_choiceMapper->setMapping(choice, 1);

    }
    if(opt_2 != "")
    {
        choice = new QRadioButton(opt_2);
        choice->setStyleSheet("QRadioButton{"
                                          "color: white;"
                                          "font-size: 18px;"
                                          "}"
                                          "QRadioButton::indicator{"
                                          "width: 50px;"
                                          "height: 50px;"
                                        "}"
                            );
        choice->setFont(font);
        choice->setFocusPolicy(Qt::NoFocus);

        ui->horizontalLayout->addWidget(choice);
        connect(choice, SIGNAL(clicked(bool)), out_choiceMapper, SLOT(map()));
        out_choiceMapper->setMapping(choice, 2);
    }
    if(opt_3 != "")
    {
        choice = new QRadioButton(opt_3);
        choice->setStyleSheet("QRadioButton{"
                                          "color: white;"
                                          "font-size: 18px;"
                                          "}"
                                          "QRadioButton::indicator{"
                                          "width: 50px;"
                                          "height: 50px;"
                                        "}"
                            );
        choice->setFont(font);
        choice->setFocusPolicy(Qt::NoFocus);

        ui->horizontalLayout->addWidget(choice);
        connect(choice, SIGNAL(clicked(bool)), out_choiceMapper, SLOT(map()));
        out_choiceMapper->setMapping(choice, 3);
    }

    // Connect all radiobutons to mapper
    connect(out_choiceMapper, SIGNAL(mapped(int)), this, SLOT(out_RadioButtonChanged(int)));
    ui->tabWidget->setCurrentIndex(1);
}

void records::save_record_to_log()
{
    QSqlQuery q;
    qDebug() << "log__date: " << log__date;
    qDebug() <<  "log__rutina_id: " << log__rutina_id;
    qDebug() << "log__rutina_text: " << log__rutina_text;
    qDebug() << "log__record_id: " << log__record_id;
    qDebug() << "log__record_text: " << log__record_text;
    qDebug() << "log__record_value: " << log__record_value;

    q.prepare("INSERT INTO log(log_date, rutina_id, rutina_name, record_id, record_name, record_value) "
              "VALUES(:log_date, :rutina_id, :rutina_name, :record_id, :record_name, :record_value)");
    q.bindValue(":log_date",log__date);
    q.bindValue(":rutina_id",log__rutina_id);
    q.bindValue(":rutina_name",log__rutina_text);
    q.bindValue(":record_id",log__record_id);
    q.bindValue(":record_name",log__record_text);
    q.bindValue(":record_value",log__record_value);
    if(!q.exec())
    {
        qDebug() << q.lastError().text();
    }
}

void records::on_key_0_clicked() {keyboard_handler("0");}
void records::on_key_1_clicked() {keyboard_handler("1");}
void records::on_key_2_clicked() {keyboard_handler("2");}
void records::on_key_3_clicked() {keyboard_handler("3");}
void records::on_key_4_clicked() {keyboard_handler("4");}
void records::on_key_5_clicked() {keyboard_handler("5");}
void records::on_key_6_clicked() {keyboard_handler("6");}
void records::on_key_7_clicked() {keyboard_handler("7");}
void records::on_key_8_clicked() {keyboard_handler("8");}
void records::on_key_9_clicked() {keyboard_handler("9");}
void records::on_key_Q_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Q");}else{keyboard_handler("q");}}
void records::on_key_W_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("W");}else{keyboard_handler("w");}}
void records::on_key_E_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("E");}else{keyboard_handler("e");}}
void records::on_key_R_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("R");}else{keyboard_handler("r");}}
void records::on_key_T_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("T");}else{keyboard_handler("t");}}
void records::on_key_Y_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Y");}else{keyboard_handler("y");}}
void records::on_key_U_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("U");}else{keyboard_handler("u");}}
void records::on_key_I_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("I");}else{keyboard_handler("i");}}
void records::on_key_O_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("O");}else{keyboard_handler("o");}}
void records::on_key_P_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("P");}else{keyboard_handler("p");}}
void records::on_key_A_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("A");}else{keyboard_handler("a");}}
void records::on_key_S_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("S");}else{keyboard_handler("s");}}
void records::on_key_D_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("D");}else{keyboard_handler("d");}}
void records::on_key_F_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("F");}else{keyboard_handler("f");}}
void records::on_key_G_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("G");}else{keyboard_handler("g");}}
void records::on_key_H_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("H");}else{keyboard_handler("h");}}
void records::on_key_J_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("J");}else{keyboard_handler("j");}}
void records::on_key_K_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("K");}else{keyboard_handler("k");}}
void records::on_key_L_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("L");}else{keyboard_handler("l");}}
void records::on_key_Z_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("Z");}else{keyboard_handler("z");}}
void records::on_key_X_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("X");}else{keyboard_handler("x");}}
void records::on_key_C_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("C");}else{keyboard_handler("c");}}
void records::on_key_V_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("V");}else{keyboard_handler("v");}}
void records::on_key_B_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("B");}else{keyboard_handler("b");}}
void records::on_key_N_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("N");}else{keyboard_handler("n");}}
void records::on_key_M_clicked(){if(ui->key_mayus->isChecked()){keyboard_handler("M");}else{keyboard_handler("m");}}

void records::on_key_equal_clicked() {keyboard_handler("=");}
void records::on_key_space_clicked() {keyboard_handler(" ");}
void records::on_key_L_corchete_clicked() {keyboard_handler("[");}
void records::on_key_R_corchete_clicked() {keyboard_handler("]");}
void records::on_key_comma_clicked() {keyboard_handler(",");}
void records::on_key_dot_clicked() {keyboard_handler(".");}
void records::on_key_slash_clicked() {keyboard_handler("/");}
void records::on_key_minus_clicked() {keyboard_handler("-");}
void records::on_key_plus_clicked() {keyboard_handler("+");}

void records::on_key_back_clicked()
{
    keyboard_handler("back");
}
void records::on_key_enter_clicked() {keyboard_handler("\n");}

void records::keyboard_handler(QString key)
{
    QWidget * fw = QApplication::focusWidget();

    QString object = fw->metaObject()->className();
    if(object ==  "QTextEdit")
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

void records::on_pushButton_clicked()
{
    log__record_value = ui->opt_text_textEdit->toPlainText().toFloat();
    save_record_to_log();
    this->close();
}

void records::out_RadioButtonChanged(int opt)
{
    qDebug() << "VALUE CHANGED " << opt;
    log__record_value = (float)opt;
}

void records::format_everything()
{
    QFont font("Typo Square Bold Demo",10,1);

    ui->tab->setStyleSheet("background:black");
    ui->tab_2->setStyleSheet("background:black");

    ui->opt_text_name_label->setFont(font);
    ui->opt_text_name_label->setStyleSheet("background-color: none;"
                                  "color: rgb(0, 167, 250);"
                                  "border: none;"
                                  "font-size: 20px;");


    ui->opt_text_textEdit->setFocus();
    ui->opt_text_textEdit->setFont(font);
    ui->opt_text_textEdit->setStyleSheet("background-color: transparent;"
                                         "color: black;"
                                         "font-size: 18px;");

    ui->opt_text_units_label->setFont(font);
    ui->opt_text_units_label->setStyleSheet("background-color: transparent;"
                                  "color: black;"
                                  "border: none;"
                                  "font-size: 14px;");

    ui->opt_ch_name_label->setStyleSheet(ui->opt_text_name_label->styleSheet());
//    ui->opt_yn_radioButton->setStyleSheet("QRadioButton{"
//                                          "color: white;"
//                                          "font-size: 18px;"
//                                          "}"
//                                          "QRadioButton::indicator{"
//                                          "width: 50px;"
//                                          "height: 500px;"
//                                          "}");

//    ui->opt_ynradioButton_2->setStyleSheet(ui->opt_yn_radioButton->styleSheet());

}

void records::on_pushButton_2_clicked()
{
    save_record_to_log();
    this->close();
}

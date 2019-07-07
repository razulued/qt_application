#ifndef CONFSETUP_H
#define CONFSETUP_H

#include <QDialog>
#include <QList>
#include <QStringList>
#include <QRadioButton>

namespace Ui {
class confsetup;
}

class confsetup : public QDialog
{
    Q_OBJECT

public:
    explicit confsetup(QWidget *parent = 0);
    ~confsetup();

private slots:
    void on_add_pushButton_clicked();

    void on_edit_pushButton_clicked();

    void on_remove_pushButton_clicked();

    void dir_RadioButtonChanged(int opt);

    void on_save_changes_pushButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::confsetup *ui;

    uint actual_dir_number = 0xFF;
    QStringList list_dir;

    void updateDirList(void);
    void updateTableFromFile(int dir);
};

#endif // CONFSETUP_H

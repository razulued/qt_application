#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QFile>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

    void sync_regulador_IDs(void);


private slots:
    void on_settings_accepted();
    void on_settings_rejected();

private:
    Ui::settings *ui;
    QFile *config_file;

};

void saveSettings(const QString &group, const QString &key, const QVariant &value);
#endif // SETTINGS_H

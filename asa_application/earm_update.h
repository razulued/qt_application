#ifndef EARM_UPDATE_H
#define EARM_UPDATE_H

#include <QDialog>

namespace Ui {
class earm_update;
}

class earm_update : public QDialog
{
    Q_OBJECT

public:
    explicit earm_update(QWidget *parent = 0);
    ~earm_update();
    void update_data();
private slots:
    void background_clicked();
private:
    Ui::earm_update *ui;

signals:
    void release_lock();
};

#endif // EARM_UPDATE_H

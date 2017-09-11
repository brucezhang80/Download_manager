#ifndef DOWNLOADITEM_H
#define DOWNLOADITEM_H

#include <QWidget>
#include <QPixmap>
#include "download_ctrl.h"

namespace Ui {
class downloaditem;
}

class downloaditem : public QWidget
{
    Q_OBJECT

public:
    explicit downloaditem(QWidget *parent = 0, QString url = "https://www.google.com", QString folder = "C:/");
    void setText(QString string);
    void setValue(int i);
    ~downloaditem();
private slots:
    void on_pause_btn_clicked();
    void on_remove_btn_clicked();
signals:
    void removeMe();
private:
    QString url;
    QString folder;
    QString filename;
    Ui::downloaditem *ui;
    bool paused;

};

#endif // DOWNLOADITEM_H

#ifndef DOWNLOADITEM_H
#define DOWNLOADITEM_H

#include <QWidget>

namespace Ui {
class downloaditem;
}

class downloaditem : public QWidget
{
    Q_OBJECT

public:
    explicit downloaditem(QWidget *parent = 0);
    void setText(QString string);
    void setValue(int i);
    ~downloaditem();
private slots:
    void on_pause_btn_clicked();
    void on_remove_btn_clicked();
signals:
    void removeMe();
private:
    Ui::downloaditem *ui;
    bool paused;

};

#endif // DOWNLOADITEM_H

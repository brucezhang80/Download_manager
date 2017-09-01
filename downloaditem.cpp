#include "downloaditem.h"
#include "ui_downloaditem.h"
#include "QPixmap"

downloaditem::downloaditem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloaditem)
{
    ui->setupUi(this);
    paused = false;
}

void downloaditem::setText(QString string){
    ui->textBrowser->setText(string);
}

void downloaditem::setValue(int i){
    ui->progressBar->setValue(i);
}
void downloaditem::on_pause_btn_clicked(){
    if (!paused){
        ui->pause_btn->setIcon(QIcon(QPixmap(":/Resources/play.png")));
        paused = !paused;
    }
    else {
        ui->pause_btn->setIcon(QIcon(QPixmap(":/Resources/pause.png")));
        paused = !paused;
    }
}
void downloaditem::on_remove_btn_clicked(){
    qDebug("DELET THIS");
}
downloaditem::~downloaditem()
{
    delete ui;
}

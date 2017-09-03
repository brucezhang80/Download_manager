#include "downloaditem.h"
#include "ui_downloaditem.h"
#include "QPixmap"



downloaditem::downloaditem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloaditem)
{
    ui->setupUi(this);
    connect(this, SIGNAL(removeMe()), this->parent(), SLOT(removePressed()));
    paused = false;
}

void downloaditem::setText(QString string){
    ui->file->setText(string);
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
    emit removeMe();
}
downloaditem::~downloaditem()
{
    delete ui;
}

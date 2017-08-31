#include "downloaditem.h"
#include "ui_downloaditem.h"
#include "QPixmap"

downloaditem::downloaditem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloaditem)
{
    ui->setupUi(this);
}

void downloaditem::setText(QString string){
    ui->textBrowser->setText(string);
}

void downloaditem::setValue(int i){
    ui->progressBar->setValue(i);
}

downloaditem::~downloaditem()
{
    delete ui;
}

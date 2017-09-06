#include "downloaditem.h"
#include "ui_downloaditem.h"

downloaditem::downloaditem(QWidget *parent, QString s_url, QString s_folder) :
    QWidget(parent),
    url(s_url),
    folder(s_folder),
    ui(new Ui::downloaditem)
{
    ui->setupUi(this);
    connect(this, SIGNAL(removeMe()), this->parent(), SLOT(removePressed()));
    paused = false;

    QStringList url_list = url.split('/');
    filename = url_list.at(url_list.count()-1);
    ui->file->setText(filename);
    download_ctrl *control = new download_ctrl(this, url, folder, filename);

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

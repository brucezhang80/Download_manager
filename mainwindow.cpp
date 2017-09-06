#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFileDialog>
#include "downloaditem.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(QSize(585, 305));
    ui->setupUi(this);
    this->set_folder(QString("C:/"));
    ui->location->setText(folder);
}
void MainWindow::on_url_returnPressed(){
    on_download_btn_clicked();
}
void MainWindow::on_download_btn_clicked(){
    QString url = (ui->url->text());
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    downloaditem *d_item = new downloaditem(this, url, folder);
    item->setSizeHint(QSize(0, 70));
    ui->listWidget->setItemWidget(item,d_item);
    qDebug("%s", qPrintable(ui->url->displayText()));
}
void MainWindow::on_folder_sel_clicked(){
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    set_folder(dir);
    ui->location->setText(dir);
}

void MainWindow::removePressed(){
    QObject* signalSender = QObject::sender();
    downloaditem* p = qobject_cast<downloaditem *>(signalSender);
    if (p == NULL){
        qDebug("Sender NULL");
        return;
    }
    for (int i = 0; i < ui->listWidget->count(); i++){
        QListWidgetItem* item = ui->listWidget->item(i);
            if (ui->listWidget->itemWidget(item) == p){
                ui->listWidget->takeItem(i);
            }
    }
}
void MainWindow::set_folder(QString dir){
    folder = dir;
}

QString MainWindow::get_folder(){
    return folder;
}

MainWindow::~MainWindow()
{
    delete ui;
}

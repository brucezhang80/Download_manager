#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFileDialog>
#include "downloaditem.h"
//Network
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSslError>
#include <QStringList>
#include <QTimer>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(QSize(585, 305));
    ui->setupUi(this);
    ui->url->setText("https://www.google.com");
    ui->location->setText("C:/");
    /*Download try outs
    QUrl url = QString("https://www.google.com");
    QNetworkAccessManager *manager;
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);
    qDebug(QUrl(reply->url()).toEncoded(QUrl::FullyEncoded));
    */

    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    downloaditem *myWidget = new downloaditem(this);
    item->setSizeHint(QSize(0, 70));
    ui->listWidget->setItemWidget(item, myWidget);

    QListWidgetItem *item2 = new QListWidgetItem(ui->listWidget);
    item2->setSizeHint(QSize(0, 70));
    downloaditem *myWidget2 = new downloaditem(this);
    myWidget2->setText("TeamSpeak3-Client-win64-3.1.4");
    myWidget2->setValue(80);
    ui->listWidget->setItemWidget(item2, myWidget2);

}
void MainWindow::on_download_btn_clicked(){
    QString url = (ui->url->text());

    qDebug("%s", qPrintable(ui->url->displayText()));
}
void MainWindow::on_folder_sel_clicked(){
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug(qPrintable(dir));
    ui->location->setText(dir);
}
void MainWindow::on_url_returnPressed(){
    on_download_btn_clicked();
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

MainWindow::~MainWindow()
{
    delete ui;
}

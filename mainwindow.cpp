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

    ui->url->setText("https://www.google.com");
    ui->location->setText("C:/");

    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    downloaditem *myWidget = new downloaditem();
    item->setSizeHint(QSize(0, 70));
    ui->listWidget->setItemWidget(item, myWidget);

    QListWidgetItem *item2 = new QListWidgetItem(ui->listWidget);
    item2->setSizeHint(QSize(0, 70));
    downloaditem *myWidget2 = new downloaditem();
    myWidget2->setText("TeamSpeak3-Client-win64-3.1.4");
    myWidget2->setValue(80);
    ui->listWidget->setItemWidget(item2, myWidget2);

}
void MainWindow::on_pushButton_clicked(){
    qDebug("%s", qPrintable(ui->url->toPlainText()));
}
void MainWindow::on_folder_sel_clicked(){
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug(qPrintable(dir));
    ui->location->setText(dir);
}
MainWindow::~MainWindow()
{
    delete ui;
}

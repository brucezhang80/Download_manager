#include "download_ctrl.h"
#include <QCoreApplication>


download_ctrl::download_ctrl(QObject *parent, QString s_url, QString s_folder, QString s_filename) : QObject(parent),
    url(s_url), folder(s_folder), filename(s_filename)
{
    manager = new QNetworkAccessManager;
    download_ctrl::setFile();
}

download_ctrl::~download_ctrl(){
    manager->deleteLater();
}

void download_ctrl::setFile(){
    QDir dir;
    if(dir.exists(folder)){
        qDebug() << "Folder exists";
    }
    else{
        dir.mkdir(folder);
        qDebug() << "Folder created";
    }
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    reply = manager->get(request);
    qDebug() << reply->readAll();
    delete reply;
}

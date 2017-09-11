#include "download_ctrl.h"
#include <QCoreApplication>


download_ctrl::download_ctrl(QObject *parent, QString s_url, QString s_folder, QString s_filename) :
    QObject(parent),
    url(s_url),
    folder(s_folder),
    filename(s_filename)
{
    manager = new QNetworkAccessManager(this);
    startDownload();
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
}

void download_ctrl::startDownload()
{
    file.setFileName(QString("D:/test.txt"));
    if(!file.open(QIODevice::ReadWrite)){
        fprintf(stderr, "Problem opening save file '%s' for download '%s': %s\n",
                filename.toLatin1().data(),
                url.toLatin1().data(),
                qPrintable(file.errorString()));
        return;
    }
    QUrl q_url = QUrl(url);
    QNetworkRequest request(q_url);
    reply = manager->get(request);
    qDebug("Downloading %s", url.toLatin1().data());
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            SLOT(downloadProgress(qint64,qint64)));
    connect(reply, SIGNAL(finished()),
            SLOT(downloadFinished()));
    connect(reply, SIGNAL(readyRead()),
            SLOT(downloadReadyRead()));
    QTextStream stream(&file);
    stream << "ASDF" << endl;
}

void download_ctrl::downloadProgress(qint64 bytesReceiveed, qint64 bytesTotal)
{

}

void download_ctrl::downloadFinished()
{
    file.close();
}

void download_ctrl::downloadReadyRead()
{
  file.write(reply->readAll());
}

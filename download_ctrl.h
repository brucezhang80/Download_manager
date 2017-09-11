#ifndef DOWNLOAD_CTRL_H
#define DOWNLOAD_CTRL_H

#include <QFile>
#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QDir>
#include <QDebug>

class download_ctrl : public QObject
{
    Q_OBJECT
public:
    explicit download_ctrl(QObject *parent = nullptr, QString url = nullptr, QString folder = nullptr, QString filename = nullptr);
    virtual ~download_ctrl();
signals:
    void finished();
private:
    void setFile();
    QString url;
    QString folder;
    QString filename;

    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile file;

private slots:
    void startDownload();
    void downloadProgress(qint64 bytesReceiveed, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();

};

#endif // DOWNLOAD_CTRL_H

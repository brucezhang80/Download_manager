#ifndef DOWNLOAD_CTRL_H
#define DOWNLOAD_CTRL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
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

private:
    void setFile();
    QString url;
    QString folder;
    QString filename;

    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;

public slots:
};

#endif // DOWNLOAD_CTRL_H

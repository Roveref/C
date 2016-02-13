#ifndef WEBCRAWLER_H
#define WEBCRAWLER_H

#include <QDebug>

class WebCrawler : public QObject
{

    Q_OBJECT

public:
    WebCrawler(const QString &websiteAddress);
    ~WebCrawler();

public slots:
    int process();

signals:
    void finished();

private:
    QString m_websiteAddress;
    QString m_systemCommand;

};

#endif // WEBCRAWLER_H

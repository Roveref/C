#include "ParallelThread.h"

ParallelThread::ParallelThread()
{
}

ParallelThread::ParallelThread(TestFunction* testFunction)
{
    testFunction->moveToThread(this);
    QObject::connect(this, SIGNAL(started()), testFunction, SLOT(process()));
    QObject::connect(testFunction, SIGNAL(finished()), this, SLOT(quit()));
    QObject::connect(testFunction, SIGNAL(finished()), testFunction, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    this->start();
}

ParallelThread::ParallelThread(WebCrawler* webCrawler)
{
    webCrawler->moveToThread(this);
    QObject::connect(this, SIGNAL(started()), webCrawler, SLOT(process()));
    QObject::connect(webCrawler, SIGNAL(finished()), this, SLOT(quit()));
    QObject::connect(webCrawler, SIGNAL(finished()), webCrawler, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    this->start();
}

ParallelThread::ParallelThread(TextExtraction* textExtraction)
{
    textExtraction->moveToThread(this);
    QObject::connect(this, SIGNAL(started()), textExtraction, SLOT(process()));
    QObject::connect(textExtraction, SIGNAL(finished()), this, SLOT(quit()));
    QObject::connect(textExtraction, SIGNAL(finished()), textExtraction, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    this->start();
}


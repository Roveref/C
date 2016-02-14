#ifndef PARALLELCONCURRENT_H
#define PARALLELCONCURRENT_H

/*!
 * \file ParallelConcurrent.h
 * \author Rovere Francois
 * \version 0.1
 */

#include <QFile>
#include <QElapsedTimer>
#include <QFutureWatcher>
#include <qtconcurrentrun.h>
#include <TestFunction.h>
#include <TextExtraction.h>
#include <WebCrawler.h>

/*! \class ParallelConcurrent
 * \brief Creating of a Concurrent for a process given in attribute
 *  This class allows to create parallel computation to improve efficiency
 */
class ParallelConcurrent : public QObject
{

    Q_OBJECT

public:
    /*!
     *  \brief Constructor 1
     */
    ParallelConcurrent();

    /*!
     *  \brief Constructor 2
     *  This Constructor launches Concurrents on the testFunction
     *  \param numberConcurrent : The number of concurrents to launch
     */
    ParallelConcurrent(const int &numberConcurrent);

    ParallelConcurrent(const int &choiceSelection, const QString &websiteAddress = "");

    ParallelConcurrent(const QString &websiteAddress);


private:
    QFuture<void> future;
    QFutureWatcher<void> m_watcher;
    TestFunction* m_testFunction;
    TextExtraction* m_textExtraction;
    WebCrawler* m_webCrawler;
};

#endif // PARALLELCONCURRENT_H

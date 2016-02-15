#ifndef PARALLELCONCURRENT_H
#define PARALLELCONCURRENT_H

/*!
 * \file ParallelConcurrent.h
 * \author Rovere Francois
 * \version 0.3
 */

#include <QFile>
#include <QElapsedTimer>
#include <QFutureWatcher>
#include <TextExtraction.h>
#include <TestFunction.h>
#include <WebCrawler.h>
#include <qtconcurrentrun.h>

/*! \class ParallelConcurrent
 * \brief - Creation of a Concurrent for a process given in attribute.
 *  - This class allows to create parallel computation to improve efficiency.
 */
class ParallelConcurrent : public QObject
{

    Q_OBJECT

public:
    /*!
     *  \brief
     *  This Constructor is empty.
     */
    ParallelConcurrent();

    /*!
     *  \brief
     *  This Constructor :
     *  - launches Concurrents on the testFunction.
     *  \param numberConcurrent1 : A first batch of concurrents to launch.
     *  \param numberConcurrent2 : A second batch of concurrents to launch.
     */
    ParallelConcurrent(const int &numberConcurrent1, const int &numberConcurrent2);

    /*!
     *  \brief
     *  This Constructor :
     *  - launches one Concurrent on the TextExtraction.
     *  \param choiceSelection : 0 or 1.
     *  - If 0, a FileDialog box will pop up to select manually, websiteAddress should not be given.
     *  - If 1, the TextExtraction will be done on the websiteAddress.
     *  \param websiteAddress : A string containing the website to extract.
     */
    ParallelConcurrent(const int &choiceSelection, const QString &websiteAddress = "");

    /*!
     *  \brief
     *  This Constructor :
     *  - launches one Concurrent on the WebCrawler.
     *  \param websiteAddress : A string containing the website to index.
     */
    ParallelConcurrent(const QString &websiteAddress);

    /*!
     *  \brief
     *  This Destructor is empty.
     */
    ~ParallelConcurrent();


private:
    QFuture<void> m_future; /*!< The QFuture associated to a QtConcurrent. */
    QFutureWatcher<void> m_watcher; /*!< A QFutureWatcher to act on the QFuture. */
    TestFunction* m_testFunction; /*!< A TestFunction to launch in a QtConcurrent. */
    TextExtraction* m_textExtraction; /*!< A TextExtraction to launch in a QtConcurrent. */
    WebCrawler* m_webCrawler; /*!< A WebCrawler to launch in a QtConcurrent. */
};

#endif // PARALLELCONCURRENT_H

#ifndef PARALLELTHREAD_H
#define PARALLELTHREAD_H

/*!
 * \file ParallelThread.h
 * \author Rovere Francois
 * \version 0.2
 */

#include <QThread>
#include <TextExtraction.h>
#include <TestFunction.h>
#include <WebCrawler.h>

/*! \class ParallelThread
 * \brief - Creation of a Thread for a process given in attribute.
 *  - This class allows to create parallel computation to improve efficiency.
 */
class ParallelThread : public QThread
 {
    Q_OBJECT

public:  
    /*!
     *  \brief
     *  This Constructor is empty.
     */
    ParallelThread();

    /*!
     *  \brief
     *  This Constructor :
     *  - launches Threads on the testFunction.
     *  \param testFunction : The TestFunction to move into a Thread.
     */
    ParallelThread(TestFunction *testFunction);

    /*!
     *  \brief
     *  This Constructor :
     *  - launches Threads on the webCrawler.
     *  \param webCrawler : The WebCrawler to move into a Thread.
     */
    ParallelThread(WebCrawler *webCrawler);

    /*!
     *  \brief
     *  This Constructor :
     *  - launches Threads on the textExtraction.
     *  \param textExtraction : The TextExtraction to move into a Thread.
     */
    ParallelThread(TextExtraction *textExtraction);

    /*!
     *  \brief
     *  This Destructor is empty.
     */
    ~ParallelThread();

};

#endif // PARALLELTHREAD_H

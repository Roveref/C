#ifndef TESTFUNCTION_H
#define TESTFUNCTION_H

/*!
 * \file TestFunction.h
 * \author Rovere Francois
 * \version 0.2
 */

#include <QDebug>
#include <QElapsedTimer>
#include <QFile>

/*! \class TestFunction
 * \brief - Creation of a function to test the performances of ParallelConcurrent and ParallelThread.
 */
class TestFunction : public QObject {

    Q_OBJECT

public:
    /*!
     *  \brief
     *  This Constructor :
     *  - gets the attribute as the file number in m_fileNumber.
     *  \param number : The number of the file to write in the file name.
     */
    TestFunction(int number);

    /*!
     *  \brief
     *  This Destructor is empty.
     */
    ~TestFunction();

public slots:
    /*!
     *  \brief
     *  This slot :
     *  - writes 2000000 lines in a file whose name is given by m_fileNumber.
     */
    void process();

signals:
    /*!
     *  \brief
     *  This signal :
     *  - indicates when the process is finished.
     *  - causes the deletion of the ParallelThread in which it was enclosed.
     */
    void finished();

private:
    int m_fileNumber; /*!< The number of the file in the file name, like 3 in Text3.txt. */
};

#endif // TESTFUNCTION_H

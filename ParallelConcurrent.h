#ifndef PARALLELCONCURRENT_H
#define PARALLELCONCURRENT_H

/*!
 * \file ParallelConcurrent.h
 * \author Rovere Francois
 * \version 0.1
 */

#include <QFile>
#include <QElapsedTimer>
#include <qtconcurrentrun.h>

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

    /*!
     *  \brief testFunction
     *  This function run a writing process to test the parallel computation
     *  \param databaseName : The name of the database to connect to
     */
    void testFunction(const int &numberConcurrent);

private:
    int m_numberConcurrent;

};

#endif // PARALLELCONCURRENT_H

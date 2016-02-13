#include "ParallelConcurrent.h"

ParallelConcurrent::ParallelConcurrent()
{
}

ParallelConcurrent::ParallelConcurrent(const int &numberConcurrent) : m_numberConcurrent(numberConcurrent)
{
    for(int i=1; i<=m_numberConcurrent; ++i)
        {
        QFuture<void> future = QtConcurrent::run(this,&ParallelConcurrent::testFunction,i);
        }
}

void ParallelConcurrent::testFunction(const int &numberConcurrent)
{
    QElapsedTimer timer;
    timer.start();

    QString directory = "/home/roveref/Test" + QString::number(numberConcurrent) + ".txt" ;
    QFile file(directory);

    if (file.open(QIODevice::ReadWrite))
    {
        double writingNumber(0);
        double exitCondition(2000000);
        while(writingNumber<exitCondition)
        {
            QTextStream stream(&file);
            stream << writingNumber << endl;
            ++writingNumber;
        }
    }
    file.close();
    qDebug() << "File " << numberConcurrent << " took:" << timer.elapsed() << "milliseconds";
}


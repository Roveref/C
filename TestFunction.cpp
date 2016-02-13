#include "TestFunction.h"

TestFunction::TestFunction(int number) : m_fileNumber(number)
{
}

TestFunction::~TestFunction() {
}

void TestFunction::process()
{
    QElapsedTimer timer;
    timer.start();

    QString directory = "/home/roveref/Test" + QString::number(m_fileNumber) + ".txt" ;
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
    qDebug() << "File " << m_fileNumber << " took:" << timer.elapsed() << "milliseconds";

    emit finished();
}

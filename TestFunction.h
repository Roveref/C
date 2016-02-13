#ifndef TESTFUNCTION_H
#define TESTFUNCTION_H


#include <QDebug>
#include <QElapsedTimer>
#include <QFile>


class TestFunction : public QObject {

    Q_OBJECT

public:
    TestFunction(int number);
    ~TestFunction();

public slots:
    void process();

signals:
    void finished();

private:
    int m_fileNumber;
};

#endif // TESTFUNCTION_H

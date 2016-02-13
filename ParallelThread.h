#ifndef PARALLELTHREAD_H
#define PARALLELTHREAD_H

#include <QThread>
#include <TestFunction.h>
#include <WebCrawler.h>
#include <TextExtraction.h>

class ParallelThread : public QThread
 {
    Q_OBJECT

public:
    ParallelThread();
    ParallelThread(TestFunction *testFunction);
    ParallelThread(WebCrawler *webCrawler);
    ParallelThread(TextExtraction *textExtraction);

private:
    int number;
};


#endif // PARALLELTHREAD_H

#ifndef MULTI_THREADING_H
#define MULTI_THREADING_H


#include <QDebug>
#include <QThread>
#include <QString>
#include <QDir>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QTextStream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <qtconcurrentrun.h>
#include <QApplication>
#include <QTextEdit>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QStack>
#include <QFileDialog>
#include <QDirIterator>
#include <QtGui>
#include <QObject>
#include <QThread>
#include <QApplication>
#include <QTime>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>


class multi_threading : public QThread
 {
    Q_OBJECT

public:
    multi_threading(int num);
    int number;
    static void msleep(unsigned long msecs)
    {
        QThread::msleep(msecs);
    }

public Q_SLOTS :
    void run();
};


#endif // MULTI_THREADING_H

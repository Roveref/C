#ifndef MULTI_CONCURRENT_H
#define MULTI_CONCURRENT_H


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

class multi_concurrent : public QObject
{

    Q_OBJECT

public:
    multi_concurrent();
    void aFunction1(int number);

private:
    int num;

};

#endif // MULTI_CONCURRENT_H

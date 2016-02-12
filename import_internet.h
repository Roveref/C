#ifndef IMPORT_INTERNET_H
#define IMPORT_INTERNET_H

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

class import_internet : public QObject
{

    Q_OBJECT

public:
    import_internet();
    void import();

private:

};

#endif // IMPORT_INTERNET_H

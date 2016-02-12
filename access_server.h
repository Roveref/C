#ifndef ACCESS_SERVER_H
#define ACCESS_SERVER_H

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
#include <QtSql>

class access_server : public QObject
{

    Q_OBJECT

public:
    access_server();
    void read_database();

private:
    int k,numero;
    QString servername;
    QString dbname;
    QSqlDatabase db;

};


#endif // ACCESS_SERVER_H

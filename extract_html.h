#ifndef EXTRACT_HTML_H
#define EXTRACT_HTML_H


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

class extraction_html : public QObject
{

    Q_OBJECT

public:
    extraction_html();
    void findFilesRecursively();
    void scanDir(QDir directory);
    virtual int getNumero();


private:
    int k,numero;
    QDir rootDir;
    QDir dir;
    QStack<QString>* filesStack;
    QFileDialog fileDialog;
    QStringList fileList;
    QStringList dirList;
    QString newPath;
    std::string site;
    std::string site_2;
    QString txt;
    QRegularExpressionMatchIterator ite;
    QString filename;
    QRegularExpressionMatch match;
    std::ofstream fichier;

};


#endif // EXTRACT_HTML_H

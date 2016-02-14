#ifndef TEXTEXTRACTION_H
#define TEXTEXTRACTION_H


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

class TextExtraction : public QObject
{

    Q_OBJECT

public:
    TextExtraction();
    TextExtraction(const QString &websiteAddress);
    ~TextExtraction();
    void findFilesRecursively();
    void selectDirectory();
    void getDirectory();
    void extractionHTMLToText();

public slots:
    void process();

signals:
    void finished();

private:
    QDir m_rootDirectory;
    QStack<QString>* m_filesStack;
    QFileDialog m_fileDialog;
    QRegularExpressionMatchIterator m_regularExpressionMatchIterator;
    QRegularExpressionMatch m_regularExpressionMatch;
    QRegularExpression m_regularExpression;
    QString m_filename;
    QString m_textFile;
    QString m_websiteAddress;
    QStringList m_extensionFilter;
    QFile* m_fileOrigin;
    QFile* m_fileDestination;
    QTextStream* m_fileOriginContent;
};


#endif // TEXTEXTRACTION_H

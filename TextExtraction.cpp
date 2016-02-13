#include "TextExtraction.h"

TextExtraction::TextExtraction() : m_regularExpression("<p>(.*)</p>"), m_extensionFilter(0)
{
    m_filesStack = new QStack<QString>();
    m_extensionFilter.append("*.html");
    selectDirectory();
    findFilesRecursively();
    extractionHTMLToText();
}

TextExtraction::TextExtraction(const QString &websiteAddress) : m_regularExpression("<p>(.*)</p>"), m_websiteAddress(websiteAddress),
    m_extensionFilter(0)
{
    m_filesStack = new QStack<QString>();
    m_extensionFilter.append("*.html");
}

TextExtraction::~TextExtraction()
{
    delete m_fileOrigin;
    m_fileOrigin = 0;
    delete m_fileDestination;
    m_fileDestination = 0;
    delete m_fileOriginContent;
    m_fileOriginContent = 0;
}

void TextExtraction::process()
{
    getDirectory(m_websiteAddress);
    findFilesRecursively();
    extractionHTMLToText();
}

void TextExtraction::selectDirectory()
{
    m_fileDialog.setFileMode(QFileDialog::Directory);
    m_fileDialog.setOption(QFileDialog::ShowDirsOnly);
    if (m_fileDialog.exec() == QFileDialog::Accepted)
    {
        m_rootDirectory = QDir(m_fileDialog.selectedFiles().first());
        qDebug() << m_fileDialog.selectedFiles().first();
        m_rootDirectory.setFilter(QDir::Files | QDir::Dirs | QDir::NoDot | QDir::NoDotDot);
        m_rootDirectory.setNameFilters(m_extensionFilter);
    }
}

void TextExtraction::getDirectory(const QString &websiteAddress)
{
        m_rootDirectory = QDir("/home/roveref/Software/build/debug/" + m_websiteAddress);
        qDebug() << "/home/roveref/Software/build/debug/" + m_websiteAddress;
        m_rootDirectory.setFilter(QDir::Files | QDir::Dirs | QDir::NoDot | QDir::NoDotDot);
        m_rootDirectory.setNameFilters(m_extensionFilter);
}

void TextExtraction::findFilesRecursively()
{
    QDirIterator directoryIterator(m_rootDirectory, QDirIterator::Subdirectories);
    while(directoryIterator.hasNext()) {
        m_filesStack->push(directoryIterator.next());
        qDebug() << directoryIterator.hasNext();
    }
}

void TextExtraction::extractionHTMLToText()
{
    qDebug() << m_filesStack->isEmpty();
    while (!m_filesStack->isEmpty())
        {
        m_fileOrigin = new QFile(m_filesStack->last());
        if (!m_fileOrigin->open(QIODevice::ReadOnly | QIODevice::Text))
        {
             qDebug() << "Not opened";
        }
        m_fileOriginContent = new QTextStream(m_fileOrigin);
        m_textFile = m_fileOriginContent->readAll();


        m_regularExpressionMatchIterator = m_regularExpression.globalMatch(m_textFile);
        m_fileDestination = new QFile(m_fileOrigin->fileName() + ".txt");
        m_fileDestination->open(QIODevice::WriteOnly);

        while(m_regularExpressionMatchIterator.hasNext())
        {
            m_regularExpressionMatch = m_regularExpressionMatchIterator.next();
            m_fileDestination->write(m_regularExpressionMatch.captured(1).toUtf8() + " " );
        }
        m_fileOrigin->close();
        m_fileDestination->close();
        m_filesStack->pop();
    }
}


#ifndef TEXTEXTRACTION_H
#define TEXTEXTRACTION_H

/*!
 * \file TextExtraction.h
 * \author Rovere Francois
 * \version 0.2
 */

#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QRegularExpression>
#include <QStack>
#include <QFileDialog>

/*! \class TextExtraction
 * \brief - Select one Directory through a FileDialog box,
 * track all html files in the sub directories,
 * get the text situated between a regular expression,
 * write it in a new file with the same + ".txt".
 * - Input directly a Directory,
 * track all html files in the sub directories,
 * get the text situated between a regular expression,
 * write it in a new file with the same + ".txt".
 */
class TextExtraction : public QObject
{

    Q_OBJECT

public:
    /*!
     *  \brief
     *  This Constructor :
     *  - lets the user select one Directory via a FileDialog box.
     *  - instances m_filesStack.
     *  - appends .html in m_extensionFilter.
     *  - tracks all files with the extension as defined in m_extensionFilter in the sub directories.
     *  - gets the text situated between the regular expression as defined in m_regularExpression.
     *  - writes it in a new file with the same name + ".txt".
     */
    TextExtraction();

    /*!
     *  \brief
     *  This Constructor :
     *  - lets the user input directly one Directory in attribute.
     *  - instances m_filesStack.
     *  - appends .html in m_extensionFilter.
     *  \param websiteAddress : The Directory to work on.
     */
    TextExtraction(const QString &websiteAddress);

    /*!
     *  \brief
     *  This Destructor deletes all the dynamic memory allocations.
     */
    ~TextExtraction();

    /*!
     *  \brief
     *  This function :
     *  - opens a FileDialog box to select a Directory to put in m_rootDirectory.
     *  - applies a filter to m_rootDirectory to keep only the extension as defined in m_extensionFilter.
     */
    void selectDirectory();

    /*!
     *  \brief
     *  This function :
     *  - gets the Directory from m_websiteAddress to put in m_rootDirectory.
     *  - applies a filter to m_rootDirectory to keep only the extension as defined in m_extensionFilter.
     */
    void getDirectory();

    /*!
     *  \brief
     *  This function :
     *  - appends in m_filesStack all the files with the extension as defined in m_extensionFilter
     *  in the subdirectories of m_rootDirectory
     */
    void findFilesRecursively();

    /*!
     *  \brief
     *  This function :
     *  - extracts from the top of the stack m_filesStack the text situated
     *  between the regular expression as defined in m_regularExpression in m_fileOriginContent.
     *  - writes it in a new file m_fileDestination with the name m_fileOrigin  + ".txt".
     */
    void extractionHTMLToText();

public slots:
    /*!
     *  \brief
     *  This slot launches the functions :
     *  - getDirectory().
     *  - findFilesRecursively().
     *   -extractionHTMLToText().
     */
    void process();

signals:
    /*!
     *  \brief
     *  This signal :
     *  - indicates when the process is finished.
     *  - causes the deletion of the ParallelThread in which it was enclosed.
     */
    void finished();

private:
    QDir m_rootDirectory; /*!< The Directory associated to m_websiteAddress. */
    QStack<QString>* m_filesStack; /*!< A Stack with the files ended with m_extensionFilter in the sub directories of m_rootDirectory. */
    QFileDialog m_fileDialog; /*!< A FileDialog box to select m_rootDirectory. */
    QRegularExpressionMatchIterator m_regularExpressionMatchIterator; /*!< Match iterator of m_regularExpression. */
    QRegularExpressionMatch m_regularExpressionMatch; /*!< Match of m_regularExpression. */
    QRegularExpression m_regularExpression; /*!< The regular expression to work on. */
    QString m_textFile; /*!< A String corresponding to m_fileOriginContent to be used with a REGEX. */
    QString m_websiteAddress; /*!< The name of the website to extract, converted into a path with QDir. */
    QStringList m_extensionFilter; /*!< A filter to keep only specific files in the sub directories of m_rootDirectory. */
    QFile* m_fileOrigin; /*!< The origin file to extract with an extension as defined in m_extensionFilter, piled up in m_filesStack. */
    QFile* m_fileDestination; /*!< The destination file receiving the text between m_regularExpression of m_fileOrigin. */
    QTextStream* m_fileOriginContent; /*!< The Content of m_fileOrigin and to convert into m_textFile. */
};

#endif // TEXTEXTRACTION_H

#ifndef WEBCRAWLER_H
#define WEBCRAWLER_H

/*!
 * \file WebCrawler.h
 * \author Rovere Francois
 * \version 0.2
 */

#include <QDebug>

/*! \class WebCrawler
 * \brief - Creation of a webcrawler to extract the full index to the local computer.
 */
class WebCrawler : public QObject
{

    Q_OBJECT

public:
    /*!
     *  \brief
     *  This Constructor is empty.
     */
    WebCrawler();

    /*!
     *  \brief
     *  This Constructor :
     *  - gets the attribute as the website address to index in m_websiteAddress.
     *  \param websiteAddress : The website address to index.
     */
    WebCrawler(const QString &websiteAddress);

    /*!
     *  \brief
     *  This Destructor is empty.
     */
    ~WebCrawler();

public slots:
    /*!
     *  \brief
     *  This slot :
     *  - launches in the terminal the wget command with m_websiteAddress.
     */
    int process();

signals:
    /*!
     *  \brief
     *  This signal :
     *  - indicates when the process is finished.
     *  - causes the deletion of the ParallelThread in which it was enclosed.
     */
    void finished();

private:
    QString m_websiteAddress; /*!< The website Address to index, like www.yahoo.com. */
    QString m_systemCommand; /*!< The command to input inside the terminal. */

};

#endif // WEBCRAWLER_H

#ifndef INTERACTIONSERVER_H
#define INTERACTIONSERVER_H

/*!
 * \file InteractionServer.h
 * \brief Connection, reading, writing and disconnection to MySQL database
 * \author Rovere Francois
 * \version 0.1
 */

#include <QDebug>
#include <QString>
#include <QApplication>
#include <QtSql>

  /*! \class InteractionServer
   * \brief Interaction with the MySql database
   *
   *  This class allows to connect, disconnect, and make all possible requests to the MySql database
   */
class InteractionServer : public QObject
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructor 1
     */
    InteractionServer();

    /*!
     *  \brief Constructor 2
     *  This Constructor connects to a server without choosing a database
     *  \param serverName : The name of the server to connect
     *  \param userName : The name of the user
     *  \param password : The password associated to the server and the user
     */
    InteractionServer(const QString &serverName, const QString &userName, const QString &password);

    /*!
     *  \brief Constructor 3
     *  This Constructor connects to a server and a database
     *  \param serverName : The name of the server to connect
     *  \param userName : The name of the user
     *  \param password : The password associated to the server and the user
     *  \param databaseName : The name of the database to connect to
     */
    InteractionServer(const QString &serverName, const QString &userName, const QString &password, const QString &databaseName);

    /*!
     *  \brief Destructor
     *  This Destructor deletes all the dynamic memory allocations and closes the connection to the server
     */
    ~InteractionServer();

    /*!
     *  \brief selectDatabase
     *  This function selects a database if the Constructor 2 has been used before
     *  This function switches from one database to another
     *  \param databaseName : The name of the database to connect to
     */
    void selectDatabase(const QString &databaseName);

    /*!
     *  \brief readTable
     *  This function prints in the terminal the information contained in a table
     *  \param tableName : The name of the table from to extract information
     *  \param whereCondition : Include a constraint with a WHERE in the SQL request
     */
    void readTable(const QString &tableName, const QString &whereCondition = "");

    /*!
     *  \brief writeTable
     *  This function writes in a table the information given in attributes
     *  \param tableName : The name of the table to write
     *  \param valuesFields : The values to write
     *  \param fieldsName : If not all, the fields of the table to write in
     */
    void writeTable(const QString &tableName, const QString &valuesFields, const QString &fieldsName ="");

    /*!
     *  \brief anyTable
     *  This function makes the query written in attribute
     *  \param anyQuery : The query written in SQL
     */
    void anyTable(const QString &anyQuery);

private:
    QString m_serverName; /*!< The name of the server, like localhost */
    QString m_userName; /*!< The name of the user, like root */
    QString m_password; /*!< The password, like aaaa */
    QString m_databaseName; /*!< The name of the database, like myDatabase */
    QString m_serverType; /*!< The name of the server type, like QMYSQL */
    QSqlDatabase m_server; /*!< An instance of server */
    QString m_output; /*!< A string for printing in terminal */
    QSqlQuery* m_query; /*!< An instance of SQL query */
    QString m_queryContent; /*!< A string with an SQL query */
    int m_queryRecordCount; /*!< An int with the number of columns of the SQL Record */
    int m_querySize; /*!< An int with the number of lines of the SQL Record */

};

#endif // INTERACTIONSERVER_H

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
    InteractionServer();
    InteractionServer(const QString &serverName, const QString &userName, const QString &password);
    InteractionServer(const QString &serverName, const QString &userName, const QString &password, const QString &databaseName);
    ~InteractionServer();

    void selectDatabase(const QString &databaseName);
    void readTable(const QString &tableName, const QString &whereCondition = "");
    void writeTable(const QString &tableName, const QString &valuesFields, const QString &fieldsName ="");
    void anyTable(const QString &anyQuery);

private:
    QString m_serverName;
    QString m_userName;
    QString m_password;
    QString m_databaseName;
    QString m_serverType;
    QSqlDatabase m_server;
    QString m_output;
    QSqlQuery* m_query;
    QString m_queryContent;
    int m_queryRecordCount;
    int m_querySize;

};


#endif // INTERACTIONSERVER_H

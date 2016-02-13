#include "InteractionServer.h"

InteractionServer::InteractionServer()
{
}

InteractionServer::InteractionServer(const QString &serverName, const QString &userName, const QString &password)
: m_serverName(serverName), m_userName(userName), m_password(password), m_serverType("QMYSQL")
{
    m_server = QSqlDatabase::addDatabase(m_serverType);
    m_server.setConnectOptions();
    m_server.setHostName(m_serverName);
    m_server.setUserName(m_userName);
    m_server.setPassword(m_password);
}

InteractionServer::InteractionServer(const QString &serverName, const QString &userName, const QString &password,
                                     const QString &databaseName)
: m_serverName(serverName), m_userName(userName), m_password(password), m_databaseName(databaseName), m_serverType("QMYSQL")
{
    m_server = QSqlDatabase::addDatabase(m_serverType);
    m_server.setConnectOptions();
    m_server.setHostName(m_serverName);
    m_server.setDatabaseName(m_databaseName);
    m_server.setUserName(m_userName);
    m_server.setPassword(m_password);

    if(m_server.open())
    {
        qDebug() << "Connection to the server " + m_serverName + " and the database "
                    + m_databaseName + " established.";
        m_query = new QSqlQuery();
    }
    else
    {
        qDebug() << "Error of connection =" << m_server.lastError().text();
    }
}

InteractionServer::~InteractionServer()
{
    m_server.close();
    delete m_query;
    m_query = 0;
    qDebug() << "Connection to the server closed.";
}

void InteractionServer::selectDatabase(const QString &databaseName)
{
    m_databaseName = databaseName;
    m_server.setDatabaseName(m_databaseName);

    if(m_server.open())
    {
        qDebug() << "Connection to the server " + m_serverName + " and the database "
                    + m_databaseName + " established.";
        m_query = new QSqlQuery();
    }
    else
    {
        qDebug() << "Error of connection to the server =" << m_server.lastError().text();
    }
}

void InteractionServer::readTable(const QString &tableName, const QString & whereCondition)
{
    m_output = "";
    m_queryContent = "SELECT * FROM " + tableName;
    if(whereCondition != "")
        m_queryContent += " WHERE " + whereCondition;
    if(m_query->exec(m_queryContent))
    {
        m_queryRecordCount = m_query->record().count();
        m_querySize = m_query->size();
        qDebug() << "Number of fields: " << m_queryRecordCount;
        qDebug() << "Number of records: " << m_querySize;
        for(int i=0; i<m_queryRecordCount; i++)
        {
        m_output += " " + m_query->record().fieldName(i);
        }
        qDebug() << m_output;
        while(m_query->next())
        {
            m_output = "";
            for(int i=0; i<m_queryRecordCount; i++)
            {
            m_output += " " + m_query->value(i).toString();
            }
            qDebug() << m_output;
        }
    }
    else
    {
        qDebug() << "Error of connection to the table =" << m_server.lastError().text();
    }
}

void InteractionServer::writeTable(const QString &tableName, const QString &valuesFields, const QString &fieldsName)
{
    m_queryContent = "INSERT INTO " + tableName;
    if(fieldsName != "")
        m_queryContent += " (" + fieldsName + ") VALUES (" + valuesFields + ")";
    else
        m_queryContent += " VALUES (" + valuesFields + ")";
    if(m_query->exec(m_queryContent))
    {
        qDebug() << "Query successfully written";
    }
    else
    {
        qDebug() << "Error of connection to the table =" << m_server.lastError().text();
    }
}

void InteractionServer::anyTable(const QString &anyQuery)
{
    if(m_query->exec(anyQuery))
    {
        qDebug() << "Query successfully completed";
    }
    else
    {
        qDebug() << "Error of connection to the table =" << m_server.lastError().text();
    }
}

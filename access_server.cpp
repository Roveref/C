#include "access_server.h"

access_server::access_server()
{


    servername = "localhost";

    dbname = "questionnaire";

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setConnectOptions();

    db.setHostName(servername);
    db.setDatabaseName(dbname);
    db.setUserName("root");
    db.setPassword("password29");

    if(db.open()) {

    qDebug() << "Connection to the database established.";
    }
    else
    {
        qDebug() << "Error =" << db.lastError().text();
    }

}

void access_server::read_database()
{
    QSqlQuery qry;

    if(qry.exec("SELECT * FROM testdatabase"))
    {
        while(qry.next())
        {
            qDebug() << qry.value(0).toString();
            qDebug() << qry.value(1).toString();
            qDebug() << qry.value(2).toString();
        }
    }
    else
    {
        qDebug() << "Error =" << db.lastError().text();
    }
    db.close();
    qDebug() << "Connection to the database closed.";
}

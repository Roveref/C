/*!
 * \file main.cpp
 * \brief main of the project
 * \author Rovere Francois
 * \version 0.1
 */

#include <InteractionServer.h>
#include <ParallelConcurrent.h>
#include <ParallelThread.h>
#include <TestFunction.h>
#include <TextExtraction.h>
#include <WebCrawler.h>

using namespace QtConcurrent;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);


    /*ParallelConcurrent parallelConcurrent(1,"www.lefigaro.fr");

    QString table[3] = {"www.lefigaro.fr", "www.yahoo.com","www.lemonde.fr"};
    for(int i=0;i<3;i++)
    {
    TextExtraction* textExtraction = new TextExtraction(table[i]);
    ParallelThread* thread = new ParallelThread(textExtraction);
    }

    TextExtraction* textExtraction = new TextExtraction();

    InteractionServer* interactionServer = new InteractionServer("localhost","root","password29","questionnaire");
    interactionServer->anyTable("SELECT general_ip FROM testdatabase");
    qDebug() << interactionServer->getm_queryResults(3);
    qDebug() << interactionServer->getrankm_queryResults();

    QString table[3] = {"http://www.yahoo.com", "http://www.lefigaro.fr", "http://www.lemonde.fr"};
    for(int i=0;i<3;i++)
    {
    WebCrawler* webCrawler = new WebCrawler(table[i]);
    ParallelThread* thread = new ParallelThread(webCrawler);
    }

    for(int i=1;i<=8;i++)
    {
    TestFunction* testFunction = new TestFunction(i);
    ParallelThread* thread = new ParallelThread(testFunction);
    }*/

    ParallelConcurrent parallelConcurrent(4,4);

    /*InteractionServer* interactionServer = new InteractionServer("localhost","root","password29");
    interactionServer->selectDatabase("questionnaire");
    interactionServer->readTable("testdatabase");
    interactionServer->readTable("general_information","sex = 'male'");
    interactionServer->writeTable("testdatabase","'male'","general_sex");
    interactionServer->anyTable("SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE table_schema = 'questionnaire' AND table_name = 'testdatabase'");
    delete interactionServer;*/


    return app.exec(); //Use with ParallelThread. Do not use with ParallelConcurrent.
}


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


    /*ParallelConcurrent parallelConcurrent(7);*/

    QString table[3] = {"www.lefigaro.fr", "www.yahoo.com","www.lemonde.fr"};
    for(int i=0;i<1;i++)
    {
    TextExtraction* textExtraction = new TextExtraction(table[i]);
    ParallelThread* thread = new ParallelThread(textExtraction);
    }

    //TextExtraction* textExtraction = new TextExtraction();

    /*InteractionServer* interactionServer = new InteractionServer("localhost","root","password29","questionnaire");
    interactionServer->anyTable("SELECT general_ip FROM testdatabase");
    qDebug() << interactionServer->getm_queryResults(3);
    qDebug() << interactionServer->getrankm_queryResults();*/

    /*QString table[3] = {"http://www.yahoo.com", "http://www.lefigaro.fr", "http://www.lemonde.fr"};
    for(int i=0;i<3;i++)
    {
    WebCrawler* webCrawler = new WebCrawler(table[i]);
    ParallelThread* thread = new ParallelThread(webCrawler);
    }

    for(int i=1;i<8;i++)
    {
    TestFunction* testFunction = new TestFunction(i);
    ParallelThread* thread = new ParallelThread(testFunction);
    }

    InteractionServer* interactionServer = new InteractionServer("localhost","root","password29");
    interactionServer->selectDatabase("questionnaire");
    interactionServer->readTable("testdatabase");
    interactionServer->readTable("testdatabase","general_sex = 'male'");
    interactionServer->writeTable("testdatabase","'male'","general_sex");
    interactionServer->anyTable("INSERT INTO testdatabase (general_sex) VALUES ('female')");
    delete interactionServer;*/

    //return app.exec();
}


/*!
 * \file main.cpp
 * \brief main of the project
 * \author Rovere Francois
 * \version 0.1
 */

#include <InteractionServer.h>
#include <extract_html.h>
#include <import_internet.h>
#include <multi_concurrent.h>
#include <multi_threading.h>
#include <unistd.h>


using namespace QtConcurrent;
//using namespace std;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    //srand(time(NULL));

    //extraction_html extract;
    //multi_concurrent multi;

    //multi_threading* thread1[8];

    //int number(0);
    //std::cin >> number;
    /*std::vector<multi_threading*> db;
    for(int num=1;num<=12;++num)
        {
        db.push_back(new multi_threading(num));
    }
    std::cout << "fini" << std::endl;*/

    InteractionServer* interactionServer = new InteractionServer("localhost","root","password29");
    interactionServer->selectDatabase("questionnaire");
    interactionServer->readTable("testdatabase");
    interactionServer->readTable("testdatabase","general_sex = 'male'");
    interactionServer->writeTable("testdatabase","'male'","general_sex");
    interactionServer->anyTable("INSERT INTO testdatabase (general_sex) VALUES ('female')");
    delete interactionServer;

    //return app.exec();
}


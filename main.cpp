/*!
 * \file main.cpp
 * \brief main of the project
 * \author Rovere Francois
 * \version 0.1
 */

#include <access_server.h>
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
    multi_concurrent multi;

    //multi_threading* thread1[8];

    //int number(0);
    //std::cin >> number;
    /*std::vector<multi_threading*> db;
    for(int num=1;num<=12;++num)
        {
        db.push_back(new multi_threading(num));
    }
    std::cout << "fini" << std::endl;*/

    access_server s;
    s.read_database();

    return app.exec();
}


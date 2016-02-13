#include "multi_concurrent.h"

multi_concurrent::multi_concurrent()
{
    for(int number=1;number<=4;++number)
        {
        QFuture<void> future = QtConcurrent::run(this,&multi_concurrent::aFunction1,number);
        }
}

void multi_concurrent::aFunction1(int number)
{
    std::string site = "/home/roveref/Test" ;
    std::string site_2 = std::to_string(number);
    std::cout << site_2 << std::endl;
    site = site + site_2;
    site = site+".txt";
    std::cout << site << std::endl;
    std::ofstream fichier;
    fichier.open(site.c_str());
    //std:: fichier(site, std::ios::out | std::ios::trunc);
    double k=1;
    while(k<2000000){
    fichier << k << std::endl;
    //std::cout << k << std::endl;
    k=k+1;
    }
    fichier.close();
}


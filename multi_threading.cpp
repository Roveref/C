#include "multi_threading.h"

multi_threading::multi_threading(int num)
{
        number = num;
        this->start();
}

void multi_threading::run()
{
    std::string site = "/home/roveref/Test" ;
    std::string site_2 = std::to_string(number);
    std::cout << site_2 << std::endl;
    site = site + site_2;
    site = site+".txt";
    std::cout << site << std::endl;
    std::ofstream fichier;
    fichier.open(site.c_str());
    double k=1;
    while(k<2000000){
    fichier << k << std::endl;
    //cout << k << endl;
    k=k+1;
    }
    fichier.close();
}



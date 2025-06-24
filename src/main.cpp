#include <iostream>
#include <vector>

#include <converterjson.h>
#include <help.h>
#include <readsettings.h>
#include <search.h>
#include <test.h>

//void find(std::string* nameSearch, std::string* rootSearch, bool* fileOnly, std::string* mask){};
void findFiles(std::string* nameSearch);

int main(int numberPS, char** arrayPS){

    //std::cout << "Welcome to the search!\n";
    std::string nameSearch="name";

    //std::string rootSearch="/";
    //bool fileOnly=true;
    //std::string mask="";
    //bool help=false;

    // std::vector<File> listIndexes;
    // bool indexingDone=false;
    // std::vector<std::string> vecIndexes;

    //getSettings(&nameSearch, &rootSearch, &fileOnly, &mask, &help);
    getSettings(&nameSearch);
   
    // if (checkParametr(&numberPS, &arrayPS, &help)==-1)
    // {
    //     std::cout << "Error parameters!";
    //     return 0;
    // };
    // if(help){
    //     std::string helptxt="";
    //     getHelp(&helptxt);
    //     std::cout << helptxt << std::endl;
    //     return 0;
    // };
        
    //find(&nameSearch, &rootSearch, &fileOnly, &mask);

    findFiles(&nameSearch);

    return 0;
};


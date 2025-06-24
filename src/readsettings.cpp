#include <iostream>
#include <fstream>

#include "readsettings.h"

#include "nlohmann/json.hpp"


void showListF(nlohmann::json dict, std::string name)
{
    int k=0;
    for (auto itF : dict)
    {
        nlohmann::json actors = itF["actors"];
        int isRole=0;
        //for (auto itA : actors)    
        for (auto& [actor, role] : actors.items())
        {
            //Actor obj=KeyValFromStr(itA.dump());
            if(actor.find(name)==std::string::npos)
            {
                continue;
            };
            //std::cout << "Actor: " << obj.actor << ", " << obj.role << "\n";
            isRole=1;
        };
        if (isRole!=0)
        {            
            k++;         // Film = itF
            //showFilmRole(itF, name, k);
        }
    };
};

void find(nlohmann::json inData)
{
    std::string name="";
    do
    {
        std::string name="";
        std::cout << "Enter the name of actor / 'show' /or 'exit'): \n";
        std::getline(std::cin, name);
        
        if (name=="show")
        {
            std::cout << inData << std::endl;
            continue;
        };       

        if (name=="exit")
        {
            return;
        };

        showListF(inData, name);

    } while (name!="exit");
};


bool readInfo(nlohmann::json& dict)
{
    std::ifstream file("information.json");
    if (!(file.is_open()))
    {
        std::cout << "The file is not open! \n";
        return false;
    };
    
    file >> dict;

    return true;
};



void save()
{
    // std::ofstream data;
    // int sum;    
    // data.open("data.txt");
    // for (int i = 0; i < 8; i++)
    // {
    //     data << read(i) << std::endl;
    // }
    // data.close();
};
void load()
{
    // std::ifstream data;
    // int sum=0;
    // data.open("data.txt");
    // while (data.eof()!=true)
    // {
    //     data >> sum;
    //     //write(sum);
    // }
    // data.close();
};

int checkParametr(int* number, char*** array, bool* help){
    int rz=0;

    if (number==0)
    {
        return 0;
    };
    

    return rz;
};

//void getSettings(std::string* nameSearch, std::string* rootSearch, bool* fileOnly, std::string* mask, bool* help)
void getSettings(std::string* nameSearch)
{

    
};


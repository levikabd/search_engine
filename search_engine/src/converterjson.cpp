#include <fstream>
#include <iostream>

#include "converterjson.h"
#include "nlohmann/json.hpp"


// class ConverterJSON
// {
// private:
        // std::string name;
        // float version;  //  std::string version;
        // int max_responses;
        // std::vector<std::string> files;
        // std::vector<std::vector<std::string>> requests;
// public:
    
    //ConverterJSON::ConverterJSON()
    //ConverterJSON::ConverterJSON()    {    };

    ConverterJSON::~ConverterJSON()
    {

    };
    
    std::string ConverterJSON::getConfigName()
    {
        return name;
    };

    //void  ConverterJSON::readSettings(std::string* name,    std::string* version, int* max_responses,    std::vector<std::string>* files)
    void  ConverterJSON::readSettings()
    {
        std::ifstream file("search_engine/res/config.json");       
        try
        {
            if (!(file.is_open()))
            {
                throw std::logic_error("Config file is missing! \n");                 
            };
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return;       
        };
        
        nlohmann::json data;
        file >> data;
        file.close();

    //    std::cout << data << "\n";

        files.clear();
        nlohmann::json configData;
        std::string nameData;
        float  versionData;    //std::string  versionData;
        int max_responsesData;
        nlohmann::json dataFiles;

        bool boolConfig=false;

        for (auto& el : data.items())
        {
            if (el.key()=="config")
            {
                configData=el.value();
                boolConfig = true;                
            };        
            if (el.key()=="files")
            {
                dataFiles=el.value();
            };        
        };

        try
        {
            if(boolConfig != true)
            {
                throw std::logic_error("Config file is empty!");
            };
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        };
        

        for (auto it : configData.items())
        {       
            if (it.key() =="name")
            {
                nameData = it.value();
            } else if (it.key() =="version")
            {
                versionData = it.value();
            } else if (it.key() =="max_responses")
            {
                max_responsesData = it.value();
            };
        };

        name = nameData;
        version = versionData;

        try
        {
            if (versionData != 1.0 )
            {
                throw std::logic_error("config.json has incorrect file version!");
            };
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        };
        

        max_responses = max_responsesData;
        //files = dataFiles;

        for (auto it : dataFiles.items())
        {       
            files.push_back(it.value());
        };
        
        // //std::cout << "configData: "       << configData << "\n";
        // std::cout << "name: "         << *name << "\n";
        // std::cout << "version: "      << *version << "\n";
        // std::cout << "max_responses: " << *max_responses << "\n";

        // for (auto it : *files)
        // {
        //     std::cout << "file: "        << it << "\n";
        // };   
        return;
    };

    std::vector<std::string> ConverterJSON::getFiles()
    {
        return files;
    };

//     //* Метод получения содержимого файлов
//     //* @return Возвращает список с содержимым файлов перечисленных
//     //* в config.json
    std::vector<std::string> ConverterJSON::GetTextDocuments()
    {
        std::vector<std::string> docs;


        return docs;
    };

    int ConverterJSON::GetResponsesLimit()
    {
        return max_responses;
    };

    void ConverterJSON::readRequests()
    {
        std::ifstream file("search_engine/res/requests.json");
        if (!(file.is_open()))
        {
            std::cout << "The file 'requests.json' is not open! \n";
            return;        
        };
        
        nlohmann::json data;
        file >> data;
        file.close();

    //    std::cout << data << "\n";
        
        nlohmann::json requestsData;
        for (auto& el : data.items())
        {
            if (el.key()=="requests")
            {
                requestsData=el.value();
                break;
            };         
        };

        requests.clear();
        for (auto it : requestsData.items())
        {       
            std::string line=it.value();
            std::string newWord="";            
            std::vector<std::string> newString;
                for (auto k : line) // selecting characters in a string
                {
                    
                    //if (((k>='A')&(k<='Z')) || ((k>='a')&(k<='z')))
                    if ((k>='a') && (k<='z'))
                    {
                        newWord=newWord + k;
                    } else
                    {
                        if (newWord.size()<1)
                        {
                            continue;
                        };
                        newString.push_back(newWord);                        
                        newWord="";
                    };

                    if (newString.size()>=10)
                    {
                        break;
                    };
                }; // end character
            requests.push_back(newString);
            
            if (requests.size()>=1000)
            {
                break;
            };  
        };

        //test show block
        for (int i = 0; i < requests.size(); i++)
        {
            std::vector<std::string> lineWords=requests[i];
            for (int k = 0; k < lineWords.size(); k++)
            {
                std::cout << "requests " << i << ": " << k << ": " << lineWords[k] << std::endl;
            };
        };

    };

//     // * Метод получения запросов из файла requests.json
//     // * @return возвращает список запросов из файла requests.json
    std::vector<std::vector<std::string>> ConverterJSON::GetRequests()
    {
        readRequests();
        return requests;
    };

//     // * Положить в файл answers.json результаты поисковых запросов
    //void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
    void ConverterJSON::putAnswers(std::vector<std::vector<RelativeIndex>> answers)
    {
        // std::ofstream sheet;
        // sheet.open("sheet.txt", std::ios::app);
        std::ofstream file("search_engine/res/answers.json");
        if (!(file.is_open()))
        {
            std::cout << "The file 'answers.json' is not open! \n";
            return;
        };
        //nlohmann::json j = json::j_vec(answers);
        nlohmann::json j;
        nlohmann::json j_answers;
        j["answers"]=j_answers;


        auto j_str = to_string(j); 
        //dict >> file;
        file << j_str << std::endl;
        file.close();

        //return;
    };

    // void convertReqJSON(){};
    // void ansverJSON();
//};


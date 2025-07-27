#include <fstream>
#include <iostream>

#include "converterjson.h"
#include "nlohmann/json.hpp"


// class ConverterJSON
// {
// private:
        // std::string name;
        // std::string version;
        // int max_responses;
        // std::vector<std::string> files;
        // std::vector<std::string> requests;
// public:
    
    //ConverterJSON::ConverterJSON()
    //ConverterJSON::ConverterJSON()    {    };

    ConverterJSON::~ConverterJSON()
    {

    };
    
    //void  ConverterJSON::readSettings(std::string* name,    std::string* version, int* max_responses,    std::vector<std::string>* files)
    void  ConverterJSON::readSettings()
    {
        std::ifstream file("search_engine/res/config.json");
        if (!(file.is_open()))
        {
            std::cout << "The file 'config.json' is not open! \n";
            return;        
        };
        
        nlohmann::json data;
        file >> data;
        file.close();

    //    std::cout << data << "\n";

        files.clear();
        nlohmann::json configData;
        std::string nameData;
        std::string  versionData;
        int max_responsesData;
        nlohmann::json dataFiles;

        for (auto& el : data.items())
        {
            if (el.key()=="config")
            {
                configData=el.value();
            };        
            if (el.key()=="files")
            {
                dataFiles=el.value();
            };        
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

//     // * Метод получения запросов из файла requests.json
//     // * @return возвращает список запросов из файла requests.json
    std::vector<std::string> ConverterJSON::GetRequests()
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
                        requests.push_back(newWord);                        
                        newWord="";
                    };
                }; // end character            
        };
        return requests;
    };

//     // * Положить в файл answers.json результаты поисковых запросов
    void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
    {
        

        //return;
    };

    // void convertReqJSON(){};
    // void ansverJSON();
//};


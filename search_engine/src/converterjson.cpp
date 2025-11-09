#include <fstream>
#include <iostream>

#include "converterjson.h"
#include "nlohmann/json.hpp"


// class ConverterJSON
// {
// private:
        // std::string name;
        // float version;  
        // int max_responses;
        // std::vector<std::string> filesNames;
        // std::vector<std::string> files;
        // std::vector<std::vector<std::string>> requests;
// public:

    ConverterJSON::~ConverterJSON()    {    };
    
    std::string ConverterJSON::getConfigName()
    {
        return name;
    };

    void ConverterJSON::readFiles()
    {
        for (auto it : filesNames)
        {     
            std::string doc="";
            std::string line="";

            std::ifstream file(it);
            if (file.is_open()!=true)
            {
                std::cout << "File: " << it << " is not open! \n";
                continue;
            };
            
            while (!file.eof())
            {
                file >> line;
                doc= doc +" "+ line; 
            }; // end file

            files.push_back(doc);            
            file.close();
        };
    };

    void  ConverterJSON::readSettings()
    {
        std::ifstream file("resources/config.json");       
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

        // log out
        //std::cout << data << "\n";

        files.clear();
        nlohmann::json configData;
        std::string nameData;
        float  versionData;   
        int max_responsesData;
        nlohmann::json dataFiles;

        // log out
        //std::cout << "Sorting through!\n";
        // int num=0;
        // for (auto& el : data.items())
        // {
        //     num++;
        //     std::cout << num << "key: " << el.key() << "\n";
        // };

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
        
        if(configData.empty())
        {
            std::cout << "Config is empty!!!\n";
            return;
        }else{
            //std::cout << "Config is reading!\n";
        };

        try
        {
            if(configData.empty() == true)
            {
                throw std::logic_error("Config file is empty!\n");
            };
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        };        

        for (auto& it : configData.items())
        {       
            if (it.key() =="name")
            {
                nameData = it.value();
            } else if (it.key() =="version")
            {
                std::string verD=it.value();
                //versionData = float(verD);
                versionData = std::stof(verD);
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

        filesNames.clear();
        for (auto it : dataFiles.items())
        {       
            filesNames.push_back(it.value());
        };
        
        // log out
        // //std::cout << "configData: "       << configData << "\n";
        // std::cout << "name: "         << *name << "\n";
        // std::cout << "version: "      << *version << "\n";
        // std::cout << "max_responses: " << *max_responses << "\n";
        // for (auto it : *files)
        // {
        //     std::cout << "file: " << it << "\n";
        // };   
    };

    std::vector<std::string> ConverterJSON::getFiles()
    {
        return files;
    };

    //* Метод получения содержимого файлов
    //* @return Возвращает список с содержимым файлов перечисленных в config.json
    // std::vector<std::string> ConverterJSON::GetTextDocuments()
    // {
    //     std::vector<std::string> docs;
    //     return docs;
    // };

    int ConverterJSON::GetResponsesLimit()
    {
        return max_responses;
    };

    void ConverterJSON::readRequests()
    {
        std::ifstream file("resources/requests.json");
        if (!(file.is_open()))
        {
            std::cout << "The file 'requests.json' is not open! \n";
            return;        
        };
        
        nlohmann::json data;
        file >> data;
        file.close();

        //  log out
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

        // log out
        // for (int i = 0; i < requests.size(); i++)
        // {
        //     std::vector<std::string> lineWords=requests[i];
        //     for (int k = 0; k < lineWords.size(); k++)
        //     {
        //         std::cout << "requests " << i << ": " << k << ": " << lineWords[k] << std::endl;
        //     };
        // };
    };

//     // * Метод получения запросов из файла requests.json
//     // * @return возвращает список запросов из файла requests.json
    std::vector<std::vector<std::string>> ConverterJSON::GetRequests()
    {
        readRequests();
        return requests;
    };

    std::string num001(std::string num)
    {
        while (num.size()<3)
        {
            num = "0" + num;
        };
        return num;
    };

    // * Положить в файл answers.json результаты поисковых запросов
    void ConverterJSON::putAnswers(std::vector<std::vector<RelativeIndex>> answers)
    {
        std::ofstream file("resources/answers.json");
        if (!(file.is_open()))
        {
            std::cout << "The file 'answers.json' is not open! \n";
            return;
        };
        
        nlohmann::json j_ans;
        for (size_t i = 0; i < answers.size(); i++)
        {
            std::vector<RelativeIndex> _answer=answers.at(i);
            nlohmann::json j_docs;
            if (_answer.size()<1)
            {
                j_docs["result"] = false;
            } else
            {
                j_docs["result"] = true;
                nlohmann::json j_rel;
                for (size_t k = 0; k < _answer.size(); k++)
                {
                    if (k==max_responses)
                    {
                        break;
                    };
                    
                    nlohmann::json j_d;
                    RelativeIndex doc=_answer.at(k);
                    size_t doc_id = doc.doc_id;
                    size_t rank   = doc.rank;     
                    std::pair<std::pair<std::string, size_t>,std::pair<std::string, size_t>> pr_doc={{"docid",doc_id},{"rank",rank}}; 
                    nlohmann::json j_pr =pr_doc;
                    j_rel.push_back(j_pr);

                    // log out
                    std::cout << "answer №" << i << ": " << doc_id << " : " << rank << "\n";
                };                

                j_docs["relevance"] = j_rel;
            };
            
            std::string num = std::to_string(i+1);     
            j_ans["request"+num001(num)]=j_docs;
        };
        
        nlohmann::json j;
        j["answers"]=j_ans;

        auto j_str = to_string(j); 
        //dict >> file;
        file << j_str << std::endl;
        file.close();
    };    
//};


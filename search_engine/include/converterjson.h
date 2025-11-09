#pragma once

#include <string>
#include <vector>

#include "search.h"

//* Класс для работы с JSON-файлами
class ConverterJSON
{ 
    private:
        std::string name;        
        float version;  
        int max_responses;
        std::vector<std::string> filesNames;
        std::vector<std::string> files;
        std::vector<std::vector<std::string>> requests;
    public:
        
        ConverterJSON() = default;
        ~ConverterJSON();

        std::string getConfigName();

        void readFiles();

        void readSettings();

        std::vector<std::string> getFiles();

//     //* Метод получения содержимого файлов
//     //* @return Возвращает список с содержимым файлов перечисленных в config.json

//     // * Метод считывает поле max_responses для определения предельного
//     // * количества ответов на один запрос * @return
        int GetResponsesLimit();

        void readRequests();

//     // * Метод получения запросов из файла requests.json
//     // * @return возвращает список запросов из файла requests.json
        std::vector<std::vector<std::string>> GetRequests();

//     // * Положить в файл answers.json результаты поисковых запросов
        void putAnswers(std::vector<std::vector<RelativeIndex>>);

};


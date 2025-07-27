#include <string>
#include <map>
#include <vector>
//#include <algorithm>

#include <iostream>
#include <fstream>

#include "search.h"

// struct Entry 
// {
//     size_t doc_id, count;
//     // Данный оператор необходим для проведения тестовых сценариев
//     bool operator ==(const Entry& other) const 
//     {
//         return (doc_id == other.doc_id && count == other.count);
//     };
// };

// class InvertedIndex
// {
// private:
//     std::vector<std::string> docs; // список содержимого документов
//     std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь
// public:
    // InvertedIndex() = default;
    
    // * Обновить или заполнить базу документов, по которой будем совершать поиск
    // * @param texts_input содержимое документов
    void InvertedIndex::UpdateDocumentBase(std::vector<std::string> list_docs)
    {   
        docs.clear();
        size_t nDoc=0;
        for (auto i : list_docs) //  list line in docs
        {

            //for (auto i : list_docs) //  list line in docs
            std::ifstream file(i);
            if (file.is_open()!=true)
            {
                std::cout << "File: " << i << " is not open! \n";
                continue;
            };
            
            std::vector<std::string> doc;
            
            std::string line="";
            while (!file.eof())
            {
                file >> line;
                docs.push_back(line);
                std::string newWord = "";
                //char letter=' ';
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

                        std::vector<Entry> vecEntry = freq_dictionary[newWord];
                        //for (auto e : entry)
                        bool entryIs = false;
                        for (int n=0; n<vecEntry.size(); n++)
                        {
                            Entry entryV;
                            entryV = vecEntry.at(n);
                            size_t id    = entryV.doc_id;
                            if (id != nDoc)
                            {
                                continue;
                            };
                            entryIs=true;
                            size_t count = entryV.count;
                            entryV.count++;
                            vecEntry[n] = entryV;
                            freq_dictionary[newWord]=vecEntry;
                            break;
                        };
                        
                        if (entryIs != true)
                        {
                            Entry entryV;
                            entryV.doc_id = nDoc;
                            entryV.count = 1;
                            std::vector<Entry> vecEntry;
                            vecEntry.push_back(entryV);
                            freq_dictionary[newWord]=vecEntry;
                        };
                        
                        newWord="";
                    };

                }; // end character
            
            }; // end line

            file.close();
            nDoc++;
        }; // end name
        return;
    };


    // void indexingDocs()    // {    // };

    // * Метод определяет количество вхождений слова word в загруженной базе документов
    // * @param word слово, частоту вхождений которого необходимо определить
    // * @return возвращает подготовленный список с частотой слов
    std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word)
    {
        std::vector<Entry> wordEntry;
        wordEntry = freq_dictionary[word];
        return wordEntry;        
    };

// };

struct RelativeIndex
{
    size_t doc_id;
    float rank;
    bool operator ==(const RelativeIndex& other) const 
    {
        return (doc_id == other.doc_id && rank == other.rank);
    };
};

// class SearchServer
// {
// private:
//     InvertedIndex _index;
// public:
    
    // /**
    // * @param idx в конструктор класса передаётся ссылка на класс
    // InvertedIndex,
    // * чтобы SearchServer мог узнать частоту слов встречаемых в
    // запросе
    // */
    //SearchServer(InvertedIndex& idx) : _index(idx)
    SearchServer::SearchServer(InvertedIndex& idx)
    { 

    };

    //SearchServer::readRequestJson(){    };

    // /**
    // * Метод обработки поисковых запросов
    // * @param queries_input поисковые запросы взятые из файла
    // requests.json
    // * @return возвращает отсортированный список релевантных ответов для
    // заданных запросов
    // */
    std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& queries_input)
    {
        std::vector<std::vector<RelativeIndex>> listAnswer;



        return listAnswer;
    };

    // SearchServer::~SearchServer()
    // {
        
    // };
//};


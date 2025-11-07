#include <string>
#include <map>
#include <vector>
//#include <algorithm>

#include <iostream>
#include <fstream>

#include <thread>
#include <mutex>

#include "../include/search.h"

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
//     //std::vector<std::vector<std::string>> docs; // список содержимого документов

//     std::mutex mtx;
//     std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь
// public:
    // InvertedIndex() = default;

    //void wordPlus(std::vector<Entry> vecEntry, std::string newWord)
    void InvertedIndex::wordPlus(std::string* newWord, size_t nDoc)
    {
        std::string newW = *newWord;

        // log out
        //std::cout << newW << std::endl;

        //std::mutex mtx;
        mtx.lock();
        //std::map<std::string, std::vector<Entry>>* dictionary=&freq_dictionary;
        //std::vector<Entry> vecEntry = dictionary->at(newW);
        std::vector<Entry> vecEntry = freq_dictionary[newW];
        //for (auto e : entry)

        if (vecEntry.size()==0)
        {
            Entry entryV;
            entryV.doc_id = nDoc;
            entryV.count = 1;
            vecEntry.push_back(entryV);

            // std::mutex mtx;
            // mtx.lock();
            //dictionary->at(newW)=vecEntry;
            freq_dictionary[newW]=vecEntry;
            // mtx.unlock();
            mtx.unlock();
            *newWord="";
            
            return;
        };
        
        // std::mutex mtx;
        // mtx.lock();
        bool iddocIs = false;
        for (int n=0; n<vecEntry.size(); n++)
        {
            Entry entryV;
            entryV = vecEntry.at(n);
            size_t id    = entryV.doc_id;
            if (id != nDoc)
            {
                continue;
            };

            //size_t count = entryV.count;
            entryV.count++;
            vecEntry[n] = entryV;

            // std::mutex mtx;
            // mtx.lock();
            //dictionary->at(newW)=vecEntry;
            freq_dictionary[newW]=vecEntry;
            // mtx.unlock();
            iddocIs=true;
            break;
        };     
        
        if (iddocIs==false)
        {
            Entry entryV;
            entryV.doc_id = nDoc;
            entryV.count = 1;
            
            vecEntry.push_back(entryV);
            // std::mutex mtx;
            // mtx.lock();
            //dictionary->at(newW)=vecEntry;
            freq_dictionary[newW]=vecEntry;
            // mtx.unlock();

            *newWord="";
        };
        mtx.unlock();

        *newWord="";
    };
    
    // * Обновить или заполнить базу документов, по которой будем совершать поиск+
    // * @param texts_input содержимое документов
    void InvertedIndex::UpdateDocumentBase(std::vector<std::string> list_docs)
    {   
        docs.clear();
        //size_t nDoc=0;
        //for (auto i : list_docs) //  list line in docs
        for (auto i = 0; i <  list_docs.size(); i++) //  list line in docs
        {
            // //nDoc++;
            // //std::vector<std::string> doc;
            // std::string doc="";
            // std::string line="";

            // //for (auto i : list_docs) //  list line in docs
            // std::ifstream file(i);
            // if (file.is_open()!=true)
            // {
            //     std::cout << "File: " << i << " is not open! \n";
            //     continue;
            // };
            
            // while (!file.eof())
            // {
            //     file >> line;
            //     doc= doc +" "+ line;
 
            // }; // end file

            // docs.push_back(doc);

            // file.close();

            docs.push_back(list_docs[i]);

        }; // end name

        // log out
        //outContentDocs();

        //return;
    };

    void InvertedIndex::indexD(const std::string* line, size_t i)    
    {
                int words=0;
                std::string newWord = "";

                // log out
                //setlocale(LC_ALL, "en");
                // setlocale(LC_ALL, "");
                // std::cout << "Str. -1: " << *line << std::endl;

                //for (auto k : line) // selecting characters in a string
                //{
                char k = ' ';
                for (size_t n = 0; n < line->size(); n++)
                {
                    k=line->at(n);
                    
                    //if (((k>='A')&(k<='Z')) || ((k>='a')&(k<='z')))
                    //if ((k>='a') & (k<='z'))
                    if (islower(k))
                    {
                        newWord=newWord + k;

                        // log out
                        // std::cout << n << ") " << k << std::endl;

                        continue;
                    } else {
                        //std::cout << k << std::endl;
                    };

                    if (newWord.size()<1)
                    {
                        continue;
                    // } else if ((!islower(k)) && (newWord.size()>0))
                    };

                    if(newWord.size()>100)
                    {
                        std::cout << "Doc " << i << ". The word length is more than 100 characters.\n";  
                        //std::cout << newWord << std::endl;
                        newWord="";                        
                        continue;
                    };
                   
                    words++;   
                    
                    // std::mutex mtx;
                    // mtx.lock();
                    wordPlus(&newWord, i);
                    //mtx.unlock();

                    newWord=""; 
                    if (words==1000)
                    {                        
                        break;
                    };        
                };
                // end line

                // log out
                //std::cout << std::endl;
                // log out
                //std::cout << newWord << std::endl;   

                if (newWord.size()>0)
                {
                    words++;               
                    if(newWord.size()>100)
                    {
                        std::cout << "Doc " << i << ". The word length is more than 100 characters.\n";
                        newWord="";  
                        //return;
                    }else if (words>1000)
                    {                        
                        //return;
                    } else
                    {
                        wordPlus(&newWord, i); 
                    };                                
                };                
                
                if (words>1000)
                {
                    std::cout << "Doc " << i << ". The number of words has reached " << words << ".\n";
                };
        //return 1;
    };

    void InvertedIndex::outContentDocs()
    {
        setlocale(LC_ALL, "");
        //std::wcout << L"Привет мир!" << std::endl;
        //for (size_t i = 0; i < freq_dictionary.size(); i++)
        // for (const auto& [word, entries] : docs)        
        for (const auto& line : docs)        
        {
            //std::map mp=freq_dictionary[i];
            //std::vector<entry> vec=entries;
            // for (auto entryV : entries)
            // {
                // std::cout << word << ": " << entryV.doc_id << " - " << entryV.count << "\n";
                // //std::wcout << word << ": " << entryV.doc_id << " - " << entryV.count << std::endl;
                std::cout << line << std::endl;
            // };          
        };
    };

    void InvertedIndex::outContentFreqDictionary()
    {
        setlocale(LC_ALL, "");
        //std::wcout << L"Привет мир!" << std::endl;
        //for (size_t i = 0; i < freq_dictionary.size(); i++)
        for (const auto& [word, entries] : freq_dictionary)        
        {
            //std::map mp=freq_dictionary[i];
            //std::vector<entry> vec=entries;
            for (auto entryV : entries)
            {
                std::cout << word << ": " << entryV.doc_id << " - " << entryV.count << "\n";
                //std::wcout << word << ": " << entryV.doc_id << " - " << entryV.count << std::endl;
            };          
        };
    };

    void InvertedIndex::sortingDict()
    {
        // for (size_t k = 0; k < freq_dictionary.size(); k++)
        for (const auto& [word, entries] : freq_dictionary)   
        {     
            std::vector<Entry> vec = entries;
            bool swapped;
            for (size_t k = 0; k < vec.size(); k++)
            {
                swapped = false;
                for (size_t j = 0; j < vec.size() - k - 1; j++)
                {
                    if (vec[j].count > vec[j + 1].count) 
                    {
                        std::swap(vec[j], vec[j + 1]);
                        swapped = true;
                    };
                };
                if (!swapped) 
                {
                    break;
                };
            };
            freq_dictionary[word]=vec;
        }; 
    };

    void InvertedIndex::indexingDocs()    
    {   
        std::vector<std::thread> threads;  
        for (int i = 0; i < docs.size(); i++) 
        {  
            std::string line=docs[i];
            threads.emplace_back([&](){ indexD(&line, i); });
        }; 
        // Дождаться завершения всех потоков  
        for (auto &thread : threads) 
        {  
            thread.join();  
        };

        // for (int i = 0; i < docs.size(); i++) 
        // {  
        //     std::string line=docs[i];
        //     indexD(&line, i);
        // }; 

        // log out
        outContentDocs();

        sortingDict();
        
        // log out
        outContentFreqDictionary();
    };

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

// struct RelativeIndex
// {
//     size_t doc_id;
//     float rank;
//     bool operator ==(const RelativeIndex& other) const 
//     {
//         return (doc_id == other.doc_id && rank == other.rank);
//     };
// };

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
        _index = idx;
    };

    // /**
    // * Метод обработки поисковых запросов
    // * @param queries_input поисковые запросы взятые из файла
    // requests.json
    // * @return возвращает отсортированный список релевантных ответов для
    // заданных запросов
    // */
    std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::vector<std::string>>* queries_input)
    {
        std::vector<std::vector<RelativeIndex>> listAnswers;

        //std::map<std::string, std::vector<Entry>> dict=_index.freq_dictionary;

        for (size_t i = 0; i < queries_input->size(); i++)
        {
            std::vector<std::string> queri= queries_input->at(i);

            std::vector<RelativeIndex> answerListDocs;
            //bool result = false;

            std::map<size_t,size_t> ranks;
            for (size_t k = 0; k < queri.size(); k++)
            {
                std::string word = queri[k];
                std::vector<Entry> docsWord= _index.GetWordCount(word);
                for (size_t p = 0; p < docsWord.size(); p++)
                {
                    Entry entryL = docsWord[p];
                    size_t doc_id = entryL.doc_id;
                    size_t count  = entryL.count;
                    ranks[doc_id]=ranks[doc_id]+count;
                };                
            };

            size_t rankMax=0;
            for (auto [key , val]: ranks)
            {
                if (val>rankMax)
                {
                    rankMax=val;
                };                
            };

            for (auto [key , val]: ranks)
            {
                RelativeIndex relInd;
                relInd.doc_id = key;
                relInd.rank   = val/rankMax;
                answerListDocs.push_back(relInd);
            };

            // for (size_t k = 0; k < answersListDocs.size()-1; k++)
            // {
            //     if (answersListDocs[k].rank<answersListDocs[k+1].rank)
            //     {
            //         RelativeIndex temp;
            //         temp=answersListDocs[k];
            //         answersListDocs[k]=answersListDocs[k+1];
            //         answersListDocs[k+1]=temp;
            //     };                
            // };

            bool swapped;
            for (size_t k = 0; k < answerListDocs.size(); k++)
            {
                swapped = false;
                for (size_t j = 0; j < answerListDocs.size() - k - 1; j++)
                {
                    if (answerListDocs[j].rank < answerListDocs[j + 1].rank) 
                    {
                        std::swap(answerListDocs[j], answerListDocs[j + 1]);
                        swapped = true;
                    };
                };
                if (!swapped) 
                {
                    break;
                };
            };

            // if (ranks.size()<1)
            // {
            //     result=true;
            // };
            listAnswers.push_back(answerListDocs);
            
        };

        return listAnswers;
    };

    // SearchServer::~SearchServer()    // { // };
//};


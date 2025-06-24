#include <iostream>
#include <vector>

#include <converterjson.h>
#include <help.h>
#include <readsettings.h>
#include <search.h>
#include <test.h>

struct Entry 
{
    size_t doc_id, count;

    // Данный оператор необходим для проведения тестовых сценариев
    bool operator ==(const Entry& other) const 
    {
        return (doc_id == other.doc_id && count == other.count);
    }
};

class InvertedIndex
{
private:
    std::vector<std::string> docs; // список содержимого документов
    std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь

public:
    InvertedIndex() = default;

    
    // * Обновить или заполнить базу документов, по которой будем совершать поиск
    // * @param texts_input содержимое документов
    void UpdateDocumentBase(std::vector<std::string> input_docs)
    {

    };
    // * Метод определяет количество вхождений слова word в загруженной базедокументов
    // * @param word слово, частоту вхождений которого необходимо определить
    // * @return возвращает подготовленный список с частотой слов
    std::vector<Entry> GetWordCount(const std::string& word);

};

struct RelativeIndex{
size_t doc_id;
float rank;
bool operator ==(const RelativeIndex& other) const {
return (doc_id == other.doc_id && rank == other.rank);
}
};


//void find(std::string* nameSearch, std::string* rootSearch, bool* fileOnly, std::string* mask){};
void findFiles(std::string* nameSearch);

int main(int numberPS, char** arrayPS){

    std::string nameSearch="name";
    //std::string rootSearch="/";
    //bool fileOnly=true;
    //std::string mask="";
    //bool help=false;

    // std::vector<File> listIndexes;
    // bool indexingDone=false;
    // std::vector<std::string> vecIndexes;

    std::cout << "Welcome to the search!\n";

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


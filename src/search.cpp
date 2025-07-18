#include <string>
#include <map>
#include <vector>

#include "search.h"

void indexingPerformed()
{

};

//void find(std::string* nameSearch, std::string* rootSearch, bool* fileOnly, std::string* mask){};
void findFiles(std::string* nameSearch)
{
    
};

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
    std::vector<Entry> GetWordCount(const std::string& word)
    {
        std::vector<Entry> wordCount;


        return wordCount;        
    };

};

struct RelativeIndex
{
    size_t doc_id;
    float rank;
    bool operator ==(const RelativeIndex& other) const 
    {
        return (doc_id == other.doc_id && rank == other.rank);
    }
};

class SearchServer
{
private:
    //* data */
    InvertedIndex _index;

public:
    //SearchServer();
    
    // /**
    // * @param idx в конструктор класса передаётся ссылка на класс
    // InvertedIndex,
    // * чтобы SearchServer мог узнать частоту слов встречаемых в
    // запросе
    // */
    SearchServer(InvertedIndex& idx) : _index(idx)
    { 

    };

    // /**
    // * Метод обработки поисковых запросов
    // * @param queries_input поисковые запросы взятые из файла
    // requests.json
    // * @return возвращает отсортированный список релевантных ответов для
    // заданных запросов
    // */
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input)
    {
        std::vector<std::vector<RelativeIndex>> listAnswer;

        return listAnswer;
    };


    ~SearchServer()
    {
        
    };
};


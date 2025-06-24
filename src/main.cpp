#include <iostream>
#include <vector>

#include <converterjson.h>
#include <help.h>
#include <readsettings.h>
#include <search.h>

#include <gtest/gtest.h>

TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}

using namespace std;

void TestInvertedIndexFunctionality(const vector<string>& docs,
const std::vector<string>& requests,const std::vector<vector<Entry>>& expected) 
{
    std::vector<std::vector<Entry>> result;
    InvertedIndex idx;
    idx.UpdateDocumentBase(docs);
    for(auto& request : requests) {
        std::vector<Entry> word_count = idx.GetWordCount(request);
        result.push_back(word_count);
    }
    ASSERT_EQ(result, expected);
}
TEST(TestCaseInvertedIndex, TestBasic) {
const vector<string> docs = {
"london is the capital of great britain",
"big ben is the nickname for the Great bell of the striking clock"
};
const vector<string> requests = {"london", "the"};
const vector<vector<Entry>> expected = {
{
    {0, 1}
}, {
    {0, 1}, {1, 3}
    }
    };
    TestInvertedIndexFunctionality(docs, requests, expected);
}
TEST(TestCaseInvertedIndex, TestBasic2) {
const vector<string> docs = {
"milk milk milk milk water water water",
"milk water water",
"milk milk milk milk milk water water water water water",
"americano cappuccino"
};
const vector<string> requests = {"milk", "water", "cappuchino"};
const vector<vector<Entry>> expected = {
{
{0, 4}, {1, 1}, {2, 5}
}, {
{0, 2}, {1, 2}, {2, 5}
}, {
{3, 1}
}
};
TestInvertedIndexFunctionality(docs, requests, expected);
}
TEST(TestCaseInvertedIndex, TestInvertedIndexMissingWord) {
const vector<string> docs = {
"a b c d e f g h i j k l",
"statement"
};
const vector<string> requests = {"m", "statement"};
const vector<vector<Entry>> expected = {
{
}, {
{1, 1}
}
};
TestInvertedIndexFunctionality(docs, requests, expected);
}

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


class ConverterJSON 
{
private:

    
public:
    // 

};

struct RelativeIndex{
size_t doc_id;
float rank;
bool operator ==(const RelativeIndex& other) const {
return (doc_id == other.doc_id && rank == other.rank);
}
};

class SearchServer
{
private:
    //* data */
    InvertedIndex _index;

public:
    SearchServer();
    ~SearchServer();
    // /**
    // * @param idx в конструктор класса передаётся ссылка на класс
    // InvertedIndex,
    // * чтобы SearchServer мог узнать частоту слов встречаемых в
    // запросе
    // */
    SearchServer(InvertedIndex& idx) : _index(idx){ };
    // /**
    // * Метод обработки поисковых запросов
    // * @param queries_input поисковые запросы взятые из файла
    // requests.json
    // * @return возвращает отсортированный список релевантных ответов для
    // заданных запросов
    // */
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input);
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


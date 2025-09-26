#include <fstream>
#include <vector>
#include <string>

//#include "search.h"
//#include "test.h"
//#include <search.h>
#include "../search_engine/include/search.h"
//#include <search.h>

#include <gtest/gtest.h>

// TEST(sample_test_case, sample_test)
// {
//     EXPECT_EQ(1, 1);
// }

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
//     //InvertedIndex() = default; 
//     void UpdateDocumentBase(std::vector<std::string> list_docs)
//     {   
//         docs.clear();
//         size_t nDoc=0;
//         for (auto i : list_docs) //  list line in docs
//         {
//             std::string doc="";
//             std::string line="";
//             std::ifstream file(i);
//             if (file.is_open()!=true)
//             {
//                 std::cout << "File: " << i << " is not open! \n";
//                 continue;
//             };
            
//             while (!file.eof())
//             {
//                 file >> line;
//                 doc= doc +" "+ line;
 
//             }; // end file

//             docs.push_back(doc);

//             file.close();
//         }; // end name
//     };

//     std::vector<Entry> GetWordCount(const std::string& word)
//     {
//         std::vector<Entry> wordEntry;
//         wordEntry = freq_dictionary[word];
//         return wordEntry;        
//     };
    
// };

using namespace std;

void TestInvertedIndexFunctionality(const std::vector<std::string> docs, const std::vector<string>& requests, const std::vector<vector<Entry>>& expected) 
{
    std::vector<std::vector<Entry>> result;
    InvertedIndex idx;
    idx.UpdateDocumentBase(docs);

    for(auto& request : requests) 
    {
        std::vector<Entry> word_count = idx.GetWordCount(request);
        result.push_back(word_count);
    };
    ASSERT_EQ(result, expected);
};

TEST(TestCaseInvertedIndex, TestBasic) 
{
    const vector<string> docs = {"london is the capital of great britain","big ben is the nickname for the Great bell of the striking clock"};
    const vector<string> requests = {"london", "the"};
    const vector<vector<Entry>> expected = {{{0, 1}}, {{0, 1}, {1, 3}}};
    TestInvertedIndexFunctionality(docs, requests, expected);
};

TEST(TestCaseInvertedIndex, TestBasic2) 
{
    const vector<string> docs = {"milk milk milk milk water water water","milk water water","milk milk milk milk milk water water water water water","americano cappuccino"};
    const vector<string> requests = {"milk", "water", "cappuchino"};
    const vector<vector<Entry>> expected = {{{0, 4}, {1, 1}, {2, 5}}, {{0, 2}, {1, 2}, {2, 5}}, {{3, 1}}};
    TestInvertedIndexFunctionality(docs, requests, expected);
}

TEST(TestCaseInvertedIndex, TestInvertedIndexMissingWord) 
{
    const vector<string> docs = {"a b c d e f g h i j k l", "statement"};
    const vector<string> requests = {"m", "statement"};
    const vector<vector<Entry>> expected = {{}, {{1, 1}}};
    TestInvertedIndexFunctionality(docs, requests, expected);
};


#pragma once

#include <string>
#include <vector>

void findFiles(std::string* nameSearch);

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


#include <iostream>
#include <vector>
#include <string>

#include <converterjson.h>
#include <search.h>

int mainSE()
{
    //std::cout << "Welcome to the search!\n";

    ConverterJSON convert;

    // 1) read settings

    convert.readSettings();

    std::cout << "Starting app " << convert.getConfigName() << std::endl;

    std::vector<std::string> input_docs;

    convert.readFiles();

    input_docs=convert.getFiles();

    InvertedIndex indexI;

    indexI.UpdateDocumentBase(input_docs);

    // 2) indexing
    indexI.indexingDocs();
    
    // 3) read request
    convert.readRequests();

    // 4) The query is transformed into a list of words.

    // 5) Documents are being searched in the index
    SearchServer serverS(indexI);

    // 6) The search results are ranked and sorted
    std::vector<std::vector<std::string>> requests=convert.GetRequests();
    std::vector<std::vector<RelativeIndex>> listAnswers = serverS.search(&requests);

    // 7) create answer
    convert.putAnswers(listAnswers);
 
    return 0;
};


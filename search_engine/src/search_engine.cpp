#include <iostream>
#include <vector>
#include <string>

#include <help.h>

#include <converterjson.h>
#include <search.h>


int mainSE()
{

    //std::cout << "Welcome to the search!\n";

    // std::string name;
    // float version;
    // int max_responses;
    // std::vector<std::string> files;

     
    
    // 1) read settings
    // try
    // {    
    ConverterJSON convert;
    convert.readSettings();

    std::cout << "Starting app " << convert.getConfigName() << std::endl;

    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    //     return -1;
    // };  
    std::vector<std::string> input_docs;
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
    //std::vector<std::vector<std::string>>* req=&requests;
    std::vector<std::vector<RelativeIndex>> listAnswers = serverS.search(&requests);

    // 7) create answer
    
    //convert.putAnswers(std::vector<std::vector<std::pair<int, float>>>);
    convert.putAnswers(listAnswers);
 
    

    return 0;
};


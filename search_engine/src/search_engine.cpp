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
    // std::string version;
    // int max_responses;
    // std::vector<std::string> files;

     
    
    // 1) read settings
    // try
    // {    
    ConverterJSON convert;
    convert.readSettings();
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
    

    


    

    // 3) read request

    // 4) The query is transformed into a list of words.

    // 5) Documents are being searched in the index

    // 6) The search results are ranked and sorted

    // 7) create answer
    
 

    return 0;
};


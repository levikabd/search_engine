
The search engine is a console application
(an executable file running on a server or computer)
that performs a search and can be configured via JSON files.

This module allows you to search for files.

1. Before launching the application, the names
of the files that the engine will search for are specified in the configuration file.

2. The search engine must independently crawl all files and
index them so that it can then find the most
relevant documents for any search query.

3. The user sets a request via the requests.json file. A query is
a set of words that you need to use to find documents.

4. The query is transformed into a list of words.
   
5. The index searches for those documents on which all these words occur.
    
6. Search results are ranked, sorted and given to the user,
The maximum number of possible documents in the response is set in
the configuration file.

7. At the end, the program generates the answers file.the json that records
the search results.


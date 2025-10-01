
The search engine is a console application
(an executable file running on a server or computer)
that performs a search and can be configured via JSON files.

The principle of operation of the search engine is as follows: 

- In the configuration file (config.json), before launching the application, the names
of the files that the engine will search for are set.

- The search engine crawls all the files and
indexes them so that it can then find the most relevant documents for any search query.

- The user sets a request via the requests.json file. The request is
a set of words to use to find documents.

- The query is transformed into a list of words.

- The index searches for those documents on which all these words occur.

- The search results are ranked, sorted and given to the user, the maximum number of possible documents in the response is set in
the configuration file.

- At the end, the program generates the answers file.the json that records the search results.


After the program is built, the search_engine executable file will be located in the search_engine build directory, as well as the "files" directory (with test files for searching) and "resources" (there are four files in it: answers.json, answers_example.json, config.json and request.json).
Specify the names of the files to be searched in config.
Write the required expressions to the request file.
Launch search_engine.
See the search results in the answers file.

If the program does not find the config or file to search for, a warning will be issued.
If a word is more than 100 letters long, the word will be skipped and will not be included in the search.
Only the first 1000 words from the document are included in the search.

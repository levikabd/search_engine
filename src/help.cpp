#include <string>

void getHelp(std::string* helptxt){

*helptxt+="\n This module allows you to search for files.";
*helptxt+="\n Settings file: settings.json";
*helptxt+="\n List of available parameters:";
*helptxt+="\n ";
*helptxt+="\n Param request file: requests.json";
*helptxt+="\n a set of words for which to find documents";
*helptxt+="\n ";

};
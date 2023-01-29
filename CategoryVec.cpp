#include "CategoryVec.h"

//members that initialized in the .h file: Vec feature, std::string category

std::string CategoryVec::copySubStr(std::string str,int from, int until){
    int i;
    //initialize a string
    std::string returnVal = "";
    //take one char at a time and add it to the return string
    for(i = from;i<until;i++){
        returnVal+=str.at(i);
    }
    return returnVal;
}

void CategoryVec::extractVec(std::string str){
    int i = 0;
    //find the index of the space or comma between the numbers and the category
    while(str.at(i) != ';'){
        i++;
    }
    //extract the part of the string which contains the numbers from the string into vec
    std::string vec = copySubStr(str,0,i);
    //insert the rest of the string, which contains the category, into 'category'
    category = copySubStr(str,i+1,str.length());
    //insert the part of the string which contains the numbers into 'feature'
    Vec::insertToVec(vec);
}

std::string CategoryVec::getCat(){return category;}

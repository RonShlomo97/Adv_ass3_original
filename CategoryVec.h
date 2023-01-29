#ifndef symbol_CV_H_
#define HEADER_CV_H_

#include <iostream>
#include "Distance.h"

//this class functions as same as Vec class, only it includes a 'category' field
class CategoryVec: public Vec{

//members:
    std::string category;

/// @brief takes a string and return a sub string of if.
/// @param str the original string
/// @param from starting index
/// @param until ending index(not included)
/// @return substring.
    std::string copySubStr(std::string str,int from, int until);

public:
/// @brief gets a string of values separated with spaces or commas. all the values are numbers, except for the
///        last value, which contains the category name. the function insert the numbers into 'feature' and the
///        last value in 'category'
/// @param str the string of values
    void extractVec(std::string str);


/// @brief getter for the category
/// @return category
    std::string getCat();

};
#endif

#ifndef symbol_DATA_H_
#define HEADER_DATA_H_

#include <iostream>
#include <string>

//this class is a tuple, contains the category of a CategoryVec and the distance from it to the input vector
class DataSimilarityItem{
    std::string category;
    double various;

public:
/// @brief setter method for 'category'.
/// @param cat the category to set
    void setCategory(std::string cat);

/// @brief setter for 'various', the distance of a vector to the input vector.
/// @param dis
    void setVarious(double dis);

/// @brief getter for the difference between the vectors
/// @return the difference between the vectors
    double getVarious();

/// @brief getter for the category
/// @return string of the category
    std::string getCategory();
};

#endif
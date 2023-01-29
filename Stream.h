#ifndef ADV_PROG1_ASS_STREAM_H
#define ADV_PROG1_ASS_STREAM_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

///this class allows us to separate lines from a csv file and convert them into strings
class Stream{
public:
    /// \brief this function convert csv lines into strings
    /// \param fileName is the path of the file
    /// \return a vector of the strings
    std::vector<std::string> csvLineToString(const std::string fileName);
};
#endif //ADV_PROG1_ASS_STREAM_H

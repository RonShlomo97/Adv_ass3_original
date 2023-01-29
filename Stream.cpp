#include "Stream.h"

// the class has no members, and therefore, doesn't need any ctor.

std::vector<std::string> Stream::csvLineToString(const std::string fileName)
{
    //content is a 2 dimensional vector which contain every cell from the csv file in its own cells
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;
    // openning the file
    std::ifstream file;
    try{
    file.open(fileName);
    }
    catch(...){ std::cout<<"oops\n";}
    //if the file opened properly
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
        //if the file could not be opened for some reason, we'll get out of the program
    else {
        std::cout<<"Ooopsi\n";
    }
    //lines will contain the strings
    std::vector<std::string> lines;
    //the loop below runs by every row in the csv file, which represents a string
    for(int i=0;i<content.size();i++)
    {
        //the loop below runs by every cell in the 'i' row
        for(int j=0;j<content[i].size();j++)
        {
            //if we are at the first cell in the row
            if (j == 0) {
                //concatenate the cell's content with the empty string
                content[i][0].append(" ");
            }
                //if we are at the last cell in the row
            else if (j == content[i].size() - 1) {
                //concatenate the cell's content with the string as it is so far
                content[i][0].append(content[i][j]);
            }
                //if we got to the last number, we'll divide it from the category with a ';'
                else if (j == content[i].size() - 2) {
                //concatenate the cell's content with the string as it is so far
                content[i][0].append(content[i][j]);
                //separate the numbers from the category
                content[i][0].append(";");
            }
            else {
                //concatenate the cell's content with the string as it is so far
                content[i][0].append(content[i][j]);
                content[i][0].append(" ");
            }

        }
        //enter the string into 'lines'
        lines.push_back(content[i][0]);
    }
    file.close();
    return lines;
}

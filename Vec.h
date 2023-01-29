#pragma once

#include <string>
#include <vector>

//This class allows us to perform additional methods on those known on a regular vector
class Vec {
private:
    bool validInput;
    // the dimension is the number of elements in 'v'.
    std::vector<double> v;
    int dimension;

    /// \brief print the string in the function below
    /// \return 0.
    int illegalInputException();

    /// @brief chek if a letter is e or E and if so, update flag to true and returm true. o.w retuen false
    /// @param letter the caher
    /// @param flag to update
    /// @return true/false
    bool isE(char letter);
    /// @brief add a string as a double var to 'v' and update the dimension
    /// @param n the number as string
    /// @return 1 if the operation succeeded, o.w. returns 0
    int addNumToVec(std::string &n, bool isNagetive);

    /// @brief method that get an input as a string
    /// @param str the string we insert into the input
    /// @return the size of the input
    int getLineInput(std::string &str);

    /// @brief get char return true and update flag if is - or +. o. return false
    /// @param simbol the char
    /// @param flag for the update
    /// @return true/false
    bool isPlusOrMInus(char simbol);

    bool checkForE(std::string str, int &i, int strLen, std::string &num, bool &flag);


    /// @brief initialize this vector
    void initVec();

    /// @brief method that checks a char is '-' according to ascii table
    /// @param st the given char
    /// @return true if it is minus and false o.w
    bool isNegativeNum(char st);



    /// @brief method that check if a char is space ' ' according to ascii table
    /// @param str the given char
    /// @return true if it is a space
    bool isSpaceChar(char str);

    /// @brief method that check if a char is a dot according to ascii table, in cases of a real number
    /// @param ch the given char
    /// @return true if it is a dot
    bool isRealNum(char ch);


    /// @brief get the absolute value of the difference between this vec and the other vec at the index i
    /// @param other is the second vec
    /// @param i is the index
    /// @return the absolute distance between the 'i' elements in the vectors
    double differenceAtIndex(Vec other, int i);


    /// @brief This function checks whether two vectors has the same amount of elements
    /// @param other vec
    /// @return true if the vectors have the same amount of elements. o.w. returns false
    bool isValidDisOp(Vec other);

public:
    /// @brief ctor
    Vec();

    /// @brief method that check if a char is a digit according to ascii table
    /// @param num the given char
    /// @return true if it is a digit
    bool isValidNumber(char num);

    /// @brief setter for number in this vector on index i
    /// @param i the index
    /// @param val the value
    void setAt(int i, double vall);

    /// @brief insert new additional value to this vector
    /// @param vall the value to add to 'v'
    void addNewVal(double val);

    /// @brief return the 'i' element in 'v'
    /// @param i the index of the asked value
    /// @return v[i]
    double at(int i);

    /// @brief return the vector
    /// @return return the vector
    std::vector<double> getVec();

    /// @brief get the dimension of the vector
    /// @return the dimension of the vector
    int getDimension();

    /// @brief method that get a string from the user, checks if the string represents a vector of numbers.
    /// @return 1 if the insertion succeeded. o.w. return 0.
    int userInput();

    /// @brief method that gets a string represents a numbers vector, check if the input is a proper numbers vector and
    ///        insert the input to 'v'.
    /// @param temp the input string
    /// @return 1- input succeed 0- illegal input
    int insertToVec(std::string temp);


    /// @brief creates a string containing 'v' elements
    /// @return string of 'v' elements
    std::string toString();

    /// \brief print all the elements in 'v'
    void print();

    /// this method checks whether a double var contains an integer
    /// \param num is a real number
    /// \return 1 if num is an integer. o.w. returns 0.
    bool ifInteger(double num);

    bool isWasValidInput();

};

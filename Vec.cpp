#include "Vec.h"
#include <iostream>

const double P_FOR_MINKOWSKI_DIS = 2;
const int SPACE = 32, DOT = 46, ZERO = 48, NINE = 57, COMMA = 44;
const int E_LETTER = 101, E_CAP_LETTER = 69, PLUS = 43, MINUS = 45;
const std::string DOT_STRING = ".", SPACE_STRING = " ";

// members: std::vector<double> v, int dimension
// the dimension is the number of elements in 'v'.

int Vec::addNumToVec(std::string &n, bool isNegative)
{
    try
    {
        // if the string isn't empty
        if (!n.empty())
        {
            // convert n into a double var
            double num = stod(n);
            if (isNegative)
            {
                num = num * (-1);
            }
            // add 'n' to 'v' as a double
            v.push_back(num);
            n.clear();
            (this->dimension)++;
            return 1;
        }
    }
    catch (...)
    {
        validInput = false;
    }
    return 0;
}

int Vec::getLineInput(std::string &str)
{
    getline(std::cin, str);
    // return tempLen so we can use its length later
    return str.size();
}

void Vec::initVec()
{
    // clear this vector from values and sets the dimension as 0
    v.clear();
    dimension = 0;
}

bool Vec::isE(char letter)
{
    if (letter == E_LETTER || letter == E_CAP_LETTER)
    {
        return true;
    }
    return false;
}

bool Vec::checkForE(std::string str, int &i, int strLen, std::string &num , bool &flag)
{
    //number that start or end with e in not valid
    if(((i == 0)||(i==strLen - 1)) && (isE(str[i]))){return false;}
    //number the end with + or - in not valid
    if((i == strLen - 1)&&(isPlusOrMInus(str[i]))){return false;}

    //we know that e is not the last number
    if(isE(str[i])){
        num.append("e");
        i++;
        if(isPlusOrMInus(str[i])){
            //the number end with e+ otr e- and it is not good
            if(i == strLen -1){
                return false;
            }
            //if we get here its not the last number so we add it and update i
            if(str[i] == MINUS){num.append("-");}
            if(str[i] == PLUS){num.append("+");}
            
            i++;
        }
        flag = true;
    }
    return true;
}

bool Vec::isPlusOrMInus(char simbol)
{
    if (simbol == PLUS || simbol == MINUS)
    {
        return true;
    }
    return false;
}

bool Vec::isNegativeNum(char st)
{
    if (st == MINUS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Vec::isValidNumber(char num)
{
    if (num >= ZERO && num <= NINE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Vec::isSpaceChar(char str)
{
    if ((str == SPACE) || (str == COMMA))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Vec::isRealNum(char ch)
{
    if (ch == DOT)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Vec::differenceAtIndex(Vec other, int i)
{
    return abs(v.at(i) - other.at(i));
}

bool Vec::isValidDisOp(Vec other)
{
    if (dimension == other.getDimension())
    {
        return true;
    }
    else
    {
        return false;
    }
}

Vec::Vec()
{
    dimension = 0;
    validInput = true;
}


void Vec::setAt(int i, double val)
{
    v.at(i) = val;
}

void Vec::addNewVal(double val)
{
    v.push_back(val);
}

double Vec::at(int i) { return v.at(i); }

std::vector<double> Vec::getVec()
{
    return v;
}

int Vec::getDimension()
{
    return dimension;
}

int Vec::illegalInputException()
{
    validInput = false;
    return 0;
}

int Vec::userInput()
{
    // string temp will contain the input
    std::string temp;
    // get input to temp and for running over the string, we'll save tempLen
    int tempLen = ZERO;
    tempLen = getLineInput(temp);
    // if there is no input, we'll throw an exception
    if (tempLen == 0)
    {
        return illegalInputException();
    }
    // else, lets try to insert the input to the vector
    return insertToVec(temp);
}

int Vec::insertToVec(std::string temp)
{
    // num will contain each element from temp
    std::string num;
    int tempLen = temp.length();
    // initialize 'dimension' and 'v'
    initVec();
    // flags for input numbers:
    // isAdded will be 1 for number that successfully inserted into the vector
    int isAdded = ZERO;
    // isFirstDigit is a flag that indicates that we checked the first digit in the element
    bool isFirstDigit = true;
    // isNegativeNumber flag that indicate if the number is negative
    bool isNegativeNumber = false;
    // isRealNumber will indicate if this is a real number, if '.' was one of the chars in the number
    bool isRealNumber = false;
    // usedChar will indicate if the char was already checked.
    bool usedChar = false;
    // flag for e or E just one time in a number.
    bool eFlad = false;

    // the loop will check the input and save it in 'v'
    // int 'i' is an iterator for the loop
    int i;
    for (i = 0; i < tempLen; i++)
    {
        if(!eFlad){
            bool isValid = checkForE(temp,i,tempLen,num,eFlad);
            if(!isValid){return illegalInputException();}
        }

        
        // check if the first char is a digit
        if (isFirstDigit)
            // if the first char is a dot
            if (isRealNum(temp[i]))
            {
                num.append("0.");
            }
        // if the first char is a '-'
        if (isNegativeNum(temp[i]))
        {
            isNegativeNumber = true;
            i++;
            usedChar = false;
        }
        // we're no longer on the first char of the element after this line
        isFirstDigit = false;
    

    if (i == tempLen - 1)
    {
        // if the last digit doesn't end with a digit
        if ((isRealNum(temp[i]) || isNegativeNum(temp[i]) || isSpaceChar(temp[i])))
        {
            return illegalInputException();
        }
    }
    // check if the char is a digit
    if (isValidNumber(temp[i]))
    {
        // insert the value the char represents to 'num'
        num.append(std::to_string(temp[i] - ZERO));
        // for the last digit
        if (i == tempLen - 1)
        {
            addNumToVec(num, isNegativeNumber);
        }
        // sign this char as checked
        usedChar = true;
    }
    if (!isRealNumber)
    {
        if (isRealNum(temp[i]))
        {
            if (!isValidNumber(temp[i + 1]))
            {
                return illegalInputException();
            }
            num.append(DOT_STRING);
            isRealNumber = true;
            usedChar = true;
        }
    }
    // if we got to a ' '
    if (isSpaceChar(temp[i]))
    {
        // isAdded will indicate if the inserted succeeded
        isAdded = addNumToVec(num, isNegativeNumber);
        // initialize the flags
        isNegativeNumber = false;
        isFirstDigit = true;
        isRealNumber = false;
        usedChar = true;
        eFlad = false;
        // if the element wasn't inserted to 'v'
        if (isAdded != 1)
        {
            initVec();
            return illegalInputException();
        }
    }

    // o.w it's not space nor a number, so it's undefined
    // we can know that this is not a defined number if usedChar == false
    else if (usedChar == false)
    {
        initVec();
        return illegalInputException();
    }
    else
    {
        usedChar = false;
    }
    }
return 1;
}

std::string Vec::toString()
{
    std::string str;
    // take all the elements from 'v' and save them in the string st by their order in 'v'
    for (int i = 0; i < dimension; i++)
    {
        str.append(std::to_string(v.at(i)));
        // split the elements in the strings with spaces
        str.append(SPACE_STRING);
    }
    return str;
}

void Vec::print()
{
    std::cout.precision(10);
    for (int i = 0; i < dimension; i++)
    {
        std::cout << v.at(i);
        // if we have an integer, we'll print it with a floating point
        if (ifInteger(v.at(i)))
            std::cout << ".0 ";
        else
            std::cout << " ";
    }
}

bool Vec::ifInteger(double num)
{
    return (num == (int)num);
}

bool Vec::isWasValidInput(){
    return validInput;
}

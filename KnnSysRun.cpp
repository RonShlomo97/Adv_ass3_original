#include "KnnSysRun.h"

//string pathFile;
std::vector<std::string> lines;

KnnSysRun::KnnSysRun(){}

/// @brief copy the what in the range of [i, j-1] to string and retuen this string
/// @param i start
/// @param j end
/// @param from the array
/// @return string in the range
std::string KnnSysRun::charArrayToString(int i, int j, char from[])
{
    int start = i;
    char *str = new char[j - i];
    for (; start < j; start++)
    {
        std::cout << from[start];
        str[start] = from[start];
    }
    return str;
}

/// @brief method that rturn the size
/// @param arr 
/// @return size
int KnnSysRun::getLen(char arr[])
{
    int i = 1;
    for (; arr[i] != '\n'; i++)
    {
    }
    return i;
}

/// @brief method that copy sub string from i to j
/// @param str 
/// @param i from
/// @param j to
/// @return substring
std::string KnnSysRun::copySubstr(std::string str, int i, int j)
{
    std::string subStr = "";
    while (i < j)
        subStr += str[i++];
    return subStr;
}

/// @brief method that skip of spaces in a string
/// @param str 
/// @param from 
/// @return index affter spases
int KnnSysRun::skipSpaces(string str,int from){
    while(isspace(str[from]) && (from != '\0')){from++;}
    if(str[from] == '\0'){return -1;}
    return from;
}

/// @brief method that set value from a string
/// @param buff 
/// @param start 
/// @param vec 
/// @param i 
/// @param j 
/// @param len 
/// @return -1 if there was a problem
int KnnSysRun::setVecFromFullString(string buff,int &start, string &vec, int &i, int &j, int len){
    // while from the start we see input that can be number
    while ((std::isdigit(buff[i]) || std::isspace(buff[i]) ||
            buff[i] == ',' || buff[i] == 'E' || buff[i] == 'e'))
    {
        //j is index for the last charecter in the vector that is not space
        if(!isspace(buff[i])){j = i;}
        i++;
        if (i >= len)
        {
            return -1;
        }
    }
    // copy to vec the string (j is the last char of the vec so we will send j+1 to copy the j cahr also)
    vec = copySubstr(buff, start, j+1);
    return 1;
}

/// @brief method that set value from a string
/// @param buff 
/// @param start 
/// @param vec 
/// @param i 
/// @param j 
/// @param len 
/// @return -1 if there was a problem
int KnnSysRun::setDisAlgoFromFullString(string buff,int &start, string &disAlgo, int &i, int &j, int len){
        while (!(std::isspace(buff[i])) || (buff[i] == '\0'))
    {
        i++;
        if (i >= len)
        {
            return -1;
        }
    }
    // copy to algo the string
    disAlgo = copySubstr(buff, start, i);
    return 1;
}

/// @brief method that set value from a string
/// @param buff 
/// @param start 
/// @param vec 
/// @param i 
/// @param j 
/// @param len 
/// @return -1 if there was a problem
int KnnSysRun::setKNumFromFullString(string buff,int &start, string &k, int &i, int &j, int len)
{
        while ((!isspace(buff[i])) && (i < len) && (buff[i] != '\0') && (buff[i] != '\n'))
    {

        i++;
    }
    k = copySubstr(buff, start, i);
    //check that its the end of the input
    
    int t = i+1;
    for(;i<len;i++){
        if(!isspace(buff[i])){return -1;}
    }

    if (buff[i] != '\0' && buff[i] != '\n'){return -1;}
    return 1;
}

/// @brief method that from a string extract the vextor, allgorithem and k.
/// @param buff 
/// @param vec 
/// @param disAlgo 
/// @param k 
/// @return if there is a probllem eeturn -1
int KnnSysRun::extractData(std::string buff, std::string &vec, std::string &disAlgo, std::string &k)
{
    // make zreo empty strings for all the strings
    int len = buff.length();
    vec = "";
    disAlgo = "";
    k = "";
    int start = 0;
    int i = 0;
    int j = 0;
    int isWored = 1;
    isWored = setVecFromFullString(buff, start, vec, i, j, len);
    if(isWored == -1){return -1;}
    //puting i as the first next index that is not space
    i = skipSpaces(buff, i);
    //if i is -1 so ther is no chars affter the space and the input is invalid
    if(i == -1){return -1;}
    //if i after the skipspace is equal to j+1 so there are not spaces and this is invalid
    if(i == j+1){return -1;}

    // update the start for next
    start = i;
    // in this posion we need to get dis algorithem we know that there is no spaces in the algorithem
    isWored = setDisAlgoFromFullString(buff,start,disAlgo, i, j, len);
    if(isWored == -1){return -1;}
    //puting i as the first next index that is not space
    i = skipSpaces(buff, i);
    //if i is -1 so ther is no chars affter the space and the input is invalid
    if(i == -1){return -1;}


    // update the start for next
    start = i;
    i = setKNumFromFullString(buff,start,k, i, j, len);
    //if i is -1 so ther is no chars affter the space and the input is invalid
    if(i == -1){return -1;}
    return 1;
}

/// @brief method thatr return string of error
/// @return 
std::string KnnSysRun::send_error()
{
    return "invalid input";
}

/// @brief method that return true id char is valid digit
/// @param num 
/// @return 
bool KnnSysRun::isValidNumber(char num)
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
/*
/// @brief 
/// @param buffer 
/// @return 
std::string KnnSysRun::charArrToString(char buffer[])
{
    std::string input = "";
}*/

/// @brief with the argument set all the informetion for KNN
/// @param algo 
/// @param k 
/// @param knns 
/// @param v1 
/// @return -1 if there was any problem. 1 o.w
int KnnSysRun::setKNN(std::string algo, int k, KNN_System &knns, Vec v1)
{
    // step 1: creating a Distance object
    Distance dis;
    // getting a vector from the user
    dis.Distance::SetVec1(v1);
    // set the algorithm the user chose to use as 'algo' in the Distance object
    dis.setAlgo(algo);
    if(dis.WasAlgoProblem()){return -1;}
    knns.KNN_System::setDis(dis);
    knns.KNN_System::setK(k);
    return 1;
}

/// @brief method that loud all the data from the file and save it in vector
/// @param pathFile 
/// @return -1 if there was any problem. 1 o,w
int KnnSysRun::loudDataFile(string pathFile){
    // loading a file containing vectors in a form of text lines
    Stream s;

    //'lines' will contain the text lines, after being converted into strings
    lines = s.csvLineToString(pathFile);
    if (lines.empty())
    {
        return -1;
    }
    return 1;
}

/// @brief method that with the knnSystem take the informethin from lines
/// @param knns 
/// @return -1 if there was any priblems
int KnnSysRun::anelizeData(KNN_System &knns)
{

    for (int i = 0; i < lines.size(); ++i)
    {
        knns.KNN_System::insertDataItem(lines[i]);
        if(knns.getDis().WasOperProblem() || knns.getDis().WasAlgoProblem()){return -1;}        
    }
    return 1;
}

/// @brief method that get string and check if its can be valid int of pore
/// @param input 
/// @return the port or if there was a problen -1
int KnnSysRun::stringToPort(std::string input)
{
    int i = 0;
    // A valid port number is any integer between 1 and 65535.
    // Anything outside of this range is considered an invalid port number.
    for (; i < input.length() && i < 8; i++)
    {
        if (!isValidNumber(input[i]))
        {
            return -1;
        }
    }
    int serverPort = std::stoi(input);
    if (serverPort > 65535 || serverPort < 0)
    {
        return -1;
    }
    return serverPort;
}

/// @brief methos that cast strinf to int
/// @param n 
/// @return the int or -1  if there was any problem
int KnnSysRun::castToInt(string n)
{
    int len = n.length();
    int i = 0;
    Vec temp;
    bool thereAreSpace = false;
    for (; i < len; i++)
    {
        if (!temp.Vec::isValidNumber(n[i]))
        {
            return -1;
        }
        if (isspace(n[i]))
        {
            thereAreSpace = true;
            break;
        }
    }
    if (thereAreSpace)
    {
        for (; i < len; i++)
        {
            if (!isspace(n[i]))
            {
                return -1;
            }
        }
    }
    try{return stoi(n);}
    catch(...){return -1;}
    
}

/// @brief method that return string of the ansser from the knn
/// @param knn 
/// @param buff 
/// @return res
string KnnSysRun::setRessaltToClient(KNN_System knn, char buff[])
{
    int i = 0;
    string res = knn.KNN_System::findCategory();

    return res;
}

string KnnSysRun::run(char buffer[])
{
    KNN_System *knn = new KNN_System();


    // change the input from char[] to string
    char *str = new char[strlen(buffer)];
    strcpy(str, buffer);
    string buffStr = str;

    // the value we get from the input
    std::string k;
    std::string alg;
    std::string vec;
    int problem = extractData(buffStr, vec, alg, k);
    if(problem == -1){return send_error();}
    //init Vec and number k
    Vec *v = new Vec();
    v->insertToVec(vec);
    int kInt = castToInt(k);
    //if k is too big.
    if(kInt>lines.size()){return send_error();}

    //check if the vec is valid input or the number k is was valid input
    if(!v->isWasValidInput()){return send_error();}
    if(kInt <= 0){return send_error();;}
    
    // seting the value to the knn
    int x = setKNN(alg, kInt, *knn, *v);
    //if there was a problem with the givven alorithem
    if(x<0){return send_error();}
    x = anelizeData(*knn);
    //if during the caculating there was a problem
    if (x == -1){return send_error();} 


    // if get -1 dont change the buffer but update stop to true
    //  get the categoey and return to the client
    string res = setRessaltToClient(*knn, buffer);
    delete v;
    delete knn;
    delete str;
    return res;
}
#include "KNN_System.h"
#include "Vec.h"
#include "Distance.h"
#include <iostream>
#include "Stream.h"
#include <stdio.h>
#include <string.h>

const int ZERO = 48, NINE = 57;
class KnnSysRun
{

    std::vector<std::string> lines;

    /// @brief copy the what in the range of [i, j-1] to string and retuen this string
    /// @param i start
    /// @param j end
    /// @param from the array
    /// @return string in the range
    std::string charArrayToString(int i, int j, char from[]);

    int getLen(char arr[]);

    std::string copySubstr(std::string str, int i, int j);

    int extractData(std::string buff, std::string &vec, std::string &disAlgo, std::string &k);

    int setVecFromFullString(string buff, int &start, string &vec, int &i, int &j, int len);
    int setDisAlgoFromFullString(string buff,int &start, string &disAlgo, int &i, int &j, int len);
    int setKNumFromFullString(string buff,int &start, string &k, int &i, int &j, int len);

    std::string send_error();

    bool isValidNumber(char num);

    std::string charArrToString(char buffer[]);

    int setKNN(std::string algo, int k, KNN_System &knns, Vec v1);



    int stringToPort(std::string input);

    int castToInt(string n);

    int skipSpaces(string str,int from);

    string setRessaltToClient(KNN_System knn, char buff[]);
public:
    KnnSysRun();

    int loudDataFile(string pathFile);

    int anelizeData( KNN_System &knns);

    string run(char buffer[]);
};
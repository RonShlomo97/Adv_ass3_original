#pragma once
#include "Vec.h"
#include <string>
using namespace std;

//This class allows us to calculate the distance between two vectors according to a specific calculating distances
//algorithm, according to the user's request
class Distance{
    bool isWasOperProblem;
    bool isWasAlgoProblem;
    Vec v1;
    Vec v2;
    string algo;

/// @brief checking whether the 2 vectors has the same amount of elements
/// @return true if they're from the same dimension. o.w. return false
    bool isValidDisOp();

/// @brief get the difference between this vec and the other vec at the index i
/// @param other vec
/// @param i index
/// @return the difference
    double differenceAtIndex(int i);

/// \brief checks whether an element in an integer
/// \param num is the number
/// \return true if num is an integer. o.w. return false
    bool ifInteger(double num);

public:
/// @brief default constructor of this class
    Distance();

/// @brief canberra distance function
/// @return the distance between v1 and v2 according to canberra algorithm
    double canberraDis();

/// @brief euclidean distance
/// @return the distance between v1 and v2 according to euclidean algorithm
    double euclideanDis();

/// @brief Manhattan distance
/// @return the distance between v1 and v2 according to Manhattan's algorithm
    double ManhattanDis();

/// @brief Chebyshev distance
/// @return the distance between v1 and v2 according to Chebyshev's algorithm
    double ChebyshevDis();


/// @brief minowski distance for const p (P_FOR_MINKOWSKI_DIS)
/// @return the distance between v1 and v2 according to minkowski's algorithm
    double minkowskiDis();

/// @brief print dis vec for given double var
/// @param dis the distance to print
    void printDis(double dis);

/// @brief set the algorithm we want to calculate distance by
/// @param inputAlgo the algorithm the user want to use.
    void setAlgo(string inputAlgo);

/// \brief return a specific distance' according to the user's algorithm choice
/// \param other is the vector we set as v2 to calculate it's distance from v1
/// \return a distance according to one of the algorithms
    double getDisWithAlgo(Vec other);

/// \brief setter to v1
/// \param v the vector to set as v1
    void SetVec1(Vec v);

/// \brief setter to v2
/// \param v the vector to set as v2
    void SetVec2(Vec v);

    bool WasOperProblem();
    bool WasAlgoProblem();

};


#include <iostream>
#include <cmath>
#include "Distance.h"
using namespace std;

const double P_FOR_MINKOWSKI_DIS = 2;
Vec v1;
Vec v2;
string algo;




double Distance::differenceAtIndex(int i)
{
    return abs(v1.at(i) - v2.at(i));
}

bool Distance::isValidDisOp(){
    if (v1.getDimension() != v2.getDimension()){isWasOperProblem = true; return false;}
    else{return true;}
}

bool Distance::ifInteger(double num){
    return (num == (int)num);
}

double Distance::canberraDis()
{
    //if v1 and v2 has different amount of elements
    if (!isValidDisOp())
    {
        isWasOperProblem = true;
        return -1;
    }
    //'dis' will contain the distance between the vectors according to canberra's algorithm
    double dis = 0;
    //the loop goes by all the elements in the vectors
    for (int i = 0; i < v1.getDimension(); i++)
    {
        if (v1.at(i) != 0 || v2.at(i) != 0)
            //add to 'dis' |v1[i]-v2[i]| / (|v1[i] + v2[i]|)
            dis += differenceAtIndex(i) / (abs(v1.at(i)) + abs(v2.at(i)));
        else    //if v1[i] and v2[i] equals to zero
            dis += 0;
    }
    return dis;
}

double Distance::euclideanDis()
{
    //same note as in line 55
    if (!isValidDisOp())
    {
        isWasOperProblem = true;
        return -1;
    }
    //same note as in line 61, only by euclidean algorithm
    double dis = 0;
    for (int i = 0; i < v1.getDimension(); i++)
    {
        //add to 'dis' (v1[i]-v2[i])^2
        dis += pow(v1.at(i) - v2.at(i), 2);
    }
    return sqrt(dis);
}

double Distance::ManhattanDis()
{
    //same note as in line 55
    if (!isValidDisOp())
    {
        isWasOperProblem = true;
        return -1;
    }
    //same note as in line 61, only by manhattan's algorithm
    double dis = 0;
    for (int i = 0; i < v1.getDimension(); i++)
    {
        //add to dis |v1[i]-v2[i]|
        dis += differenceAtIndex(i);
    }
    return dis;
}

double Distance::ChebyshevDis()
{
    //same note as int line 55
    if (!isValidDisOp())
    {
        isWasOperProblem = true;
        return -1;
    }
    //same note as in line 61, only by chebyshev's algorithm
    double dis = 0;
    for (int i = 0; i < v1.getDimension(); i++)
    {
        //set dis as the maximum absolute distance between v1 and v2 at the same element index
        dis = max(differenceAtIndex(i), dis);
    }
    return dis;
}

double Distance::minkowskiDis()
{
    //same note as in line 55
    if (!isValidDisOp())
    {
        isWasOperProblem = true;
        return -1;
    }
    //same note as in line 61, only by Minkowski's algorithm
    double dis = 0;
    for (int i = 0; i < v1.getDimension(); i++)
    {
        //add to dis (|v1[i]-v2[i]|)^2
        dis += pow(differenceAtIndex(i), P_FOR_MINKOWSKI_DIS);
    }
    //return (dis)^0.5
    return pow(dis, 1 / P_FOR_MINKOWSKI_DIS);
}

void Distance::printDis(double dis)
{
    cout<<dis;
    //add a floating point to an integer
    if(ifInteger(dis)){std::cout<<".0 "<<endl;}
}

void Distance::SetVec1(Vec v){
    v1 = v;
}

void Distance::SetVec2(Vec v){
    v2 = v;
}

void Distance::setAlgo(string inputAlgo){
    //make deep copy of the given string and put it in our algo member.
    algo = inputAlgo.c_str();
    //check the input
    if(algo != "AUC" && algo != "MAN" && algo != "CHB" && algo != "CAN" && algo != "MIN"){
        isWasAlgoProblem = true;
    }
}

double Distance::getDisWithAlgo(Vec other){
    SetVec2(other);
    if(algo == "AUC"){return euclideanDis();}
    if(algo == "MAN"){return ManhattanDis();}
    if(algo == "CHB"){return ChebyshevDis();}
    if(algo == "CAN"){return canberraDis();}
    if(algo == "MIN"){return minkowskiDis();}
    //if we made it this far, the algorithm's choice is illegal
    isWasAlgoProblem = true;
    return -1;
}

Distance::Distance() {
    algo = "";
    isWasOperProblem = false;
    isWasAlgoProblem = false;
}

bool Distance::WasOperProblem(){return isWasOperProblem;}
bool Distance::WasAlgoProblem(){return isWasAlgoProblem;}

#include "DataSimilarityItem.h"
#include "CategoryVec.h"
#include <iostream>

//this class will contain the following members: (1) tuples of string represented categories and float represented
// distances, calculated on all the vectors from a file, (2) the Distance object which contain the algorithm and
//vector chosen by the user, (3) and the 'k' the user chose, and will return the most common category according to them
class KNN_System
{
    bool isWasAproblem;
    //members
    Distance dis;
    int k;
    vector<DataSimilarityItem> *knn;
    int size;
    double maxDiffer;

public:
    /// @brief ctor
    KNN_System();

    /// setter for the Distance object inside KNNS
    /// \param d  the distance
    void setDis(Distance d);

    /// @brief getter for dis memberObgect
    /// @return dis
    Distance getDis();

    /// setter for the 'k' inside KNNS
    /// \param k
    void setK(int k);

    /// @brief insert one item to the knn
    /// @param item
    void insertDataItem(DataSimilarityItem item);

    /// @brief inset new item to knn with CategoryVec type input.
    /// @param cv
    void insertDataItem(CategoryVec cv);

    /// @brief inset new item to knn with string as a input
    /// @param str
    void insertDataItem(std::string str);

    /// @brief find the most common category in the kth first items in knn
    /// @return the most common category
    std::string mostCommonCategInRange();

    /// @brief this function sorts knn so the kth closest vectors to the input vector will be at the beginning of knn
    void kClossest();

    /// @brief print the 'various' of the elements in knn
    void printVec();

    /// @brief put the kth smolest items at the beggining and find the moust commen category and return it
    /// @return the cayegory.
    std::string findCategory();

};

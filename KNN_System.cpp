#include "KNN_System.h"
#include <unordered_map>

/// @brief implementation of merge sort that find the k smallest numbers in a vector in O(nlogn) run time
class SortAlgorithm {
public:
    void MergeSortedIntervals(vector<DataSimilarityItem>& v, int s, int m, int e) {
        // temp is used to temporary store the vector obtained by merging elements from [s to m] and [m+1 to e] in v
        vector<DataSimilarityItem> temp;
        int i, j;
        i = s;
        j = m + 1;
        while (i <= m && j <= e) {
            if (v[i].getVarious() <= v[j].getVarious()) {
                temp.push_back(v[i]);
                ++i;
            }
            else {
                temp.push_back(v[j]);
                ++j;
            }
        }
        while (i <= m) {
            temp.push_back(v[i]);
            ++i;
        }
        while (j <= e) {
            temp.push_back(v[j]);
            ++j;
        }
        for (int i = s; i <= e; ++i)
            v[i] = temp[i - s];
    }

// the MergeSort function sorts the array in the range [s to e] in v, using merge sort algorithm
    void MergeSort(vector<DataSimilarityItem>& v, int s, int e) {
        if (s < e) {
            int m = (s + e) / 2;
            MergeSort(v, s, m);
            MergeSort(v, m + 1, e);
            MergeSortedIntervals(v, s, m, e);
        }
    }
};

// members of KNN_SYSTEM class: Distance dis, int k, vector<DataSimilarityItem> knn, int size, double maxDiffer

KNN_System::KNN_System()
{
    knn = new vector<DataSimilarityItem>();
    k = 0;
    size = 0;
    maxDiffer = -2;
    isWasAproblem = false;
}

void KNN_System::setDis(Distance d) {
    this->dis = d;
}

void KNN_System::setK(int k) {
    this->k = k;
}

Distance KNN_System::getDis(){
    return dis;
}

//The following methods are performed according to the principle of operator overloading

/// @brief insert one data item to the knn
/// @param item data item
void KNN_System::insertDataItem(DataSimilarityItem item)
{
    knn->push_back(item); //insert the tuple to the vector
    size++; //increase the amount of tuples the vector contains
    if (maxDiffer < item.getVarious()) //set the maximum difference from the tuples distances
    {
        maxDiffer = item.getVarious();
    }
}

void KNN_System::insertDataItem(CategoryVec cv)
{
    // create a DataSimilarityItem
    DataSimilarityItem dsl;
    // insert the category and calculate the distance for the 'Various'
    dsl.setCategory(cv.getCat());
    dsl.setVarious(dis.getDisWithAlgo(cv));
    // insert to knn
    insertDataItem(dsl);
}

void KNN_System::insertDataItem(std::string str)
{
    CategoryVec cv;
    // creates a CategoryVec with a string input
    cv.extractVec(str);
    // insert cv to knn
    insertDataItem(cv);
}

void KNN_System::kClossest(){
    SortAlgorithm sa;
    //sort the tuples in knn by their 'various' member
    sa.MergeSort(*knn ,0 , knn->size() -1);
}

std::string KNN_System::mostCommonCategInRange(){
    //the map's keys will be the categories' names and the values of them will be the amount of times they found in the
    //first k tuples in the sorted vector
    unordered_map<std::string, int> categories;
    int i;
    int max= -1; //initial maximum distance
    std::string categ;
    //the loop goes by the closest k vectors to the input vector
    for(i = 0;i< this->k;i++){
        //Increasing the number of appearances of the category shown in knn[i] in the vector by 1
        categories[knn->at(i).getCategory()]++;
        //setting the maximum appearances of a category in every iteration
        if(max < categories[knn->at(i).getCategory()]){
            max = categories[knn->at(i).getCategory()];
            categ = knn->at(i).getCategory();
        }
    }
    return categ;
}

std::string KNN_System::findCategory(){
    //sorting knn
    kClossest();
    //returning the most common category among the first k DataSimilarityItems in knn
    return mostCommonCategInRange();
}

void KNN_System::printVec(){
    int i = 0;
    for(;i<knn->size();i++){
        std::cout<<knn->at(i).getVarious()<<", ";
    }
    std::cout<<std::endl;
}


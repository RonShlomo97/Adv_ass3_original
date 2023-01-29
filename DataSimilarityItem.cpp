#include "DataSimilarityItem.h"

//members initialized in the .h file: std::string category, double various

void DataSimilarityItem::setCategory(std::string cat){
    category = cat;
}

void DataSimilarityItem::setVarious(double dis){
    various = dis;
}

double DataSimilarityItem::getVarious(){return various;}

std::string DataSimilarityItem::getCategory(){return category;}



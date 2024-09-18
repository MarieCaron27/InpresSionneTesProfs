#ifndef DATASOURCE2DCLASS_H
#define DATASOURCE2DCLASS_H

#include <iostream>
#include <vector>
using namespace std;

struct DataSource2D
{
    int value;
    int result;
};

class DataSource2DClass
{    
    private:
        vector<DataSource2D> myData;

    public:    
        //Setters :
        void setData2D(int value,int result);

        //Getters :
        const vector<DataSource2D>& getVector() const;

        //Méthode d'affichage du vecteur :
        void Affichage2D() const;
};

#endif
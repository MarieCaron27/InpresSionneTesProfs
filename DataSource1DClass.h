#ifndef DATASOURCE1DCLASS_H
#define DATASOURCE1DCLASS_H

#include <iostream>
#include <vector>
using namespace std;

struct DataSource1D
{
    int value;
    int effectif;
};

class DataSource1DClass
{    
    private:
        vector<DataSource1D> myData;
        int totalStandardDeviation;
    
    public:
        //Constructeur par défaut :
        DataSource1DClass(); 

        //Setters :
        void setData1D(int value);
        int calculeTotalEffectif();
        void setTotalEffectif(int totalEffectif);

        //Getters :
        const vector<DataSource1D>& getVector() const;
        int getTotalStandardDeviation() const;

        //Méthode d'affichage du vecteur :
        void Affichage1D() const;
};

#endif
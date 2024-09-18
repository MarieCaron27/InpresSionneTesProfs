#include <iostream>
#include <ostream>
#include <string.h>
#include <vector>
#include "DataSource1DClass.h"
using namespace std;

//Constructeur par défaut :

DataSource1DClass::DataSource1DClass() 
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de la classe DataSource1D" << endl;
    #endif

    setData1D(0);
    totalStandardDeviation = 0;
}

//Setters :

void DataSource1DClass::setData1D(int value) 
{
    bool found = false;

    for(DataSource1D& dataItem : myData) 
    {
        if(dataItem.value == value)
        {
            dataItem.effectif++;
            found = true;
            break;
        }
    }

    if(!found)
    {
        DataSource1D newDataItem;
        newDataItem.value = value;
        newDataItem.effectif = 1;
        myData.push_back(newDataItem);
    }
}

int DataSource1DClass::calculeTotalEffectif()
{
    int totalEffectif = 0;

    for(const DataSource1D& dataItem : myData)
    {
        totalEffectif += dataItem.effectif;
    }

    return totalEffectif;
}

void DataSource1DClass::setTotalEffectif(int totalEffectif)
{
    totalEffectif = calculeTotalEffectif();
    totalStandardDeviation = totalEffectif;
}

//Getters :

const vector<DataSource1D>& DataSource1DClass::getVector() const
{
    #ifdef DEBUG
        cout << "Méthode getVector de la classe DataSource1D" << endl;
    #endif

    return myData;
}

int DataSource1DClass::getTotalStandardDeviation() const
{
    #ifdef DEBUG
        cout << "Méthode getTotalStandardDeviation de la classe DataSource1D" << endl;
    #endif

    return totalStandardDeviation;
}

//Méthode d'affichage du vecteur :

void DataSource1DClass::Affichage1D() const 
{
    #ifdef DEBUG
        cout << "Méthode Affichage de la classe DataSource1D" << endl;
    #endif

    for(int i = 0; i < myData.size(); i++) 
    {
        cout << "Element [" << i << "] : " << "value = " << myData[i].value << ", effectif = " << myData[i].effectif << endl;
    }

    cout << "Effectif total :" << getTotalStandardDeviation() << endl;
}


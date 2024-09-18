#include <iostream>
#include <ostream>
#include <string.h>
#include <vector>
#include "DataSource2DClass.h"
using namespace std;

//Setters :

void DataSource2DClass::setData2D(int valeur,int resultat) 
{
    DataSource2D newDataItem;
    
    newDataItem.value = valeur;
    newDataItem.result = resultat;

    myData.push_back(newDataItem);
}

//Getters :

const vector<DataSource2D>& DataSource2DClass::getVector() const
{
    #ifdef DEBUG
        cout << "Méthode getVector de la classe DataSource2D" << endl;
    #endif

    return myData;
}

//Méthode d'affichage du vecteur :

void DataSource2DClass::Affichage2D() const 
{
    #ifdef DEBUG
        cout << "Méthode Affichage de la classe DataSource2D" << endl;
    #endif

    for(int i = 0; i < myData.size(); i++) 
    {
        cout << "Element [" << i << "] : " << "value = " << myData[i].value << ", résultat = " << myData[i].result << endl;
    }
}



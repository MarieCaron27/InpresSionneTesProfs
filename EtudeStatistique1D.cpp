#include <iostream>
#include <ostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include "EtudeStatistique1D.h"
using namespace std;

//Constructeur d'initialisation :

EtudeStatistique1D::EtudeStatistique1D(DataSource1DClass data)
{
    #ifdef DEBUG
        cout << "Constructeur d'initialisation de la classe EtudeStatistique1D" << endl;
    #endif

    myData = data;
    myData.setTotalEffectif(data.getTotalStandardDeviation());

    calculeMoyenne();
    calculeEcartType();
    calculeMode();
    calculeMediane();
    calculeEtendue();
    calculeCV();
}

//Setters :

void EtudeStatistique1D::calculeCV()
{
    #ifdef DEBUG
        cout << "Méthode calculeCV de la classe EtudeStatistique1D" << endl;
    #endif

    float s = getEcartType();
    float moy = getMoyenne();

    coefficientVariation = (s / moy) * 100;
}

void EtudeStatistique1D::calculeEcartType()
{
    #ifdef DEBUG
        cout << "Méthode calculeEcartType de la classe EtudeStatistique1D" << endl;
    #endif

    int n = myData.getVector().size();

    float moy = getMoyenne();
    float somme = 0.0;
    int totalEffectif = myData.getTotalStandardDeviation();

    for (int i = 0; i < n; i++) 
    {
        int valeurs = myData.getVector()[i].value;
        int effectifs = myData.getVector()[i].effectif;

        somme += pow(valeurs - moy, 2) * effectifs;      
    }
    
    float fraction = 1.0 / n;
    ecartType = sqrt(fraction * somme);
}

void EtudeStatistique1D::calculeEtendue()
{
    #ifdef DEBUG
        cout << "Méthode calculeEtendue de la classe EtudeStatistique1D" << endl;
    #endif

    int min = myData.getVector()[0].value;
    int max = myData.getVector()[0].value;
    int n = myData.getVector().size();

    if (myData.getVector().empty()) 
    {
        etendue = 0;
    }
    else
    {
        for (int i = 0; i < n; ++i) 
        {
            int valeurs = myData.getVector()[i].value;

            if (valeurs < min) 
            {
                min = valeurs;
            }

            if (valeurs > max) 
            {
                max = valeurs;
            }
        }

        etendue = max - min;
    }
}

void EtudeStatistique1D::calculeMediane()
{
    #ifdef DEBUG
        cout << "Méthode calculeMediane de la classe EtudeStatistique1D" << endl;
    #endif

    int n = myData.getVector().size();

    if (n % 2 == 0)
    {
        mediane = ((n/2) + ((n/2)+1)) / 2;
    }
    else
    {
        mediane = (n + 1) / 2;
    }
}

void EtudeStatistique1D::calculeMode()
{
    #ifdef DEBUG
        cout << "Méthode calculeMode de la classe EtudeStatistique1D" << endl;
    #endif

    if (myData.getVector().empty()) 
    {
        mode.push_back(0);
    }
    else
    {
        vector<int> frequencyMap(myData.getVector().size());

        for (int i = 0; i < myData.getVector().size(); i++) 
        {
            int effectifs = myData.getVector()[i].effectif;
            frequencyMap[i] = effectifs;
        }

        int maxFrequency = *max_element(frequencyMap.begin(), frequencyMap.end());

        for (int i = 0; i < frequencyMap.size(); i++) 
        {
            if (frequencyMap[i] == maxFrequency) 
            {
                mode.push_back(myData.getVector()[i].value);
            }
        }
    }
}

void EtudeStatistique1D::calculeMoyenne()
{
    #ifdef DEBUG
        cout << "Méthode calculeMoyenne de la classe EtudeStatistique1D" << endl;
    #endif

    float sum = 0;
    int totalEffectifs = myData.getTotalStandardDeviation();
    int n = myData.getVector().size();

    for (int i = 0; i < n; i++) 
    {
        int valeurs = myData.getVector()[i].value;
        int effectifs = myData.getVector()[i].effectif;

        sum += valeurs * effectifs;
    }

    moyenne = sum / totalEffectifs;
}

//Getters :

float EtudeStatistique1D::getCV() const
{
    #ifdef DEBUG
        cout << "Méthode getCV de la classe EtudeStatistique1D" << endl;
    #endif

    return coefficientVariation;
}

float EtudeStatistique1D::getEcartType() const
{
    #ifdef DEBUG
        cout << "Méthode getEcartType de la classe EtudeStatistique1D" << endl;
    #endif

    return ecartType;
}

int EtudeStatistique1D::getEtendue() const
{
    #ifdef DEBUG
        cout << "Méthode getEtendue de la classe EtudeStatistique1D" << endl;
    #endif

    return etendue;
}

int EtudeStatistique1D::getMediane() const
{
    #ifdef DEBUG
        cout << "Méthode getMediane de la classe EtudeStatistique1D" << endl;
    #endif

    return mediane;
}

vector<int> EtudeStatistique1D::getMode() const
{
    #ifdef DEBUG
        cout << "Méthode getMode de la classe EtudeStatistique1D" << endl;
    #endif

    return mode;
}

float EtudeStatistique1D::getMoyenne() const 
{
    #ifdef DEBUG
        cout << "Méthode getMoyenne de la classe EtudeStatistique1D" << endl;
    #endif

    return moyenne;
}

//Fonction d'affichage :

void EtudeStatistique1D::Affiche1D(const EtudeStatistique1D& etude1D) const 
{
    #ifdef DEBUG
        cout << "Méthode Affiche1D dans le main" << endl;
    #endif

    cout << "Affichage de vos données dans EtudeStatistique1D :" << endl;
    myData.Affichage1D();

    cout << "Ecart-type = " << etude1D.getEcartType() << endl;
    cout << "Etendue = " << etude1D.getEtendue() << endl;
    cout << "Médiane = " << etude1D.getMediane() << endl;

    for(int i=0;i<etude1D.getMode().size();i++) 
    {
        cout << "Mode(s) = " << etude1D.getMode()[i] << endl;
    }

    cout << "Moyenne = " << etude1D.getMoyenne() << endl;
    cout << "Coefficient de variation = " << etude1D.getCV() << endl;
}
#include <iostream>
#include <ostream>
#include <string.h>
#include <vector>
#include <math.h>
#include "EtudeStatistique2D.h"
using namespace std;

//Constructeur d'initialisation :

EtudeStatistique2D::EtudeStatistique2D(DataSource2DClass data)
{
    #ifdef DEBUG
        cout << "Constructeur d'initialisation de la classe EtudeStatistique2D" << endl;
    #endif

    myData = data;

    calculeCoefficientCorrelation(myData);
    calculePremierParametereDroite(myData);
    calculeDeuxiemeParametereDroite(myData);
}

//Setters :

void EtudeStatistique2D::calculeCoefficientCorrelation(DataSource2DClass data)
{
    #ifdef DEBUG
        cout << "Méthode calculeCoefficientCorrelation de la classe EtudeStatistique2D" << endl;
    #endif

    int n = data.getVector().size();
    float sommeValeurs = 0, sommeResultats = 0, sommeProduit = 0;
    float sommeValeursCarres = 0, sommeResultatsCarres = 0;

    for (int i = 0; i < n; i++) 
    {
        int valeurs = data.getVector()[i].value;
        int resultats = data.getVector()[i].result;

        sommeValeurs += valeurs;
        sommeResultats += resultats;
        sommeProduit += valeurs * resultats;
        sommeValeursCarres += valeurs * valeurs;
        sommeResultatsCarres += resultats * resultats;
    }
 
    float numerator = n * sommeProduit - sommeValeurs * sommeResultats;
    float denominator = sqrt((n * sommeValeursCarres - sommeValeurs * sommeValeurs) * (n * sommeResultatsCarres - sommeResultats * sommeResultats));
    
    coefficientCorrelation = numerator / denominator;

    /*float numerator = sommeProduit - ((sommeValeurs * sommeResultats)/n);
    float denominator = sqrt((sommeValeursCarres - (sommeValeursCarres/n)) * (sommeResultatsCarres - (sommeResultatsCarres/n)));*/
}

void EtudeStatistique2D::calculePremierParametereDroite(DataSource2DClass data)
{
    #ifdef DEBUG
        cout << "Méthode calculePremierParametereDroite de la classe EtudeStatistique2D" << endl;
    #endif

    int n = data.getVector().size();
    float sommeValeurs = 0, sommeResultats = 0, sommeProduit = 0;
    float sommeValeursCarres = 0, sommeResultatsCarres = 0;

    for (int i = 0; i < n; i++) 
    {
        int valeurs = data.getVector()[i].value;
        int resultats = data.getVector()[i].result;

        sommeValeurs += valeurs;
        sommeResultats += resultats;
        sommeProduit += valeurs * resultats;
        sommeValeursCarres += valeurs * valeurs;
        sommeResultatsCarres += resultats * resultats;
    }
 
    float numerator = sommeProduit - ((sommeValeurs * sommeResultats)/n);
    float denominator = sommeValeursCarres - ((sommeValeurs * sommeValeurs)/n);
    a = numerator/denominator;
}

void EtudeStatistique2D::calculeDeuxiemeParametereDroite(DataSource2DClass data)
{
    #ifdef DEBUG
        cout << "Méthode calculeDeuxièmeParametereDroite de la classe EtudeStatistique2D" << endl;
    #endif

    int n = data.getVector().size();
    float sommeValeurs = 0, sommeResultats = 0;
    float moyenneResultats = 0,moyenneValeurs = 0;

    for (int i = 0; i < n; i++) 
    {
        int valeurs = data.getVector()[i].value;
        int resultats = data.getVector()[i].result;

        sommeValeurs += valeurs;
        sommeResultats += resultats;
    }

    moyenneResultats = sommeResultats/n;
    moyenneValeurs = sommeValeurs/n;

    b = moyenneResultats - (getPremierParametereDroite()*moyenneValeurs);
}

//Getters :

float EtudeStatistique2D::getCoefficientCorrelation() const
{
    return coefficientCorrelation;
}

float EtudeStatistique2D::getPremierParametereDroite() const
{
    return a;
}

float EtudeStatistique2D::getDeuxiemeParametereDroite() const
{
    return b;
}

//Affichage des données :

void EtudeStatistique2D::Affiche2D(const EtudeStatistique2D& data) const
{
    #ifdef DEBUG
        cout << "Méthode Affiche2D dans EtudeStatistique2D" << endl;
    #endif

    float cC = data.getCoefficientCorrelation();

    // Définir une tolérance pour déterminer si une valeur est proche de zéro
    const float tolerance = 0.1;

    cout << "Affichage de vos données dans EtudeStatistique2D :" << endl;
    myData.Affichage2D();

    cout << "Voici le coefficient de corrélation :" << cC << endl;

    // Vérifier si le coefficient de corrélation est proche de -1, 0 ou +1
    if (fabs(coefficientCorrelation - 1.0) < tolerance || fabs(coefficientCorrelation + 1.0) < tolerance) 
    {
        cout << "On remarque qu'il y a entre les deux valeurs étudiées car le coefficient de corrélation est proche de +/- 1." << endl;
        cout << "Par conséquent, nous avons pu calculer les paramètres a et b de la droite y = ax + b." << endl;
        cout << "Voici donc cette droite :" << endl;
        cout << "y =" << data.getPremierParametereDroite() << "x +" << data.getDeuxiemeParametereDroite() << endl;
    } 
    else  
    {
        cout << "Nous n'avons pas calculé la droite car on constate que la valeur n'est pas proche de +/-1." << endl;
        cout << "En d'autres termes, cela signifie qu'il n'y a pas de lien entre les deux valeurs étudiées." << endl;
    }
}


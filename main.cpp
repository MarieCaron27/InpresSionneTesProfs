#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <math.h>

using namespace std;

//On inclut les fichiers pour l'étude statistique à 1D :
#include "DataSource1DClass.h"
#include "EtudeStatistique1D.h"

//On inclut les fichiers pour l'étude statistique à 2D :
#include "DataSource2DClass.h"
#include "EtudeStatistique2D.h"

//Déclaration des méthodes :
int choixFichier();
int choixEtudeStatistique();
int choixVariableEtudiee();
DataSource1DClass OuvertureFichier1D(const string& nomFichier, int choixVariableEtudiee);
DataSource2DClass OuvertureFichier2D(const string& nomFichier);
void Affiche1D(const EtudeStatistique1D& etude1D);
void Affiche2D(const EtudeStatistique2D& etude2D);

//Main :
int main(int argc, char* argv[])
{
    int choix1, choix2, choix3;

    choix1 = choixFichier();
    choix2 = choixEtudeStatistique();

    DataSource1DClass data1D;
    DataSource2DClass data2D;

    if (choix2 == 1)
    {
        choix3 = choixVariableEtudiee();
    }

    if (choix2 == 1)
    {
        if (choix1 == 1)
        {
            data1D = OuvertureFichier1D("./Fichiers_de_donnees/Heures.csv", choix3);
        }
        else
        {
            data1D = OuvertureFichier1D("./Fichiers_de_donnees/Cafes.csv", choix3);
        }
    }
    else
    {
        if (choix1 == 1)
        {
            data2D = OuvertureFichier2D("./Fichiers_de_donnees/Heures.csv");
        }
        else
        {
            data2D = OuvertureFichier2D("./Fichiers_de_donnees/Cafes.csv");
        }
    }

    const EtudeStatistique1D& etude1D = EtudeStatistique1D(data1D);
    const EtudeStatistique2D& etude2D = EtudeStatistique2D(data2D);

    if(choix2 == 1)
    {
        //Méthode d'affichage 1D :
        cout << "Voici vos données pour l'étude statistique à 1D :" << endl;
        etude1D.Affiche1D(etude1D);
    }
    else
    {
        //Méthode d'affichage 2D :
        cout << "Voici vos données pour l'étude statistique à 2D :" << endl;
        etude2D.Affiche2D(etude2D);
    }

    return 0;
}

//Fonction de choix du fichier :

int choixFichier()
{
    #ifdef DEBUG
        cout << "Méthode de choix du fichier étudié dans le main" << endl;
    #endif

    bool fini = false;
    int choix;

    while(fini == false)
    {
        cout << "Avec quel fichier souhaitez-vous travailler ?" << endl;
        cout << " 1. Tapez 1 pour celui des heures." << endl;
        cout << " 2. Tapez 2 pour celui du café." << endl;
        cout << " Faites votre choix : ";
        cin >> choix; 
        
        switch(choix)
        {
            case 1 :
                {
                    choix = 1;
                    fini = true;
                } 
                break;
            
            case 2 :
                {
                    choix = 2;
                    fini = true;
                } 
                break;

            default :
                {
                    cout << "Vous n'avez pas correctement répondu au sondage !" << endl;
                    cout << "Veuillez recommencez !" << endl << endl;
                    fini = false;
                }  
                break;
        }
    }

    return choix;
}

//Fonction de choix de l'étude statistique :

int choixEtudeStatistique()
{
    #ifdef DEBUG
        cout << "Méthode de choix de l'étude statistique étudiée dans le main" << endl;
    #endif

    bool fini = false;
    int choix;

    while(fini == false)
    {
        cout << "Quelle type d'étude statistique souhaitez-vous réaliser ?" << endl;
        cout << " 1. Tapez 1 pour réaliser une étude statistique à 1 dimension." << endl;
        cout << " 2. Tapez 2 pour réaliser une étude statistique à 2 dimensions." << endl;
        cout << " Faites votre choix : ";
        cin >> choix; 
        
        switch(choix)
        {
            case 1 :
                {
                    choix = 1;
                    fini = true;
                } 
                break;
            
            case 2 :
                {
                    choix = 2;
                    fini = true;
                } 
                break;

            default :
                {
                    cout << "Vous n'avez pas correctement répondu au sondage !" << endl;
                    cout << "Veuillez recommencez !" << endl << endl;
                    fini = false;
                }  
                break;
        }
    }

    return choix;
}

//Fonction de choix de la variable étudiée :

int choixVariableEtudiee()
{
    bool fini = false;
    int choix;

    while(fini == false)
    {
        #ifdef DEBUG
            cout << "Méthode de choix de la variable étudiée dans le main" << endl;
        #endif

        cout << "Avec quelle variable souhaitez-vous travailler ?" << endl;
        cout << " 1. Tapez 1 si vous souhaitez travailler avec les résultats obtenus par les élèves aux examens." << endl;
        cout << " 2. Tapez 2 si vous souhaitez travailler avec le nombre d'heures d'études/de cafés bus." << endl;
        cout << " Faites votre choix : ";
        cin >> choix; 
        
        switch(choix)
        {
            case 1 :
                {
                    choix = 1;
                    fini = true;
                } 
                break;
            
            case 2 :
                {
                    choix = 2;
                    fini = true;
                } 
                break;

            default :
                {
                    cout << "Vous n'avez pas correctement répondu au sondage !" << endl;
                    cout << "Veuillez recommencez !" << endl << endl;
                    fini = false;
                }  
                break;
        }
    }

    return choix;
}

//Méthodes d'ouvertures du fichier :
//1D :

DataSource1DClass OuvertureFichier1D(const string& nomFichier, int choixVariableEtudiee) 
{
    int resultat;
    int variable;

    DataSource1DClass myData;
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) 
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << endl;
        exit(EXIT_FAILURE);
    }

    // Ignorer la première ligne contenant les titres :
    string ligne;
    getline(fichier, ligne);

    // Lire les données ligne par ligne :
    while (getline(fichier, ligne)) 
    {
        stringstream ss(ligne);
        string valeur;

        getline(ss, valeur, ';');
        variable = stoi(valeur);

        getline(ss, valeur, ';');
        resultat = stoi(valeur);

        if (choixVariableEtudiee == 1) 
        {
            myData.setData1D(resultat);
        } 
        else 
        {
            myData.setData1D(variable);
        }
    }

    myData.calculeTotalEffectif();
    fichier.close();
    
    return myData;
}

//2D :

DataSource2DClass OuvertureFichier2D(const string& nomFichier)
{
    #ifdef DEBUG
        cout << "Méthode d'ouverture d'un fichier pour l'étude statistique 2D dans le main" << endl;
    #endif

    int resultat;
    int variable;

    DataSource2DClass myData;
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) 
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << endl;
        exit(EXIT_FAILURE);
    }

    // Ignorer la première ligne contenant les titres :
    string ligne;
    getline(fichier, ligne);

    // Lire les données ligne par ligne :
    while (getline(fichier, ligne)) 
    {
        stringstream ss(ligne);
        string valeur;

        getline(ss, valeur, ';');
        variable = stoi(valeur);
        //cout << "Nombre :" << variable << endl;

        getline(ss, valeur, ';');
        resultat = stoi(valeur);
        //cout << "Resultats :" << resultat << endl;

        myData.setData2D(variable,resultat);
    }

    fichier.close();
    return myData;
}

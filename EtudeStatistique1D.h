#ifndef ETUDESTATISTIQUE1D_H
#define ETUDESTATISTIQUE1D_H

#include <iostream>
using namespace std;

#include "DataSource1DClass.h"

class EtudeStatistique1D
{    
    private:
        DataSource1DClass myData;

        float coefficientVariation;
        float ecartType;
        int etendue;
        int mediane;
        vector<int> mode;
        float moyenne;
    
    public:
        //Constructeur d'initialisation :
        EtudeStatistique1D(DataSource1DClass data);

        //Setters :
        void calculeCV();
        void calculeEcartType();
        void calculeEtendue();
        void calculeMediane();
        void calculeMode(); 
        void calculeMoyenne();

        //Getters :
        float getCV() const;
        float getEcartType() const;
        int getEtendue() const;
        int getMediane() const;
        vector<int> getMode() const;
        float getMoyenne() const;

        //Affichage :
        void Affiche1D(const EtudeStatistique1D& etude1D) const;
};

#endif
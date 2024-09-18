#ifndef ETUDESTATISTIQUE2D_H
#define ETUDESTATISTIQUE2D_H

#include <iostream>
using namespace std;

#include "DataSource2DClass.h"

class EtudeStatistique2D
{    
    private:
        DataSource2DClass myData;

        float coefficientCorrelation;

        //Droite :
        float a;
        float b;

    public:
        //Constructeur d'initialisation :
        EtudeStatistique2D(DataSource2DClass data);

        //Setters :
        void calculeCoefficientCorrelation(DataSource2DClass data);
        void calculePremierParametereDroite(DataSource2DClass data);
        void calculeDeuxiemeParametereDroite(DataSource2DClass data);

        //Getters :
        float getCoefficientCorrelation() const;
        float getPremierParametereDroite() const;
        float getDeuxiemeParametereDroite() const;

        //Affichage :
        void Affiche2D(const EtudeStatistique2D& data) const;
};

#endif
.SILENT:

main:	main.o DataSource1DClass.o EtudeStatistique1D.o DataSource2DClass.o EtudeStatistique2D.o
	echo "Création du main exécutable"
	g++ -o main main.o DataSource1DClass.o EtudeStatistique1D.o DataSource2DClass.o EtudeStatistique2D.o

main.o:	main.cpp DataSource1DClass.h EtudeStatistique1D.h DataSource2DClass.h EtudeStatistique2D.h
	echo "Création de main.o"
	g++ main.cpp -c -o main.o

DataSource1DClass.o:	DataSource1DClass.cpp DataSource1DClass.h
	echo "Création de DataSource1DClass.o"
	g++ DataSource1DClass.cpp -c -o DataSource1DClass.o

EtudeStatistique1D.o:	EtudeStatistique1D.cpp EtudeStatistique1D.h
	echo "Création de EtudeStatistique1D.o"
	g++ EtudeStatistique1D.cpp -c -o EtudeStatistique1D.o

DataSource2DClass.o:	DataSource2DClass.cpp DataSource2DClass.h
	echo "Création de DataSource2DClass.o"
	g++ DataSource2DClass.cpp -c -o DataSource2DClass.o

EtudeStatistique2D.o:	EtudeStatistique2D.cpp EtudeStatistique2D.h
	echo "Création de EtudeStatistique2D.o"
	g++ EtudeStatistique2D.cpp -c -o EtudeStatistique2D.o

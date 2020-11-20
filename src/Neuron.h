#ifndef NEURONE_H
#define NEURONE_H

#include "Random.h"
#include <string>

/*!
 * La classe Neurone permet de créer un neurone. 
 * Un Neurone est caractérisé par :
 * -4 paramètres, a,b,c,d.
 * -sa qualité : inhibiteur ou excitateur
 * -v : son potentiel de membrane
 * -u : la variable de relaxation
 * -un identifiant : un entier qui permet d'identifier le neuronne
 * -Les types de neuronnes : RS, FS, IB, CH, LTS
 */

class Neuron{
public :
/*! @name Initialisation
 * Un neuronne doit être initialisé avec :
 * - sa qualité : true pour excitateur et false pour inhibiteur
 * - un identifiant
 * @param _q : la qualité
 * @param _id : l'identifiant
 * @param _type le type du neuronne
 * -Le constructeur du Neurone va ensuite initialiser tous les attributs restant 
 */
///@{ 
	Neuron(bool _q, int _id, std::string _type );
	~Neuron();
///@}

/*! @name Gérer les attributs du neurone
 */
///@{
	void setFiring(bool _f);
	void setPotentiel(double _v);
	void setRelaxation(double _u);
	bool isFiring();	
///@}
	
private :
	bool qualite;
	int  id;
	std::string type;
	bool firing;
	double v;
	double a;
	double b;
	double c;
	double d;
	double  u;
};
	
#endif	

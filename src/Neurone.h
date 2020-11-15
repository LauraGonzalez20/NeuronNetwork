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
 * -Le type du neuronne : RS, FS, IB, CH, LTS
 */

class Neurone{
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
	Neurone(bool _q, int _id, std::string _type ) : firing(false), v(-65) {/*! temporaire :assigner a,b,c,d et u dans .cpp ici*/};
	~Neurone();
///@}

/*! @name Gérer les attributs du neurone
 */
///@{
	void setFiring(bool _f);
	void setPotentiel(double _v);
	void setRelaxation(double _u);
///@}
	
private :
	double a;
	double b;
	double c;
	double d;
	bool qualite;
	bool firing;
	int  id;
	double v;
	double  u;
	

};
	
#endif	

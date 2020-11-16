#pragma once
#include <stdexcept>


/*!
  Une classe pour lancer les erreurs dans le programme.
  Elle hérite d'une sous-classe de la classe std::exception.
  Chaque classe d'erreurs a un code de sortie spécifique.
  Les messages d'erreurs sont affichés par l'appeleur d'exceptions. 
*/

class Erreur : public std::runtime_error {	
public:
    Erreur (const char *c, int v=0) : std::runtime_error(c), code(v) {}
    Erreur (const std::string &s, int v=0) : std::runtime_error(s), code(v) {}  
    int value() const {return code;}
    
protected:
    const int code;
};


/// * valeurs pas défaut des paramètres *
#define _TEMPS_DEFAUT_ 10
#define _N_DEFAUT_ 100
#define _PROPORTIONS_DEFAUT_ "RS:0,8, FS:0,2"
#define _P_EXCIT_DEFAUT_ 0.8
#define _CONN_MOY_DEFAUT_ 1 //?
#define _INTENSITE_CONN_DEFAUT_ 1 //?

/// * messages *
#define _PRGRM_TEXTE_ "Simulation du réseau de neurones"
#define _TEMPS_TEXTE_ "Durée en ms de la simulation"
#define _N_NEUR_TEXTE_ "Nombre de neurones dans la simulation"
#define _PROPORTIONS_TEXTE_ "Proportions des différents neurones (écrire RS: x , FS: y avec x et y les proportions respectives)" //spécifier ensuite RS, IB, CH, FS et LTS
#define _P_EXCIT_TEXTE_ "Proportion de neurones excitateurs"
#define _CONN_MOY_TEXTE_ "Connectivité moyenne"
#define _INTENSITE_CONN_TEXTE_ "Intensité moyenne des connexions"





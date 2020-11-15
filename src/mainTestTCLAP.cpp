#include <iostream>
#include <tclap/CmdLine.h>
#include "constants.h"



void Simulation(int argc, char**argv);


void Simulation(int argc, char **argv) {
    try {
        TCLAP::CmdLine cmd(_PRGRM_TEXTE_);
        
        TCLAP::ValueArg<double> temps ("t", "temps", _TEMPS_TEXTE_ , true, _TEMPS_DEFAUT_, "double");
        cmd.add(temps);
        
        TCLAP::ValueArg<double> nb_neur ("N", "nb_neur", _N_NEUR_TEXTE_ , true, _N_DEFAUT_, "double");
        cmd.add(nb_neur);
        
        TCLAP::ValueArg<std::string> proportions("T", "Proportions", _PROPORTIONS_TEXTE_ , false, _PROPORTIONS_DEFAUT_, "string");
        cmd.add(proportions);
        
        cmd.parse(argc, argv);
        
        if (temps.getValue()<0) throw (Erreur("Le temps doit être une valeur positive"));
        if (nb_neur.getValue()<0) throw (Erreur("Le nombre de neurones doit être positif"));
        
        //vérifier les proportions (la somme doit donner 1 et la rédaction doit être correcte) throw (Erreur("Vérifier que la somme des proportions donne 1 et que la syntaxe attendue soit correcte))
        
    } catch(TCLAP::ArgException &e) {
		std::cerr<<"Error: " + e.error() + " " + e.argId();
    }
}


int main(int argc, char **argv) {    
    try {
        Simulation(argc, argv);
    } catch(Erreur &e) {
        std::cerr << e.what() << std::endl;
        return e.value();
    }
    return 0;
}

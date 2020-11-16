#include <tclap/CmdLine.h>
#include <iostream>
#include "constants.h"
#include "Simulation.h"




Simulation::Simulation(int argc, char **argv) {
    try {
        TCLAP::CmdLine cmd(_PRGRM_TEXTE_);
        
        TCLAP::ValueArg<double> duree_sim ("t", "duree_sim", _TEMPS_TEXTE_ , true, _TEMPS_DEFAUT_, "double");
        cmd.add(duree_sim);
        
        TCLAP::ValueArg<double> nb_neur ("N", "nb_neur", _N_NEUR_TEXTE_ , true, _N_DEFAUT_, "double");
        cmd.add(nb_neur);
        
        TCLAP::ValueArg<double> propexcitateurs ("P", "propexcitateurs", _P_EXCIT_TEXTE_ , false , _P_EXCIT_DEFAUT_, "double");
        cmd.add(propexcitateurs);
        
        TCLAP::ValueArg<double> conn_moy ("C", "conn_moy", _CONN_MOY_TEXTE_ , false , _CONN_MOY_DEFAUT_ , "double");
        cmd.add(conn_moy);
        
        TCLAP::ValueArg<double> intensite_conn ("L", "intensite_conn", _INTENSITE_CONN_TEXTE_ , false , _INTENSITE_CONN_DEFAUT_ , "double");
        cmd.add(intensite_conn);
        
        TCLAP::ValueArg<std::string> proportionstot ("T", "Proportions", _PROPORTIONS_TEXTE_ , false, _PROPORTIONS_DEFAUT_, "string");
        cmd.add(proportionstot);
        
        cmd.parse(argc, argv);
        
        if (duree_sim.getValue()<0) throw (Erreur("Le temps doit être une valeur positive"));
        if (nb_neur.getValue()<0) throw (Erreur("Le nombre de neurones doit être positif"));
        if (propexcitateurs.getValue()<0 or propexcitateurs.getValue()>1) throw (Erreur("La proportion de neurones excitateurs doit se trouver entre 0 et 1 inclus"));
        if (conn_moy.getValue()<0) throw (Erreur("La connectivité moyenne doit être positive"));
        if (intensite_conn.getValue()<0) throw (Erreur("L'intensite moyenne des connexions doit être positive"));
        
        
        std::cout<<" Le temps choisi est "<<duree_sim.getValue()<<" , le nombre de neurones est "<<nb_neur.getValue()<<" et les proportions sont "<<proportionstot.getValue()<<std::endl;
        
        //vérifier les proportions (la somme doit donner 1 et la rédaction doit être correcte) throw (Erreur("Vérifier que la somme des proportions donne 1 et que la syntaxe attendue soit correcte))
        
    } catch(Erreur &e) {
		//std::cerr<<"Error: " + e.error() + " " + e.argId()));
    }
    
    
}



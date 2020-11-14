#include "constants.h"
#include "Simulation.h"


Simulation::Simulation(int argc, char **argv) {
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
		std::cerr<<"Error: " + e.error() + " " + e.argId()));
    }
    
    
    //Juste pour pour tester cette partie
    std::cout<<" Le temps choisi est "<<temps.getValue()<<" , le nombre de neurones est "<<nb_neur.getValue()<<" et les proportions sont "<<proportions.getValue()<<std::endl;
}



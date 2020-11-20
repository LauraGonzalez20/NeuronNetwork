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



Simulation::~Simulation()
{
    delete network_;
    for(auto& n : neurons_) delete n;
    outfile_.close();
}


void Simulation::run()
{
    int j(0);
    int delta_t_U(0);
    while(_time<_time_lim){

        if( (_time-last_t>=2*delta_t_) or (_time==0)) print(j); ++j;  //on affiche toutes les 1 secondes;

        network_->update(_time, last_t, delta_t_, delta_t_U);

        last_t=_time;
        _time+=delta_t_;
    }

}




double Simulation::eqDiffSolver(double u, double v, double I)
{
    return v + (0.04*std::pow(v,2)  + 5*v +140 -u + I)*delta_t_;
}

double Simulation::eqDiffSolverV(double u, double v, int a, int b)
{
    return u + a*(b*v-u)*delta_t_;
}


void Simulation::print(int j)
{
    for(int i(0); i<neurons_.size(); ++i);
        result_[j][i]=neurons_[i]->isFiring();

    std::ostream *outstr = &std::cout;
    if(outfile_.is_open()) outstr = &outfile_;
    for(int i(0); i<result_.size(); ++i){
        for(int j(0); j<i; ++j){
            *outstr << result_[i][j];
        }
        *outstr << &std::endl;
    }


}


double Simulation::getDelta() const
{
    return delta_t_;
}

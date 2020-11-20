#include <tclap/CmdLine.h>
#include <iostream>
#include "constants.h"
#include "Simulation.h"
#include <map> 
#include <string>



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
        
    //gerer erreurs
    if (duree_sim.getValue()<0) throw (Erreur("Le temps doit être une valeur positive"));
    if (nb_neur.getValue()<0) throw (Erreur("Le nombre de neurones doit être positif"));
    if (propexcitateurs.getValue()<0 or propexcitateurs.getValue()>1) throw (Erreur("La proportion de neurones excitateurs doit se trouver entre 0 et 1 inclus"));
    if (conn_moy.getValue()<0) throw (Erreur("La connectivité moyenne doit être positive"));
    if (intensite_conn.getValue()<0) throw (Erreur("L'intensite moyenne des connexions doit être positive"));
    testlireproportions(proportionstot.getValue());
    //
               
    std::cout<<" Le temps choisi est "<<duree_sim.getValue()<<" , le nombre de neurones est "<<nb_neur.getValue()<<" et les proportions sont "<<proportionstot.getValue()<<std::endl;
              
    } catch(Erreur &e) {
		//std::cerr<<"Error: " + e.error() + " " + e.argId()));
    }
    
    
}



void Simulation::testlireproportions(std::string donneesprop){
		
	std::map<std::string, double> p;	
	p["FS"] = 0.2;
    p["LTS"] = 0.0;
    p["RS"] = 0.8;
    p["IB"] = 0.0;
    p["CH"] = 0.0; 
	
	try{			 		 	
		std::string key, numb_s;
		std::stringstream ss(donneesprop);
		int e(0);
								
		donneesprop.erase(std::remove_if(donneesprop.begin(), donneesprop.end(), isspace), donneesprop.end()); //on enlève espaces 
			
		
		do { 
			std::getline(ss, key, ':'); //On enregistre dans key ce qu'il y a avant les :
				
			for (auto x : p){
				if (key==x.first) {
					std::getline(ss, numb_s, ',');
					x.second=stod(numb_s); 
					e=1;
				}
			}
			
			} while (!key.empty());
		
		if (e==0) throw (Erreur("L'information est impossible à interpréter, vérifiez une syntaxe de type 'IB:0.3, FS:0.3, CH:0.2'avec les types de neurones que vous souhaitez"));
						
		} catch (Erreur &e){};
				
	double sum;
	 for (auto typeneurone : p){
		 sum+=typeneurone.second;
	 } 	
	 if (sum>1.0 or sum<0.0) throw (Erreur("La somme des proportions données doit se trouver entre 0 et 1"));	
	 
	 double reste (1.0-sum);
	 p["RS"]+=reste;	
				
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
    for(int i(0); i<neurons_.size(); ++i){
        result_[j][i]=neurons_[i]->isFiring();
	}

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







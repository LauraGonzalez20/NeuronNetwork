#include "Simulation.cpp"

int main(int argc, char **argv){
	int nerr = 0;
    try{
        Simulation s(argc, argv);
        s.run();
    }catch(Erreur& e){
       //std::cerr<<"Error: " + e.error() + " " + e.argId();
       nerr=1;
    }
    
return nerr;
}



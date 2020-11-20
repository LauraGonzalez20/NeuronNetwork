#include "Simulation.cpp"

int main(int argc, char **argv){
    try{
        Simulation s(argc, argv);
        s.run();
    }catch(Erreur& e){
       std::cerr<<"Error: " + e.error() + " " + e.argId();
    }
    
return 0;
}

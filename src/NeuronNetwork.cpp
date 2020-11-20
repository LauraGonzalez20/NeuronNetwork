#include "NeuronNetwork.h"
#include "Simulation.h"
#include "Random.h"


NeuronNetwork::NeuronNetwork() {}

NeuronNetwork::NeuronNetwork(std::vector<Neuron*>& neurons, double lambda, double L)
: neurons(getNeurons()), lambda_(lambda), L_(L)
{}


void NeuronNetwork::set_connections() {
    int d(0);
    double l(0);
    for (size_t i(0); i < neurons.size(); ++i) {
        d = poisson(lambda);
        for (size_t j(0); j < d; ++j) {
            l = uniform(0, 2*L);
            double id_neuron = uniform_int(0,N);
            if (id_neuron == i) {
                id neuron = uniform_int(0,N);
                i.connection.insert(std::pair<int, int>(id_neuron,l));
            }
            else {
                i.connection.insert(std::pair<int, int>(id_neuron,l)); // on ajoute à chaque neurone une paire d'entiers qui représentent le numéro du neurone connecté et l'intensité du lien : connection doit etre un attribut de la classe Neuron
            }
        }
    }
}

double NeuronNetwork::I(Neuron& n) // on utilise cette méthode à chaque pas de temps dans simulation pour calculer l'intensité de chaque neurone du tableau de neurones de Simulation
    {
    double I(0);
    double w(0);
    double J = uniform_double(0,1);
    
    std::vector<Neuron*> M_e; // tableau de neurones excitateurs liés à n
    std::vector<Neuron*> M_i; // tableau de neurones inhibiteurs liés à n
    
    double intensity_inhib(0);
    double intensity_excit(0);
    
    for (int i(0); i < n.connection.size; ++i) {
        Neuron& neurons[n.connection.first] = connected_neuron;
        
        if (connected_neuron.isFiring()) {  // rajouter une méthode isFiring() dans Neurone
            if ((connected_neuron.qualite == false){
                M_i.push_back(connected_neuron);
            }
            else {
                M_e.push_back(connected_neuron);
            }
        }
    }
                
    for (int i(0); i < M_i.size(); ++i) {
        double i.connection.second = intensity;
        intensity_inhib += intensity;
    }
    for (int j(0); j < M_e.size(); ++j) {
        double i.connection.second = intensity;
        intensity_excit += intensity;
    }
    if (n.qualite == false) {
        w = 2;
        I = (w*J) + ((1/2)*intensity_excit) - intensity_inhib;
    }
    else {
        w = 5;
        I = (w*J) + ((1/2)*intensity_excit) - intensity_inhib;
    }
                
    return I;
    
}
                

Neuron& NeuronNetwork::getNeuron(int id) {
    return neurons[id];
}

void NeuronNetwork::getPot(int id) {
    return neurons[id].v;
}

void NeuronNetwork::getRelax(int id) {
    return neurons[id].u;
}




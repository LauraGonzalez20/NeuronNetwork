#pragma once
#include <unordered_map>
#include "Neuron.h"

class Simulation;

class NeuronNetwork
{

/*!
 * La classe NeuronNetwork consiste à assembler des Neuron interagissant entre eux.
 * Le réseau de neurones a comme paramètres un tableau de Neuron, une connectivité moyenne /lambda_ et une intensité moyenne de connection /L_. Cette classe permet de creer le réseau de neurones et de calculer le courant synaptique d'un neurone en particulier.
 * Les manipulations des neurones se font grâce à la méthode \ref getNeurons qui va chercher le tableau de neurones dans la Simulation.
*/

public:

    NeuronNetwork();
    NeuronNetwork(std::vector<Neuron*>& neurons, double lambda, double L); //pour construire un réseau de neurones à partir d'un vec
    ~NeuronNetwork();

    
    void getPot(int id); //retourne le potentiel d'un neurone avec un id
    void getRelax(int id);  //retourne la relaxation d'un neurone avec un id

    Neuron& getNeuron(int id); //récupère un neurone avec un id donné


    
    void set_connections(); // création aléatoires des connections de chaque neurone du NeuronNetwork
    double I(Neuron& n); //calcule l'I(t) d'un neurone

    double NeuronNetwork::eqDiffSolverV(double u, double v, double I);
    double NeuronNetwork::eqDiffSolverU(double u, double v, int a, int b) ;
    void update(t, last_t, delta_t, delta_t_U);   //update le réseau et calcule toutes les nouvelles valeurs

private:
    double lambda_;
    double L_;

};

#pragma once
#include <unordered_map>

class NeuronNetwork
{

/*!
 * The NeuronNetwork class consists to assemble neurons interacting with each others. It constructs the network with a given set of neurons \ref Neuron and the link force \L_. The links are created with the variable \lambda randomly. This class will then store the data about the links properties to help computations made in the simulation.
 * Computations on the neurons themselves will be performed with the help of the \ref getNeuron method which will get the set of neurons from the simulation.
 * 
*/

public:

NeuronNetwork();
NeuronNetwork(std::vector<Neuron*>& neurons, double lambda, double L); //pour construire un réseau de neurones à partir d'un vec
~NeuronNetwork();


double getTotalLinkPower(int id) const; //calcule pour un id de neurone son I(t)
void getPot(int id); //retourne le potentiel d'un neurone avec un id
void getRelax(int id)  //retourne la relaxation d'un neurone avec un id

Neuron& getNeuron(int id); //récupère un neurone avec un id donné


private:

void initId();
double computeLink();  //calcule intensité d'un lien
int createLink();	//initialise links_


std::unordered_map<int, std::unordered_map<int, int>> links_;  //numéro de neurone : id du neurone connecté, avec intensité du lien
double lambda_;
double L_;



};
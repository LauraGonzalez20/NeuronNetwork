#pragma once
#include "Random.h"
#include "Neurone.h"
#include "NeuroneNetwork.h"


class Simulation
{


/*!
  The Simulation class is the main class in this program. It constructs the chemical \ref System according to user-specified parameters, and @ref run "runs" the simulation.

  Simulation results are printed to screen or file

  A Simulation is made of a neuron network \ref NeuronNetwork and a vector of neurons \ref Neuron. These neurons are constructed with the function \ref add_genes and \ref add_gene.
Each new Neuron initializes itself with the given parameters

  Time (\ref _time) advances from 0 until it reaches \ref _last. Two types of events are controlled by the \ref _time variable. The next neuron network simulation will be performed at time \ref next_t, and the \ref print function is called at every multiple of \ref delta_t.
*/

public:

Simulation();
Simulation(int argc, char** argv);
~Simulation;

/*! These methods are used to create and add_neurons to the colection of neuron
 */
///@{
void add_neurons(size_t N, std::string name); // N: nb neurones  name: RS/FS/...
void add_neurons(size_t N, double a, double b, double c, double d, bool inhib, bool firing, double v, double u);
void add_neuron(double a, double b, double c, double d, bool inhib, bool firing, double v, double u);
///@}


double eqDiffSolver(double u, double v, double t);

/*! The simulation is made by calling run and print
 */
///@{
void run(double time, double next_t);
void print();
///@}

std::vector<Neurone*>& getNeurons();  //retourne vecteur de neurones
Neurone& getNeuron(int id);


private:

NeuroneNetwork* network_;
std::vector<Neurone*> neurons_;
double _time, delta_t, next_t, _last;

};

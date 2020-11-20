#include "Neuron.h"
//#include "Random.h"



Neuron::Neuron(bool _q, int _id, std::string _type) 
	: qualite(_q),
	  id(_id),
	  type(_type),
	  firing(false),
	  v(-65)
{
	Random ra;
	double r(ra.uniform(0,1));
	
	if (_q){
		a=0.2;
		b=0.2;
		c=(-65)*(1-(3/13)*r*r);
		d=(8)*(1-(3/4)*r*r);
	}
	else{
		a=0.1*(1-0.8*r);
		b=0.2*(1+0.25*r);
		c=-65;
		d=2;		
	}	
	u=b*v; 
};
		
Neuron::~Neuron()
{}

void Neuron::setFiring(bool _f){
	firing=_f;
}

void Neuron::setPotentiel(double _v){
	v=_v;	
}
	
void Neuron::setRelaxation(double _u){
	u=_u;	
}
	
bool Neuron::isFiring(){
	return firing;	
}

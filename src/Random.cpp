#include <iostream>
#include "Random.h"

Random::Random() 
{
   std::random_device rd;
   seed = rd();
        
   rng.seed(seed); //?
}

int Random::uniform(int lower,int upper) {
    std::uniform_int_distribution<> unif(lower, upper);
    return unif(rng); 
}

double Random::normal(double moy, double sd) {
    std::normal_distribution<> norm(moy, sd);
    return norm(rng);
}

int Random::poisson(int lambda)
{
	std::poisson_distribution<> pd(lambda);
	return pd(rng);
}
    

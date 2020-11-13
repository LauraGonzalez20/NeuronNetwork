#ifndef RANDOM_H
#define RANDOM_H

#include <random>

/*!
 * La classe Random gère tout ce qui est variables aléatoires 
 */
 
class Random {

public :
/*! @name Initialisation
  Le generator \ref rng est un Mersenne twister *mt19937* 
  Il est seeded avec un *random_device*
*/
///@{
	Random(/*!provisoir :initialiser la seed avec un random_device comme gillespie, et le rng*/);
///@}
/*! @name Ditributions
 * Ces fonctionspeuvent soit retourner un seul nombre ou bien un container avec des nombres aléatoires
 */
///@{
	int poisson(int _lambda);
	int uniform(int lower , int upper);
	double normal(double lower=0, double upper=1);
///@}

private :
	std::mt19937 rng;
    long int seed;

};
#endif

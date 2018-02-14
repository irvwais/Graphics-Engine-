#pragma once

namespace MATH {

class Randomizer{
private:
	int seed;
	long ran1idnum;
	int qd2idnum;
public:
	Randomizer();


	Randomizer(const long seed);

	~Randomizer();

	double rand(const double low, const double high);

	int rand(const int low, const int high);

	double ran1();


	inline double rand2(){
		unsigned long itemp;
		static unsigned long jflone = 0x3f800000;
		static unsigned long jflmsk = 0x007fffff;
		qd2idnum = 1664525L * qd2idnum + 1013904223L;
		itemp = jflone | (jflmsk & qd2idnum);
		return (double)(*(float *)&itemp) - 1.0;
	}


	double box_muller(const double mean , const double std_devation);
	
};

}/// End of namespace MATH
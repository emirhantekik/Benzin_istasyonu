#ifndef Akaryakit_H
#define Akaryakit_H
#include <iostream>
using namespace std;

class Akaryakit{
	public:
		Akaryakit();
		Akaryakit(const Akaryakit& obj);
		Akaryakit& operator=(const Akaryakit& obj);
		friend double operator+( Akaryakit& obj1, Akaryakit& obj2);
		friend double operator+(double a, Akaryakit& obj);
		friend ostream& operator<<(ostream& o, const Akaryakit& obj);
		
		void satis();
		double get_litre();
		double get_tl();
		int get_choice();
	private:
		const double motorin=7.21;
		const double benzin=7.73;
		const double lpg=4.51;
		double litre;
		double tl;
		int choice;
};

#endif

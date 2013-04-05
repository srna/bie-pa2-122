#include <iostream>

using namespace std;

class Vehicle
{
	int year;
public:
	Vehicle(int year) : year(year) {}
	int getYear()
	{
		return year;
	}
	virtual void print(ostream& os)
	{
		os << "Vehicle [Y: " << getYear() << "]";
	}
	virtual ~Vehicle() {}
};

class Car : public Vehicle
{
	int passengers;
public:
	Car(int year, int passengers) 
		: Vehicle(year), passengers(passengers) {}
	int getPassengers()
	{
		return passengers;
	}
	virtual void print(ostream& os)
	{
		os << "Car [Y: " << getYear() << ", P:"
			<< getPassengers() << "]";
	}
	virtual ~Car() {}
};

class Truck : public Vehicle
{
	int cargo;
public:
	Truck(int year, int cargo) 
		: Vehicle(year), cargo(cargo) {}
	int getCargo()
	{
		return cargo;
	}
	virtual void print(ostream& os)
	{
		os << "Truck [Y: " << getYear() << ", C:"
			<< getCargo() << "]";
	}
	virtual ~Truck() {}
};

int main()
{
	Vehicle* v[5];

	v[0] = new Car(2000, 5);
	v[1] = new Car(2005, 8);
	v[2] = new Truck(1995, 30);
	v[3] = new Truck(2008, 50);
	v[4] = new Car(1990, 2);

	Car *c;
	for(int i = 0; i < 5; i++)
	{
		v[i]->print(cout);
		cout << endl;
		if((c = dynamic_cast<Car*>(v[i])) != NULL)
			cout << "I wrote a car with " 
				<< c->getPassengers() 
				<< " passengers." << endl;
		delete v[i];
	}

	return 0;
}


#include <iostream>

using namespace std;

class Employee
{
	char name[26];
	char surname[37];
	int id;
	static int __next_id;
public:
	Employee(const char* n, const char* s)
	{
		id = __next_id++;
		strncpy(name, n, sizeof(name));
		strncpy(surname, s, sizeof(surname));
	}
	int getId() const { return id; }
	virtual int salary() const = 0;
	friend ostream& operator<< (ostream& os, const Employee& e)
	{
		os << e.id << ". " << e.name << " " << e.surname 
			<< "; Salary: " << e.salary();
		return os;
	}
	virtual ~Employee() {}
};
int Employee::__next_id = 1;

class Worker : public Employee
{
	int hrs, hrly;
public:
	Worker(const char* n, const char* s, int h, int hy)
		: Employee(n, s)
	{
		hrs = h;
		hrly = hy;
	}
	int salary() const
	{
		return hrs*hrly;
	}
};

class Clerk : public Employee
{
	int pay;
public:
	Clerk(const char* n, const char* s, int p)
		: Employee(n, s)
	{
		pay = p;
	}
	int salary() const
	{
		return pay;
	}
	friend ostream& operator<< (ostream& os, const Clerk& c)
	{
		os << "Clerk: ";
		os << (const Employee&)c;
		return os;
	}
};

class Manager : public Clerk {
public:
	Manager(const char* n, const char* s, int p)
		: Clerk(n,s,p) {}
};

class Company
{
	int count, size;
	Employee** data;
public:
	Company(int maxemp) : count(0), size(maxemp) 
	{
		data = new Employee*[size];
	}
	~Company()
	{
		delete [] data;
	}
	Company& insert(Employee* e)
	{
		if (count < size)
			data[count ++] = e;
		return *this;
	}
	Company& remove(int id)
	{
		int i;
		for(i = 0; i < count; i++)
			if(data[i]->getId() == id)
				break;
		if(i < count) // found
		{
			memmove(data+i, data+i+1, count-i-1);
			count --;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Company& c)
	{
		os << "--- Company of " << c.count << " employees ---" << endl;
		for(int i = 0 ; i < c.count ; i++)
		{
			os << *(c.data[i]) << endl;
		}
		return os;
	}
	int salaries()
	{
		int sal = 0;
		for(int i = 0 ; i < count ; i++)
		{
			sal += data[i]->salary();
		}
		return sal;
	}
};

int main()
{
	Worker w("Asd", "Fgh", 160, 100);
	Clerk  c("Qwe", "Rty", 20000);
	Manager m("Big", "Manager", 200000);

	cout << w << endl << c << endl;

	Company comp(5);
	comp.insert(&w)
		.insert(&c)
		.insert(&m);
	cout << comp << endl;
	cout << "Salary together: " << comp.salaries() << endl;
	comp.remove(1);
	cout << comp << endl;

	return 0;
}

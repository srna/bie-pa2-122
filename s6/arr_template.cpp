#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const char* logfile = "arr_template.log";

template <class T>
class NotFoundException
{
	string file;
	int line;
	time_t t;
	struct tm * datetime;
	T val;
public:
	NotFoundException
		(T val, const char* file = __FILE__,
		int line = __LINE__)
		: file(file), line(line), val(val)
	{
		t = time(NULL);
		datetime = localtime( & t );
	}
	void log() const
	{
		ofstream ofs(logfile, ios::app);
		ofs.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
		ofs << *this << endl;
		ofs.close();
	}
	string getFile() const { return file; }
	int getLine() const { return line; }
	friend ostream& operator<<
		(ostream& os, 
		const NotFoundException& e)
	{
		os  << "[" << e.datetime->tm_year + 1900
			<< "-" << e.datetime->tm_mon+1
			<< "-" << e.datetime->tm_mday
			<< " " << e.datetime->tm_hour
			<< ":" << e.datetime->tm_min
			<< ":" << e.datetime->tm_sec
			<< "] " << e.file << ":" << e.line
			<< " error: " << "Item '"<<e.val<<"' not found";
		return os;
	}
};

template <class T>
T* find(T* a, int size, const T& x)
{
	int i;
	for(i = 0; i < size; i++)
		if(a[i] == x)
			break;
	if (i == size)
		throw NotFoundException<T>
			(x, __FILE__,__LINE__);
	return &a[i];
}

int main()
{
	const int size = 5;
	int ai[size];
	char ac[size];
	float af[size];

	for(int i = 0; i < size; i++)
	{
		ai[i] = i+1;
		ac[i] = 'A'+i;
		af[i] = 1.1*i;
	}

	try
	{
		int *fi = find(ai,size,3);
		cout<< *fi << " is found at index "
			<< fi - ai << endl;

		char *fc = find(ac,size,'B');
		cout<< *fc << " is found at index "
			<< fc - ac << endl;

		float *ff = find(af,size,4.5f);
		cout<< *ff << " is found at index "
			<< ff - af << endl;
	}
	catch(const NotFoundException<int>& e)
	{
		e.log();
		cerr << e << endl;
		cerr << "The last exception was"
			<< " on line " << e.getLine()
			<< endl;
	}
	catch(const NotFoundException<char>& e)
	{
		e.log();
		cerr << e << endl;
		cerr << "The last exception was"
			<< " on line " << e.getLine()
			<< endl;
	}
	catch(const NotFoundException<float>& e)
	{
		e.log();
		cerr << e << endl;
		cerr << "The last exception was"
			<< " on line " << e.getLine()
			<< endl;
	}
	catch(const char * e)
	{
		cerr << e << endl;
	}
	catch(...)
	{
		cout << "Unknown error." << endl;
	}
	return 0;
}

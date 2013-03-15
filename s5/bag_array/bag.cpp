#include "bag.h"
#include <cstring>

using namespace std;

const int INIT_SIZE = 2;

Bag::Bag()
{
	size = INIT_SIZE;
	count = 0;
	data = new int[size];
}

Bag::Bag(const Bag& b)
{
	size = b.size;
	count = b.count;
	data = new int[size];
	memcpy(data,b.data,count*sizeof(int));
}

void Bag::resize(int newsize)
{
	int *newdata = new int[newsize];
	memcpy(newdata,data,count*sizeof(int));
	delete [] data;
	data = newdata;
	size = newsize;
}

int Bag::find(int a)
{
	int i;
	for(i = 0; i < count; i++)
		if(data[i] == a)
			break;
	return i;
}

Bag::~Bag()
{
	delete [] data;
}

void Bag::insert(int a)
{
	if(count+1 > size)
		resize(size*2);
	data[count++] = a;
}

void Bag::remove(int a)
{
	int idx = find(a);
	if(idx == count)
		return;
	data[idx] = data[count-1];
	count--;
	if(count <= size/2 && size > INIT_SIZE)
		resize(size/2);
}

bool Bag::isThere(int a)
{
	return find(a) < count;
}

Bag& Bag::operator+=(int a)
{
	insert(a);
	return *this;
}

Bag& Bag::operator= (const Bag& b)
{
	if(this != &b)
	{
		delete [] data;
		size = b.size;
		count = b.count;
		data = new int[size];
		memcpy(data,b.data,count*sizeof(int));
	}
	return *this;
}

ostream& operator << (ostream& os, const Bag& b)
{
	for (int i = 0; i < b.count; i++)
	{
		os << b.data[i] << " ";
	}
	return os;
}

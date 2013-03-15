#ifndef __BAG_H_
#define __BAG_H_

#include <iostream>

class Bag
{
private:
	int *data;
	int size,count;
	void resize(int newsize);
	int find(int a);
public:
	Bag();
	Bag(const Bag& b);
	~Bag();

	void insert(int a);
	void remove(int a);
	bool isThere(int a);
	Bag& operator+=(int a);
	Bag& operator= (const Bag& b);

	friend std::ostream& operator << (std::ostream& os,
		const Bag& b);
};

#endif /* __BAG_H_ */
#ifndef __CCOUNTER_H_
#define __CCOUNTER_H_

class CCounter {
	int m_Value;
	int m_Init;
public:
	CCounter(int init = 0);
	int Value();
	void Increment();
	void Decrement();
	void Reset();
};

#endif

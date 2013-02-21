#include "ccounter.h"

CCounter::CCounter(int init){
	m_Init=init;
	Reset();
}

int CCounter::Value(){
	return m_Value;
}

void CCounter::Increment(){ m_Value++;}

void CCounter::Decrement(){ m_Value--;}

void CCounter::Reset(){ m_Value = m_Init; }

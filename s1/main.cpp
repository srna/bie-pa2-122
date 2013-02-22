#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void readArray(int& len, int*& arr)
{
	cin >> len;
	while(cin.fail()||len<=0)//if invalid input ask for a valid one
	{
		cin.clear();
		cin.ignore(numeric_limits<int>::max(),'\n');
		cout<<"Invalid input, please enter a positive integer."<<endl;
		cin>>len;
	}
	arr=new int[len];
	cout<<"Give numbers : "<<endl;
	for(int i =0;i<len;i++)
	{
		cin>>arr[i];
		while(cin.fail())//if invalid input ask for a valid one
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(),'\n');
			cout<<"Invalid input, please enter an integer."<<endl;
			cin>>arr[i];
		}
	}
	cout<<endl;
}

void printArray(int len, int* arr)
{
	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void deleteArray(int* arr)
{
	delete [] arr;
}

int compare(const void*a,const void*b)//compare made for qsort
{
  return ( *(int*)a - *(int*)b);
}

void qsortArray(int len, int *arr)//standard implementation
{
	qsort(arr,len,sizeof(int),compare);
}

int main()
{
	int len;
	int *arr;
	cout << "Write the count of numbers and the numbers: " << endl;
	readArray(len, arr);
	cout << "You entered array:" << endl;
	printArray(len,arr);

	qsortArray(len, arr);

	cout << "Sorted array:" << endl;
	printArray(len,arr);

	deleteArray(arr);
	return 0;
}


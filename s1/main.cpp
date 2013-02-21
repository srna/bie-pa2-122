#include <iostream>
using namespace std;

void readArray(int& len, int*& arr)
{
	cin >> len;
	arr = new int[len];
	for(int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}
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

void sortArray(int len, int* arr)
{
	bool switched = false;
	while (!switched)
	{
		switched = false;
		for(int j = 0; j < len; j++)
		{
			if(arr[j] < arr[j-1])
			{
				switched = true;
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	int len;
	int *arr;
	cout << "Write the count of numbers and the numbers: " << endl;
	readArray(len, arr);
	cout << "You entered array:" << endl;
	printArray(len,arr);

	sortArray(len, arr);

	cout << "Sorted array:" << endl;
	printArray(len,arr);

	deleteArray(arr);
	return 0;
}


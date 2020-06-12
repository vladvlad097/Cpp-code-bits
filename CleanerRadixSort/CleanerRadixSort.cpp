#include <iostream>
#include<queue>
using namespace std;

//less efficient but a bit cleaner

int GetMax(int arr[], int arraySize)	//find max number of digits
{
	int maxNumber = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (maxNumber < arr[i])
		{
			maxNumber = arr[i];
		}
	}


	int countDigits = 1;
	int divide = 10;
	while (maxNumber / divide != 0)
	{
		divide *= 10;
		countDigits++;
	}
	return countDigits;
}

void radixSort(int arr[], int arraySize)
{

	int countDigits = GetMax(arr, arraySize); //find max number of digits
	queue<int> countQueues[10];
	int modulo = 1;

	for (int i = 0; i < countDigits; i++)
	{

		for (int j = 0; j < arraySize; j++)		//store the values in the queues
		{
			countQueues[(arr[j] / modulo) % 10].push(arr[j]);
		}

		int m = 0;
		for (int k = 0; k < 10; k++)		// move them back in the array
		{
			while (!countQueues[k].empty())
			{
				arr[m] = countQueues[k].front();
				countQueues[k].pop();
				m++;
			}
		}
		modulo *= 10;
	}
}


int main()
{
	int arr[] = { 802, 170, 45, 75, 90, 24, 2, 66 };
	int arraySize = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << ' ';
	}
}

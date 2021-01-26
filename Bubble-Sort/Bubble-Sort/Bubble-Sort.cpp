#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}


int main()
{
	int arr[] = { 9,5,7,3,1,0,11,2 };
	int n;
	n = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, n);
	cout << "The bubble sorted array " << endl << "[ ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;


}
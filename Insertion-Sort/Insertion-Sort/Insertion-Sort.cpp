#include <iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
	int arr[] = { 9,5,7,3,1,0,11,2 };
	int n;
	n = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, n);
	cout << "The insertion sorted array " << endl << "[ ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}


#include <iostream>
using namespace std;
int binary_search(int arr[], int h, int key) {
    int m, l;
    l = 0;
    while (h >= l) {
        m = (l + h) / 2;
        if (arr[m] == key)
            return m;
        else if (arr[m] > key)
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int num;
    int arr[] = { 0,3,5,7,8,9,10,11,15 };
    int h = sizeof(arr) / sizeof arr[0];

    cout << "enter the num" << endl;
    cin >> num;
    int result = binary_search(arr, h, num);
    if (result == -1)
        cout << "The num is not found" << endl;
    else
        cout << "The num is found (" << num << ")" << "in index:  " << result << endl;

}
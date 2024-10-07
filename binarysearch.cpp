#include <iostream>
using namespace std;
int binarysearch(int arr[], int s, int e, int k)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == k)
    {
        return true;
    }
    else if (arr[mid] < k)
    {
        return binarysearch(arr, mid + 1, e, k); // right prt mai jaayga pehle.
    }
    else
    {
        return binarysearch(arr, s, e - 1, k); // left part mai jayga.
    }
}

int main()
{
    int arr[5] = {3, 2, 1, 6, 5};
    int size = 5;
    int k = 5;
    int ans = binarysearch(arr, 0, 5, k);
    if (ans)
    {
        cout << "Element is present " << endl;
    }
    else
    {
        cout << "Element Not Found " << endl;
    }
}
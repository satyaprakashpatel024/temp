#include <bits\stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int f, int l)
{
    int pivit = arr[l];
    int i = (f - 1);

    for (int j = f; j <= l - 1; j++)
    {
        if (arr[j] < pivit)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[l]);
    return i + 1;
}

void quicksort(int arr[], int f, int l)
{
    if (f >= l)
    {
        return;
    }
    int loc = partition(arr, f, l);
    quicksort(arr, f, loc - 1);
    quicksort(arr, loc + 1, l);
}

void printarr(int arr[], int n)
{

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
}
int main()
{
    int arr[] = {11, 18, 9, 13, 10, 12, 15, 14};
    int n = sizeof(arr) / sizeof(int);
    cout << "\n NAME : SATYA PRAKASH PATEL \n";
    cout << " BRANCH : CSE(B2) \n";
    cout << " ENROLLMENT NO. : 0131CS211099 \n";
    cout << "\n Topic : Quick sort \n";
    cout << "\n Printing unsorted array : \n";
    printarr(arr, n);

    quicksort(arr, 0, n - 1);
    cout << " Printing  sorted  array : \n";
    printarr(arr, n);
    cout << endl;
    return 0;
}

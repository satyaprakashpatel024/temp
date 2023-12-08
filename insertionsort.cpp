#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionsort(int arr[], int n)
{
    int temp,j; 
    for(int i=1; i<n; i++)
    {      
        temp = arr[i]; 
        for(j=i-1; j>=0; j--)
        {
            if(arr[j]>temp)
            {
                //swap(arr[j], temp);
                arr[j+1]= arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
    printarr(arr, n);
}

int main()
{
    int v[] = {1,2,5,9,6,3,4,7,8,5,2};
    int n = sizeof(v)/sizeof(int);
    printarr(v, n);
    insertionsort(v, n);
    return 0;
}
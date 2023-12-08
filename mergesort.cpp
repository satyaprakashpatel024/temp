#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int f, int l, int p)
{
    int i,j,k;
    vector<int> temp;
    i = f;
    j = p+1;
    k = f;

    while(i<=p && j<=l)
    {
        if(arr[i]<arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=p)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=l)
    {
        temp.push_back(arr[j++]);
    }

    for(k=f; k<=l; k++)
    {
        arr[k]=temp[k-f];
    }
}

void mergeSort(int arr[], int f, int l)
{
    if(f>=l)
    {
        return;
    }
    int p = f+(l-f)/2;
    mergeSort(arr,f,p);
    mergeSort(arr,p+1,l);
    merge(arr,f,l,p);
}

int main()
{
    int arr[]={27,9,14,21,11,17,56,34};
    int n = sizeof(arr)/sizeof(int);
    cout<<"\n NAME : SATYA PRAKASH PATEL \n";
    cout<<" BRANCH : CSE(B2) \n";
    cout<<" ENROLLMENT NO. : 0131CS211099 \n";
    cout<<"\n Topic : Merge Sort \n";
    cout<<"\n Printing unsorted array : \n";
    printarr(arr,n);

    mergeSort(arr,0,n-1);
    cout<<"\n Printing sorted array : \n";
    printarr(arr,n);
    cout<<endl;
    return 0;
}

    
#include<iostream>
using namespace std;

int binarysearch(int arr[], int s, int e,int key)
{
    if(s<=e)
    {
        int mid = s+(e-s)/2;
        if(arr[mid]==key)
        {
            return mid+1; 
        }
        else if(arr[mid]>key)
        {
            return binarysearch(arr,s,mid-1,key);
        }
        else
        {
            return binarysearch(arr,mid+1,e,key);
        }
    }
    return -1;
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(array)/sizeof(int);
    int key = 6;
    int ans = binarysearch(array,0,size-1,key);
    cout<<"\n NAME : SATYA PRAKASH PATEL \n";
    cout<<" BRANCH : CSE(B2) \n";
    cout<<" ENROLLMENT NO. : 0131CS211099 \n";
    cout<<" TOPIC : BINARY SEARCH BY RECURSION \n";

    if(ans==-1)
    {
        cout<<"\n Element is not present in array. \n";
    }
    else
    {
        cout<<"\n Element is present at position no : "<<ans<<"\n";
    }
    cout<<endl;
    return 0;
}
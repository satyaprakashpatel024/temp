#include<iostream>
using namespace std;

void knapsack(int arr1[], int arr2[], int kweight,int n){
    
    int check[n];
    for(int i=0; i<n; i++)
    {
       if(arr2[i]<=kweight)
       {
            check[i] = 1;
            kweight = kweight-arr2[i];
       }
       else
       {
            check[i] = 0;
       }
    }
    int maxprofit = 0;
    int weight_in_kbag = 0;
    
    for(int i=0; i<n; i++)
    {
        maxprofit = maxprofit+arr1[i]*check[i];
        weight_in_kbag = weight_in_kbag+arr2[i]*check[i];
    }
    cout<<" Maximum profit of knapsack problem : "<<maxprofit<<endl;
    cout<<" total weight in knapsack bag : "<<weight_in_kbag<<endl;

}

int main(){
    int profit[] = {35,25,22,20,10,5};
    int weight[] = {100,20,50,30,7,10};
    int n = sizeof(profit)/sizeof(int);
    knapsack(profit,weight,165,n);
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int optimalMerge(int arr[], int n) 
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);

    int cost = 0;
    while (pq.size() > 1) 
    {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();

        int z = x + y;
        cost += z;
        pq.push(z);
    }
    return cost;
}

int main() {
    int N;
    cout<<" Enter the no of elements : ";
    cin>>N;
    int arr[N];
    cout<<" Enter the elements to merge : \n";
    for(int i=0; i<N; i++)
    {
        cout<<" Enter element "<<i+1<<" ";
        cin>>arr[i];
    }

    cout << "Minimum cost of merging is : " << optimalMerge(arr, N) << endl;

    return 0;
}

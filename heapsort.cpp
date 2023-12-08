#include <iostream>
#include <queue>
#include <vector>
using namespace std;
              // heap sort using priority queue

void heap_sort(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    for (int i = 0; i <n; i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

                // heap sort by build heap and heapify function

void heapify(vector<int> & arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2*i + 1; // left = 2*i + 1
    int right = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
    return;
}

void heapSort(vector<int>& arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(vector<int> &arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

                // main function

int main() {
    vector<int> arr = {5, 3, 1, 4, 2};
    int n = arr.size();
    cout<<"\n without sorted array : ";
    //heapify(arr,n,0);
    printArray(arr,n);
    heap_sort(arr); 
    cout<<" Sorted array using priority queue : ";
    printArray(arr, n);
    // heapSort(arr, n);
    // cout << " Sorted array by normal method : ";
    // printArray(arr, n);
    cout << endl;
    return 0;
}

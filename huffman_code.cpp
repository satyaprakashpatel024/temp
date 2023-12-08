#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000

class freq{
public:
    char ch;
    int f;
    freq* left;
    freq* right;
    
    freq(char character, int frequency){
        ch = character;
        f = frequency;
        left = NULL;
        right = NULL;
    }       
};

class compare{
public:
    bool operator() (freq* node1, freq* node2){
        return node1->f > node2->f;
    }
};

freq* heap(priority_queue<freq*, vector<freq*>, compare>& pq){
    while(pq.size() != 1){
        freq* left = pq.top();
        pq.pop();
        freq* right = pq.top();
        pq.pop();
        freq* intnod = new freq('&', (left->f + right->f));
        intnod -> left = left;
        intnod -> right = right;
        pq.push(intnod);
    }
    return pq.top();    
}

void printcodes(freq* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printcodes(root->left, arr, top+1);
    }
    if(root->right){
        arr[top] = 1;
        printcodes(root->right, arr, top+1);
    }
    if(!root->left && !root->right){
        cout << root->ch << " ";
        for(int i = 0; i < top; i++){
            cout << arr[i];
        }
        cout << endl;
    }
}

void huffmancodes(char ch[], int f[], int size){
    priority_queue<freq*, vector<freq*>, compare> pq;
    for(int i = 0; i < size; i++){
        pq.push(new freq(ch[i], f[i]));
    }
    freq* root = heap(pq);
    int arr[MAX_SIZE], top = 0;
    printcodes(root, arr, top);
}

int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int f[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    huffmancodes(arr, f, size);
    return 0;
}

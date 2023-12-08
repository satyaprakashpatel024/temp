#include<bits/stdc++.h>
using namespace std;
//maximum size kuch bhi le sakte hai jitni badi tree utne jyada codes
#define MAX_SIZE 1000
//0.structure banenge node k 
//1.character or frequency ko lekr ek node create krenge
//2.sabhi nodes ko priority queue me dalkr heap banaenge 
//3.smallest nodes ko add krke internal node banenge jisme ki ek unique character hoga or ek frequency
//4.internal or external nodes k  heap banenge jisme ki left side pe value choti hona chahiye like bst
//5.min heap ko code provide krenge left me 0 or right me 1
//or code ko print krenge frequency k sath



//node k structure ek character ek frequency
//left k null,right k null
class node{
	public:
		char ch;
		int freq;
		node* left;
		node* right;
		
		node(char character,int frequency){
			ch = character;
			freq = frequency;
			left = NULL;
			right = NULL;
		}		
};

//comapre krne k liye class agar node1badi hai to return true krega nhi to kuch false return karega
//kyuki left side smaller value rahegi
class compare{
	public:
		bool operator()(node* node1,node*node2){
			
			return node1->freq > node2->freq;
		
		}
};

//yaha pe ek heap banaenge is heap k andar internal node ko bhi add krke heap tree banega

node* heap(	priority_queue<node*,vector<node*>,compare>pq){
	//jab tak queue k size 1 se bada hai tb tk chlana hai
	while(pq.size()!=1){
		node*left  = pq.top();
		pq.pop();
		//node left ek pointer hai jisme hum queue k top ko store karenge matlb sabse choti node ko
		//fir hum use delete kr denge queue se
		node*right = pq.top();
		pq.pop();
			//node right ek pointer hai jisme hum queue k top ko store karenge matlb dusri sabse choti node ko
		//fir hum use delete kr denge queue se
		
		//ek internalnode banaenge jisme ek random character daleenge or internode ki frequency me
		//sabse choti node or dusri sabse choti node k addition dal denge
		//isse ek internalnode ban jaegi
		
		node* intnod = new node('&',(left->freq + right->freq));
		//internal node k left side me hum sabse choti wali node to link krenge
		intnod -> left = left;
		//internode k right me hum dusri sabse choti node to link krenege
		intnod -> right = right;
		//internode ko wapas minheap k andar dal denge taki ab firse ek or internal node create ho sake
		//jak tak hum sabhi nodes ko visit nhi kr lete
		pq.push(intnod);
		
	}
	//ab ham minheap k top ko matlb root node ko return kr denge jisse hum pure minheap ko access kr sakte hai
	return pq.top();
		
}
//minheap banne k baad code assign krnege left wali side 0 or right wali side 1
void printcodes(node*root,int arr[],int top){
	//ek array banaaenge jo ki 0 1 ko store krega 
	//ek top ye kuch bhi le sakte hai ye bss index ko badange as a counter
	if(root->left){
		//agar root k left khali nhi hai to root k left me 0 assign krete jao or array me 0 dal do
		arr[top] = 0;
		//recursion se last left tk jaega
		printcodes(root->left,arr,top+1);
		//jese left khatm hoga right side jaega
	}
	
	//agar root k right khali nhi hai to root k right me 1 assign krete jao or array me 1 dal do
		if(root->right){
		arr[top] = 1;
		printcodes(root->right,arr,top+1);
		//root  k right jab khali ho jae iska mtlb hai left bhi khali or right bhi khali  
	}
	//root k left or right dono null hai mtlb hum leaf node pe hai
	if(!root->left && !root->right){
		//leaf k character print krwa do
		cout<< root->ch<<" ";
		for(int i =0;i<top;i++){
			//leaf tk pahuchne me jitne 0 1 travesre kiye sabko print krwa do
			cout<<arr[i];
		}cout<<endl;
	}
	//ese hi sab node ko visit krega or jitni bhi node hogi sab external hogi a b c d e f inko print kreage
	
}

 void huffmancodes(char character[],int frequency[],int size){
 	//priority queue banayi minheap k liye
	priority_queue<node*,vector<node*> ,compare>pq;
	
	for(int i =0;i<size;i++){
		//priority queue k andar hamare character or frequency ki node ko pass krke minheap create krenge
		node* node1 = new node(character[i],frequency[i]);
		pq.push(node1);
		
	}
	//nodes k min heap k baad hum 2 smallest node lenge or ek internal banege ek unique character k sath
	//internal node me sum hoga dono smallest node k
	//ab internal nodes or baki sab nodes k min heap banaenge
	node* root = heap(pq);
	int arr[MAX_SIZE],top = 0;
	//minheap banne k baad code assign kr denge
	
	printcodes(root,arr,top);
	
}
//1.character or frequency ko lekr ek node create krenge
//2.sabhi nodes ko priority queue me dalkr min heap banaenge
//3.smallest nodes ko add krke internal node banenge jisme ki ek unique character hoga or ek frequency
//4.internal or external nodes k min heap banenge
//5.min heap ko code provide krenge left me 0 or right me 1
//or code ko print krenge frequency k sath




int main(){
	int n;
	cout<<"enter no. of characters : "<<endl;
	cin>>n;
	int freq[n];
    char chara[n+1];

 	for(int i =0;i<n;i++){
	cout<<"enter the characters and frequencies : ";
 	  cin>>chara[i]>>freq[i];
	}
	
	huffmancodes(chara,freq,n);
	return 0;
	
	
}
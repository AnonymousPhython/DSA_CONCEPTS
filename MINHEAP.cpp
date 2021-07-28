#include <bits/stdc++.h>

#define ll long long int
#define MOD 1000000007
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define test int t; cin>>t; while(t--)

using namespace std;

ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll power(ll x, ll y) {ll res=1; x%=MOD; while(y){if(y&1)res=mul(res,x); y>>=1; x=mul(x,x);} return res;}
ll max(ll x,ll y){if(x>y) return x; else return y;}

void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    
class MinHeap{
    public:
    int *data,capacity,size;
};

MinHeap* create(int capacity){
    MinHeap *heap=new MinHeap;
    heap->capacity=capacity;
    heap->size=0;
    heap->data=new int[capacity];
    return heap;
}



int getmin(MinHeap *heap){
    int i;
    if(heap->size==0){
        cout<<"Heap size is 0 can't get min"<<endl;
        return INT_MIN;
    }
    return heap->data[0];
}

void shiftdown(MinHeap *heap,int i){
    int minindex=i;
    if(2*i+1<heap->size && heap->data[2*i+1]<heap->data[minindex]){
        minindex=2*i+1;
    }
    if(2*i+2<heap->size && heap->data[2*i+2]<heap->data[minindex]){
        minindex=2*i+2;
    }
    if(minindex!=i){
        swap(&(heap->data[i]),&(heap->data[minindex]));
    }
    if(i==minindex)
    return;
    shiftdown(heap,minindex);
}

void shiftup(MinHeap *heap,int i){
    if(i==0)
    return;
    if(heap->data[(i-1)/2]>heap->data[i]){
        swap(&(heap->data[(i-1)/2]),&(heap->data[i]));
        shiftup(heap,(i-1)/2);
    }
    
}

void changevalue(MinHeap *heap,int i,int val){
    if(i>=heap->size || i<0){
        cout<<"Invalid Operation"<<endl;
        return;
    }
    int oldval=heap->data[i];
    heap->data[i]=val;
    if(val>oldval){
        shiftdown(heap,i);
    }
    if(val<oldval){
        shiftup(heap,i);
    }
}

int extractmin(MinHeap *heap){
    int i;
    if(heap->size<=0){
        cout<<"Heap size is 0 can't extractmin"<<endl;
        return INT_MIN;
    }
    if(heap->size==1){
        heap->size--;
        return heap->data[0];
    }
    int ans=heap->data[0];
    heap->data[0]=heap->data[heap->size-1];
    heap->size--;
    shiftdown(heap,0);
    return ans;
}

void insert(MinHeap *heap,int val){
    int i;
    if(heap->size==heap->capacity){
        cout<<"OverFlow for adding element "<<val<<endl;
        return;
    }
    i=heap->size;
    heap->size++;
    heap->data[i]=val;
    
    shiftup(heap,i);
    
}

void printheap(MinHeap *heap){
    int i=0;
    cout<<endl;
    for(i=0;i<heap->size;i++){
        cout<<heap->data[i]<<" ";
    }
    cout<<endl;
}

int main() {
    MinHeap *heap=create(5);
    int i=0;
    for(i=5;i>=0;i--){
        insert(heap,i);
    }
    printheap(heap);
    
    
    cout<<"min value element is: "<<getmin(heap)<<endl;
    changevalue(heap,0,10);
    cout<<endl<<"after changing the value of root to 10 new minheap:";
    printheap(heap);
    
}

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

class Queue{
    public:
    int front,back,size,capacity,*data;
};

Queue* make(int capacity){
    Queue *queue=new Queue();
    queue->data=new int[capacity];
    queue->capacity=capacity;
    queue->size=0;
    queue->front=0;
    queue->back=capacity-1;
    return queue;
    
}

bool isempty(Queue *queue){
    return (queue->size==0);
}

bool isfull(Queue *queue){
    return (queue->size==queue->capacity);
}

void enqueue(Queue *queue,int val){
    if(isfull(queue)){
        cout<<"Given Queue is Full can't Enqueue"<<endl;
        return;
    }
    queue->back=(queue->back+1)%queue->capacity;
    queue->data[queue->back]=val;
    queue->size++;
}

void dequeue(Queue *queue){
    if(isempty(queue)){
        cout<<"Given Queue is Empty can't Dequeue"<<endl;
        return;
    }
    queue->front=(queue->front+1)%queue->capacity;
    queue->size--;
}

int getfront(Queue *queue){
    if(isempty(queue)){
        cout<<"Given Queue is Empty"<<endl;
        return INT_MIN;
    }
    return queue->data[queue->front];
}

int getback(Queue *queue){
    if(isempty(queue)){
        cout<<"Given Queue is Empty"<<endl;
        return INT_MIN;
    }
    return queue->data[queue->back];
}

int main() {
    Queue* queue = make(10);
  
    enqueue(queue,34);
    enqueue(queue,54);
    enqueue(queue,67);
    enqueue(queue,49);
  
    dequeue(queue);
    cout<<"dequeued from queue\n";
  
    cout<<"Front item is "<<getfront(queue)<<endl;
    cout<<"Rear item is "<<getback(queue)<<endl;
    dequeue(queue);
    enqueue(queue,50);
    cout<<endl<<"dequeued from queue\n";
    cout<<"Front item is "<<getfront(queue)<<endl;
    cout<<"Rear item is "<<getback(queue)<<endl;
  
    return 0;
}

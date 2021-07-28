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
    
    Queue(int capacity);
    bool isempty();
    bool isfull();
    void enqueue(int val);
    void dequeue();
    int getfront();
    int getback();
    
};

Queue::Queue(int Capacity){
    data=new int[Capacity];
    capacity=Capacity;
    size=0;
    front=0;
    back=Capacity-1;
}

bool Queue::isempty(){
    return (size==0);
}

bool Queue::isfull(){
    return (size==capacity);
}

void Queue::enqueue(int val){
    if(isfull()){
        cout<<"Given Queue is Full can't Enqueue"<<endl;
        return;
    }
    back=(back+1)%capacity;
    data[back]=val;
    size++;
}

void Queue::dequeue(){
    if(isempty()){
        cout<<"Given Queue is Empty can't Dequeue"<<endl;
        return;
    }
    front=(front+1)%capacity;
    size--;
}

int Queue::getfront(){
    if(isempty()){
        cout<<"Given Queue is Empty"<<endl;
        return INT_MIN;
    }
    return data[front];
}

int Queue::getback(){
    if(isempty()){
        cout<<"Given Queue is Empty"<<endl;
        return INT_MIN;
    }
    return data[back];
}

int main() {
    Queue q(10);
  
    q.enqueue(34);
    q.enqueue(54);
    q.enqueue(67);
    q.enqueue(49);
  
    q.dequeue();
    cout<<"dequeued from queue\n";
  
    cout<<"Front value is "<<q.getfront()<<endl;
    cout<<"Back value is "<<q.getback()<<endl;
    q.dequeue();
    q.enqueue(50);
    cout<<endl<<"dequeued from queue\n";
    cout<<"Front value is "<<q.getfront()<<endl;
    cout<<"Back value is "<<q.getback()<<endl;
  
    return 0;
}

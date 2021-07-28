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

class Stack{
    private:
    int *data,capacity,size;
    
    public:
    Stack(int capacity);
    void pop();
    void push(int val);
    int peek();
    bool isempty();
    
};

Stack::Stack(int capa){
    data=new int[capa];
    capacity=capa;
    size=0;
}

bool Stack::isempty(){
    return (size==0);
}

void Stack::push(int val){
    if(size==capacity){
    cout<<"Stack Overflowed for value: "<<val<<endl;
    return;
    }
    data[size]=val;
    size++;
}

void Stack::pop(){
    if(isempty()){
        cout<<"Stack Underflowed"<<endl;
        return;
    }
    size--;
}

int Stack::peek(){
    if(!isempty()){
        return data[size-1];
    }
    return INT_MIN;
}


int main() {
    Stack s(5);
    int i;
    for(i=1;i<=6;i++){
        s.push(i);
    }
    
    
    while(!s.isempty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
}

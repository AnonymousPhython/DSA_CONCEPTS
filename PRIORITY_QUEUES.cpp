#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define mit(it) ::iterator it;
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector <pair<int,int> >
#define vpll vector <long long int, long long int>
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cut int t; cin>>t; while(t--)
#define cook int n; cin>>n; int a[n],i;for(i=0;i<n;i++)scanf("%d",&a[i]);
#define pb push_back 
using namespace std;
// map set insert
// list vector push_back
ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll power(ll x, ll y) {ll res=1; x%=MOD; while(y){if(y&1)res=mul(res,x); y>>=1; x=mul(x,x);} return res;}
ll max(ll x,ll y){if(x>y) return x; else return y;}

void swap(int *a,int *b){
        int t=*a;
        *a=*b;
        *b=t;
    }

vector<int> shiftup(vector<int>&a,int i){
    if(a[i]>a[i/2]){
        swap(a[i],a[i/2]);
        a=shiftup(a,i/2);
    }
    return a;
}

vector<int> shiftdown(vector<int>&a,int i){
    int maxin=i;
    if(2*i+1<a.size() && a[maxin]<a[2*i +1]){
        maxin=2*i+1;
    }
    if(2*i+2<a.size() && a[maxin]<a[2*i +2]){
        maxin=2*i+2;
    }
    if(maxin==i)
    return a;
    swap(a[i],a[maxin]);
    a=shiftdown(a,maxin);
    
    return a;
}


int main() {
    int n,i,k;
    cin>>n;
    vector<int>a;
    for(i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    a=shiftdown(a,0);
    for(i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    
}

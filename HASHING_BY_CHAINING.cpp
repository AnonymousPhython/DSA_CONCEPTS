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
# define pb push_back 
using namespace std;
// map set insert
// list vector push_back
ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll power(ll x, ll y) {ll res=1; x%=MOD; while(y){if(y&1)res=mul(res,x); y>>=1; x=mul(x,x);} return res;}
ll max(ll x,ll y){if(x>y) return x; else return y;}

struct node{
  string str;
  struct node *adr=NULL;
};

int hashf(string a,int m){
int i;
ull ans=0;
for(i=a.length()-1;i>-1;i--){
    ans=(ans*263+a[i])%MOD;
}
return (int)ans%m;
}

bool find(string b,int m,struct node* a[]){
    int i;
    struct node *it;
    i=hashf(b,m);
    it=a[i];
    while(it){
        if(it->str==b)
        return true;
        it=it->adr;
    }
    return false;
}

void del(string b,int m,struct node* a[]){
    if(find(b,m,a)){
    int i;
    struct node *it,*prev;
    i=hashf(b,m);
    it=a[i];
    while(it){
        if(it->str==b && it!=a[i]){
            prev->adr=it->adr;
            return;
        }
        else if(it==a[i] && it->str==b){
            a[i]=it->adr;
        }
        prev=it;
        it=it->adr;
    }
    } 
}

void addit(string b,int m,struct node* a[]){
    if(!find(b,m,a)){
    int i;
    struct node *it,*ir;
    i=hashf(b,m);
    it=a[i];
    ir=(struct node*)malloc(sizeof(struct node));
    a[i]=ir;
    ir->str=b;
    ir->adr=it;
}
}

void check(int i,struct node* a[]){
    struct node *it;
    it=a[i];
    while(it){
      cout<<it->str<<" ";
      it=it->adr;
    }
    cout<<endl;
}

int main() {
    
    int m,n;
    cin>>m>>n;
    int i;
    struct node *v[m]={NULL},*it;
    string a,b;
    int x;
    for(i=0;i<n;i++){
        cin>>a;
        if(a=="find"){
         cin>>b;
         if(find(b,m,v))
         cout<<"yes"<<endl;
         else
         cout<<"no"<<endl;
         
        }
        else if(a=="add"){
            cin>>b;
         addit(b,m,v);
        }
        else if(a=="del"){
            cin>>b;
            del(b,m,v);
        }
        else{
            cin>>x;
            check(x,v);
        }
        
    }
    //cout<<hashf("HellO",m);
    
    
}


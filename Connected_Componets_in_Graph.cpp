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

class Graph{
    private:
        int vertices;
        vector<int> *adj;
    public:
        Graph(int v);
        void connect(int u,int v);
        void bfs(int i);
        void dfs(int i);
        void dfsrec(int i,bool visited[]);
        void connected_components();
};

Graph::Graph(int v){
    vertices=v;
    adj=new vector<int>[v];
}

void Graph::connect(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::bfs(int i){
    bool visited[vertices]={false};
    queue<int>q;
    q.push(i);
    visited[i]=true;
    
    
    while(!q.empty()){
       int i=q.front();
       cout<<i<<" ";
       q.pop();
       for(int j=0;j<adj[i].size();j++){
           if(!visited[adj[i][j]]){
           visited[adj[i][j]]=true;
           q.push(adj[i][j]);
           }
       }
       
    }
    
    
}

void Graph::dfsrec(int i,bool visited[]){
    cout<<i<<" ";
    visited[i]=true;
    for(int j=0;j<adj[i].size();j++){
        if(!visited[adj[i][j]]){
            dfsrec(adj[i][j],visited);
        }
    }
}

void Graph::dfs(int i){
    bool visited[vertices]={false};
    dfsrec(i,visited);
}

void Graph::connected_components(){
    bool visited[vertices]={false};
    cout<<endl<<"Connected components in graph are:"<<endl;
    for(int p=0;p<vertices;p++){
        if(!visited[p]){
            queue<int>q;
            q.push(p);
            visited[p]=true;
            while(!q.empty()){
                int i=q.front();
                cout<<i<<" ";
                q.pop();
                for(int j=0;j<adj[i].size();j++){
                    if(!visited[adj[i][j]]){
                        visited[adj[i][j]]=true;
                        q.push(adj[i][j]);
                    }
                }
            }
        cout<<endl;
        }
    }
}

int main() {
    Graph g(7);
    g.connect(0, 1);
    g.connect(0, 3);
    g.connect(1, 2);
    g.connect(2, 3);
    g.connect(4, 5);
    g.connect(4, 6);
    g.connect(5, 6);
    
    
    /*
    
    GRAPH GIVEN AS INPUT:
    
    0---3     4
    |   |    . .
    |   |   .   .
    1---2  5-----6
    
    */
    
 
    g.connected_components();
    
    
 
    return 0;
}

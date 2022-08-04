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
    vector<pair<int,int>>*adj;
    int vertices,edges;
    
    public:
    Graph(int v){
        vertices = v;
        adj = new vector<pair<int,int>>[v];
    }
    
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int> Dijkstra(int source){
        
        vector<int> dist(vertices,INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int,int>>pq;
        pq.push({0,source});
        
        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if(dist[u]==d){
                for(auto it:adj[u]){
                    int v = it.first;
                    int w = it.second;
                    
                    if(dist[u]+w<dist[v]){
                        dist[v]=dist[u]+w;
                        pq.push({dist[v],v});
                    }
                
                }
            }
            
        }
        return dist;
    }
    
};


int main(){
  
    int edges,vertices;
    cin>>vertices>>edges;
  
    Graph g(vertices);
    for (int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    vector<int>distances;
    
    distances=g.Dijkstra();
  
    for(int i=0;i<distances.size();i++){
        cout<<"Min distance of node "<<i<<" from source is "<<distances[i]<<endl;
    }
 
    return 0;
}

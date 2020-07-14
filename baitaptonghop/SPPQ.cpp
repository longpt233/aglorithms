//duong di ngan nhat 
// dijtra


#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
 
typedef pair<int, int> iPair;
vector<pair<int,int> > adj[MAX];

int s,t;

long long  primMST(){
   //min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(MAX, INT_MAX);    // dist to dinh truoc
    vector<bool> visited(MAX, false);  
    pq.push(make_pair(0,s)); // chi phi, tu dinh 
    dist[s] = 0;
    long long  res=0;  // neu de int se bi wrong tesst cuoi 
    while (!pq.empty()) {   
        int u = pq.top().second; 
        pq.pop(); 
        if(u==t) return dist[u];
        // Get all adjacent of u.  
        for (auto x : adj[u]){ 
            int v = x.first; 
            int weight = x.second; 
            // If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
    
        return -1;
}
int main() {
    
    ios_base::sync_with_stdio(0);
    int k;
    int V;
    cin >>V>>k;
    while(k--){
            int u,v,wt;
            cin >>u>>v>>wt;
            adj[u].push_back(make_pair(v, wt));
    }

    cin >>s>>t;
    cout<<primMST();
 
    return 0;

}

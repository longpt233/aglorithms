// cay khung nho nhat
// prim 


#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
 
typedef pair<int, int> iPair;
vector<pair<int,int> > adj[MAX];

long long  primMST()
{
   //min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> key(MAX, INT_MAX);    // dist to mst cua 1 dinh
    vector<bool> inMST(MAX, false);  
    pq.push(make_pair(0,1));
    key[1] = 0;
      long long  res=0;  // neu de int se bi wrong tesst cuoi 
while (!pq.empty()) {   
    int u=pq.top().second;// second se chua dinh
        if(inMST[u]==true){
            pq.pop();
        }else{
       
        res+=pq.top().first;
        pq.pop();
          inMST[u] = true; // Include vertex in MST
        // Traverse all adjacent of u
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (inMST[v] == false && key[v] > weight) {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));  
            }
            }
        }
}
 
    return res;
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
        adj[v].push_back(make_pair(u, wt));
    }
    cout<<primMST();
 
    return 0;

}

#include<bits/stdc++.h>
using namespace std;

// contest/bai

struct Point{
	int index;
	int l,r;
	int w;
};

bool cmp(const Point a,const Point b){
	if(a.w == b.w){
		if(a.l == b.l){
			return a.r < b.r;
		}
		return a.l < b.l;
	}
	return a.w > b.w;
}

int main(){
	int n,k;
	cin>>n>>k;
	Point arr[k+1];
	for(int i=1;i<=k;i++){
		arr[i].index = i;
		cin>>arr[i].l>>arr[i].r;
		arr[i].w = arr[i].r - arr[i].l + 1;
	}
	sort(arr+1,arr+k+1,cmp);
	long long res = 0;
	vector<Point> vec;
	for(int i=1;i<=k;i++){
		if(arr[i].index <= arr[i].r && arr[i].index>=arr[i].l){
			vec.push_back(arr[i]);
		}
	}
	set<int> s;
	res += vec[0].w;
	for(int i=vec[0].l;i<=vec[0].r;i++){
		s.insert(i);
	}
	for(int i=2;i<=k-2;i++){
		res += vec[i-1].w;
		if(s.find(vec[i-1].l) != s.end()){
			res--;
		}
		if(s.find(vec[i-1].r) != s.end()){
			res--;
		}
		for(int j=vec[i-1].l;j<=vec[i-1].r;j++){
			s.insert(j);
		}
	}
	cout<<res<<"\n";
	return 0;
}

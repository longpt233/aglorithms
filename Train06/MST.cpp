// A C++ program for Prim's Minimum  
// Spanning Tree (MST) algorithm. The program is  
// for adjacency matrix representation of the graph  
#include <bits/stdc++.h> 
using namespace std; 
  
int v;// so dinh

vector<pair<int ,int>> adj[100001];
// distToMST values used to pick minimum weight edge to MST
int distToMST[100001];  
// cac dinh v  co trong set hay khong 
bool mstSet[100001];  
 
void InPut(){
    int k;
    cin >>v>>k;
    for (int i=1;i<=v;i++){
        distToMST[i] =1000000;
        mstSet[i] = false;  
        // for (int j =1;j<=v;j++){
        //     graph[i][j]=0;   // bang 0 tuc la khong ton tai duong di 
        // }
    }
 
    while(k--){
        int p,q,h;
        cin >>p>>q>>h;
        adj[p].push_back(make_pair(q,h));
        adj[q].push_back(make_pair(p,h));
    } 
    //  for (int i=1;i<=v;i++){
    //     for (int j =1;j<=v;j++){
    //        // graph[i][j]=0;   // bang 0 tuc la khong ton tai duong di 
    //         cout<< graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
 
  
int mindistToMST( )  {  
    // Initialize min value  
    int min =1000000, min_index;  
  
    for (int i = 1; i <= v; i++)  // set tat cac cac dinh 
        if (mstSet[i] == false)     // set cac dinh khong co trong set 
            
            if(distToMST[i] < min){  
                min = distToMST[i];
                min_index = i;
            }  
  
    return min_index;    // tra ve cai dinh ma f minh noi ra day 
}  
  
 
int primMST()  {
    int res=0;  
    distToMST[1] = 0; 
  
    for (int count = 0; count < v; count++) {  
        int u = mindistToMST();  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;
        res+=distToMST[u];  
  
        for (int i=1; i <= v; i++){ //UPDATE tat ca dinh 
        //co the toi duoc tu u vi chi co u thay doi moi phai UPDATE
        //khong trong mst 
            int cost=0;
            for(auto x: adj[u]){
                if (x.first==i) cost=x.second;
            }
            if(cost!=0 && mstSet[i] == false)
                  // duuong di nho hon 
                if (cost < distToMST[i])  
                     distToMST[i] = cost; 

        } 
    }  
  
    return res;
}  
  
// Driver code 
int main()  
{  
    ios_base::sync_with_stdio(false);
    InPut();
    cout<< primMST();  
  
    return 0;  
}  
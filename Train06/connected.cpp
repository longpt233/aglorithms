    #include<bits/stdc++.h>
     
    using namespace std;
     
    int n,m;
    vector<int > a[100001];// danh dsach ke
    vector<int> visited(100001,0);  // chua visit gan bang 0;
    queue<int> q;  // hang doi 
     
    void bfs(int start){    // tham  bfs tinh tu dinh start 
        q.push(start);
        visited[start]=1;// tham roi thi cho bang 1
        while (!q.empty()){
            int push= q.front();
            q.pop();
            for(auto i: a[push]){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
     
    void input(){
        ios_base::sync_with_stdio(0);
        cin>>n>>m;
        while (m--){
            int k,b;
            cin>> k>>b;
            a[k].push_back(b);
            a[b].push_back(k);
        }
        
    }
    
    int main(){
     
        input();
        int count=0;
        for(int i =0;i<n;i++){
            if(visited[i]==0){
                bfs(i);
                count++;
            }
        }
        cout<<count-1;
        
    }
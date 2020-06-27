#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int > a[100001];// danh dsach ke
vector<int> visited(100001,-1);  // chua visit gan bang -1;
queue<int> q;  // hang doi 

int  bfs(int start){    // tham  bfs tinh tu dinh start 
    q.push(start);
    visited[start]=1;// tham roi thi set mau la 1
    while (!q.empty()){
        int push= q.front();
        q.pop();
        for(auto i: a[push]){
            if(visited[i]==visited[push])return 0;   // 1 la khong phai do thi 2 phia 
            else if (visited[i]==-1){
                q.push(i);
                visited[i]=(visited[push]+1)%2;
            }
        }
    }
    return 1;
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
    
    cout<<bfs(1);
    
}
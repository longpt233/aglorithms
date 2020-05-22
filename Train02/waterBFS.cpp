#include<iostream>
#include<map>
#include<utility>// pair
#include<queue>   // queue
#include<algorithm>  // max

// duyet BFS thuong la cho nhung bai toi uu dang ngan nhat
//  KHAC quy hoạch động hoặc backtrack
#define pii pair<int,int>  // luu tru trang thai cua 2 jugs
using namespace std;

void Init(int a,int b,int visited[][],queue<pii> &q,int x,int y){
    if(visited[a][b]==0) {  
            q.push({ a , b }); 
            visited[a][b]=visited[x][y]+1;
        }
}


int BFS(int a,int b,int c){
    int visited[a][b];  // luu giu thu tu tham

    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
            visited[i][j]=0;
    
    
    queue<pii>q;  // BFS
    q.push({0,0}); // Initialing 

    visited[0][0]=1;
    while (!q.empty()) { 
        pii u = q.front(); 
        q.pop(); 
        int x=u.first ;
        int y=u.second;
        if (x == c || y == c) { 
            return visited[x][y];
        }

        // taoo cau hinh moi
        // 6 truong hop
       /*  if(visited[x][b]==0) {  
            q.push({ x , b }); 
            visited[x][b]=visited[x][y]+1;
        }
        if(visited[a][y]==0) {
            q.push({ a, y });
            visited[a][y]=visited[x][y]+1;
        }
        if(visited[x][0]==0 ){
            q.push({ x , 0 });
            visited[x][0]=visited[x][y]+1;
        }
        if(visited[0][y]==0) {
            q.push({ 0, y }); 
            visited[0][y]=visited[x][y]+1;
        }*/

        Init(x,b,visited,q,x,y);
       
    } 


    return -1;
}
int main(){

    cout<<BFS(6,8,4);
    return 0;
}
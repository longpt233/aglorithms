#include<bits/stdc++.h>

using namespace std;


int c[5001],d[5001];
int n,k;
vector<int > a[5001];// danh dsach ke
vector<int> visited(5001,-1);  // chua visit gan bang -1;
queue<int> q;  // hang doi 
int dist[5001][5001];   // mag chi phi cua duong di ngan nhat

void input(){
 
    cin>>n>>k;
    for (int i = 1; i <=n; i++){
        /* code */
        cin >> c[i]>>d[i];
        for (int j =1;j<=n;j++){
            dist[i][j]=INT_MAX;
        }
    }
    
    
    while (k--){
        int k,b;
        cin>> k>>b;
        a[k].push_back(b);
        a[b].push_back(k);
    }
    
}

int  bfs(int start){    // tham  bfs tinh tu dinh start 
    q.push(start);
    visited[start]=1;// tham roi thi set mau la 1
    dist[start][start]=0;
    while (!q.empty()){
        int push= q.front();
        q.pop();
      //  if(dist[start][push]<d[start]){   // chi tham toi nhung dinh du chi phi cai nay se dc kiem tra o duoi roi 
  
            for(auto i: a[push]){
                if (visited[i]==-1){
                    q.push(i);
                    visited[i]=1;
                    dist[start][i]=dist[start][push]+1;  // day chinh la thay cho cai visited 
                }
            }
       // }
    }
    return 1;
}

void calculate(){
    for (int i =1;i<=n;i++){
        bfs(i);
        for (int j=1;j<=n;j++){
            visited[j]=-1;
        }
    }
}

void disjtra(){ 
        int ans[5001];  // mang chua min chay tu dinh 1 
        for ( int i = 0; i <= n ; i ++) {
            ans[i] = INT_MAX ;   // ans 0 cung la max
            visited[i] = 0;   // vitst bang 0 la chua tham 
        }
        ans[1] = 0;   // tham tu dionh 0
        // visited[1]=1;
        int step = n ;
        while(step--) {
            int min_vertex = 0;   //*min_element(ans+1,ans+n);   // nay khong dc vi con co dieu kien visited
            // vong for nay chinh la hang doi uu tien 
            for ( int i=1;i<=n;i++) {
                if ( visited[i]==0)      // neu chua tham toi thi moi tham . neu tham roi tuc la co ton tai res +visited roi  
                    if( ans[min_vertex] > ans[i]){  // cap nhat lien tuc min_vertex
                        min_vertex = i ;     // sau moi for thi quang duong ans giam di va luu lai trong min_vertex 
                }
            }                   // cuoi cung i = min_vertex = dinh gan nhat tu 1 toi dc 
            visited[min_vertex] = 1;   // cho no la da tham 
            
            for (int i= 1;i<=n;i++) {
                if ( dist[min_vertex][i] <= d[min_vertex]) { // neu con tham dc thi tham tu dinh gan nhat 
                    ans[i] = min(ans[i],ans[min_vertex]+c[min_vertex]);
                }
            }
        }
        cout << ans[n] ;//<< endl;

            // for (int i= 1;i<=n;i++) {

            //    // cout<<ans[i]<<endl;
            //     for(int j=1;j<=n;j++){
            //         cout<< dist[i][j]<<" ";
            //     }
            //     cout <<endl;
            // }
}




int main (){
       ios_base::sync_with_stdio(0);
       input();
       calculate();
       disjtra();


       return 0;
}
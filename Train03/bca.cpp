/*
    sogiaovien somonhoc
    nhungmonhocgiaovien thu nhat day dc
    gv 2
    so cac cap mau thuan 
    cap mau thuan 

*/

// xet het cach chia => tinh  ham muc tieu
#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 30
 
int m,n;   // m la sô giáo viên <=10 , n là số môn <30
int gvmon[11][31]={0};  // voi gv-mon =1 neu gv day  
int conflic,con[MAX][MAX];
int x[31];  // x[mon]=giao vien
int gvsomon[11]={0};// tim max cua cai nay 
int gvsomonMax=INT32_MAX;
int gvsomonMaxToi[31]={0};  // [11]  ##


bool Can(int j,int i){// xem mon i co bij trung gio voi tc do khong voi cung mot giao vien j
    if(i==1) return true;
    else
    for (int k=1;k<i;k++){
        if(x[k]==j){
            if(con[k][i]==1) return false;
        }
    }
    return true;
}

void Try(int i){      // try toi so mon  n
    for (int j=1;j<=m;++j){    // for tat ca giao vien 
        if((gvsomon[j]+1<gvsomonMax)&&gvmon[j][i]==1&&Can(j,i)){
            
            x[i]=j;  // mon i dc giao vien j day
            gvsomon[j]++;  // so mon day cau giao vien j
            if(i==n){
                gvsomonMax=min(gvsomonMax,gvsomonMaxToi[i-1]);
            }else{
                gvsomonMaxToi[i]=max(gvsomonMaxToi[i-1],gvsomon[j]);
                if(gvsomonMaxToi[i]<gvsomonMax) Try(i+1);
            }
            gvsomon[j]--;
            
        }
    }
}

int main(){
    cin >>  m>>n; 
    for(int i=1;i<=m;i++){
        int p;
        cin >> p;
        for (int j=1;j<=p;j++){
            int q;
            cin>>q;
            gvmon[i][q]=1;
        }
    }
    cin >> conflic;  
    for (int i=1;i<=conflic;i++){
        int p,q;
        cin >>p>>q;
        con[p][q]=con[q][p]=1;
    }
    gvsomonMaxToi[0]=0;
    Try(1);
    if(gvsomonMax==INT32_MAX) cout<< "-1";
    else cout<< gvsomonMax;


    return 0;
}
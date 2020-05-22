// ver 11/3 
// chu y co them lam lai duong (tuc la thuco tinh van the)
#include<iostream>
#include<fstream>

using namespace std;
// truyen *t la du khong can den muc (&t)[]
int reroad(int *t,int &rugged,int n, int pi,int ci){
      //t[pi]=ci;
       // khon gthay doi j
      if (t[pi]==ci)  return rugged;
      // xet bieen truoc
      if(pi==1){
            if (t[pi]==t[pi+1]) rugged++;
            else {
                t[pi]=ci;
                if (t[pi]==t[pi+1])rugged--;
            }
      }else if (pi==n){
            if (t[pi]==t[pi-1]) rugged++;
            else {
                t[pi]=ci;
                if (t[pi]==t[pi-1])rugged--;
            }
      }else 
      
      // xet vao trong 
      // truong hop 1 :dang bang nhau 
      if (t[pi]==t[pi+1]&&t[pi]==t[pi-1]){
          t[pi]=ci;
          rugged=rugged+2;
      }else{   // truogn hop 2: khac nhau 
            //t[pi]=ci;

            if(t[pi]==t[pi+1]||t[pi]==t[pi-1]) {// truong hop co mot cai bang san roi
                t[pi]=ci;
                //if(t[pi]==t[pi+1]||t[pi]==t[pi-1])
                if(t[pi]!=t[pi+1]&&t[pi]!=t[pi-1])
                    rugged++;
            }else if (t[pi]!=t[pi+1]&&t[pi]!=t[pi-1]&&t[pi+1]!=t[pi-1]){  // th khac ca 2 cai lien ke 
                t[pi]=ci;
                if(t[pi]==t[pi+1]||t[pi]==t[pi-1])
                    rugged--;
            }else if (t[pi]!=t[pi+1]&&t[pi]!=t[pi-1]&&t[pi+1]==t[pi-1]){ // khac nhung 2 cai ria lai bang nhau
                t[pi]=ci;
                if(t[pi]==t[pi+1]||t[pi]==t[pi-1])
                    rugged=rugged-2;
            }
      }
        
      return rugged;
}

int road (int *t,int n){
    int rugged=1;
    for (int i=1;i<n;i++){
        if (t[i+1]==t[i]) continue;
        else rugged++;
    }
    return rugged;
}


int main(){
    //freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int n; cin >>n;
    int t[n+1];
    
    for (int i=1;i<=n;i++) cin >>t[i];  // dung thu tu doan duong thi 1=>n.
    int rugged=road(t,n);
    //cout<< rugged;
    int q; cin >>q;
    int pi,ci;
    for (int i=0;i<q;i++){
        cin >>pi>>ci;
        cout<< reroad(t,rugged,n,pi,ci)<<endl;  // tại sao không truyền duwopcj &t?
        // vi t vôn dĩ là tên mảng là đia chỉ rồi .
    }
    return 0;
}


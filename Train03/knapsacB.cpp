// knapsac branch and bouch
// khong dc lay trung lap

#include<iostream>

using namespace std;
int n,b;
int w[31],c[31];  // c la gia tri su dung
int x[31]={0};// danh dau duong di  10110101
int fMax=0 ;    // c  toi uu 
int f=0;        // c hien tai 
int bCur;   // w hien tai
int g=0;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void Print(){
    for (int i=1;i<=n;i++){
        cout << w[i]<< " "<< c[i]<<endl;
    }
}

void Sort(){  // gia tri su dung =c/w xap xep theo thu tu giam dan

    for (int i = 1; i <=n-1; i++){
        for (int j = i+1; j <= n; j++)
            if (c[j]/w[j] > c[i]/w[i]){
                swap(c[j],c[i]);
                swap(w[j],w[i]);
            }
    }
}

void Try(int k){
    
   /*  if (bCur <w[k]){ 
        x[k]=0;
        if(k==n) {
            fMax=f;
            return;
        }
        else Try(k+1);
    }else */
    int m=1;
    if(bCur<w[k]){
        m=0;
    }
    
    for (int i=m;i>=0;i--){
        x[k]=i;
        bCur-=i*w[k];
        f+= i*c[k]; 
        if(k==n){
            if (f>fMax) fMax=f;
        } 
        else {
            //g=f+c[k+1]*(bCur/w[k+1]);  // can tren neu xet tiep 
            /* if (g>fMax) */ Try(k+1);      // >
        } 
        bCur+=i*w[k];
        f-= i*c[k];
    }
}



int main(){
    //freopen("input.txt","r",stdin);
    cin >>n>>b;
    for(int i=1;i<=n;i++){
        cin >>w[i]>>c[i];
    }
    /* Print();
    cout<<"out put"<< endl;
    Sort();
    Print(); */
   // Sort();
    bCur=b;
    Try (1);
    cout<< fMax;
    return 0;
}
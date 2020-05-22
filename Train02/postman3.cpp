#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

struct custommer{
    int x;
     int m;
};

bool compare(custommer a,custommer b){
    return (a.x<b.x);
}

unsigned long int kq(custommer a[],int soluong,int k){
    sort(a,a+soluong,compare); // sap xep tang dan thao khoang cach x
    unsigned long int result=0;
    int i=soluong-1;
    while(i>=0){
        int loop =a[i].m/k;
        if(loop*k!=a[i].m ){ 
            loop++;
            result +=(long long)a[i].x*(loop)*2;
            // int remain=k-a[i].m;
            int remain=k*loop-a[i].m;
            i--;
            while((remain>0)&&(i>=0)){
                //i--;
                if(remain>=a[i].m){
                    remain-=a[i].m;
                    i--;
                }else{
                    a[i].m-=remain;
                    remain=0;
                }
            }
        }else{
            //result +=a[i].x*(loop)*2;  tran so truoc khi cong
            result +=(long long)a[i].x*(loop)*2;
            i--;
        }
    }
    return result;
}

int main(){
    //freopen("input.txt","r",stdin);
    int n,k;
    cin >>n >>k;
    custommer a[n],b[n];  // tach lam 2 day con nau x am cho vao b
    int duong=0,am=0;
    //custommer *a=new custommer[n]; // *a 
    for(int i=0;i<n;i++){
        int temp;
            cin >>temp;
            if (temp>0){
                a[duong].x=temp;
                 cin>>a[duong].m;
                duong++;
               
            }else{
                b[am].x=-temp;
                 cin>>b[am].m;
                am++;
            }
    }
    cout<<kq(a,duong,k)+kq(b,am,k);

    return 0;
}


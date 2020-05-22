// DynamicProgramming in Slide 
// DP

#include<iostream>
using namespace std;

const int MaxN= 1000000;


// hàm tính max dãy 
int MaxElement(int *a,int n){
    int max=-MaxN;
    for (int i=1;i<=n;i++){
        if (a[i]>max) max=a[i];
    }
    return max;

}

int MaxSub(int *a,int n){
    int s[n];
    s[1]=a[1];   
    for (int i=2;i<=n;i++){
        if(s[i-1]<0) s[i]=a[i];
        else s[i]=s[i-1]+a[i];
    } 
    return MaxElement(s,n);
}// ket hop 2 hàm tren thi ta van có độ phức tạp On2 ?

// cải tiến : tính dãy con đến đâu tìm  max đến đấy 


int main (){
    int n;
    cin>>n;
    int w[n+1];
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cout<<MaxSub(w,n);

    return 0;
}

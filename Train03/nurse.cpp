// xet lan luotj tung xau nhi phan . neu thoa man thi tang kq len 
// xau : sinh ke tiep + de quy+ doi thap phan, nhi phan 

// de quy 
// O(2^n)
#include<iostream>

using namespace std;

int n,k1,k2;
int ans=0;
int x[100];// de in ra xem 

void Try(int i, int l){   // l  la phan bit 1 dai nhat
    if (i>n){
        ans += (l>=k1||l==0);
        return;
    }
    // them 0
    if (i==1||l>=k1) Try(i+1,0);
    // them 1
    if (l<k2) Try(i+1,l+1);
}

int main(){
    cin >> n>>k1 >>k2; // so buoi nghi >= k1<= k2
    Try(1,0);
    cout << ans;


    return 0;
}
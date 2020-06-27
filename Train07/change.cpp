#include<bits/stdc++.h>

using namespace std;

int deno[6]={500,100,50,10,5,1};

int change(int n){  // retuen so dong de co the cau thanh nen to tien 
    int res=0;
    while(n>0){
        for(int i:deno){
            while (n>=i) {
                n-=i;
                res++;
            }
        }
    }
    return res;
}

int main (){
    int n ;
    cin >>n;
    cout<< change(1000-n);




    return 0;
}
#include<iostream>

using namespace std;
const unsigned int c = 1000000007;


// unsigned long long thi dung trong khi int thoi lai khong duoc tai sao??]
// kieu tra vef cung nhu tham so cung chi gioi hanj trong int maf >?

unsigned long long expmmod(unsigned long long  a,unsigned long long b){
    unsigned long long kq;
    if(b==1)return a%c;
    if (b%2==0){
        kq=expmmod(a,b/2);
        kq=(kq*kq)%c;
    }else{
        kq=expmmod(a,b/2);
        kq=(  (kq*kq)%c  )*(a%c)%c;
    }
    return kq;
}

int power(int x, unsigned int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p  
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  

int main(){
    unsigned long long a,b;
    cin >> a>>b;  // dung co cin>> a,b 
    cout << expmmod(a,b);
    return 0;
}
#include<iostream>

using namespace std;

int main (){
        unsigned long long a,b;
    // unsigned long long c=( unsigned long long) 10^9+7;
     const unsigned int c = 1000000007; // thi laij duoc ??
    cin >> a>>b;
    cout <<(unsigned long long)(a%c+b%c)%c;
    return 0;
}
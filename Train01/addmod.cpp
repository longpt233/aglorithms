#include<iostream>

using namespace std;

int Mod(long long a){

}

int mod(string num) { 
    // Initialize result 
    int res = 0; 
  
    // One by one process all digits of 'num' 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0')%(10^9+7) ; 
  
    return res; 
} 

int main(){
    string  a,b;
    cin >> a>>b;
    cout <<(mod(a)+mod(b))%(10^9+7);

    return 0;
}
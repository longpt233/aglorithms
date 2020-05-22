#include<iostream>
#include<limits.h> // for int,char macros 
#include<string>
using namespace std;

int main(){

    cout << "\n\nint ranges from : " << INT_MIN << " to " << INT_MAX;
    cout << "\n\nunsigned long int ranges from : " << 0 << " to " << ULONG_MAX; 
    

    string a;
    cin>>a;
    for(int  i=0;i<a.length();i++)  cout << a.at(i);
    
    return 0;
}
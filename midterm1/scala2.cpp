#include<iostream>
#include<algorithm>

using namespace std;

int T, n;
int x[1000]={0};
int y[1000]={0};

int fopt=INT32_MAX;
int fcur=0;
 
int main(){
    cin>> T;
    for(int i=1;i<=T;i++){
        //fopt=INT32_MAX;
        cin >> n;

        
        for(int j=0;j<n;j++){
            cin>>x[j];
            
        }
        for(int j=0;j<n;j++){
            cin>>y[j];
        }

        sort(x,x+n);
        sort(y,y+n);
         
         fcur=0;
        for(int j=0;j<n;j++){
            fcur+=x[j]*y[n-j-1];
        }

        
        

        cout<< "Case #"<<i<<": " <<fcur<<endl;


    }
    return 0;
}
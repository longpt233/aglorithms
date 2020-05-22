#include<iostream>

using namespace std;

int max(int *a,int b,int c){
    int result=0;
    for(int i=b;i<=c;i++){
        if (a[i]>result ) result=a[i];
    }
    return result;
}
// On2 => 25 point
int cut(int *a,int b,int length){
    for (int i=1;i<length-2;i++){
        int maxleft=max(a,0,i-1);
        int maxright=max(a,i+1,length-1);
        if( (maxleft-a[i])>=b&&(maxright-a[i])>=b)
        return ((maxleft-a[i])+(maxright-a[i]));
        
    }

    return -1;

}



int main(){
    int n,b;
    cin >>n>>b;
    int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }

    cout<< cut(a,b,n);


    return 0;
}
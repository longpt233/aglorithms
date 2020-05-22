#include<iostream>
#include<algorithm>

using namespace std;


// DP :O(n)
int cut2(int *a,int b,int length){
    int left[length],right[length];
    left[0]=a[0];
    right[length-1]=a[length-1];
    int result=-1;

    for (int i=1;i<length;i++){
        left[i]=max(left[i-1],a[i]);
    }
    for (int i=length-2;i>=0;i--){
        right[i]=max(right[i+1],a[i]);
    }

    for (int i=1;i<length-2;i++){
        
        if( (left[i-1]-a[i])>=b&&(right[i+1]-a[i])>=b)

        // deo hieu sao bai co the co nhieu vi tri cat ma k noi ???
        result=max(result,((left[i-1]-a[i])+(right[i+1]-a[i])));
        
    }

    return result;
}


int main(){
    //freopen("input.txt","r",stdin);
    int n,b;
    cin >>n>>b;
    int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }

    cout<< cut2(a,b,n);


    return 0;
}
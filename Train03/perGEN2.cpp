// tim hoan vi ke tiep

#include<iostream>

using namespace std;

int n;// do dai 

int *goal;


void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

// int find =0  => loi trung mot ham nao do .them #define find acasfxc
int Find(){
    for(int i=n-1;i>=1;i--){
        int k=0;// luu chi chi so cua phan tu nho nhat con nho hon goal[i]
 
        if (goal[i]<goal[i+1]){
            int m=INT32_MAX;
                for(int j=i+1;j<=n;j++){
                if(goal[j]>goal[i]&&goal[j]<m) {
                        m=goal[j];
                        k=j;
                    }
                }
            swap(goal[i],goal[k]);
            for (int j=1;j<=(n-i)/2;j++){
                swap(goal[i+j],goal[n-j+1]);
            }
            
            return 1;    
        }
        
    }
    return -1;
}
int main(){
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin >>n;
    goal=new int[n+1];
    for (int i=1;i<=n;i++){
        cin>>goal[i];
    }
    
    if(Find()==-1) cout <<"-1";
    else 
    for (int i=1;i<=n;i++) cout << goal[i]<<" ";
    
    return 0;
}
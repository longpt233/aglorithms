#include<iostream>
#include<vector>
#include<algorithm>   // sort 

using namespace std;

vector <int > a={1,3,4,5,6,32,-1,-32};

int binarySearch(vector<int >&a,int l,int h,int x){
    if(l>h) return 0;
    int m=(h-l)/2;
    if (l==h) return l;
    else if(a[m]>x) return binarySearch(a,l,m,x);

}

int main(){
    int x;
    cin>>x;
    sort(a.begin(),a.end());
    cout<< binarySearch(a,0,a.capacity(),x);
    return 0;
}
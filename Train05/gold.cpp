
#include<algorithm>
#include<iostream>


using namespace std;

int main(){
    int n,l1,l2;
    cin >>n>>l1>>l2;
    int a[n+1];

    // for(int &A :a) cin >>A;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
   // cout<< " done";       // cout oc cho phai chay het chuong trinh moi in het

    // DP
    long long f[n]={0};
    f[0]=0;
    for (int i=1;i<=n;i++){
      //  cout<<"vao for";
        f[i]=a[i];        // phai co cai nay de cap nhat 
        int h=max(0,i-l2); // dinh xa nhat cach i, va no khong the am 
        int j=max(0,i-l1);  // dinh gan nhat . chac chan xe k lay dc n-1 vi l1 duong 
        for(int k=h;k<=j;k++){
            f[i]=max(f[i],f[k]+a[i]);
        }
      //  cout << "f-"<<i<<"="<< f[i]<<endl;
        // cai tien dung hang doi : xap giam dan 
    }
    cout<< *max_element(f,f+n);    // day la mot con tro

    return 0;
}
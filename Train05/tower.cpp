/* sap xep tap cac vien da giam dan theo 
   cong thuc quy hoach dong theo day giam dan day 
   co n vien => 3n cach xoay
   ham f(i)  do cao lon nhat lay 1->i (bat buoc phai dung cai i)
   f(i)=z[i] neu co vien thu i
   f(i)=z[i] +max(f(j)|j<i )
 
 */

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

#define x first.first
#define y first.second
#define z second 

using namespace std;

int main(){
  
int t=1;
  
  while (1){
    vector <pair<pair<int,int>,int>> a;
    int n;
  cin >>n;
  if(n==0) break;

    for (int i=0;i<n;i++){
      int m,n,p;
      cin >>m>>n>>p;
      a.push_back({{m,n},p});
      a.push_back({{m,p},n});
      a.push_back({{p,n},m});
    }
    for (auto &A:a){
      if(A.x>A.y) swap (A.x,A.y);  // ham so sanh : sanh cai first trc sau do den cai second
    }// sau do moi vien se co chieu rong la ffirsst.firrst

    // khong can xoay
    sort(a.begin(),a.end());  // chac chan chieu rongn tang 
    reverse(a.begin(),a.end());  // chach chan cos 1 chieu giam => cai sau k thr dat len cai trc 
    vector <int> f(a.size());
    for (int i=0;i<f.size();i++){
      f[i]=a[i].z;   // chi lay vien i
      for (int j=0;j<i;j++){
        if(a[j].x>a[i].x &&a[j].y>a[i].y){   // vien j co the nam duoi vien i
          f[i]=max(f[i],f[j]+a[i].z);
        }
      }
    }
    std::cout<<"Case " <<t++<<": maximum height = " <<*max_element(f.begin(),f.end())<< endl;



  }



    
    return 0;
}
// dynamic programming

#include <iostream>
#include<stack>
using namespace std;

const int MAXTEST=1000000;

long long  GetMax(int n, int *hist){
    stack<int> s;// luu tru stt i cua hist 
    long long max=0;
    int topStack;
    // long int khác lon glong đéo hiểu kiểu j
    long long  area;
    int i=0;
    while (i<n){
        if (s.empty()||hist[s.top()]<=hist[i]) {  // lon hon cho vao stack.
            s.push(i);
            i++;
            
        }else{   // nho hon tinh s. chu y buoc nay k tang i.
            topStack=s.top();// lấy  đàn top top ra cho đến khi gặp hist nho  hon 
            s.pop();
            area= (long long )hist[topStack]*(s.empty()? i:i-s.top()-1);
            if(max <area) max=area;
        }
    }

    // sau qua trìhh tren stack chi con cac dinh la dinh chốt mà từ đó hist có xu hướng giảm
    // và các đỉnh đó sắp xếp theo thứ tự tăng dần 

    while(!s.empty()){// du bao nhieu lay ra
        topStack=s.top();
        s.pop();
        area= (long long) hist[topStack]*(s.empty()? i:i-s.top()-1);
         if(max <area) max=area;
    }
    return max;
}
int main(){
    int n; 
    //long int kq[MAXTEST];
    int dem=0;
    while(1){
        cin>>n;
        // xuất trực tiếp luôn cx được 
        if (0==n) break;
        // tran bo nho dem  int hist[n];
        int* hist = new int[n];
        for(int i=0;i<n;i++){
            cin >>hist[i];
        }
        cout <<GetMax(n,hist)<<endl ;
        //kq[dem]=GetMax(n,hist);
        //dem++;
    }
    /* for(int i=0;i<dem;i++){
        cout<< kq[i]<<endl;
    } */
    return 0;
}
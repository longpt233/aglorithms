#include <bits/stdc++.h>
using namespace std;

int N,F, r[10001];// r la bk cac phan 
const double pi = 3.14159265358979323846;
const double err=pow(10,-7);

bool Can(double v){// the tich
	int s = 0;//so phan co the tich bang v co the chia ra 
	for (int i=0;i<N;i++){   // chia het tat ca banh ra lam cac phan co the tich v
		s +=(int)(  (double)pi*r[i]*r[i] / v);// con lai vut di 
	}
	// tai sao s>=F lai dc co 10 point ? vi co ca chu tiec nua
	if( s>=F+1) return true;  // so phan co lon hon so nguoi khong ?
	else return false;
}

int main(){
	int t;
	cin >> t;
	double res[t];
	for(int k=0;k<t;k++){
		cin >> N >> F;
		for (int i=0;i<N;i++){
			//printf("nhap %d=",i);

			 cin >>r[i];
		}
		double L = 0, H = 10000000001,M;// H phai lon  tai sao ?? 
		while (H-L>=err){// trong khi con lon hon sai so 
		 	M = (L+H)/2;
			if (Can(M)) L=M;
			else H=M;
		}

		//printf("%.6f\n",H);
		res[k]=H;
		
	}
	for(int k =0;k<t;k++){
		//cout << res[k]<<endl;
		printf("%.6f\n",res[k]);

	}
	return 0;
}
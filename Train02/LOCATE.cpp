#include <iostream>
#include <math.h>

using namespace std;

main() {
	int t;
	
	cin >> t;
	
	while (t--) {
		int l, c = 0, max = 0;
		int x = 0, y = 0;   // chua so luong diem 1 
		
		cin >> l >> c;   // so dong va so cot 
		
		int a[l][c], b[l][c];  // mang luu tru ban dau
		int  rada1[10000][2], rada2[10000][2];// chua toa do ca diem 1 
		for (int j = 0; j < l; j++) 
			for (int h = 0; h < c; h++){
				cin >> a[j][h];
				if (a[j][h]) {
					rada1[x][1] = j;
					rada1[x][2] = h;
					x++;
				}
			}
				
		for (int j = 0; j < l; j++) 
			for (int h = 0; h < c; h++) {
				cin >> b[j][h];
				if (b[j][h]) {
					rada2[y][1] = j;
					rada2[y][2] = h;
					y++;
				}
			}
		
		
		int s1[l][c], s2[l][c], s3[l][c], s4[l][c];
		for (int j = 0; j < l; j++) 
			for (int h = 0; h < c; h++) {
				s1[j][h] = 0;
				s2[j][h] = 0;
				s3[j][h] = 0;
				s4[j][h] = 0;
			}
		
		for (int j = 0; j < x; j++) // for toa do  tat ca cac diem 1 
			for (int h = 0; h < y; h++)
				if (rada1[j][1] - rada2[h][1] < 0)
					if (rada1[j][2] - rada2[h][2] < 0)
					// chia ra lam 4 huong tuong doi 
					// cap s[a][b]=> a,b xac dinhj huocn cuj the cua diem do trong huong do 
						s1[abs(rada1[j][1] - rada2[h][1])][abs(rada1[j][2] - rada2[h][2])]++;  
					else 
						s2[abs(rada1[j][1] - rada2[h][1])][abs(rada1[j][2] - rada2[h][2])]++;
				
				else if (rada1[j][2] - rada2[h][2] < 0)
						s3[abs(rada1[j][1] - rada2[h][1])][abs(rada1[j][2] - rada2[h][2])]++;
					else 
						s4[abs(rada1[j][1] - rada2[h][1])][abs(rada1[j][2] - rada2[h][2])]++;
		
		for(int j = 0; j < l; j++) 
			for (int h = 0; h < c; h++) {
				if (max < s1[j][h]) 
					max = s1[j][h];
				if (max < s2[j][h]) 
					max = s2[j][h];
				if (max < s3[j][h]) 
					max = s3[j][h];
				if (max < s4[j][h]) 
					max = s4[j][h];
			}
				
		cout << max << endl;
	}
}

#include <iostream>
#include <math.h>

using namespace std;

main() {
	int t, i, j;
	
	cin >> t;
	
	for(i = 0; i < t; i++) {
		int l, c, h, k = 0, max = 0, x = 0, y = 0;
		
		cin >> l >> c;
		
		int a[l][c], b[l][c], s1[l][c], s2[l][c], s3[l][c], s4[l][c], d1[10000][2], d2[10000][2];
		for (j = 0; j < l; j++) 
			for (h = 0; h < c; h++){
				cin >> a[j][h];
				if (a[j][h]) {
					d1[x][1] = j;
					d1[x][2] = h;
					x++;
				}
			}
				
		for (j = 0; j < l; j++) 
			for (h = 0; h < c; h++) {
				cin >> b[j][h];
				if (b[j][h]) {
					d2[y][1] = j;
					d2[y][2] = h;
					y++;
				}
			}
		
		for (j = 0; j < l; j++) 
			for (h = 0; h < c; h++) {
				s1[j][h] = 0;
				s2[j][h] = 0;
				s3[j][h] = 0;
				s4[j][h] = 0;
			}
		
		for (j = 0; j < x; j++) 
			for (h = 0; h < y; h++)
				if (d1[j][1] - d2[h][1] < 0)
					if (d1[j][2] - d2[h][2] < 0)
						s1[abs(d1[j][1] - d2[h][1])][abs(d1[j][2] - d2[h][2])]++;
					else s2[abs(d1[j][1] - d2[h][1])][abs(d1[j][2] - d2[h][2])]++;
				else if (d1[j][2] - d2[h][2] < 0)
						s3[abs(d1[j][1] - d2[h][1])][abs(d1[j][2] - d2[h][2])]++;
					else s4[abs(d1[j][1] - d2[h][1])][abs(d1[j][2] - d2[h][2])]++;
		
		for (j = 0; j < l; j++) 
			for (h = 0; h < c; h++) {
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

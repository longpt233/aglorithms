#include<bits/stdc++.h>

using namespace std;

vector<string> f;
string p;
int n;

string g(int n, int k){   // lay k ki tu cuoi cua f[n]
    if (n < f.size()){
		if (f[n].size() < k) return f[n];
		else return string(f[n].end()-k, f[n].end());
	}
	if (f[n-2].size() >= k) return g(n-2, k);
	return g(n-1, k - f[n-2].size()) + f[n-2];
}

string h(int n ,int k){   // lay ra k ki tu dau 

}

int Check(string s){   // dem so lan saut hien p trong s
    for(int )
}

long long  Fib(int n){    // co the dung mang luu dau
    if(n<=1) return(p==f[n]);
    long long ans = Fib(n-1) + Fib(n-2);
	string s = g(f[24+n%2], p.size()-1) + h(n-2, p.size()-1);
	ans+=Check(s);
	return ans;
}

int main(){
    cin>> n;	// sinh toi f(n)	
    cin >>p;   // xau can tim 
    f.push_back("0");  // f[0]=0
    f.push_back("1");   //f[0]=0,f[1]=1,f[2]=10, f[3]=101
    for (int i = 2; i <= n; ++i){
		f.push_back(f.back() + f[f.size() - 2]);
	}

}
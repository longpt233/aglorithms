#include <iostream>
#include <algorithm>

using namespace std;

int Sobo(int d, int n, int x[])
{ // tra veso bo co the dat dc voi khoang cach d
    int count = 1;
    int last = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] - last >= d)
        {
            count++;
            last = x[i];
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, c;
    cin >> t;
    int res[t];
    //while (t--){

    for (int k = 0; k < t; k++)
    {
        cin >> n >> c;
        int x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        sort(x, x + n);
        // for (int i =0;i<n;i++){
        //     cout << x[i];
        // }
        // int sobo[x[n-1]];  // so bo voi khoang cach
        // for (int d=1;d<=x[n-1];d++){
        //     sobo[d]=Sobo(d,n,x);
        // }

        long long low = 0, high = x[n - 1];
        while (1 + low < high)
        {

            long long mid = (low + high) / 2;

            if (Sobo(mid, n, x) >= c)
            {              //
                low = mid; // co the tang khang cach  => giam so bo
            }
            else
            {
                high = mid;
            }
        }
        //cout << low;
        res[k]=low;
    }

    for(int i=0;i<t;i++){
        cout << res[i]<< endl;
    }

    return 0;
}
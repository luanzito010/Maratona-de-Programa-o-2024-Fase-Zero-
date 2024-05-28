#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;

const int maxn = 1e6 + 10,inf = 1e16 + 10;

int n,t = 6;

int32_t main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << t - (a + b + c) << "\n";

    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;

const int maxn = 1e6 + 10,inf = 1e16 + 10;

double e,v;
int h,m;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> e >> v;
    
    int dif = (int) e % (int) v;
    m = (int) ((60.0 / v) * (double) dif);
    h = e / v;
    h = (19 + h) % 24;
    string hh,mm;
    if(h / 10 == 0) hh = "0" + to_string(h);
    else hh = to_string(h);
    if(m / 10 == 0) mm = "0" + to_string(m);
    else mm = to_string(m);
    
    cout << hh << ":" << mm << "\n";

    return 0;
}
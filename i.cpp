#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;

const int maxn = 1e6 + 10,inf = 1e16 + 10;

int n,m,pref[2 * maxn];
set<int> ss[maxn];
string s;

int32_t main(){
    
    cin >> n >> m >> s;
    
    for(int i = 0;i < n * m;i++)
        s.pb(s[i]);
    
    for(int i = 1;i <= 2 * n * m;i++){
        if(s[i - 1] == '1') pref[i] = 1;
        pref[i] += pref[i - 1];
    }
    
    for(int i = 1;i <= (n * m);i++){
        int pos = (i - 1) % m;
        int qtd = pref[i + m - 1] - pref[i - 1];
        if(ss[pos].find(qtd) == ss[pos].end()) ss[pos].insert(qtd);
        else{
            cout << "N\n";
            return 0;
        }
    }
    
    cout << "S\n";

    return 0;
}
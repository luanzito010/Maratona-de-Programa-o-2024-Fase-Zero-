#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;

const int maxn = 1e6 + 10,inf = 1e16 + 10;

int t;

bool ehprimo(int n){
    
    if(n == 0 || n == 1) return 0;
    
    bool ok = 1;
    
    for(int i = 2;i * i <= n;i++)
        if(n % i == 0){ 
            ok = 0;
            break;
        }
    
    return ok;
    
}

void solve(){
    
    int x;
    cin >> x;
    int a = x / 2;
    int b;
    if(x & 1) b = a + 1;
    else b = a;
    
    while(a != -1 && b != x + 1){
        //cout << a << " " << b << "\n";
        if(a == b || ehprimo(a) || ehprimo(b)){
            a--;
            b++;
        }
        else break;
    }
    
    if(a == -1 || b == x + 1) cout << -1 << "\n";
    else cout << a << " " << b << "\n";
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;
using tii = tuple<int,int,int>;

const int maxn = 1e6 + 10,inf = 1e16 + 10;

int n,m,k,resp = inf,pai[maxn],peso[maxn],horas[maxn];
bool ok = 1;
vector<tii> edge;

int find(int x){
    return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x,int y,int c){
    x = find(x);
    y = find(y);
    
    if(x == y) return;
    
    if(peso[x] < peso[y]) swap(x,y);
    if(find(1) == x && peso[x] >= k) resp = min(resp,horas[x]);
    peso[x] += peso[y];
    horas[x] = max(horas[x],c); 
    pai[y] = x;
    if(find(1) == x && peso[x] >= k) resp = min(resp,horas[x]);
    
}

int32_t main(){
    
    cin >> n >> m >> k;
    
    for(int i = 1;i <= m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        edge.pb({c,u,v});
    }
    
    sort(edge.begin(),edge.end());
    
    iota(pai + 1,pai + n + 1,1);
    fill(peso + 1,peso + n + 1,1);
    
    for(auto [c,u,v] : edge)
        if(find(u) != find(v))
            join(u,v,c);
    
    cout << (k == 1 ? 0 : resp) << "\n";

    return 0;
}
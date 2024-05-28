#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;

const int maxn = 1e6 + 10,inf = 1e16 + 10;
map<string,int> mark;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> c(n);
    vector<string> o(n);
    
    for(int i = 0;i < n;i++)
        cin >> c[i];
    
    for(int i = 0;i < n;i++)
        cin >> o[i];
        
    int j = 0;
    
    for(int i = 0;i < n;i++){
        cout << (i == 0 ? "" : " ") << o[j] << (i == n - 1 ? "\n" : "");
        mark[c[i]] = 1;
        if(c[i] == o[j]){
            while(mark[o[j]] && j < n - 1)
                j++;
        }
        else continue;
    }

    return 0;
}
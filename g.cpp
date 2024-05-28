#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;

const int maxn = 1e5,inf = 1e16 + 10;

int n,k,r,a[maxn + 5],b[maxn + 5],dp[maxn + 5];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    
    for(int i = 1;i <= n;i++){
        cin >> b[i];
    }
    
    int last = 0;
    int last_pos = 0;
    
    while(true){
        int maior = 0,pos = 0;
        
        for(int i = last_pos + 1;i <= n;i++)
            if(a[i] - last <= k){
                if(i == n){ 
                    pos = n;
                    break;
                }
                else if(maior <= a[i] + b[i]){
                    maior = a[i] + b[i];
                    pos = i;
                }
            }
            else break;

        
        if(pos == n) break;
        else if(maior == 0){
            cout << -1 << "\n";
            return 0;
        }
        else{ 
            r++;
            k = b[pos];
            last = a[pos];
            last_pos = pos;
        }
    }
    
    cout << r << "\n";

    return 0;
}
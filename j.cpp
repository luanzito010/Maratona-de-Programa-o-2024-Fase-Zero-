#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lsb(x) (x & (-x))

using namespace std;

const int maxn = 5e2 + 10,inf = 1e16 + 10;

int n,m,l,k,maior,x,y;
char mat[maxn][maxn];
string s;
vector<pair<int,string>> v;

bool comp(pair<int,string> a,pair<int,string> b){
    
    if(a.fr != b.fr) return a.fr < b.fr;
    return a.sc > b.sc;
    
}

int32_t main(){
    
    cin >> n >> m >> l >> k;
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> mat[i][j];
    
    l--;
    k--;
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++){
            if(mat[i][j] == '*') continue;
            int aux = 0;
            if(l == 0){
                if(i + l <= n && j + k <= m) aux += (mat[i + l][j + k] == '*');
                if(i + l <= n && j - k > 0) aux += (mat[i + l][j - k] == '*');
                if(i + k <= n && j - l > 0) aux += (mat[i + k][j - l] == '*');
                if(i - k > 0 && j + l <= m) aux += (mat[i - k][j + l] == '*');
            }
            else if(k == 0){
                if(i + l <= n && j - k > 0) aux += (mat[i + l][j - k] == '*');
                if(i - l > 0 && j + k <= m) aux += (mat[i - l][j + k] == '*');
                if(i + k <= n && j - l > 0) aux += (mat[i + k][j - l] == '*');
                if(i - k > 0 && j + l <= m) aux += (mat[i - k][j + l] == '*');
            }
            else{
                if(i + l <= n && j + k <= m) aux += (mat[i + l][j + k] == '*');
                if(i + l <= n && j - k > 0) aux += (mat[i + l][j - k] == '*');
                if(i - l > 0 && j + k <= m) aux += (mat[i - l][j + k] == '*');
                if(i - l > 0 && j - k > 0) aux += (mat[i - l][j - k] == '*');
                if(i + k <= n && j + l <= m) aux += (mat[i + k][j + l] == '*');
                if(i + k <= n && j - l > 0) aux += (mat[i + k][j - l] == '*');
                if(i - k > 0 && j + l <= m) aux += (mat[i - k][j + l] == '*');
                if(i - k > 0 && j - l > 0) aux += (mat[i - k][j - l] == '*');
            }
        
            if(aux > maior){ 
                x = i;
                y = j;
                maior = aux;
            }
            else if(aux == maior){
                if(x + y == 0){
                    x = i;
                    y = j;
                }
                else if(i < x){
                    x = i;
                    y = j;
                }
                else if(i == x && j < y){
                    x = i;
                    y = j;
                }
            }
            
        }
    
    cout << x << " " << y << "\n";

    return 0;
}
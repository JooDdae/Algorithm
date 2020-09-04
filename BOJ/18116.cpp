#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,par[1001001],sz[1001001];
int f(int a){
    if(a == par[a]) return a;
    return par[a] = f(par[a]);
}
void uni(int a,int b){
    a = f(a), b = f(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=1;i<=1000000;i++) par[i] = i, sz[i] = 1;
    cin >> n;
    for(int i=1;i<=n;i++){
        char a; cin >> a;
        if(a == 'I'){
            int b,c; cin >> b >> c;
            uni(b, c);
        }else{
            int b; cin >> b;
            cout << sz[f(b)] << '\n';
        }
    }
}
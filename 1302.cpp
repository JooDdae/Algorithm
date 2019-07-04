#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
char s[55];
string out;
map<string,int> mp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        mp[s]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(ans < it->second){
            out = it->first;
            ans = it->second;
        }
    }
    printf("%s",out.data());
}

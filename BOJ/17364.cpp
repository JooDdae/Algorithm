#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cur,cnt;
pair<int,int> p[101010];
multiset<int> st;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&p[i].second,&p[i].first);
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        if(cur < p[i].second){
            auto it = st.lower_bound(p[i].second);
            if(it!=st.begin() && *(--it)<p[i].second) st.erase(it),st.insert(p[i].first);
            else if(st.size() < m-1) st.insert(p[i].first);
            else cnt++,cur=p[i].first;
        }
    }
    printf("%d",cnt);
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
queue<ll> qx,qc;
unordered_set<ll> st;
ll f(ll x){
    for(ll i=1;i<=x;i*=10){
        if(x/i%10 == 2){
            x -= i*2;
            x += i*10;
        }
        if(x/i%10 == 9){
            x -= i*8;
        }
    }
    return x;
}
int main(){
    scanf("%lld %lld",&a,&b);
    qx.push(a); qc.push(0);
    st.insert(a);

    while(!qx.empty()){
        ll x = qx.front(), c = qc.front(); qx.pop(), qc.pop();
        if(x >= 10000000000) continue;
        if(x == b) return !printf("%lld",c);

        ll F = f(x + 1);
        if(!st.count(F)){
            st.insert(F);
            qx.push(F), qc.push(c+1);
        }

        if(x > 0){
            ll F = f(x - 1);
            if(!st.count(F)){
                st.insert(F);
                qx.push(F), qc.push(c+1);
            }
        }

        for(ll i=1;i*10<=x;i*=10){
            if(x/i%10 == 0 && !st.count(x+i)){
                st.insert(x+i);
                qx.push(x+i), qc.push(c+1);
            }else if(x/i%10 == 1 && !st.count(x-i)){
                st.insert(x-i);
                qx.push(x-i), qc.push(c+1);
            }
        }
    }

    return 1;
}
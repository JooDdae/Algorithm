#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int fl=0;
stack<char> st;
void f(ll a){
	if(a == 0) return;
	if(a&1) st.push('+');
	if(a/2) st.push('*');
	f(a/2);
}
int main(){
    scanf("%lld",&n);
    if(n&1){
    	if(n >> 62) return !printf("-1");
    	n *= 2;
    	fl = 1;
    }
    f(n/2);
    printf("%d\n",fl+st.size());
    while(!st.empty()){
    	printf("[%c] ",st.top());
    	st.pop();
    }
    if(fl) printf("[/]");
} 
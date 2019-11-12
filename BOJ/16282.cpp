#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a;
    for(int i=1;i<=63;i++){
    	ll j = i;
    	for(int k=1;k<=i+1;k++) j += j+1;
    	if(j >= a){
    		cout << i;
    		return 0;
    	}
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<int,int> x,y;
int main(){
    scanf("%d",&n);
    while(n--){
    	int a,b; scanf("%d %d",&a,&b);
    	x[a]++;
    	y[b]++;
    }
    for(auto it : x) if(it.second > 1) ans++;
    for(auto it : y) if(it.second > 1) ans++;
    printf("%d",ans);
}
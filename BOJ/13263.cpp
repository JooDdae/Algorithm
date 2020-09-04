#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, front, back;
ll a[100100], b[100100], dp[100100], x[100100], y[100100];
bool f(int a,int b,int c){
    __int128 X1 = x[b] - x[a], X2 = x[c] - x[a], Y1 = y[b] - y[a], Y2 = y[c] - y[a];
    return X1 * Y2 >= X2 * Y1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++) scanf("%lld",b+i);
	x[0] = b[1];
	for(int i=2;i<=n;i++){
		while(front < back && x[front] * a[i] + y[front] > x[front+1] * a[i] + y[front+1]) front++;
		dp[i] = x[front] * a[i] + y[front];
		back++;
		x[back] = b[i], y[back] = dp[i];
		while(front + 2 <= back && f(back-2, back-1, back)){
			back--;
			x[back] = x[back+1], y[back] = y[back+1];
		}
	}
	printf("%lld",dp[n]);
}
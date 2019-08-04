#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[10101],cnt;
void f(int l,int r){
	if(l>r) return;

	int root = l;
	int e=r;
	while(arr[e] > arr[root]) e--;
	f(l+1, e);
	f(e+1, r);
	printf("%d\n",arr[root]);
}
int main(){
    while(~scanf("%d",&arr[++cnt]));
    f(1,cnt-1);
}
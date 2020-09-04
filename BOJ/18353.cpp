#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
        int a; scanf("%d",&a); a=-a;
		if (v.empty() || v.back() < a) v.push_back(a); 
		else *lower_bound(v.begin(), v.end(), a) = a;
	}
	printf("%d",n-v.size());
}
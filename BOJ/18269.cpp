#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[111];
int main(){
	scanf("%d %s",&n,s+1);

	for(int i=1;i<=n;i++){
		map<string, int> mp;
		int fl = 0;
		for(int j=1;j<=n-i+1;j++){
			char tmp = s[j+i];
			s[j+i] = 0;
			if(mp[s+j]++){
				s[j+i] = tmp;
				fl = 1;
				break;
			}
			s[j+i] = tmp;
		}
		if(!fl) return !printf("%d",i);
	}
}
#include<bits/stdc++.h>
using namespace std;
char s[55],a[3];
int main(){
    scanf("%s",s);
    a[0] = 1;
    for(int i=0;s[i];i++){
    	if(s[i] == 'A') swap(a[0],a[1]);
    	if(s[i] == 'B') swap(a[1],a[2]);
    	if(s[i] == 'C') swap(a[0],a[2]);
    }
    for(int i=0;i<3;i++) if(a[i]) printf("%d",i+1);
}
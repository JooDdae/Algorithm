// boj.kr/1786
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1010101

char s1[MAX_N],s2[MAX_N];
int fail[MAX_N],i,j,len1,len2;
vector<int> ans;

int main(){
    fgets(s1,MAX_N,stdin);
    fgets(s2,MAX_N,stdin);
    len1=strlen(s1);
    len2=strlen(s2);
    if(s1[len1-1]=='\n') s1[--len1]='\0';
    if(s2[len2-1]=='\n') s2[--len2]='\0';

    fail[0] = -1;
    i=-1, j=0;
    while(j<len2){
    	if(i<0 || s2[i]==s2[j]){
    		i++,j++;
    		fail[j]=i;
    	}else i=fail[i];
    }

    i=0,j=0;
    while(j<len1){
    	if(i<0 || s2[i] == s1[j]){
    		i++,j++;
    		if(i == len2){
    			ans.push_back(j-len2+1);
    			i=fail[i];
    		}
    	}else i=fail[i];
    }
    printf("%d\n",ans.size());
    for(int x : ans) printf("%d\n",x);
}
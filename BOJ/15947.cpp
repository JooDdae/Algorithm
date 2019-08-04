#include <bits/stdc++.h>
using namespace std;
char s[14][10]={"baby","sukhwan","tu","tu","very","cute","tu","tu","in","bed","tu","tu","baby","sukhwan"};
int n;
int main(){
    scanf("%d",&n);
    n--;
    if(n%14/2 == 1 || n%14/2 == 3 || n%14/2 == 5){
        printf("%s",s[n%14]);
        int cnt = 2 - n%14%2 + n/14;
        if(cnt >= 5) printf("+ru*%d",cnt);
        else for(int i=1;i<=cnt;i++) printf("ru");
    }else printf("%s",s[n%14]);
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char s[111][111];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=m;i>=1;i--){
        for(int j=1;j<=n;j++){
            switch(s[j][i]){
                case '-' : printf("|"); break;
                case '|' : printf("-"); break;
                case '/' : printf("\\"); break;
                case '\\' : printf("/"); break;
                case '^' : printf("<"); break;
                case '<' : printf("v"); break;
                case 'v' : printf(">"); break;
                case '>' : printf("^"); break;
                default : printf("%c",s[j][i]);
            }
        }
        puts("");
    }
}

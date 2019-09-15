#include <cstdio>
#include <sys/stat.h>
#include <sys/mman.h>
int z[36];
char*c=(char*)mmap(0,z[12],1,2,0,fstat(0,(struct stat*)z));inline int f(){int x=0;bool e;c+=e=*c=='-';while(*c>='0')x=x*10+*c++-'0';c++;return e?-x:x;}
int n,m,cnt[70000],cnt2[70000],c1,c2,mid=1e9,a[5005000];
int main(){
    n = f(), m = f();
    for(int i=1;i<=n;i++) a[i] = f() + mid;
    for(int i=1;i<=n;i++) cnt[a[i]>>16]++;
    while(m>cnt[c1]) m-=cnt[c1++];
	for(int i=1;i<=n;i++) if(a[i]>>16 == c1) cnt2[a[i]&65535]++;
    while(m>cnt2[c2]) m-=cnt2[c2++];
    printf("%d",(c1<<16)+c2-mid);
}
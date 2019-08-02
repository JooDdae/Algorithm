// boj.kr/2750
#include<cstdio>

#define MAX_N 1010
#define mid ((l+r)>>1)

int n,arr[MAX_N],tmp[MAX_N];

void merge(int l,int r){
	if(l==r) return;
	merge(l,mid),merge(mid+1,r);
	int s=l,e=mid+1,cnt=l;
	while(s<=mid || e<=r){
		if(e>r || (s<=mid && arr[s]<=arr[e])){
			tmp[cnt++] = arr[s++];
		}else{
			tmp[cnt++] = arr[e++];
		}
	}
	for(int i=l;i<=r;i++) arr[i]=tmp[i];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	merge(1,n);
	for(int i=1;i<=n;i++) printf("%d\n",arr[i]);
}
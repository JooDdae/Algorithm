// boj.kr/11658
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1030

int n,m,tree[MAX_N][MAX_N];

void update(int x,int y,int val){
	while(x <= n){
		int yy = y;
		while(yy <= n){
			tree[x][yy] += val;
			yy += yy & (-yy);
		}
		x += x & (-x);
	}
}
int find(int x,int y){
	int re=0;
	while(x){
		int yy = y;
		while(yy){
			re += tree[x][yy];
			yy -= yy & (-yy);
		}
		x -= x & (-x);
	}
	return re;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int a; scanf("%d",&a);
			update(i,j,a);
		}
	}
	for(int i=1;i<=m;i++){
		int a,b,c,d,e; scanf("%d",&a);
		if(a){
			scanf("%d %d %d %d",&b,&c,&d,&e);
			printf("%d\n",find(d,e)-find(d,c-1)-find(b-1,e)+find(b-1,c-1));
		}else{
			scanf("%d %d %d",&b,&c,&d);
			update(b,c,d-find(b,c)+find(b,c-1)+find(b-1,c)-find(b-1,c-1));
		}
	}
}
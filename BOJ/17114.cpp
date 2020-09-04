#include<bits/stdc++.h>
using namespace std;
int a[12], b[11], chk[1001001], mp[1001001], d[2] = {-1, 1}, ans, cnt;
queue<int> q[11], qc;

void input(int cur, int id){
	if(cur < 0){
		scanf("%d",mp+id);
		if(mp[id] == 1){
			chk[id] = 1;
			for(int i=0;i<11;i++){
				q[i].push(id / a[i+1] + 1);
				id %= a[i+1];
			}
			qc.push(0);
		}
		else if(!mp[id]) cnt++;
		return;
	}
	for(int i=1;i<=a[cur]/a[cur+1];i++) input(cur-1, id+(i-1)*a[cur+1]);
}

int f(int* arr){
	int re = 0;
	for(int i=0;i<11;i++) re += (*(arr+i)-1) * a[i+1];
	return re;
}

int main(){
	for(int i=0;i<11;i++) scanf("%d",a+i);
	a[11] = 1;
	for(int i=10;i>=0;i--) a[i] *= a[i+1];

	input(10, 0);

	while(!qc.empty()){
		for(int i=0;i<11;i++) b[i] = q[i].front(), q[i].pop();
		int c = qc.front(); qc.pop();
		ans = c;


		for(int i=0;i<11;i++){
			for(int j=0;j<2;j++){
				b[i] += d[j];
				int id = f(b);
				if(1 <= b[i] && b[i] <= a[i]/a[i+1] && !chk[id] && mp[id] == 0){
					chk[id] = 1;
					for(int i=0;i<11;i++) q[i].push(b[i]);
					qc.push(c+1);
					cnt--;
				}
				b[i] -= d[j];
			}
		}
	}

	printf("%d",cnt?-1:ans);
}
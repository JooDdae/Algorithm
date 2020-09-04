#include<cstdio>
#include<unordered_map>
#include<vector>
using namespace std;
int curx, cury, stx, sty, maxhp = 20, curhp = 20, atk = 2, def = 2, lev = 1, exp = 0, wep = 0, arm = 0, acc = 0;
char mp[111][111], s[5050], input[50];
unordered_map<string,int> MP;
int n, m, cnt, t, dx[256], dy[256], mp2[111][111];;
struct monster{
	int x, y, atk, def, hp, exp;
	char name[20];
};
struct item{
	int x, y, val;
	char type;
};
vector<monster> mon;
vector<item> tem;
void output(){
	for(int i=1;i<=n;i++) printf("%s\n",mp[i]+1);
	printf("Passed Turns : %d\n",t+1);
	printf("LV : %d\n",lev);
	printf("HP : %d/%d\n",max(0,curhp),maxhp);
	printf("ATT : %d+%d\n",atk,wep);
	printf("DEF : %d+%d\n",def,arm);
	printf("EXP : %d/%d\n",exp,lev*5);
}
int main(){
	MP["HR"] = 1, MP["RE"] = 2, MP["CO"] = 4, MP["EX"] = 8, MP["DX"] = 16, MP["HU"] = 32, MP["CU"] = 64;
	dx['U'] = -1, dx['D'] = 1, dy['L'] = -1, dy['R'] = 1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == '@') curx = stx = i, cury = sty = j, mp[i][j] = '.';
	scanf("%s",s);
	cnt = 0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == 'M' || mp[i][j] == '&') cnt++;
	while(cnt--){
		monster a;
		scanf("%d %d %s %d %d %d %d",&a.x,&a.y,&a.name,&a.atk,&a.def,&a.hp,&a.exp);
		mp2[a.x][a.y] = mon.size();
		mon.push_back(a);
	}
	cnt = 0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == 'B') cnt++;
	while(cnt--){
		item a;
		scanf("%d %d %c",&a.x,&a.y,&a.type);
		if(a.type == 'O'){
			scanf("%s",input);
			a.val = MP[input];
		}else scanf("%d",&a.val);
		mp2[a.x][a.y] = tem.size();
		tem.push_back(a);
	}

	for(t=0;s[t];t++){
		int x = curx + dx[s[t]], y = cury + dy[s[t]];
		if(x<1 || y<1 || x>n || y>m || mp[x][y] == '#') x = curx, y = cury;
		if(mp[x][y] == '^'){
			curhp -= (MP["DX"] & acc) ? 1 : 5;
			if(curhp <= 0){
				if(acc & MP["RE"]){
					acc -= MP["RE"];
					curx = stx, cury = sty;
					curhp = maxhp;
					continue;
				}
				output();
				return !printf("YOU HAVE BEEN KILLED BY SPIKE TRAP..");
			}
		}
		if(mp[x][y] == 'B'){
			auto u = tem[mp2[x][y]];
			if(u.type == 'O' && __builtin_popcount(acc) < 4 && !(acc & u.val)) acc += u.val;
			if(u.type == 'W') wep = u.val;
			if(u.type == 'A') arm = u.val;
			mp[x][y] = '.';
		}
		if(mp[x][y] == '&' || mp[x][y] == 'M'){
			auto u = mon[mp2[x][y]];
			if(mp[x][y] == 'M' && (acc & MP["HU"])) curhp = maxhp;
			if(acc & MP["CO"]) u.hp -= max(1, (atk + wep) * ((acc & MP["DX"]) ? 3 : 2) - u.def);
			else u.hp -= max(1, atk + wep - u.def);
			if(u.hp > 0 && !(mp[x][y] == 'M' && (acc & MP["HU"]))) curhp -= max(1, u.atk - def - arm);

			if(u.hp <= 0 || u.hp / max(1, atk + wep - u.def) + (u.hp % max(1, atk + wep - u.def) ? 1 : 0) <= curhp / max(1, u.atk - def - arm) + (curhp % max(1, u.atk - def - arm) ? 1 : 0)){
				if(u.hp > 0) curhp -= (u.hp / max(1, atk + wep - u.def) + (u.hp % max(1, atk + wep - u.def) ? 1 : 0) - 1) * max(1, u.atk - def - arm);
			}else{
				if(acc & MP["RE"]){
					acc -= MP["RE"];
					curx = stx, cury = sty;
					curhp = maxhp;
					continue;
				}
				curhp = 0;
				output();
				return !printf("YOU HAVE BEEN KILLED BY %s..",u.name);
			}

			exp += u.exp + (acc & MP["EX"] ? u.exp/5 : 0);
			if(exp >= lev*5) lev += 1, exp = 0, maxhp += 5, curhp = maxhp, atk += 2, def += 2;
			if(acc & MP["HR"]) curhp = min(curhp + 3, maxhp);
			if(mp[x][y] == 'M'){
				mp[x][y] = '@';
				output();
				return !printf("YOU WIN!");
			}
			mp[x][y] = '.';
		}
		curx = x, cury = y;
	}
	t--;
	mp[curx][cury] = '@';
	output();
	printf("Press any key to continue.");
}
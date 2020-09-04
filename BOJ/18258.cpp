#include<bits/stdc++.h>
using namespace std;
string cmd;
int n,s,e,su,que[2000010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> cmd;
        if(cmd[2] == 's')
        {
            cin >> su;
            que[e++]=su;
        }
        else if(cmd[1] == 'o' && cmd[2] == 'p')
        {
            if(s==e) cout << -1 << '\n';
            else cout << que[s++] << '\n';
        }
        else if(cmd[2] == 'z')
        {
            cout << e-s << '\n';
        }
        else if(cmd[2] == 'p')
        {
            if(s==e) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd[2] == 'o')
        {
            if(s==e) cout << -1 << '\n';
            else cout << que[s] << '\n';
        }
        else if(cmd[2] == 'c')
        {
            if(s==e) cout << -1 << '\n';
            else cout << que[e-1] << '\n';
        }
    }
}

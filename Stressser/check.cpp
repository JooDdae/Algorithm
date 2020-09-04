#include "bits/stdc++.h"
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());



int main(int argc, char *argv[]){
	cin.tie(0)->sync_with_stdio(0);

	char Print = 'y';

	for(int i = 0; ; ++ i){
		system("_gen.exe>./stress/in");
		auto p1 = high_resolution_clock::now();
		system("bad_solution.exe <./stress/in >./stress/out_bad");
		auto p2 = high_resolution_clock::now();
		system("checker.exe<./stress/out_bad>./stress/_res");
		ifstream _res("./stress/_res"), badin("./stress/out_bad"), inp("./stress/in");
		int res;
		_res >> res;
		vector<string> bad, out;
		string t;
		while(badin >> t) bad.push_back(t);
		while(inp >> t) out.push_back(t);
		cout << "Case #" << i << "\n";
		cout << "Bad: " << duration<double>(p2 - p1).count() << " seconds" << endl;
		if(!res){
			cout << "Failed!\n";
			cout << "input = ";
			for(auto s: out){
				cout << s << " ";
			}
			cout << '\n';
			cout << "Bad = ";
			for(auto s: bad){
				cout << s << " ";
			}
			cout << "\n";
			break;
		}

		cout << "Ok\n";
		if(Print == 'y'){
			cout << "input = ";
			for(auto s: out){
				cout << s << " ";
			}
			cout << '\n';
			cout << "Bad = ";
			for(auto s: bad){
				cout << s << " ";
			}
			cout << "\n";
		}
		cout << '\n';
	}
	return 0;
}
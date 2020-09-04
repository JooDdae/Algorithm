#include "bits/stdc++.h"
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());



int main(int argc, char* argv[]){
	cin.tie(0)->sync_with_stdio(0);
	cout << "Print the results? Type (y) or (n): ";
	cout.flush();
	char X;
	cin >> X;
	for(int i = 1; ; ++ i){
		system("./stress/_gen>./in");
		auto p1 = high_resolution_clock::now();
		system("./good_solution.exe<./in>./stress/out_bad");
		auto p2 = high_resolution_clock::now();
		system("./bad_solution.exe<./in>./stress/out_bad");
		auto p3 = high_resolution_clock::now();
		ifstream goodin("./stress/out_good.txt"), badin("./stress/out_bad.txt");
		vector<string> good, bad;
		string t;
		while(goodin >> t) good.push_back(t);
		while(badin >> t) bad.push_back(t);
		cout << "Case #" << i << "\n";
		cout << "Good: " << duration<double>(p2 - p1).count() << " seconds\n";
		cout << "Bad: " << duration<double>(p3 - p2).count() << " seconds" << endl;
		if(good != bad){
			cout << "Failed\n";
			cout << "good = ";
			for(auto s: good){
				cout << s << " ";
			}
			cout << "\n";
			cout << "bad = ";
			for(auto s: bad){
				cout << s << " ";
			}
			cout << "\n";
			break;
		}
		cout << "Ok\n";
		if(X == 'y'){
			cout << "good = ";
			for(auto s: good){
				cout << s << " ";
			}
			cout << "\n";
			cout << "bad = ";
			for(auto s: bad){
				cout << s << " ";
			}
			cout << "\n";
		}
		cout << endl;
	}
	return 0;
}
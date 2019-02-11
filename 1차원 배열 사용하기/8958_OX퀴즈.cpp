#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main (){
	int n;
	cin >> n;
	
	while(n--){
		string s="";
		while(s.length() == 0) getline(cin, s);
		vector<int> v;
		int o_score=0;
		for (char c : s){
			switch(c){
			case 'X':
				v.push_back(0);
				o_score = 0;
				break;
			case 'O':
				v.push_back(++o_score);
				break;
			default:
				break;
			}					
		}
		int sum = 0;
		for (auto it = v.begin(); it!=v.end(); it++)
			sum+=*it;
		cout << sum << '\n';

	}
	
}


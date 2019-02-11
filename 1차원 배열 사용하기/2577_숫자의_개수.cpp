#include <iostream>
#include <vector>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	
	int m = a*b*c;
	vector<int> v;
	
	while(m != 0){
		v.push_back(m%10);
		m/=10;
	}
	for(int i = 0 ; i < 10 ; i++){
		int count = 0;
		for(auto it = v.begin() ; it!=v.end(); it++)
			if(*it == i) count++;
		cout << count << '\n';
	}


}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
	int n, k;
	int cnt;

	cin >> n >> k;
	vector<int> v;
	while(n--){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
		
	reverse(v.begin(), v.end());
	
	cnt = 0;
	for(auto it = v.begin() ; it!= v.end(); it++){
		if (*it > k ) continue;
		cnt += k / *it;
		k %= *it;	
	}
	cout << cnt;
	
}

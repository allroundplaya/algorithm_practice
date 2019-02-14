#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v;
	int temp;
	while( n-- ){
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	int prev= *v.begin();
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		if( prev != *it || it == v.begin()){
			cout << *it << '\n';
			prev = *it;
		}
		
	return 0;
}

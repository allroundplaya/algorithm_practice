#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v;
	int temp;
	while(cin>>temp){
		if( temp >= 40) v.push_back(temp);
		else v.push_back(40);
	}
	int sum = 0;
	for(auto it = v.begin(); it != v.end(); it++){
		sum+=*it;
	}
	cout << sum / 5;
	return 0;	
}

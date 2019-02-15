#include <iostream>

using namespace std;

short isPrime(int n){
	if (n==1) return 0;
	else{
		for(int i = 2; i< n ; i++)
			if( n%i ==0 ) return 0;
	}
	return 1;
}


int main (){
	int n;
	cin >> n;
	int cnt=0;
	while(n--){
		int temp;
		cin >> temp;
		if(isPrime(temp)) cnt++;
	}
	cout << cnt;
	
}

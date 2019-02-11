#include <iostream>

using namespace std;

int main (){
	int n;
	cin >> n;
	
	int temp = n;
	int i = 0;
	
	do{
		temp = temp % 10 * 10 + (temp / 10 + temp % 10 ) % 10;
		i++;
	}while(n!=temp);
	
	cout << i;

}

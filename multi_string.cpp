#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	string a;
	int i = 0; // counts up at each iteration
	
	while(cin >> a){
		++i;
	}
	printf("%d", i);
}

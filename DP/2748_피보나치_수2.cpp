#include <iostream>

using namespace std;

int main (){
	long long n;
	
	cin >> n;
	
	long long* arr = (long long*)malloc(sizeof(long long) * (n+1));
	
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i<=n ; i++) arr[i] = arr[i-1] + arr[i-2];
	
	cout << arr[n];
}

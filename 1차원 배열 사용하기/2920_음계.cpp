#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int* arr = (int*) malloc (sizeof(int) * 8);
	
	for (int i = 0 ;i < 8 ; i++) cin >> arr[i];
	short asc=0, dsc=0;
	
	for(int i = 0 ;i < 8 ; i++){
		if(arr[i] == i+1) asc = 1;
		else if(arr[i] == 8-i) dsc = 1;
		else{
			asc = 0;
			dsc = 0;
		}
		if((asc && dsc) || (!asc && !dsc)){
			cout << "mixed";
			return 0;
		}
	}
	
	if(asc) cout << "ascending";
	else if(dsc) cout << "descending";
	return 0;

}


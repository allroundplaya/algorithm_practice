#include <iostream>
using namespace std;

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        int* arr = (int*)malloc(sizeof(int)* n);
        int sum=0;
        for(int i = 0 ;i < n ; i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        double mean = (double)sum/(double)n;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if((double)arr[i] > mean) count++; 
        }
        printf("%.3lf\%\n", (double)count/(double)n*100.0);
            
    }
}

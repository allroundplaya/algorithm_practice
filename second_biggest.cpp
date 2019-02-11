#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v(3);
    
    for(auto it= v.begin(); it != v.end(); it++){
        cin >> *it;
    }
    sort(v.begin(), v.end());
    cout << v[v.size()/2];
}
#include<bits/stdc++.h>

using namespace std;

const int N = 1e9;
vector<int> fn(int n){
    vector<int> ans(n);
    srand(time(0));
    for(int i = 0; i <n; i++){
        ans[i] = rand()%N + 1;
    }
    for(int i : ans)cout << i << " ";
    cout << endl;
    return ans;
}

void selectionSort(vector<int>&a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        
    }
}

int main(){

    fn(9);



    return 0;
}
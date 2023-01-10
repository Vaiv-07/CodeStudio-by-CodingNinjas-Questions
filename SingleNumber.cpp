#include <bits/stdc++.h> 
int occursOnce(vector<int> &a, int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans^a[i];
    }
    return ans;
	
}

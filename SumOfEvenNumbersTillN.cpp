#include <bits/stdc++.h> 
long long evenSumTillN(int n) {
    
    // Method 1: By Forula n*(n-1)
    
    long long int range = n / 2;
    return range*(range+1);
    
    // By adding 
    
//     long long int sum = 0;
//     for(int i = 2; i<=n; i = i+2){
//         sum = sum + i;
//     }
//     return sum;
}

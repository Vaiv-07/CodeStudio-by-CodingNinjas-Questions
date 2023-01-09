#include <bits/stdc++.h> 

bool isPossible(long long int n, long long int m, vector<int> time, long long int mid){
    //Checking whether mid value is a possible solution or not
    long long int daysCount = 1, sum = 0;
    for(int i=0; i<m; i++){
        if(sum + time[i] <= mid){
            sum += time[i];
        }
        else{
            daysCount++;
            if(daysCount > n || time[i] > mid){
                return false;
            }
            // Again initallizing sum for new days
            sum = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int start=0, sum=0, ans=-1;
    for(long long int i=0; i<m; i++){
        sum = sum+time[i];
    }
    long long int end = sum, mid = start + (end-start)/2 ;
    while(start <= end){
        if(isPossible(n, m, time, mid)){
            // Storing mid and moving to left part of space
            ans = mid;
            end = mid-1;
        }
        else{
            // Move to right part of space
            start = mid + 1;
        }
        mid = start + (end - start)/2 ;
    }
    return ans;
}

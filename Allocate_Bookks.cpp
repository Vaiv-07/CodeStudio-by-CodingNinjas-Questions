#include <bits/stdc++.h> 

bool isPossible(vector<int> arr, int n, int m, int mid){
    //Checking whether mid value is a possible solution or not
    int stuCount = 1, sum = 0;
    for(int i=0; i<n; i++){
        if(sum + arr[i] <= mid){
            sum += arr[i];
        }
        else{
            stuCount++;
            if(stuCount > m || arr[i] > mid){
                return false;
            }
            // Again initallizing sum for new student
            sum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    //Our search space is from 0 to sum of all elements
    int start=0, sum=0, ans=-1;
    for(int i=0; i<n; i++){
        sum = sum+arr[i];
    }
    int end = sum, mid = start + (end-start)/2 ;
    while(start <= end){
        if(isPossible(arr, n, m, mid)){
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

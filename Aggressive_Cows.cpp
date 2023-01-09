bool isPossibleSoln(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastPosition = stalls[0]; // lastPosition refer to position in array where we had put cow
    // also initillized with 0th index because we already sorted the given stall
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i] - lastPosition >= mid){ //arr[i] - lastPosition will give the difference between current ith stall to previous stall
            // now we can place cow at ith index
            cowCount++;
            if(cowCount == k){
                return true;
            }
            // After placing cow at ith index, updating the last position with ith stall
            lastPosition = stalls[i] ;
        }
    }
    
    return false ;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int ans = -1;
    int start = 0, end = stalls[n-1] - stalls[0] ;
    int mid = start + (end - start)/2 ;
    while(start <= end){
        if(isPossibleSoln(stalls, k, mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;   
    
}

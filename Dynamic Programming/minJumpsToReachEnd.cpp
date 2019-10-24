#include <bits/stdc++.h>
using namespace std;


int minJumps(int arr[] , int n){
    
    int dp[n]={0};
    
    if(arr[0]==0 || n==0)
        return -1;
    
    for(int i =1 ; i<n;i++){
        dp[i] = INT_MAX;
        for(int j =0 ; j<i;j++){
            
            if(i <=j+arr[j] && dp[j]!=INT_MAX){
                dp[i] = min(dp[i] , dp[j] + 1);
                break;
            }
        }
    }
    if(dp[n-1]==0 || dp[n-1]==INT_MAX)
        return -1;
    return dp[n-1];
}


int minJumpsLinear(int arr[] , int n ){
    
    if(n<=0)
        return 0;
    if(arr[0]==0)
        return -1;
    
    int steps = arr[0];
    int maxReach = arr[0];
    int jumps=1;
    for(int i =1 ; i<n;i++){
        
        if(i==n-1)
            return jumps;
        maxReach = max(maxReach , arr[i]+i);
        
        steps--;
        
        if(steps==0){
            
            jumps++;
            //update the steps with current max Reach and the index where we are now
            
            if(i >=maxReach)
                return -1;
            
            steps = maxReach - i;
        }
    }
    
    return -1;
}
int main() {
	//code
	
	
	int t =0;
	cin>>t;
	
	while(t--){
	    
	    int n ;
	    cin>>n;
	    int arr[n];
	    
	    for(int i =0 ; i<n;i++){
	        cin>>arr[i];
	    }
	    
	    cout<<minJumpsLinear(arr , n)<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

//Longest subaaray with sum K [positions]
int subarray(int n,vector<int>&arr,int k){  //tc=O(n^3)approx , sc=O(1)
    int len =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int p=i;p<=j;p++){
                sum+=arr[p];
            }
                if(sum==k){
                    len=max(len,(j-i)+1);
                }
            
        }
    }
    return len;
}
// after optimizing brute force approach 
int Longest_subarray(int n,vector<int>&arr,int k){  //tc=O(n^2)approx , sc=O(1)
    int len =0;
    for(int i=0;i<n;i++){
            int sum = 0;
        for(int j=i;j<n;j++){
               sum+=arr[j];
                if(sum==k){
                    len= max(len,(j-i)+1);
                }
            }
    }
    return len;
}

// better approach using hashing
int longestSubarray(vector<int>a,long long k){  // TC -> O(n*log n)
    map<long long, int>preSumMap;
    long long sum =0;
    int maxLen=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum == k){
            maxLen=max(maxLen,i+1);
        }
        long long rem = sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len = i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxLen;
}

//  optimal solution :  2 pointer approach
int longestSubaarayWithSumK(vector<int> a,long long k){
    int left=0,right=0;
    long long sum= a[0];
    int maxlen=0;
    int n= a.size();
    while(right<n){    // tc - O(2n)
        while(left<=right && sum>k){
            sum -= a[left];
            left++;
        }
        if(sum==k){
            maxlen = max(maxlen,right-left +1);
        }
        right++;
        if(right<n)sum+=a[right];
    }
    return maxlen;
}


int main(){
    vector<int> arr;
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int i=0;
    while(i<n){
        arr.push_back(ar[i]);
        i++;
    }
    int k = 5;
    int ans =subarray(n,arr,k);
    cout<<"the longest subaaray is : "<<ans;
    cout<<endl;
    int Solu = Longest_subarray(n,arr,k);
    cout<<"Longest subbaray : "<<Solu;
    cout<<endl;
    int Solu1 = longestSubaarayWithSumK(arr,k);
    cout<<"Longest subbaray : "<<Solu1;

}
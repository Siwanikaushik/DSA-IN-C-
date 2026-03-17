#include<bits/stdc++.h>
using namespace std;

//longest subarray with sum k
int longSubarray(vector<int>&arr,int k,int n){
    int len =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum =0;
            for(int k=i;k<j;k++){
                sum +=arr[k];
            }
            if(sum == k){
                len = max(len,(j-i)+1);
            }
        }
    }
    return len;
}
    int main(){

    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    int nums[n];
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        arr.push_back(nums[i]);
    }
    int res = longSubarray(arr,3,n);
    cout<<res;
    return 0; 
}
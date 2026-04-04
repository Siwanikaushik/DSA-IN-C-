#include<bits/stdc++.h>
using namespace std;

// number os subaaaray with sum k


// brute force 
int sum(vector<int>&a,int k){/// TC-> O(n^3)
    int n = a.size();
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int total=0;
            for(int k=i;k<j;k++){
                total=total+a[k];
            }
            if(total==k){
                count ++;
            }
        }
    }
    return count;
}

// better solu
int total(vector<int>&a,int k){   // TC-> O(n^2)
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+a[j];
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}

// optimal - prefix sum
//use hashmap
int findAllSubarrayWithGivenSum(vector<int>&a,int k){
    unordered_map<int,int>mpp;
    mpp[0]=1;
    int preSum=0;
    int cnt=0;
    // O(n *log n)
    // sc-> O(n)
    for(int i=0;i<a.size();i++){
        preSum += a[i];
        int remove = preSum - k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;
}
int main(){
    return 0;
}
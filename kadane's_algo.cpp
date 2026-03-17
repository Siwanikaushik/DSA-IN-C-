#include<bits/stdc++.h>
using namespace std;
// kadane's algorithm : maximum subarray sum

int subarray(vector<int> v){    // TC -> O(n^3)
    int maximum =INT_MIN;
    for(int i=0; i<v.size();i++){
        for(int j=i;j<v.size();j++){
            int sum =0;
            for(int k=i;k<j;k++){
                sum+=v[k];
                maximum = max(sum,maximum);
            }
        }
    }
}

// bettere
int subarraySum(vector<int> v){    // TC -> O(n^2)
    int maximum =INT_MIN;
    for(int i=0; i<v.size();i++){
        int sum =0;
        for(int j=i;j<v.size();j++){
            sum += v[j];
            
            return maximum = max(sum,maximum);
        }
    }
}

// optimal approach : kadane's algorithm
long long maxSubarraySum(int arr[],int n){   // TC -> O(n)
    long long sum =0, maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum>maxi){
            maxi = sum;
        }

        if(sum<0){
            sum = 0;
        }
    }
    if(maxi < 0){
        maxi = 0; 
    }
    return maxi;
}


int main(){
    return 0;
}
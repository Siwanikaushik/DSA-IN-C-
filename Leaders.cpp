#include<bits/stdc++.h>
using namespace std;

// Leader in an array  -> everything on the right should be smaller


// brute force 
vector<int> leader(vector<int>&A){   // tc->O(n^2)
    vector<int>ans;
    int n= A.size();
    for(int i=0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if( A[j]>A[i]){
                leader = false;
                break;
            }

        }
        if(leader ==true){
            ans.push_back(A[i]);
        }
    }
    return ans;
}

// optimal
vector<int> superiorElements(vector<int>&a){
    // space in wrost case : O(n)
    vector<int>ans;
    int maxi = INT_MIN;
    int n= a.size();
    //O(n)
    for(int i=n;i>=0;i){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        //keep track of roght maximum
        maxi=max(maxi,a[i]);
    }
 // O(nlogn)
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// 2 sum array :

// brute force approach 
void twoSum(vector<int>a ,int k){    // tc ->O(n^2)
    int n= a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==k){
                cout<<i;
                cout<<j;

            }
        }
    }
}

// hashing - better approach
string read(int n,vector<int> book , int target){  // tc-> O(n * log n)
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int a= book[i];
        int more = target-a;
        if(mpp.find(more)!=mpp.end()){
            return "YES"; // return(mpp[more],i)
        }
        mpp[a] =i;
    }
    return "NO";
}

// optimal solu - two pointer approach/greedy approach
string reading(int n,vector<int>book,int target){   // TC -> O(n log n)
    int left=0 ,right=n-1;
    sort(book.begin(),book.end());
    while(left<right){
        int sum = book[left]+book[right];
        if(sum==target){
            return " YES";
        }
        else if(sum<target) left++;
        else right--;
    }
    return "NO";
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
    return 0;
}
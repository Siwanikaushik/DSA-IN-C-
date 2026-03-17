#include<bits/stdc++.h>
using namespace std;

// majority element (>N/2 times)
// brute force
int major(vector<int> a, int n){  //tc-> O(n^2)
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if(a[j]==a[i]) count++;
        }
        if(count>n/2) return a[i];
    }
    return -1;
}

// better solution
int majorityElement(vector<int> v){  // TC ->O(n log n) + O(n)
    map<int,int>mpp;
    for(int i=0;i<v.size();i++){
        mpp[v[i]]++;
    }
    for(auto it : mpp){
        if(it.second>(v.size()/2)){
            return it.second;
        }
    }
}

// optimal approach : Moore's Voting Algorithm
int majorityElementPrblm(vector<int>v){ // tc-> O(2n)
    int cnt =0;
    int el;
    for(int i=0;i<v.size();i++){
        if(cnt == 0){
            cnt=1;
            el =v[i];
        }
        else if(v[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 =0;
    for(int i=0;i<v.size();i++){  // verify for majority
        if(v[i]==el){
            cnt1++;
        }
    }
    if(cnt1>(v.size()/2)){
        return el;
    }
    return -1;
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
    int sol = majorityElementPrblm(arr);
    cout<<"majority element is : "<<sol;
    return 0;
}
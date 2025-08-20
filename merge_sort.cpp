#include<bits/stdc++.h>
using namespace std;

// merge sort : -> divide & merge  // tc ->  O(N * log2(n)) , space complexity -> O(n)
void merge(vector<int> &arr,int low,int mid ,int high){  
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] =temp[i-low];
    }
}

void mergeSort(vector<int> &arr,int low,int high){
    if(low>=high)return;
    int mid = (low +high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cout<<"enter the range of array : ";
    cin>>n;
    int arr[n];
    int i=0;
    vector<int>temp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(i<n){
        temp.push_back(arr[i]);
        i++;
    }
    mergeSort(temp,0,n-1);
    for(auto it : temp){
        cout<<it<<" ";
    }
    
    return 0;
}
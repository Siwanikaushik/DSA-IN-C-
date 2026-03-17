#include<bits/stdc++.h>
using namespace std;

// sort an array of 0's , 1's , 2's
// brute force approach - merge sort gives TC ->O(n log n)

// better solution
int sortingArray(vector<int>a,int n){   // TC-> O(2n)
    int count0 ,count1,count2;
    for(int i=0;i<n;i++){
        if(a[i]==0)count0++;
        else if(a[i]==1)count1++;
        else count2++;
    }
    for(int i=0;i<count0;i++) a[i]=0;
    for(int i=count0;i<count0+count1;i++) a[i]=1;
    for(int i=count0+count1;i<n;i++) a[i]=2;
}

// optimal solution 
// Dutch National Flag Algorithm
void sortArray(vector<int>&arr , int n){   //TC -> O(n)
    int low =0 , mid =0 , high = n-1;
    while(mid <= high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// quick sort -> make the data in ascending / descending order
// tc ->   O(Nlogn) , sc-> O(1)
//-> pick a pivet(element) & place it in its correct place in the sorted array
// smaller on left 7 greater on the right.
// divide & conquer algo
int partition(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>= pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high){
    if(low<high){
    int pIndex = partition(arr,low,high);
    quickSort(arr,low, pIndex -1);
    quickSort(arr, pIndex +1,high);
    }

}
vector<int> qs(vector<int> &arr){
    quickSort(arr,0,arr.size()-1);
    return arr;
}
int main(){
    int n;
    cout<<"enter the numebr : ";
    cin>>n;
    int arr[n];
    vector<int>ar;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ar.push_back(arr[i]);
    }
    qs(ar);
    for(auto it : ar){
        cout<<it<<" ";
    }
    return 0;
}
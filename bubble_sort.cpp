#include<bits/stdc++.h>
using namespace std;

// bubble sort -> push the maximum to the last by adjacent swap
void bubble_sort(int ar[], int n){ // tc-> O(n^2) -> wrost case
    for(int i=n-1;i>=1;i--){ // after optimization -> best case -> tc= O(N)
        int didSwap =0;
        for(int j=0;j<=i-1;j++){
            if(ar[j]>ar[j+1]){
                // swap(ar[j+1],ar[j]);
                int temp =ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=temp;
                didSwap =1;
            }
        }
        if(didSwap == 0){
            break;
        }
        cout<<"runs"<<endl;
    }
}
int main(){

    int n;
    cout<<"enter the no. of elements you want in the array : ";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    bubble_sort(ar,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}
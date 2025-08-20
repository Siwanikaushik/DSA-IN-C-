#include<bits/stdc++.h>
using namespace std;

// insertion sort -> takes an element & place it in its correct order
void insertion_sort(int ar[],int n){ // tc-> wrost & avg = O(n^2)
    for(int i=0;i<=n-1;i++){  // best case = TC -> O(n)
       int  j=i;
        while(j>0 && ar[j-1]>ar[j]){
            int temp = ar[j-1];
            ar[j-1]=ar[j];
            ar[j]=temp;
            j--;
            cout<<"runs"<<endl;
        }
    }
}
int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    insertion_sort(ar,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}
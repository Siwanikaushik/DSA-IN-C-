#include<bits/stdc++.h>
using namespace std;

void selection_sort(int ar[],int n){  // tc = O(n^2)
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i;j<=n-1;j++){
            if(ar[j]<ar[mini]){
                mini =j;
            }
        }
        int temp =ar[mini];
        ar[mini] = ar[i];
        ar[i] = temp;
    }
}
int main(){
// selection sort -> ascending order -> select minimum
    int n;
    cout<<"enter the no. of elements you want in an array :";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    selection_sort(ar,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}
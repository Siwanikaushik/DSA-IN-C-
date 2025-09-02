#include<bits/stdc++.h>
using namespace std;

// largest element of array
int large(vector <int> &arr,int n){ // tc -> O(n)
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest)
        largest = arr[i];
    }
    return largest;
}

// second largest element of array -brute force approach
int secondLarge(vector<int> &arr, int n ){  // tc = O(2n)
    int largest = 0;
    int secondLargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest)
        largest = arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]>secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// second largest & smallest element of array - better approach
int secondLargest(vector<int> &a,int n){     // tc = O(n)
    int largest = a[0];
    int sLargest = -1;
    for(int i=1;i<n;i++){
        if(a[i]>largest){
            sLargest = largest;
            largest = a[i];
        }
        else if(a[i]<largest && a[i] > sLargest){
            sLargest = a[i];
        }
    }
    return sLargest;
}

int secondSmallest(vector<int> &a ,int n) {
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i]<smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i]!= smallest &&  a[i]< ssmallest){
            ssmallest = a[i];
        }
    }
    return ssmallest;
}
vector<int> getSecondOrderElements(int n, vector<int>a){
    int sLargest = secondLargest(a,n);
    int sSmallest = secondSmallest(a,n);
    return {sLargest,sSmallest};
}

// check if array is sorted
int isSorted(int n, vector<int> a){  // tc = O(n)
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

// remove duplicates from the sorted array
// brute force approach - declare a set & pass elements into it

// Left rotate the array by one place
void leftRotate(int n, int arr[]){ // TC-> O(n)
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1] = temp;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// left rotate the array by D places -brute force approach
void leftRotateD(int n,int d,int arr[]){
    d=d%n;
    int temp[d];
    int k=0;
    for(int i=0;i<d;i++){
        temp[i]=arr[k];
        k++;
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

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
    cout<<"largest is : ";
    cout<<large(arr,n);
    cout<<endl<<"secod largest is : ";
    cout<<secondLarge(arr,n);
    vector<int> result = getSecondOrderElements(n,arr);
    cout<<endl;
    cout<<"Second largest"<< result[0]<< endl<<"Second smallest"<<result[1];
    int res = isSorted(n,arr);
    cout<<endl;
    cout<<res;
    cout<<endl;

    // remove duplicates from the sorted array
// brute force approach - declare a set & pass elements into it
    set<int>st; // TC-> O(nlog n + n)  & SC -> O(n)
    for(int i=0;i<n;i++){  // TC - O(nlog n)
        st.insert(arr[i]);
    }
    int index =0;
    for(auto it: st){  // tc -> O(n)
        arr[index] =it;
        cout<<arr[index]<<" ";
        index++;
    }
    cout<<endl;

    // optimal approach for removing duplicate elements using 2 pointer approcah
    int k=0;
    for(int j=1;j<n;j++){  //tc-> O(n) , s-> O(n)
        if(arr[j] != arr[k]){
            arr[k+1]=arr[j];
            k++;
        }
    }
    cout<<k+1;
    cout<<endl;
    int m;
    cout<<"Enter the number : ";
    cin>>m;
    int arry[m];
    for(int i=0;i<m;i++){
        cin>>arry[i];
    }
    leftRotate(m,arry);
    cout<<endl;
    int d;
    cout<<"Enter the d : ";
    cin>>d;
    leftRotateD(m,d,arry);
    return 0;
}

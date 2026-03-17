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

//left rotate optimal approach
void leftRot(int arr[],int n, int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


// move zeros to end brute force approach
void zeros(int arr[],int n){  //TC :-> O(2n)
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


// move zeros to right - optimal solution
void zeroRight(int arr[],int n){  //TC -> O(n)
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// linear search
int linearSearch(int arr[],int target,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

// union of two sorted array
void unionNum(int arr1[],int arr2[],int n1,int n2){
    set<int>st;
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    int Union[st.size()];
    int i=0;
    for(auto it:st){
        Union[i++]=it;
    }
}

//optimal solution for union of two sorted array
vector<int> sortedArray(vector<int>a,vector<int>b){
    int n1= a.size();
    int n2= b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 || unionArr.back()!= a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!= b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
        while(i<n1){
            if(unionArr.size()==0 || unionArr.back()!= a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        while(i<n2){
              if(unionArr.size()==0 || unionArr.back()!= b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    return unionArr;

}

// intersection of two sorted array

vector<int> findArrayIntersection(vector<int> &A,int n,vector<int>&B,int m){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<m){
        if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<A[i]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

// finding missing number
int missing(int n,int arr[],int N){ // TC - O(N*N)
    for(int i=1;i<=N;i++){
        int flag =0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
            flag =1;
            break;
            }
        }
        if(flag==0){
            return i;
        }
    }
}

//finding missing number using hashing
int hasMiss(int arr[],int n){
    int hash[n+1]={0};
    for(int i=0;i<n-1;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
}
// finding the missing number of optimzied approach
int sumMiss(int n,int arr[]){  //tc = O(n)
    int sum = (n*(n+1))/2;
    int s2=0;
    for(int i=0;i<=n-1;i++){
        s2+=arr[i];
    }
    return(sum-s2);
}

//finding missing number using xor concept i.e a^a=0 , 0^a=a
int xorMiss(int n,int arr[]){  // tc= O(n)
    int xor1 =0;
    int xor2 =0;
    for(int i=0;i<n-1;i++){
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    return(xor1^xor2);
}

// maximum consecutive ones 
int findMaxConsecutiveOnes(vector<int>&nums){
    int maxi =0;
    int cnt =0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else{
            cnt =0;
        }
    }
    return maxi;
}

//find the number that appears once , and the other twice
int numOne(vector<int>&num,int n){  // TC =O(3n)
    int maxi = num[0];
    for(int i=0;i<n;i++){
        maxi = max(maxi,num[i]);
    }
    int hash[maxi]={0};
    for(int i=0;i<n;i++){
        hash[num[i]]++;
    }
    for(int i=0;i<n;i++){
        if(hash[num[i]]==1){
            return num[i];
        }
    }
}

//find the number that appears once , and the other twice using XOR
int xorNumOne(vector<int>&num,int n){  //TC = O(n)
    int Xor = 0;
    for(int i=0;i<n;i++){
        Xor = Xor^num[i];
    }
    return Xor;
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
    cout<<endl;
    leftRot(arry,m,d);
    cout<<endl;
    int p;
    cout<<"Enter the Number of elements in the array :";
    cin>>p;
    int q[p];
    for(int i=0;i<p;i++){
        cin>>q[i];
    }
    zeros(q,p);
    cout<<endl;
    zeroRight(q,p);
    int target;
    cout<<"enter the target";
    cin>>target;
    int num;
    cout<<"enter the no of arrays : ";
    cin>>num;
    int array[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    cout<<linearSearch(array,target,num);
    return 0;
}

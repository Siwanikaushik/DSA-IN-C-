#include<bits/stdc++.h>
using namespace std;

// Next permutation : doing permtation in sorted order & finding the next ans

// Brute force : 1) generate all permutations in sorted order  (using recurssion)
//                2) linear search 
//                3) print next index
// tc -> O(n! * n)


// better approach -> for c++ we can use stl library
vector<int> nextGreaterPremutation(vector<int>&A){
    next_permutation(A.begin(),A.end());
    return A;
}

//optimal :  1) longer prefix match i.e a[i]<a[i+1]
//           2) find > A , but the smallest one  so that you stay close
//           3) try to place remaining in sorted order

vector<int> nextPermutation(vector<int> & A){    // TC -> O(3n)
    int ind = -1;
    int n = A.size();
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            ind =i;
            break;
        }
    }
    if(ind == -1){
        reverse(A.begin(),A.end());
    }
    for(int i=n-1;i>=0;i--){
        if(A[i]>A[ind]){
            swap(A[i],A[ind]);
            break;
        }
    }
    reverse(A.begin()+ ind + 1,A.end());
    return A;
}

int main(){
    
    return 0;
}
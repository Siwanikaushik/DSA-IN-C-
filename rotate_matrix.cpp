#include<bits/stdc++.h>
using namespace std;

// rotate matrix by 90 degree in clockwise direction / rotate image

// brute force
vector<vector<int>> matrix(vector<vector<int>>&a,int n){ // tc -> O(n**2)
    // sc-> O(n^2)
    int ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i]=a[i][j];
        }
    }
    return a;
}

// optimal
// 1>  transpose
//2> reverse every row
void rotateMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    //  O(n/2 * n/2)
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    // O(n*n/2)
    for(int i=0;i<n;i++){
    // row is mat[i]
        reverse(mat[i].begin(),mat[i].end());
    }
}

int main(){
    return 0;
}
# include<bits/stdc++.h>
using namespace std;


// set matrix zero : where there is zero in any cell of matrix having 0/1 items 
// mark that entire row & column as 0


// brute force 
void markRow(int i, vector<vector<int>>&a,int n,int m){
 for(int j=0;j<m;j++){
        if(a[i][j] != 0){
            a[i][j]=-1;
        }

    }
}
void markCol(int j, vector<vector<int>>&a,int n,int m){
 for(int i=0;i<n;i++){
        if(a[i][j] != 0){
            a[i][j]=-1;
        }

    }
}
int zero(vector<vector<int>> & a , int n , int m){   // TC O((n*m)*(n+m)+(n*m))
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                markRow(i,a,n,m);
                markCol(j,a,n,m);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==-1){
                a[i][j]=0;
            }
        }
    }
    
}




// better solution

vector<vector<int>> matrix(vector<vector<int>>&a,int n,int m){  // TC ->O(2*n*m)
    // SC ->O(N)+O(M)
    int col[m]={0};
    int row[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
            

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                a[i][j]=0;
            }
        }
    }
    return a;
}


//  optimal solution
// tc -> same as better but space -> 1
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix , int n ,int m){
    int col0 =1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                // mark the i th row
                matrix[i][0] =0;
                // mark jth column
                if(j !=0){
                    matrix[0][j] =0;
                }
                else{
                    col0=0;
                }

            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[0][j] || matrix[i][0]){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
    return matrix;
}

int main(){
    return 0;
}
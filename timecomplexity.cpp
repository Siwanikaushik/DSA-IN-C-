// time complexity :
// the rate at which time taken increases with respect to input size rather. it is computed in terms of Big O Notation
//O() - Big O Notation
// Rules
// 1) tC , worst case Scenerio
//2) avoid constants
// 3) avoid lower values

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){ //// time complexity - O(n*3) - 3 means three things are done : check , increment & prints, where n is no of steps
        cout<<"lakshay"<<endl;
    }
    return 0;
}
// other notations :
/* Big -Oh(O) -> worst case [upper bound]
 Theta -> average complexity
 Omega -> lowest bound
*/

// examples:
/*
for(int i=0;i<n:i++){                   => TC: O(n^2)
    for(int j=0;j<n;j++){
    block of code
    }
}

for(int i=0;i<n:i++){                   => TC: (1+2+3+............+n) => n*(n+1)/2 => n^2 /2 +n/2 => O(n^2/2)=> O(n^2)
    for(int j=0;j<=i;j++){
    block of code
    }
}
*/


// space complexity -> memory space that you program takes
/*
Big -O Notation is used
space complexity = auxilary space(space you take to solve the problem) + input space(space you take to store input)
*/
#include<bits/stdc++.h>
using namespace std;

// Recurssion
// when function calls itself until a specified task is met.

// prints names n times
void printName(int i,int n){ // tC - O(n)
    if(i>n) return;
    cout<<"Siwani   ";
    printName(i+1,n);
}

// print n numbers
void printNumber(int i,int n){  // tc = O(n)
    if(i>n) return;
    cout<<i<<" ";
    printNumber(i+1,n);
}

// prints in terms of n->1
void printReverse(int i,int n){
    if(n<i)return;
    cout<<n<<" ";
    printReverse(i,n-1);
}

// print n->1 another way
    void print(int i,int n){
    if(i<1)return;
    cout<<i<<" ";
    print(i-1,n);
}


// print lineraly from 1->n (but by backtrack)
void printNumBackTrack(int i ,int n){
    if(i<1) return;
    printNumBackTrack(i-1,n);
    cout<<i<<" ";
}

// print from n->1 by backtrack
void printRevBackTrack(int i,int n){
    if(i>n)return;
    printRevBackTrack(i+1,n);
    cout<<i<<" ";
}
 
//sumof n numbers using parameterized way
void sum(int i,int s){
    if(i<1){
        cout<<s<<" ";
        return;
    }
    sum(i-1,s+i);
}

// prints sum using functional
int sumFun(int n){
    if(n==0) return 0;
    return n+sumFun(n-1);
}

// factorial of n
int fact(int n){  // tc= O(n)
    if(n==0) return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    printName(1,n);
    cout<<endl;
    printNumber(1,n);
    cout<<endl;
    printReverse(1,n);
    cout<<endl;
    print(n,n);
    cout<<endl;
    printNumBackTrack(n,n);
    cout<<endl;
    printRevBackTrack(1,n);
    cout<<endl;
    sum(n,0);
    cout<<endl;
    cout<<sumFun(n);
    cout<<endl;
    cout<<fact(n);
    return 0;
}

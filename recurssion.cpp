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

// reverse an array
void reverseArray(int i,int a[],int n){
    if(i>=n/2) return;
    swap(a[i],a[n-i-1]);
    reverseArray(i+1,a,n);
}

// check string palindrome
bool stringPalindrome(int i,string &s,int n){  // tc = n/2
    if(i>=n/2) return true;
    if(s[i] != s[n-i-1]){
    return false;
     }
    return stringPalindrome(i+1,s,n);
}

// multiple recurssion calls

//  fibonacci numbers
int fibo(int n){  // TC = 2^n exponential
    if(n<=1) return n;
    int last =fibo(n-1);
    int second = fibo(n-2);
    return last + second;
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
    cout<<endl;
    int a[n];
    cin>>n;
    cout<<"enter array of "<<n<<" elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    reverseArray(0,a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<"enter the string :";
    string s;
    cin>>s;
    int l= s.size();
    int m =stringPalindrome(0,s,l);
    if(m==0){
        cout<<"not a palindrome";
    }
    else cout<<" is a palindrome.";
    cout<<endl;
    cout<<fibo(4);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
    // void - doesnt return anything
    //return - returns something
    // parametrised
    //non- parameterised
 void printName(string name){
    cout<<"hey"<<name;
 }

int sum(int a,int b){
    return a+b;
}
// pass  by value

void doSomething(int num){
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
}

//passs by reference
void something(string &s){
    s[0] = 't';
    cout<<s<<endl;
}
 int main(){
    string name;
    cin>>name;
    printName(name);
    int a,b;
    cin>>a>>b;
    int res =sum(a,b);
    cout<<res;
    cout<<endl;

    int minimum= min(a,b);
    cout<<"mininmum is :"<<minimum;
    cout<<endl;
    int num =10;
    doSomething(num);//by value
    cout<<num<<endl;
    string s = "raj";
    something(s); //by reference
    cout<<s<<endl;
// array is always passed by reference without using & symobl
    return 0;
}
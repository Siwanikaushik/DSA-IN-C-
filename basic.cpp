#include<iostream> // if we want to use multiple library the instead we can write single i.e #include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int  main(){
    std::cout<<"hellow woeld"<<"\n";
    std::cout<<"heloo worlds"<<std::endl;
    std::cout<<"hello shivani"<<endl;

    // input
    int x,y;
    cin>>x>>y;
    cout<<"the value of x  & y is :"<<x<<"\n"<<y;

    // datatypes

    //int
    int z=10;
    //long
    long a=17;
    long long b=13456789098;
    // float , double
    // string and getline
    string s1,s2;
    cin>>s1>>s2;
    cout<<s1<<" "<<s2;
    cout<<endl;
    cout << endl;
    string str;
    cout<<"enter your fullname:";
    cin.ignore();
    getline(cin,str);// to print entire line getline is used which takes all the words of a line in str
    cout<<str;
    //char
    char ch;
    cin>>ch;
    cout<<ch;

    return 0;
}
// we need not use std in each line if we use namespace std at the begining



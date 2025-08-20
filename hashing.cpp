#include<bits/stdc++.h>
using namespace std;
// if declare array globally it can go upto -> 1e7 ie 10^7
// Hashing -> prestore/fetching 
// a hash array is created.

// counting number of times it appear
int fun(int n,int num, int ar[]){ // tc O(n) if there are alot number complexity will be 100sec
    // which is not a good thing so here hashing comes into existence.
    int count=0;
    for(int i=0;i<n;i++){
        if(ar[i]==num){
            count++;
        }
    }
    return count;
}
int main(){
    // if array is declary in main it could be go upto 10^6

    // counting the no of times a number appeared using hashing
    int n;
    cin>>n;
    cout<<"eneter the elements: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // precompute -> hasharray
    int hash[13] ={0};
    for(int i=0;i<n;i++){
        hash[arr[i]] +=1;
    }
    cout<<"enter how many numbers you need to find:";
    int q;
    cin>>q;
    while(q--){
        int number;
        cout<<"enter number you want to find :";
        cin>>number;
        cout<<"it is called times :";
        // fetching
        cout<<hash[number]<<endl;
    }

    // counting the no. of times a character appeared using hashing

    // for on;y lower case
    string s;
    cout<<"enter the string : ";
    cin>>s;

    // pre compute
    int hashs[26] ={0};
    for(int i=0;i<s.size();i++){
        hashs[s[i] -'a']++;
    }
    int p;
    cout<<" enter the queries :";
    cin>>p;
    while(p--){
        char c;
        cout<<" enter the character you want to count : ";
        cin>>c;

        //fetching
        cout<<" the character  "<<c<<"  is called :  "<<hashs[c - 'a']<<" times ."<<endl;
    }


    // in number hashing we can go atmost to the 10^7 aray size
    // here in cpp stl comes into existence
    // in stl there comes 2 thingss :
    // ->  map & unordered map
    // map -> <key,value> ie<number,frequency>
    int m;
    cout<<"enter the no of vakues you want in an array : ";
    cin>>m;
    int arry[m];
    map<int,int>mpp; // tc - sorting & fetching map -> log(n)
    for(int i=0;i<m;i++){
        cin>>arry[i];
        mpp[arry[i]]++; // pre computation can be done here.
    }

    // pre compute :
    // map<int,int>mpp;
    // for(int i=0;i<m;i++){
    //     mpp[arry[i]]++;
    // }
    for(auto it : mpp){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    int r;
    cout<<"enter the number if queries : ";
    cin>>r;
    while(r--){
        int numb;
        cout<<"enetr the number want to find  : ";
        cin>>numb;
        // fetching :
        cout<<" the frequency is : "<<mpp[numb]<<endl;
    }
    // in unorderd map only the iteration order is not in sequence 
    // we have to generaly use unorderd map because in average & best case it have time complexity of O(1)
    // but in wrost case it goes to O(n) -> therefore, if the time of computation increases then
    // we have to use map instēsd of unordered


    // hasing -> division method
    //        -> folding method
    //        -> mid square method

    // division method : modulate it with 10  -> linear chaining -> collision
    return 0;
}
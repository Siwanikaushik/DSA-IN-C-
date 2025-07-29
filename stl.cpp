// STL : Standard template library
// c++ stl is devided into 4 parts : Algorithms , containers , functions , iterators
#include<bits/stdc++.h>
using namespace std;
void print(){
    cout<<"Lakshay";
}
int sum(int a,int b){
    return a+b;
}

// Pairs - its a part of utlity libraray
void explainPair(){
    pair<int , int>p = {1,3};
    cout<<p.first<<" "<<p.second;
    cout<<endl;
    pair<int, pair<int,int>>q = {1,{3,4}};
    cout<<q.first<<" "<<q.second.second<<" "<<q.second.first;
    cout<<endl;
    pair<int,int>arr[]={{1,2},{2,5},{5,1}};
    cout<<arr[1].second;
}

// vector - dynamic & stores elements just like array.
void explainVector(){
    vector<int>v;
    v.push_back(1);
    v.emplace_back(3);// similar to push_back but faster than push_back
    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);// no need of curl braces.

    vector<int>v2(5,100);
    vector<int>v1(5);
    vector<int>v3(5,100);
    vector<int>v4(v1);

    vector<int>::iterator it =v.begin();// v.begin is pointing memoet not the element
    it++;
    cout<<*(it)<<" ";
    it = it+2;
    cout<<*(it)<<" ";
    vector<int>::iterator it= v.end();// point to memory location that is right after the last element
    // vector<int>::iterator it= v.rend(); //reverse end
    // vector<int>::iterator it= v.rbegin();

    cout<<v[0]<<" "<<v.at(0);
    cout<<v.back()<<" ";

    for(vector<int>::iterator it=v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }
    // shortcut given by stl
    for(auto it =v.begin(); it!= v.end(); it++){
        cout<<*(it)<<" ";
    }
    for(auto it :v){
        cout<<it<<" ";
    }

    v.erase(v.begin()+1);
    v.erase(v.begin()+2,v.begin()+4);//(star,end)


//insert function
    vector<int>v(2,100);
    v.insert(v.begin(),300);
    v.insert(v.begin()+1,2,10);// position, number of elements , element

    vector<int>copy(2,50);
    v.insert(v.begin(),copy.begin(),copy.end());
    cout<<v.size();
    v.pop_back();
    v1.swap(v2);
    v.clear();
    cout<<v.empty();
}

// list
void explainList(){
    list<int>ls;
    ls.push_back(2);//{2}
    ls.emplace_back(4);//{2,4}
    ls.push_front(5);//cheaper than insert of vector{5,2,4}
    ls.emplace_front();// {2, 4} ;
// rest functions same as veector
//begin,end,rbegin,rend,clear,insert,size,swap
}
// deque
void explainDeque(){
    deque<int>dq;
    dq.push_back(1);//{1}
    dq.emplace_back(2);//{1,2}
    dq.push_front(4);//{4,1,2,}
    dq.emplace_front(3);//{3,4,1,2}
    dq.pop_back();//{3,4,1}
    dq.pop_front();//{4,1}
    dq.back();
    dq.front();
    // rest functions same as vector
    //begin , end,rbegin,rend,insert,clear,insert,size,swap
}
// stack -lifo
void explainStack(){
    stack<int>st;
    st.push(1);//{1}
    st.push(2);//{2,1}
    st.push(4);//{4,2,1}
    st.push(3);//{3,4,2,1}
    st.emplace(5);//{5,3,4,2,1}
    cout<<st.top();//prints 5
    st.pop();//{3,4,2,1}
    cout<<st.top();//3
    cout<<st.size();//4
    cout<<st.empty();
    stack<int>st1,st2;
    st1.swap(st2);

}

//queue -fifo
void ecplainQueue(){
    queue<int>q;
    q.push(1);//{1}
    q.push(2);//[1,2]
    q.emplace(4);//{1,2,4}
    q.back() +=5;
    cout<<q.back();//prints 9
    cout<<q.front();//prints 1
    q.pop();//{2,9}
    cout<<q.front();//prints 2
    //sizwswap empty same asstack
}

//prioprity queue
void explainPriority(){
    priority_queue<int>pq;
    pq.push(5);//{5}
    pq.push(2);//{5,2}
    pq.push(8);//{,85,2}
    pq.emplace(10);//{10,8,5,2}
    cout<<pq.top();//10
    pq.pop();//{8,5,2}
    cout<<pq.top();//8
    // size swap empty function same as others
    //minimum heap
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(5);//{5}
    pq.push(2);//{2,5}
    pq.push(8);//{2,5,8}
    pq.emplace(10);//{,5,8,10}
    cout<<pq.top();//2
}

//set -- stores everything in a sorted manner & unique
void exaplainSet(){
    set<int>st;
    st.insert(3);//{3}
    st.emplace(1);//{1,3}
    st.insert(2);//{1,2,3}
    st.insert(2);//{1,2,3}
    st.insert(6);//{1,2,3,6}
    //functionality of insert in vector can be used also, that only increase efficiency
    //begin(),end(),rbegin(),rend(),size(),empty()and swap() are sameas those of above

    //{1,2,3,4,5}
    auto it=st.find(3);
    //{1,2,3,4,5}
    auto it = st.find(6);
    //{1,4,5}
    st.erase(5);// erase 5 // takes logarithmic time
    int cnt=st.count(1);// if present gives 1 otherwise gives 0
    auto it =st.find(3);
    st.erase(it);// it takes constant time
    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2);//{1,4,5} ,{first,last}

    // lower_bound() and upper_bound() function works in the same way
    //as in vector it does.

    // this is syntax
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);   
}

// multi set
void explainMultiSet(){
    //  everything same as set
    //only stores duplicate element also
    multiset<int>ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}

    ms.erase(1);// all 1's are erased
    int cnt = ms.count(1);
    ms.erase(ms.find(1));//only single 1 is erased
    ms.erase(ms.find(1),ms.find(1+2));
    //rest all functiom are same as set
}

// unordered set
void explainUSet(){ // very rare whne complexity goes to O(n)
    unordered_set<int>st;
    //lower_bound & upper_bound function does not work
    //rest all works sa,e as above ,
    //it doesnot stores in any particular order it have better complexity
    //than set in most cases , except some when collison happnes 
}

//Map
void explainMap(){
    map<int,int>mp;
    map <int ,pair<int,int>>mp;
    map<pair<int,int>,int>mp;

    mp[1]=2;
    mp.emplace(3,1);
    mp.insert({2,4});
    mp[(2,3)]=10;
//  {
//     {1,2}
//     {2,4}
//     {3,4}
//  }
 for(auto it : mp){
    cout<<it.first<<" "<<it.second<<endl;
 }
cout<<mp[1];
cout<<mp[5];
auto it = mp.find(3);
// cout<<*(it).second;
auto it=mp.find(5);
// this is the syntax
auto it =mp.lower_bound(2);
auto it = mp.upper_bound(3);
//erase, swap , size , empty , are same as above
}

// multi map
void explainMultiMap(){
    //every thing issame as map , only it can store multiple keys
    //only mpp[key] cannot be used here.
}

// unordered map
void explainUorderdMap(){
    //same as set & unorderd_set difference.
}

// algorithms
bool comp(pair<int,int>p1,pair<int,int>p2){
       if(p1.second <p2.second){
        return true;
       } 
       if(p1.second >p2.second) return false;
       if(p1.first>p2.first) return true;
       return false;
    }
void explainExtra(){
    int a,n;
    vector<int>v;
    sort(a,a+n);
    sort( v.begin(),v.end());
    // sort(a,a+n, greater<int>);// sort in descending order
    pair<int,int>a[]={{1,2},{2,1},{4,1}};
    // sort is according to the second elemnet 
    //if secon elment is same , the sort
    //it according to first elemet but in decreasing

    sort(a,a+n,comp);// comp is a self written comparator
    //{4,1},{2,1},{1,2}
    int num=7;
    int cnt =__builtin_popcount(num);
    long long num = 1234567876543;
    int cnt = __builtin_popcount(num);
    string s="123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    // int maxi = *max_element(a,a+n);
}
int main(){
    print();
    cout<<endl;
    int s= sum(1,4);
    cout<<s;
    cout<<endl;
    explainPair();
    // explainVector();
    return 0;
}
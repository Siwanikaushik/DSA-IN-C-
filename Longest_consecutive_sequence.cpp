#include<bits/stdc++.h>
using namespace std;

//  longest consecutive sequence


// brute force
bool ls(vector<int>arr,int num){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==n){
            return true;
        }
    }
    return false;
}
vector<int> longestConse(vector<int>&a){  // tc -> O(n^2)
    int longest =1;
    int x;
    int n = a.size();
    for(int i=0;i<n;i++){
        x= a[i];
        int count =1;
        while(ls(a,x+1)==true){
            x=x+1;
            count=count+1;
        }

    }
}

// better solution
int longestConsecutive(vector<int>&a){  // tc-> O(n log n + n)
    if(a.size()==0)return 0;
    int n= a.size();
    sort(a.begin(),a.end());
    int longest=1;
    int curnt_cont=0;
    int last_smaller = INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]-1== last_smaller){
            curnt_cont++;
            last_smaller = a[i];
        }
        else if(a[i] != last_smaller){
            curnt_cont =1;
            last_smaller = a[i];
        }
        longest = max(longest,curnt_cont);

    }
    return longest ;

}


// optimal solution
int longestSuccessiveElements(vector<int>&a){  // O(3n)
    int n = a.size();
    if(n==0) return 0;
    int longest =1;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    for(auto it : st){
        if(st.find(it-1)== st.end()){
            int cnt =1;
            int  x =it;
            while(st.find(x+1)!=st.end()){
                x = x+1;
                cnt = cnt+1;

            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}
int main(){

    return 0;
}
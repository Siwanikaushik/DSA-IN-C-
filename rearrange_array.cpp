#include<bits/stdc++.h>
using namespace std;

// rearrange the array elements by sign

// brute force 
void arrays(vector<int>v){   // tc -> O(n + n/2)  , sc ->O(n)
    int n = v.size();
    vector<int> pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(v[i]>0){
            pos.push_back(v[i]);
        }
        else{
            neg.push_back(v[i]);
        }
    }
    for(int i=0;i<n/2;i++){
        v[2*i] = pos[i];
        v[2*i + 1] = neg[i];
    }
    cout<<"the rearranged arra is : ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }

}

// optimal  - negative & positive are equal
vector<int> rearrangeArray(vector<int>& nums){
    int n= nums.size();
    vector<int> ans(n,0);
    int posIndex =0 , negIndex =1;
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            ans[negIndex]=nums[i];
            negIndex+=2;
        }else{
            ans[posIndex]=nums[i];
            posIndex+=2;

        }
    }
    return ans;
}

// another variety where positive & negative are not same
vector<int> alternatNumbers(vector<int>&a){  // tc-> O(n)+O(n) -> O(2n)
    vector<int> pos,neg;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]>0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);

        }
    }
    if(pos.size()>neg.size()){
        for(int i=0; i<neg.size();i++){
            a[2*i]=pos[i];
            a[2*i +1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            a[index]=pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<neg.size();i++){
            a[2*i]=pos[i];
            a[2*i +1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            a[index]=neg[i];
            index++;
        }

    }
    return a;
}
int main(){
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    int nums[n];
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        arr.push_back(nums[i]);
    }
    arrays(arr);

    return 0;
}
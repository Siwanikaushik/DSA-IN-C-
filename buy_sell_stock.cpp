#include<bits/stdc++.h>
using namespace std;

// buy & sell stock -dp problrem
// best time to buy & sell stock
// mini = a[0] , profit =0

int maximumProfit(vector<int> &prices){     // TC -> O(n) , sc-> O(i)
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for(int i=0;i<n;i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini , prices[i]);
    }
    return maxProfit;
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
    int sol = maximumProfit(arr);
    cout<<"Maximum Profit : "<<sol;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// counting digits
int count(int n){  // Time complexity : O(log 10(N))
    int cnt=0;
while(n>0){
    int last_digit = n%10;
    // cout<<last_digit;
    cnt = cnt+1;
    n=n/10;
}
return cnt;
}

// reverse of number & do no include xeros at the end 
int reverse(int n){
    int reverse_num=0;
    while(n>0){
        int last_digit = n%10;
        n=n/10;
        reverse_num= (reverse_num*10)+last_digit;
    }
    return reverse_num;
}

// palindrome of a number
int palindrome(int n){
    int temp = n;
    int reverse_num=0;
    while(n>0){
        int last_digit = n%10;
        n=n/10;
        reverse_num= (reverse_num*10)+last_digit;
    }
    if(reverse_num == temp)
    cout<<" is a palindrome";
    else cout<<" is not a palindrome";
}

//Armstrong number
int armstrong(int n){
    int temp=n;
    int sum =0;
    while(n>0){
        int last_digit=n%10;
        sum= sum+(last_digit*last_digit*last_digit);
        n=n/10;
    }
    if(temp==sum) cout<<temp<<" is a armstrong number";
    else cout<<temp<< " is not an armstrong number";
}

// print all divisors
void divisor(int n){  // have time complexity is O(n)
    for(int i=1;i<=n;i++){
        if(n%i == 0){
            cout<<i<<" ";
        }
    }
}

// divisor using less tc
void divisorsTC(int n){  // have time complexity is O(sqrt(n))+O(no of factors *log(no. of factors))+O(no of factors)
    vector<int>ls;
    //O(sqrt(n))
    for(int i=1;i*i<=(n);i++){
        if(n%i == 0){
            ls.push_back(i);
            if(n/i !=i){
                ls.push_back(n/i);
            }
        }
    }
    //O(no of factors *log(no. of factors))
    sort(ls.begin(),ls.end());
    //  O(no of factors)
    for(auto it :ls) cout<<it<<" ";
}

// prime number : a number that has two factors 1 & itself
// extreme brute force algorithm
void prime(int n){  // tc= O(n)
    int count =0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2)cout<<n<<" is aprime number";
    else cout<<n<<" is not a prime number";
}

// prime factor with less time complexity
void primeTc(int n){   // tc is O(sqrt(n))
    int count =0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if(n/i != i){
                count++;
            }
        }
    }
    if(count == 2) cout<<n<< " is a prime number";
    else cout<<n<<" is not a prime number";
}


//GCD / HCF
void gcd(int n,int m){
    int gcd=1;
    for(int i=1;i<=min(n,m);i++){// TC =O(min(n,m))
        if(n%i==0 && m%i==0){
            gcd=i;
        }
    }
    cout<<gcd;
}

// Euclidean Algorithm : for prime number : gcd(n,m)= gcd(n-m,m)
// if n>m ; gcd(n,m) = gcd(n%m,m) , if one is 0 then another is gcd
void euclidean(int n, int m){
    while(n>0 && m>0){ // tc =O(log fie(min(a,b)))
        if(n>m) n=n%m;
        else m = m%n;
    }
    if(n==0) cout<<m;
    else cout<<n;
}
int main(){
// basic maths
// digit concept :
//extracting  digits : ex->7789
int n;
cin>>n;
while(n>0){
    int last_digit = n%10;
    cout<<last_digit;
    n=n/10;
}
cout<<endl;
int num;
cin>>num;
cout<<count(num);
cout<<endl;
// another way to find count is:
int count;
count = (int)(log10(num)+1);
cout<<count;
cout<<endl;
cout<<reverse(num);
palindrome(num);
cout<<endl;
armstrong(num);
cout<<endl;
divisor(num);
cout<<endl;
divisorsTC(num);
cout<<endl;
prime(num);
cout<<endl;
primeTc(num);
cout<<endl;
int num2;
cout<<"enter second number";
cin>>num2;
cout<<"gacd is : ";
gcd(num,num2);
cout<<endl;
euclidean(num,num2);

    return 0;
}
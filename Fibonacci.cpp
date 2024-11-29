#include <bits/stdc++.h>
using namespace std;
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
int n; cin>>n;
cout<<n<<"th Fibonacci term is: "<<fib(n)<<endl; 
    return 0;
}

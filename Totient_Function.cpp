#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, coprimes=0; 
    cin >> n;
    for(int i=1; i<=n; i++){
        if(gcd(i, n) == 1) coprimes++;
    }
    cout << coprimes << endl;
}

#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-7;

double bin(double x){
    double l = 1.0, h = x;
    if(x < 0) return -1;
    else if(x < 1){
        l = x, h = 1.0;
    }
    while(h-l>eps){
        double m = (h+l)/2.0;
        if(m*m == x) return m;
        else if(m*m > x){
            h = m;
        }
        else l = m;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double x;
    cin>>x;
    if(bin(x) == -1)cout<<"No real solution\n";
    else cout<<fixed<<setprecision(7)<<bin(x)<<"\n";
} 

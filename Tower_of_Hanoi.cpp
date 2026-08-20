#include<bits/stdc++.h>
using namespace std;
using ll = long long;


// initially a(start), b(helper), c(dest)
void tower_of_hanoi(ll n, char start, char helper, char dest){
    if(n == 1){
        cout << "Move disc 1 from " << start << " to " << dest << '\n';
        return;
    }
    // moving n - 1 discs from a to b with c 
    tower_of_hanoi(n - 1, start, dest, helper);
    
    // moving largest discs from a to c 
    cout << "Move disc " << n << " from " << start << " to " << dest << '\n';
    
    // moving remaining n - 1 discs from b to c with a
    tower_of_hanoi(n - 1, helper, start, dest);
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;// number of discs
    cin >> n;
    tower_of_hanoi(n, 'a', 'b', 'c');
    
    
    return 0;
}

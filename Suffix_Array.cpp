#include <bits/stdc++.h>
using namespace std;
vector<string>suffix(string s){
    vector<string>arr;
    for(int i=0; i<s.length(); i++){
        arr.push_back(s.substr(i));
    }
    sort(arr.begin(), arr.end());
    return arr;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;
vector<string>sorted_array = suffix(s);
for(const auto &a: sorted_array){
    cout<<a<<endl;
}
    return 0;
}

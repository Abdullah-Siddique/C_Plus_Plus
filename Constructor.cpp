#include <bits/stdc++.h>
using namespace std;
class me{
    public:
    string name;
    int age;
    string color;
    // Creating constructor
    me(){
        cout<<"Enter your name: "<<endl;
        cin>>name;
        cout<<"Enter your age: "<<endl;
        cin>>age;
        cout<<"Enter your favourite color: "<<endl;
        cin>>color;
    }
    void display(){
        cout<<"I am "<<name<<", I am "<<age<<" years old"<<" and my favourite color is "<<color<<endl;
    }
    
};
int main()
{
me Me;
Me.display();

    return 0;
}

#include <iostream>
using namespace std;

class Vehicle{
public:
    string color;
    int number;
    int year;
    
    void setData(string c, int n, int y){
        color = c;
        number = n;
        year = y;
    }
    
    void getData(){
        cout<<"Color: "<<color<<endl;
        cout<<"Number: "<<number<<endl;
        cout<<"Year: "<<year<<endl;
    }
};

class Car: public Vehicle{
    public:
    string name;
    void setName (string na){
        name = na;
    }
    void getName(){
        cout<<"Name: "<<name<<endl;
    }
};

int main() {
    Car myCar;
    //Taking input
    cout<<"Enter Color: ";
    cin>>myCar.color;
    cout<<"Enter Number: ";
    cin>>myCar.number;
    cout<<"Enter Year: ";
    cin>>myCar.year;
    cout<<"Enter name: ";
    cin>>myCar.name;
    
    
    //Displaying data
    myCar.getData();
    myCar.getName();

  return 0;
}

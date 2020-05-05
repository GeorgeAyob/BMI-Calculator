//This program uses a class with member functions and member variables with definitions to implement a program that utilizes and outputs their functions
#include<iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class secretType
{
public:
    void print();
    void setName(string);
    void setAge(int);
    void setWeight(int);
    void setHeight(double);
    string getName();
    int getAge();
    int getWeight();
    double getHeight();
    void weightStatus();
    secretType(string,int,int,double);// constructor
    secretType();// default constructor
    
private:
    string name;
    int age,weight;
    double height;
};

int main()
{
    fstream infile;
    infile.open("PersonInfo.txt");
    if(!infile){
        cout<<"Error opening file";
        return 0;
    }
    
    string name;
    int age,weight,a;
    double height;
    
    cout<<"How many people do you have in your file?"<<endl;
    cin>>a;
    
    secretType Person[a];

    for(int i=0;i<a;i++)
    {
    infile>>name>>age>>weight>>height;
    
    Person[a].setName(name);
    Person[a].setAge(age);
    Person[a].setWeight(weight);
    Person[a].setHeight(height);
    Person[a].print();
    Person[a].weightStatus();
    }
    
    
    
    
    
}// End Main

secretType::secretType() //default constructor
{
    name = " ";
    age = 0;
    weight = 0;
    height = 0;
}

void secretType::print(){
    cout<<"\nName:"<<name<<endl<<"Age:"<<age<<endl<<"Weight:"<<weight<<endl<<"Height:"<<height<<endl;}

void secretType::setName(string a){name=a;}

void secretType::setAge(int a){age=a;}

void secretType::setWeight(int a){weight=a;}

void secretType::setHeight(double a){height=a;}

string secretType:: getName()   {return name;}
int secretType:: getAge()       {return age;}
int secretType:: getWeight()    {return weight;}
double secretType:: getHeight() {return height;}

void secretType::weightStatus(){
    int BMI;
    
    weight*=703;
    height*=12;
    height*=height;
    
    BMI=weight/height;
    
    if(BMI < 18.5)
        cout<<"BMI:Under Weight"<<endl;
    
    else if(BMI>=18.5 && BMI<=24.9)
        cout<<"BMI:Normal"<<endl;
    
    else if(BMI>=25 && BMI<=29.9)
        cout<<"BMI:Over Weight"<<endl;
       
    else if(BMI>=30)
        cout<<"BMI:Obese"<<endl;
}

/*
 Text file:
 John_Alex          18     145    5.4
 Samatha-Wilson     21     60     5.2
 David-J            54     300    6.0
 Kyle-Anderson      22     240    6.4
 
 
 Output File:
 How many people do you have in your file?
 4
 
 Name:John_Alex
 Age:18
 Weight:145
 Height:5.4
 BMI:Normal
 
 Name:Samatha-Wilson
 Age:21
 Weight:60
 Height:5.2
 BMI:Under Weight
 
 Name:David-J
 Age:54
 Weight:300
 Height:6
 BMI:Obese
 
 Name:Kyle-Anderson
 Age:22
 Weight:240
 Height:6.4
 BMI:Over Weight
 Program ended with exit code: 0
 
 */



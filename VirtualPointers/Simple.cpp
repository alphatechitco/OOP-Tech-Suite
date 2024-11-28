#include<iostream>
using namespace std;

class Animal{
public:
virtual void sound(){
    cout<<"Animal creates sound\n";
}

};

class Cat:public Animal{
public:
void sound(){
    cout<<"Meows\n";
}

};

class Dog:public Animal{
public:
void sound(){
    cout<<"Barks\n";

}

};

class Wolf:public Animal{
public:
void sound(){
    cout<<"Hooowls\n";

}

};

class Lion:public Animal{
public:
void sound(){
    cout<<"Rooaars\n";

}

};

int main(){

    Animal a;
    Cat c;
    Dog d;
    Wolf w;
    Lion l;

    Animal *PA[]={&a,&c,&d,&w,&l};
    for(int j=0;j<5;j++)
    PA[j]->sound();

}
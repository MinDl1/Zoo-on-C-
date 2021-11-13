#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class zoo{
    int number;
    string animal;
    string sex;
    string name;
    double price;
    int how;
    double price_how;
    zoo *next;
public:
//    Default constructors 1) Common 2) for chain of objects
    zoo(){
        animal="Nothing";
        sex='N';
        name="Nothing";
        price=0;
        how=0;
        price_how=0;
    }
    zoo(zoo &obj){
        obj.next=this;
        animal="Nothing";
        sex='N';
        name="Nothing";
        price=0;
        how=0;
        price_how=0;
    }
//    Value constructors 1) constructor for creating a regular object 2) constructor for creating a chain dynamic objects
    zoo(string animal,string sex,string name,double price,int how){
        this->number=1;
        this->animal=animal;
        this->sex=sex;
        this->name=name;
        this->price=price;
        this->how=how;
        this->price_how=price*how;
    }
    zoo(string animal,string sex,string name,double price,int how,zoo &obj){
        obj.next=this;
        this->number=1;
        this->animal=animal;
        this->sex=sex;
        this->name=name;
        this->price=price;
        this->how=how;
        this->price_how=price*how;
    }
//    Copy constructor which I'm not using
    zoo(string anim,zoo &obj){
        obj.next=this;
        this->animal=obj.animal;
        this->sex=obj.sex;
        this->name=obj.name;
        this->price=obj.price;
        this->how=obj.how;
        this->price_how=obj.price_how;
    }
//    Destructor
    ~zoo(){
        cout<<"Object deleted"<<endl;
    }
//    Shows all objects
    void show(){
        cout<<number<<")"<<animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<price_how<<endl<<endl;
        if(next){
            next->show();
        }
    }
//    gives the number to object
    void numb(){
        if(next){
            next->number=this->number+1;
            next->numb();
        }
    }
//    Searches and chaneges
    void change(string nam,string sex,string name,int how,zoo &obj){
        if(this->name==nam){
            cout<<number<<")"<<animal<<endl<<this->sex<<endl<<this->name<<endl<<price<<endl<<this->how<<endl<<price_how<<endl<<endl;
            this->sex=sex;
            this->name=name;
            this->how=how;
            this->price_how=price*how;
            cout<<number<<")"<<animal<<endl<<this->sex<<endl<<this->name<<endl<<price<<endl<<this->how<<endl<<price_how<<endl<<endl;
        }
        else{
            next->change(nam,sex,name,how,obj);
        }
    }
    void change(string anima,string animal,string sex,string name,double price,int how,zoo &obj){
        if(this->animal==anima){
            cout<<number<<")"<<this->animal<<endl<<this->sex<<endl<<this->name<<endl<<this->price<<endl<<this->how<<endl<<price_how<<endl<<endl;
            this->animal=animal;
            this->sex=sex;
            this->name=name;
            this->price=price;
            this->how=how;
            this->price_how=price*how;
            cout<<number<<")"<<this->animal<<endl<<this->sex<<endl<<this->name<<endl<<this->price<<endl<<this->how<<endl<<price_how<<endl<<endl;
        }
        else{
            next->change(anima,animal,sex,name,price,how,obj);
        }
    }
    void change(string animal,double price,zoo &obj){
        if(this->animal==animal){
            cout<<number<<")"<<this->animal<<endl<<sex<<endl<<name<<endl<<this->price<<endl<<how<<endl<<price_how<<endl<<endl;
            this->price=price;
            this->price_how=price*how;
            cout<<number<<")"<<this->animal<<endl<<sex<<endl<<name<<endl<<this->price<<endl<<how<<endl<<price_how<<endl<<endl;
        }
        else{
            next->change(animal,price,obj);
        }
    }
//    Searches and displays the desired result
    void search(string animal){
        if(next){
            if(this->animal==animal){
                cout<<this->number<<")"<<this->animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<price_how<<endl<<endl;
            }
            else{
                next->search(animal);
            }
        }
        else{
            if(this->animal==animal){
                cout<<this->number<<")"<<this->animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<price_how<<endl<<endl;
            }
        }
    }
    void search(int number){
        if(next){
            if(this->number==number){
                cout<<this->number<<")"<<this->animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<price_how<<endl<<endl;
            }
            else{
                next->search(number);
            }
        }
        else{
            if(this->number==number){
                cout<<this->number<<")"<<this->animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<price_how<<endl<<endl;
            }
        }
    }
//      Deleting unnecessary object
    void search_delete(string animal, zoo* obj){
        if(next->animal==animal){
            cout<<this->number<<")"<<next->animal<<endl<<next->sex<<endl<<next->name<<endl<<next->price<<endl<<next->how<<endl<<next->price_how<<endl<<endl;
            delete this->next;
            this->next=next->next;
        }
        else{
            next->search_delete(animal, obj);
        }
    }
//      Deleting all objects
    void delete_all(zoo *obj){
        if(obj->next){
            delete_all(obj->next);
        }
        delete obj;
    }
//    Copies the values of another object
    void copy(string anim,string &animal,string &sex,string &name,double &price,int &how,zoo &obj){
        if(this->animal==anim){
            animal=this->animal;
            sex=this->sex;
            name=this->name;
            price=this->price;
            how=this->how;
            cout<<number<<")"<<animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<price_how<<endl<<endl;
        }
        else{
            next->copy(anim,animal,sex,name,price,how,obj);
        }
    }
//    Write all objects in the file
    void write(ofstream &obj){
        obj<<number<<")"<<animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<price_how<<endl<<endl;
        if(next){
            next->write(obj);
        }
    }
//    For method change and other methods check
    bool search_change(string animal){
        if(next){
            if(this->animal==animal){
                return true;
            }
            else{
                return next->search_change(animal);
            }
        }
        else{
            if(this->animal==animal){
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool search_change(int number){
        if(next){
            if(this->number==number){
                return true;
            }
            else{
                return next->search_change(number);
            }
        }
        else{
            if(this->number==number){
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool search_changes(string name){
        if(next){
            if(this->name==name){
                return true;
            }
            else{
                return next->search_change(name);
            }
        }
        else{
            if(this->name==name){
                return true;
            }
            else{
                return false;
            }
        }
    }
};

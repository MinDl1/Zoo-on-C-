#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class zoo{
    string animal;
    string sex;
    string name;
    double price;
    int how;
    zoo *next;
public:
//    Default constructors 1) Common 2) for chain of objects
    zoo(){
        animal="Nothing";
        sex='N';
        name="Nothing";
        price=0;
        how=0;
    }
    zoo(zoo &obj){
        obj.next=this;
        animal="Nothing";
        sex='N';
        name="Nothing";
        price=0;
        how=0;
    }
//    Value constructors 1) constructor for creating a regular object 2) constructor for creating a chain dynamic objects
    zoo(string animal,string sex,string name,double price,int how){
        this->animal=animal;
        this->sex=sex;
        this->name=name;
        this->price=price;
        this->how=how;
    }
    zoo(string animal,string sex,string name,double price,int how,zoo &obj){
        obj.next=this;
        this->animal=animal;
        this->sex=sex;
        this->name=name;
        this->price=price;
        this->how=how;
    }
//    Copy constructor which I'm not using
    zoo(string anim,zoo &obj){
        obj.next=this;
        this->animal=obj.animal;
        this->sex=obj.sex;
        this->name=obj.name;
        this->price=obj.price;
        this->how=obj.how;
    }
//    Destructor
    ~zoo(){
        cout<<"Object deleted"<<endl;
    }
//    Shows all objects
    void show(){
        cout<<animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<endl;
        if(next){
            next->show();
        }
    }
//    Searches and chaneges
    void change(string nam,string sex,string name,int how,zoo &obj){
        if(this->name==nam){
            cout<<animal<<endl<<this->sex<<endl<<this->name<<endl<<price<<endl<<this->how<<endl<<endl;
            this->sex=sex;
            this->name=name;
            this->how=how;
            cout<<animal<<endl<<this->sex<<endl<<this->name<<endl<<price<<endl<<this->how<<endl<<endl;
        }
        else{
            next->change(nam,sex,name,how,obj);
        }
    }
    void change(string anima,string animal,string sex,string name,double price,int how,zoo &obj){
        if(this->animal==anima){
            cout<<this->animal<<endl<<this->sex<<endl<<this->name<<endl<<this->price<<endl<<this->how<<endl<<endl;
            this->animal=animal;
            this->sex=sex;
            this->name=name;
            this->price=price;
            this->how=how;
            cout<<this->animal<<endl<<this->sex<<endl<<this->name<<endl<<this->price<<endl<<this->how<<endl<<endl;
        }
        else{
            next->change(anima,animal,sex,name,price,how,obj);
        }
    }
    void change(string animal,double price,zoo &obj){
        if(this->animal==animal){
            cout<<this->animal<<endl<<sex<<endl<<name<<endl<<this->price<<endl<<how<<endl<<endl;
            this->price=price;
            cout<<this->animal<<endl<<sex<<endl<<name<<endl<<this->price<<endl<<how<<endl<<endl;
        }
        else{
            next->change(animal,price,obj);
        }
    }
//    Searches and displays the desired result
    void search(string animal){
        if(next){
            if(this->animal==animal){
                cout<<this->animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<endl;
            }
            else{
                next->search(animal);
            }
        }
    }
//      Deleting unnecessary object
    void search_delete(string anim, zoo* obj){
        if(next->animal==anim){
            cout<<next->animal<<endl<<next->sex<<endl<<next->name<<endl<<next->price<<endl<<next->how<<endl<<endl;
            delete this->next;
            next=next->next;
        }
        else{
            next->search_delete(anim, obj);
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
            cout<<animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<endl;
        }
        else{
            next->copy(anim,animal,sex,name,price,how,obj);
        }
    }
//    Write all objects in the file
    void write(ofstream &obj){
        obj<<animal<<endl<<sex<<endl<<name<<endl<<price<<endl<<how<<endl<<endl;
        if(next){
            next->write(obj);
        }
    }
//    For method change
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

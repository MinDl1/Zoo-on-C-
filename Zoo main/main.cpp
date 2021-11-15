//
//  main.cpp
//  Zoo
//
//  Created by MinDl on 13.11.2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include "zoo.h"
using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"  ________   ________    ________ "<<endl;
    cout<<" /\\_____  \\ /\\   __  \\  /\\   __  \\ "<<endl;
    cout<<" \\/____/  / \\ \\  \\/\\  \\ \\ \\  \\/\\  \\ "<<endl;
    cout<<"      /  /   \\ \\  \\ \\  \\ \\ \\  \\ \\  \\ "<<endl;
    cout<<"     /  /____ \\ \\  \\_\\  \\ \\ \\  \\_\\  \\ "<<endl;
    cout<<"    /\\_______\\ \\ \\_______\\ \\ \\_______\\ "<<endl;
    cout<<"    \\/_______/  \\/_______/  \\/_______/  "<<endl;
    //    Definning the first object
    string animal;
    string sex;
    string name;
    double price;
    int how;
    
    string ex;
    cout<<"Enter the details of the first object: "<<endl;
    cout<<"Kind of animal: ";
    cin>>animal;
    while(true){
        cout<<"How many: ";
        if(cin>>how){
            break;
        }
        else{
            cout<<"Wrong input"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    cout<<"Sexes: ";
    cin>>sex;
    cout<<"Names: ";
    cin>>name;
    while(true){
        cout<<"Price: ";
        if(cin>>price){
            break;
        }
        else{
            cout<<"Wrong input"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
        
    zoo *pnt=new zoo(animal,sex,name,price,how);
    zoo *p;
    p=pnt;
    
    cout<<"\nEnter command:\nh - help - display this message\ncrv - create_void - create void obj\ncr - create - create new object with your input values\nsh - show - show all objects\nsa - search_animal - search with kind of animal\nsn - search_number - search with number\nca - copy_animal - copy with animal search\ncn - copy_number - copy with number search\nch - change - change some values\ndoc - document - take data from document\ndela - delete_animal - delete with kind of animal search\ndeln - delete_number - delete with number search\nexit - exit"<<endl;
    
//    An endless cycle of creating objects and action with them
    while(ex!="exit"){
        cin>>ex;
        cout<<endl;
//        Creating empty object
        if(ex=="create_void"||ex=="crv"){
            p=new zoo(*p);
            pnt->numb();
            cout<<"Empty object created\n\n";
        }
//        Creating object with values
        else if(ex=="create"||ex=="cr"){
            cout<<"Creating a new object:"<<endl;
            cout<<"Kind of animal: ";
            cin>>animal;
            while(true){
                cout<<"How many: ";
                if(cin>>how){
                    break;
                }
                else{
                    cout<<"Wrong input"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            }
            cout<<"Sexes: ";
            cin>>sex;
            cout<<"Names: ";
            cin>>name;
            while(true){
                cout<<"Price: ";
                if(cin>>price){
                    break;
                }
                else{
                    cout<<"Wrong input"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            }
            cout<<endl;
            p=new zoo(animal,sex,name,price,how,*p);
            pnt->numb();
            cout<<"Object was created"<<endl<<endl;
        }
//        Shows all objects
        else if(ex=="show"||ex=="sh")pnt->show();
//        Shows one object that you search with kind of animal
        else if(ex=="search_animal"||ex=="sa"){
            string anima;
            cout<<"Enter kind of animal: ";
            cin>>anima;
            cout<<endl;
            pnt->search(anima);
        }
//          Shows one object that you search with number
        else if(ex=="search_number"||ex=="sn"){
            int number;
            while(true){
                cout<<"Enter number of object: ";
                if(cin>>number){
                    break;
                }
                else{
                    cout<<"Wrong input"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            }
            cout<<endl;
            pnt->search(number);
        }
//        Copies another object
        else if(ex=="copy_animal"||ex=="ca"){
            string anima;
            cout<<"Enter kind of animal: ";
            cin>>anima;
            if(pnt->search_change(anima)){
                cout<<endl;
                pnt->copy(anima,animal,sex,name,price,how,*p);
                p = new zoo(animal,sex,name,price,how,*p);
                pnt->numb();
            }
            else{
                cout<<endl<<"No such object"<<endl<<endl;
            }
        }
        else if(ex=="copy_number"||ex=="cn"){
            int number;
            while(true){
                cout<<"Enter number of object: ";
                if(cin>>number){
                    break;
                }
                else{
                    cout<<"Wrong input"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            }
            if(pnt->search_change(number)){
                cout<<endl;
                pnt->copy(number,animal,sex,name,price,how,*p);
                p = new zoo(animal,sex,name,price,how,*p);
                pnt->numb();
            }
            else{
                cout<<endl<<"No such object"<<endl<<endl;
            }
        }
//        Copies values from document
        else if(ex=="document"||ex=="doc"){
            int ext=0;
            string file;
            cout<<"File name: ";
            cin>>file;
            char buff[100];
            ifstream fin(file);
            try{
//        File check
                if(!fin.is_open()){
                    throw "Error: file won't open of not found";
                }
                cout<<"How many objects are in the file?: ";
                cin>>ext;
                string a6[6];
                for(int i=0;i<ext;i++){
                    cout<<"Frist line: ";
                    fin>>buff;
                    for(int j=0;j<6;j++){
                        fin>>buff;
                        a6[j]=buff;
                        cout<<a6[j]<<" ";
                    }
                    cout<<endl;
                    animal=a6[0];
                    sex=a6[1];
                    name=a6[2];
                    price=stod(a6[3]);
                    how=stoi(a6[4]);
                    p=new zoo(animal,sex,name,price,how,*p);
                }
                pnt->numb();
                fin.close();
                cout<<endl;
            }
            catch(const char* error){
                cout<<error<<endl;
            }
        }
//        Delete object that you want
        else if(ex=="delete_animal"||ex=="dela"){
            cout<<"Kind of animal for deleting: ";
            cin>>animal;
            pnt->search_delete(animal,pnt);
            pnt->numb();
        }
        else if(ex=="delete_number"||ex=="deln"){
            int number;
            while(true){
                cout<<"Enter number of object: ";
                if(cin>>number){
                    break;
                }
                else{
                    cout<<"Wrong input"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            }
            pnt->search_delete(number,pnt);
            pnt->numb();
        }
        else if(ex=="change"||ex=="ch"){
            string what;
            cout<<"What do you want to change?\n1)All\n2)Sexes,Names,How\n3)Price"<<endl;
            cin>>what;
            if(what=="1"||what=="1)"||what=="all"||what=="All"||what=="ALL"||what=="1)All"||what=="1)all"){
                int number;
                while(true){
                    cout<<"Enter number of object: ";
                    if(cin>>number){
                        break;
                    }
                    else{
                        cout<<"Wrong input"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    }
                }
                if(pnt->search_change(number)){
                    cout<<"Kind of animal: ";
                    cin>>animal;
                    while(true){
                        cout<<"How many: ";
                        if(cin>>how){
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                    }
                    cout<<"Sexes: ";
                    cin>>sex;
                    cout<<"Names: ";
                    cin>>name;
                    while(true){
                        cout<<"Price: ";
                        if(cin>>price){
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                    }
                    pnt->change(number,animal,sex,name,price,how,*p);
                }
                else{
                    cout<<endl<<"No such object"<<endl<<endl;
                }
            }
            else if(what=="2"||what=="2)"||what=="2)Sexes,Names,How"||what=="Sexes,Names,How"||what=="sexes,names,how"){
                int number;
                while(true){
                    cout<<"Enter number of object: ";
                    if(cin>>number){
                        break;
                    }
                    else{
                        cout<<"Wrong input"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    }
                }
                if(pnt->search_changes(number)){
                    cout<<"New sexes: ";
                    cin>>sex;
                    cout<<"New names: ";
                    cin>>name;
                    while(true){
                        cout<<"How many: ";
                        if(cin>>how){
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                    }
                    pnt->change(number,sex,name,how,*p);
                }
                else{
                    cout<<endl<<"No such object"<<endl<<endl;
                }
            }
            else if(what=="3"||what=="3)"||what=="3)Price"||what=="3)price"||what=="Price"||what=="price"){
                int number;
                while(true){
                    cout<<"Enter number of object: ";
                    if(cin>>number){
                        break;
                    }
                    else{
                        cout<<"Wrong input"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    }
                }
                if(pnt->search_change(number)){
                    while(true){
                        cout<<"Price: ";
                        if(cin>>price){
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                    }
                    pnt->change(number,price,*p);
                }
                else{
                    cout<<endl<<"No such object"<<endl<<endl;
                }
            }
            else{
                cout<<"Command entered incorectly"<<endl<<endl;
            }
        }
//        for "else"
        else if(ex=="exit");
        else if(ex=="h"||ex=="help"){
            cout<<"\nEnter command:\nh - help - display this message\ncrv - create_void - create void obj\ncr - create - create new object with your input values\nsh - show - show all objects\nsa - search_animal - search with kind of animal\nsn - search_number - search with number\nca - copy_animal - copy with animal search\ncn - copy_number - copy with number search\nch - change - change some values\ndoc - document - take data from document\ndela - delete_animal - delete with kind of animal search\ndeln - delete_number - delete with number search\nexit - exit"<<endl;
        }
        else{
            cout<<"Command entered incorrectly, 'h' or 'help' for help"<<endl<<endl;
        }
    }
    string Yes_No;
    bool Yes_No_bool=true;
//    An endless loop to create a file with data
    while(Yes_No_bool){
        cout<<"Do you want to save the data file?(Yes, No) "<<endl;
        cin>>Yes_No;
        if(Yes_No=="y"||Yes_No=="Yes"||Yes_No=="yes"||Yes_No=="YES"||Yes_No=="yES"||Yes_No=="yEs"||Yes_No=="yeS"){
            string file;
            cout<<"File name for data recording: ";
            cin>>file;
            ofstream out_file(file, ios_base::out | ios_base::trunc);
            pnt->write(out_file);
            Yes_No_bool=false;
        }
        else if(Yes_No=="n"||Yes_No=="N"||Yes_No=="No"||Yes_No=="no"||Yes_No=="NO"||Yes_No=="nO"){
            cout<<"Exiting"<<endl;
            Yes_No_bool=false;
        }
        else{
            cout<<"Wrong command, re-enter"<<endl;
        }
    }
//    Deleting all objects
    pnt->delete_all(pnt);
    return 0;
}

//
//  main.cpp
//  Zoo V2.0
//
//  Created by MinDl on 02.12.2021.
//

#include <iostream>
#include <map>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout<<"  ________   ________    ________ "<<endl;
    cout<<" /\\_____  \\ /\\   __  \\  /\\   __  \\ "<<endl;
    cout<<" \\/____/  / \\ \\  \\/\\  \\ \\ \\  \\/\\  \\ "<<endl;
    cout<<"      /  /   \\ \\  \\ \\  \\ \\ \\  \\ \\  \\ "<<endl;
    cout<<"     /  /____ \\ \\  \\_\\  \\ \\ \\  \\_\\  \\ "<<endl;
    cout<<"    /\\_______\\ \\ \\_______\\ \\ \\_______\\ "<<endl;
    cout<<"    \\/_______/  \\/_______/  \\/_______/  "<<endl;
    
    map<int,tuple<string,string,string,float>> zoo;
    string exit;
    int number=1;
    while(exit!="exit"){
        string animal_type;
        string name;
        string sex;
        float price;
        cout<<"Exit or command\nCommands:\nnew - new animal\nshow - show all animals\ndel - delete animal\nfind - find animal\ncopy - copy animal\nchange - change animal\ndoc - take data from document";
        cin>>exit;
        if(exit=="new"){
            cout<<"Animal type: ";
            cin>>animal_type;
            cout<<"Name type: ";
            cin>>name;
            cout<<"Sex: ";
            cin>>sex;
            while(true){
                cout<<"Price: ";
                if(cin>>price){
                    break;
                }
                else{
                    cout<<"Wrong input\n";
                    cin.clear();
                    cin.ignore(price<=0,'\n');
                }
            }
            zoo.emplace(number,make_tuple(animal_type,name,sex,price));
            number++;
        }
        else if(exit=="show"){
            for(int i=1;i<number;i++){
                cout<<i<<") "<<get<0>(zoo[i])<<"\n   "<<get<1>(zoo[i])<<"\n   "<<get<2>(zoo[i])<<"\n   "<<get<3>(zoo[i])<<endl;
            }
        }
        else if(exit=="delete"||exit=="del"){
            int del;
            while(true){
                cout<<"Number of animal: ";
                if(cin>>del){
                    break;
                }
                else{
                    cout<<"Wrong input\n";
                    cin.clear();
                    cin.ignore(del<=0,'\n');
                }
            }
            cout<<del<<") "<<get<0>(zoo[del])<<"\n   "<<get<1>(zoo[del])<<"\n   "<<get<2>(zoo[del])<<"\n   "<<get<3>(zoo[del])<<endl;
            for(int i=del;i<number-1;i++){
                zoo[i].swap(zoo[i+1]);
            }
            zoo.erase(number-1);
            number--;
        }
        else if(exit=="find"){
            int fd;
            while(true){
                cout<<"Number of animal: ";
                if(cin>>fd){
                    break;
                }
                else{
                    cout<<"Wrong input\n";
                    cin.clear();
                    cin.ignore(fd<=0,'\n');
                }
            }
            const auto it=zoo.find(fd);
            if(it!=zoo.end()){
                cout<<fd<<") "<<get<0>(zoo[fd])<<"\n   "<<get<1>(zoo[fd])<<"\n   "<<get<2>(zoo[fd])<<"\n   "<<get<3>(zoo[fd])<<endl;
            }
            else{
                cout<<"Animal not found\n";
            }
        }
        else if(exit=="copy"){
            int cp;
            while(true){
                cout<<"Number of animal: ";
                if(cin>>cp){
                    break;
                }
                else{
                    cout<<"Wrong input\n";
                    cin.clear();
                    cin.ignore(cp<=0,'\n');
                }
            }
            zoo.emplace(number,make_tuple(get<0>(zoo[cp]),get<1>(zoo[cp]),get<2>(zoo[cp]),get<3>(zoo[cp])));
            cout<<number<<") "<<get<0>(zoo[number])<<"\n   "<<get<1>(zoo[number])<<"\n   "<<get<2>(zoo[number])<<"\n   "<<get<3>(zoo[number])<<endl;
            number++;
        }
        else if(exit=="change"){
            int ch;
            while(true){
                cout<<"Number of animal: ";
                if(cin>>ch){
                    break;
                }
                else{
                    cout<<"Wrong input\n";
                    cin.clear();
                    cin.ignore(ch<=0,'\n');
                }
            }
            cout<<"Animal type: ";
            cin>>animal_type;
            cout<<"Name type: ";
            cin>>name;
            cout<<"Sex: ";
            cin>>sex;
            while(true){
                cout<<"Price: ";
                if(cin>>price){
                    break;
                }
                else{
                    cout<<"Wrong input\n";
                    cin.clear();
                    cin.ignore(price<=0,'\n');
                }
            }
            zoo[ch]=tuple<string,string,string,float>(animal_type,name,sex,price);
        }
        else if(exit=="document"||exit=="doc"){
            string file;
            cout<<"File name: ";
            cin>>file;
            char buff[100];
            ifstream fin(file);
            if(!fin.is_open()){
                cout<<"Error: file won't open or not found\n\n";
            }
            else{
                string data[4];
                for(int i=0;fin>>buff;i++){
                    cout<<"Frist line: ";
                    for(int j=0;j<4;j++){
                        fin>>buff;
                        data[j]=buff;
                        cout<<data[j]<<" ";
                    }
                    cout<<endl;
                    animal_type=data[0];
                    sex=data[1];
                    name=data[2];
                    price=stof(data[3]);
                    zoo.emplace(number,make_tuple(animal_type,name,sex,price));
                    number++;
                }
                fin.close();
                cout<<endl;
            }
        }
        else if(exit=="exit"){}
        else{
            cout<<"Wrong command\n\n";
        }
        cout<<endl;
    }
    string Yes_No;
    bool Yes_No_bool=true;
    while(Yes_No_bool){
        cout<<"Do you want to save the data file?(Yes, No) "<<endl;
        cin>>Yes_No;
        if(Yes_No=="y"||Yes_No=="Yes"||Yes_No=="yes"||Yes_No=="YES"||Yes_No=="yES"||Yes_No=="yEs"||Yes_No=="yeS"){
            string file;
            cout<<"File name for data recording: ";
            cin>>file;
            ofstream out_file(file, ios_base::out | ios_base::trunc);
            for(int i=1;i<number;i++){
                out_file<<i<<") "<<get<0>(zoo[i])<<"\n   "<<get<1>(zoo[i])<<"\n   "<<get<2>(zoo[i])<<"\n   "<<get<3>(zoo[i])<<endl;
            }
            Yes_No_bool=false;
        }
        else if(Yes_No=="n"||Yes_No=="N"||Yes_No=="No"||Yes_No=="no"||Yes_No=="NO"||Yes_No=="nO"){
            cout<<"Exiting"<<endl;
            Yes_No_bool=false;
        }
        else{
            cout<<"Wrong command, re-enter\n\n";
        }
    }
    return 0;
}

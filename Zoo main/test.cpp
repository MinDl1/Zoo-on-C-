#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

class zoo {
    string animal_type;
    string name;
    string sex;
    float price;
public:
    zoo(string animal_type, string name,string sex,float price) {
        this->animal_type = animal_type;
        this->name = name;
        this->sex = sex;
        this->price = price;
    }
    ~zoo() {}
    void show() {
        cout << "Animal:" << animal_type << "\n   Name:" << name << "\n   Sex:" << sex << "\n   Price:"<< price << endl;
    }
    void copy(string &animal_type,string &name,string &sex,float &price) {
        animal_type = this->animal_type;
        name = this->name;
        sex = this->sex;
        price = this->price;
    }
    void out_to_file(int i, ofstream &out_file) {
        out_file << i << ") " << animal_type << "\n" << name << "\n" << sex << "\n" << price << endl;
    }
};

int main()
{
    cout << "  ________   ________    ________ " << endl;
    cout << " /\\_____  \\ /\\   __  \\  /\\   __  \\ " << endl;
    cout << " \\/____/  / \\ \\  \\/\\  \\ \\ \\  \\/\\  \\ " << endl;
    cout << "      /  /   \\ \\  \\ \\  \\ \\ \\  \\ \\  \\ " << endl;
    cout << "     /  /____ \\ \\  \\_\\  \\ \\ \\  \\_\\  \\ " << endl;
    cout << "    /\\_______\\ \\ \\_______\\ \\ \\_______\\ " << endl;
    cout << "    \\/_______/  \\/_______/  \\/_______/  " << endl;
    int number = 0;
    string animal_type;
    string name;
    string sex;
    float price;
    list<zoo> zoo_list;
    string exit;
    while (exit!="exit") {
        cout << "Exit or command\nCommands:\nnew - new animal\nnew_in - new animal in the certain sequence\nshow - show all animals\ndel - delete animal\nfind - find animal\ncopy - copy animal\ndoc - take data from document\n::";
        cin >> exit;
        if (exit=="new") {
            number++;
            cout << "Animal type:";
            cin >> animal_type;
            cout << "Name:";
            cin >> name;
            cout << "Sex:";
            cin >> sex;
            while (true) {
                cout << "Price:";
                if (cin>>price) {
                    break;
                }
                else {
                    cout << "Wrong input\n";
                    cin.clear();
                    cin.ignore(price<=0,'\n');
                }
            }
            zoo_list.push_back(zoo(animal_type, name, sex, price));
        }
        else if (exit == "new_in") {
            int num;
            while (true) {
                cout << "Number after which the animal will be created:";
                if (cin >> num) {
                    break;
                }
                else {
                    cout << "Wrong input\n";
                    cin.clear();
                    cin.ignore(num <= 0, '\n');
                }
            }
            try{
                if (num >= number) {
                    throw "Wrong number\n";
                }
                cout << "Animal type:";
                cin >> animal_type;
                cout << "Name:";
                cin >> name;
                cout << "Sex:";
                cin >> sex;
                while (true) {
                    cout << "Price:";
                    if (cin >> price) {
                        break;
                    }
                    else {
                        cout << "Wrong input\n";
                        cin.clear();
                        cin.ignore(price <= 0, '\n');
                    }
                }
                number++;
                auto it = zoo_list.begin();
                for (int i = 0; i < num; i++) {
                    it++;
                }
                zoo_list.emplace(it, zoo(animal_type, name, sex, price));
            }
            catch (const char *a) {
                cout << a;
            }
        }
        else if (exit=="show") {
            cout << endl;
            int i=1;
            for (auto it = zoo_list.begin(); it != zoo_list.cend();it++) {
                cout << i <<") ";
                it->show();
                i++;
                cout << endl;
            }
            cout << "Number of animals:" << zoo_list.size() << endl << endl;
        }
        else if (exit=="find") {
            int num;
            while (true) {
                cout << "Number of deleting animal:";
                if (cin >> num) {
                    break;
                }
                else {
                    cout << "Wrong input\n";
                    cin.clear();
                    cin.ignore(num <= 0, '\n');
                }
            }
            try {
                if (num>number) {
                    throw "a";
                }
                cout << endl;
                auto it = zoo_list.begin();
                for (int i = 0; i < num-1; i++) {
                    it++;
                }
                cout << num << ") ";
                it->show();
                cout << endl;
            }
            catch (...) {
                cout << "Wrong number\n";
            }
        }
        else if (exit=="del") {
            int num;
            while (true) {
                cout << "Number of deleting animal:";
                if (cin>>num) {
                    break;
                }
                else {
                    cout << "Wrong input\n";
                    cin.clear();
                    cin.ignore(num<=0,'\n');
                }
            }
            try {
                if (num > number) {
                    throw "Wrong number\n";
                }
                auto it = zoo_list.begin();
                for (int i = 0; i < num-1; i++) {
                    it++;
                }
                zoo_list.erase(it);
                number--;
            }
            catch (const char *a) {
                cout << a;
            }
        }
        else if (exit=="copy") {
            int num;
            while (true) {
                cout << "Enter the animal number to copy:";
                if (cin >> num) {
                    break;
                }
                else {
                    cout << "Wrong input\n";
                    cin.clear();
                    cin.ignore(num <= 0, '\n');
                }
            }
            try {
                if (num>number) {
                    throw "Wrong number\n";
                }
                number++;
                auto it = zoo_list.begin();
                for (int i = 0; i < num - 1; i++) {
                    it++;
                }
                it->copy(animal_type, name, sex, price);
                zoo_list.push_back(zoo(animal_type, name, sex, price));
            }
            catch(const char *a){
                cout << a;
            }
        }
        else if (exit=="doc") {
            string file;
            cout << "File name: ";
            cin >> file;
            char buff[100];
            ifstream fin(file);
            if (!fin.is_open()) {
                cout << "Error: file won't open or not found\n\n";
            }
            else {
                string data[4];
                for (int i = 0; fin >> buff; i++) {
                    cout << "Frist line: ";
                    for (int j = 0; j < 4; j++) {
                        fin >> buff;
                        data[j] = buff;
                        cout << data[j] << " ";
                    }
                    cout << endl;
                    animal_type = data[0];
                    sex = data[1];
                    name = data[2];
                    price = stof(data[3]);
                    number++;
                    zoo_list.push_back(zoo(animal_type, name, sex, price));
                }
                fin.close();
                cout << endl;
            }
        }
        else if (exit == "exit") {}
        else {
            cout << "Error: Wrong command\n";
        }
    }
    string Yes_No;
    bool Yes_No_bool = true;
    while (Yes_No_bool) {
        cout << "Do you want to save the data file?(Yes, No) " << endl;
        cin >> Yes_No;
        if (Yes_No == "y" || Yes_No == "Yes" || Yes_No == "yes" || Yes_No == "YES" || Yes_No == "yES" || Yes_No == "yEs" || Yes_No == "yeS") {
            string file;
            cout << "File name for data recording: ";
            cin >> file;
            ofstream out_file(file, ios_base::out | ios_base::trunc);
            auto it = zoo_list.begin();
            for (int i = 1; i < zoo_list.size()+1; i++) {
                it->out_to_file(i,out_file);
                it++;
            }
            Yes_No_bool = false;
        }
        else if (Yes_No == "n" || Yes_No == "N" || Yes_No == "No" || Yes_No == "no" || Yes_No == "NO" || Yes_No == "nO") {
            cout << "Exiting" << endl;
            Yes_No_bool = false;
        }
        else {
            cout << "Wrong command, re-enter\n\n";
        }
    }
    return 0;
}
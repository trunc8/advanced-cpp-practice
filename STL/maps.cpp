#include <iostream>
#include <map>
using namespace std;

int main() {    
    cout << "---------Start of program----------\n\n\n";
    
    map<string, int> ages;
    ages["Tintin"] = 25;
    ages["Peter"] = 10;
    ages["Raghu"] = 20;

    map<string, int>::iterator it;


    string name;
    int age;
    bool ret;
    // int elem, insert_index, erase_index, list_index;
    // vector<int> list_contents;
    // ofstream out_file;
    // ifstream in_file;
    // string filename = "list_contents.bin";

    cout << "-Initial map-" << endl;
    for (it=ages.begin(); it!=ages.end(); it++) {
        cout << it->first << ": " << it -> second << endl;
    }

    int choice=-1;
    while (choice!=0) {
        
        name = "";
        age = 0;
        ret = 0;

        cout << "\n--------New turn---------\n"
            "CHOICES\n"
            "0: Exit\n"
            "1: Insert person\n"
            "2: Erase person\n"
            "3: Update person age\n"
            "4: Search person\n"
            "Any other integer views the map\n\n";
        cout << "Please enter an integer choice: ";
        cin >> choice;
        cout << "\n--------Output---------\n";

        switch (choice) {
        case 1:
            cout << "Please enter person name to insert: ";
            cin >> name;
            cout << "Please enter person age: ";
            cin >> age;
            if (ages.find(name)==ages.end()) {
                ages[name] = age;
                cout << name << " inserted successfully\n";
            }
            else {
                cout << name << " already exists\n";
            }
            
            break;

        case 2:
            cout << "Please enter person name to erase: ";
            cin >> name;

            ret = ages.erase(name);
            
            if (ret) {
                cout << name << " erased successfully\n";
            }
            else {
                cout << name << " does not exist\n";
            }
            
            break;

        case 3:
            cout << "Please enter person name to update: ";
            cin >> name;
            cout << "Please enter person age: ";
            cin >> age;
            if (ages.find(name)!=ages.end()) {
                ages[name] = age;
                cout << name << " updated successfully\n";
            }
            else {
                cout << name << " does not exist\n";
            }
            
            break;

        case 4:
            cout << "Please enter person name: ";
            cin >> name;
            
            if (ages.find(name)!=ages.end()) {
                cout << name << " found! Age: " << ages[name] << endl;
            }
            else {
                cout << name << " does not exist.\n";
            }            
            
            break;

        default:
            break;

        }
        
        cout << "\n\n-Current map-" << endl;
        for (it=ages.begin(); it!=ages.end(); it++) {
            cout << it->first << ": " << it -> second << endl;
        }
        cout << endl;

        
    }

    cout << "\n\n---------End of program----------\n";

    return 0;
}

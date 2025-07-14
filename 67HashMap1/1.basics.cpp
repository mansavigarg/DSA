#include<iostream>
using namespace std;

int main(){
    
    //$ Creation
    unordered_map<string, int> mapping;

    //$ Pair creation
    pair<string, int> p = make_pair("Manu", 22);

    pair<string, int> q("Shivi", 20);

    pair<string, int> r;
    r.first = "Shivani";
    r.second = 20;

    pair<string, int> s = {"Mansavi", 25};

    //$ Inserion
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping.insert(s);
    mapping["newmapping"] = 55;

    //$ Size
    cout << "Size of map: " << mapping.size() << endl;

    //$ Access of values
    cout << mapping.at("Shivi") << endl;
    cout << mapping["Shivi"] << endl;

    //$ Searching
    cout << mapping.count("Shivi") << endl;
    // count will return 1 if the key is present in map otherwise if not present then returns 0

    if(mapping.find("Shivi") != mapping.end()){
        cout << "Found in map" << endl;
    }else cout << "Not found in map." << endl;

    return 0;
}
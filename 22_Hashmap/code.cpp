#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

//Implementation of Hashmap/Hashing
int main() {
    cout<<endl<<"---Hashmap/Hashing Implementaion---"<<endl;

    //Creation : (ordered map)map complexity O(log n) : unordered_map complexity O(1)
    //when we'll use unordered_map then data will print in random order And for map it prints in the order we write/defined it
    //unordered_map<string, int> m;
    map<string, int> m;

    //Insertion
    //1st way
    pair<string, int> p = make_pair("Vicky", 3);
    m.insert(p);

    //2nd way
    pair<string, int> pair2("chaudhary", 2);
    m.insert(pair2);

    //3rd way
    m["jee"] = 1;

    //if we write again then it will update not create one
    m["jee"] = 2;


    //Searching
    cout<<"Corespending value: "<< m["jee"] <<endl;
    cout<<"Corespending value: "<< m.at("Vicky") <<endl;
    
    cout<<"Searching unknown key: "<< m["unknown key"] <<endl; //it will give 0 : it will create new key and assign with 0
    cout<<"Searching unknown key: "<< m.at("unknown key") <<endl; //it will give error because this key does'nt exist : But when print after above line then it will give 0
    
    cout<<"Size: "<< m.size() <<endl;

    //To check this key is present or not, we'll use count function
    cout<<"Key is present or not: "<< m.count("Vicky") <<endl;

    //For deletion we'll use erase function
    m.erase("Vicky");
    cout<<"After erasing, size: "<< m.size() <<endl;

    //Accessing/Printing using for each loop
    cout<<endl<<"---Printing the elements---"<<endl;
    for(auto i : m) {
        cout<< i.first <<" "<< i.second <<endl;
    }

    //Printing by creating iterator
    cout<<"Printing using iterator: "<<endl;
    //unordered_map<string,int> :: iterator i = m.begin();
    map<string,int> :: iterator i = m.begin();
    while(i != m.end()) {
        cout<< i->first <<" "<< i->second <<endl;
        i++;
    }

    return 0;
}
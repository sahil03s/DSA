#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

void print(unordered_map<string, int> &mp)
{
    for(auto &[str, freq] : mp)
        cout << str << "\t" << freq << endl;

    cout << "\n\n";
}

int main()
{
    unordered_map<string, int> m;

    //insertion 1
    pair<string, int> pair1 = make_pair("Sahil",3);
    m.insert(pair1);

    //insertion 2
    pair<string, int> pair2("Singh",7);
    m.insert(pair2);

    //insertion 3
    m.insert({"Singh",10}); //does nothing as Singh is already present

    //if key is not present, it inserts <key, value> pair. Else if it is present, it updates its value
    m["good"] = 4;

    print(m);

    m["good"] = 10; //updates the value mapped with key = "good"
    print(m);

    //size of the map
    cout << "size = " << m.size() << endl;
    
    //m[key] returns the value associated with the key if present. 
    //If not present, it inserts pair (key, 0) into map
    cout << m["abc"] << endl;

    //m.at(key) returns the value associated with the key if it is present. 
    //If not present, it throws error.
    cout << m.at("abc") << endl;

    cout << "size = " << m.size() << endl << endl;
    print(m);

    //m.count(key) returns 1 if key is present in the map and returns 0 if key is not present
    cout << m.count("Sahil") << endl;
    cout << m.count("Sumit") << endl;

    //removes corresponding (key, value) pair
    m.erase("Sahil");

    cout << endl;

    //iterating over the map
    for(auto &i : m)
        cout << i.first << "\t" << i.second << endl;

    cout << endl;


    //another way of iteration
    for(auto [key, value] : m)
        cout << key << "\t" << value << endl;
    
    cout << endl;
    
    //iterating using the iterator
    unordered_map<string, int>::iterator it = m.begin();

    while(it != m.end())
    {
        cout << it->first << "\t" << it->second << endl;
        it++;
    }
    
    cout << endl;






    return 0;
}

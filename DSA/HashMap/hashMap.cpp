#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;

    // insert
    pair<string, int> p = make_pair("clg", 4);
    m.insert(p);
    pair<string, int> p2("chutiya", 3);
    m.insert(p2);
    m["mera"] = 1;

    // search
    cout << m["clg"] << endl;
    cout << m.at("mera") << endl;

    // cout<<m.at("kbg")<<endl;
    // cout<<m["kbg"]<<endl;

    // size
    cout << m.size() << endl;

    // check presence of key
    cout << m.count("mera") << endl;

    // erase
    // cout<<m.erase("mera")<<endl;;

    // print the map
    for (auto i : m)
    {
        cout << i.first << " --> " << i.second << endl;
    }

    // using iterator

    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " --> " << it->second << endl;
        it++;
    }

    return 0;
}
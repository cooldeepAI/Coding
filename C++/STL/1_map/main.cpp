#include <iostream>
#include <iterator>
#include <map>

using namespace std;

/**
 * 1. Some basic functions associated with Map:
 *
 * begin() – Returns an iterator to the first element in the map
 * end() – Returns an iterator to the theoretical element that follows last element in the map
 * size() – Returns the number of elements in the map
 * max_size() – Returns the maximum number of elements that the map can hold
 * empty() – Returns whether the map is empty
 * pair insert(keyvalue, mapvalue) – Adds a new element to the map
 * erase(iterator position) – Removes the element at the position pointed by the iterator
 * erase(const g)– Removes the key value ‘g’ from the map
 * clear() – Removes all the elements from the map
 *
 */

int main() {
    // create an empty map container
    map<int, int> a_map;

    // insert elements in random order
    a_map.insert(pair<int, int>(1, 40));
    a_map.insert(pair<int, int>(2, 30));
    a_map.insert(pair<int, int>(3, 60));
    a_map.insert(pair<int, int>(4, 20));
    a_map.insert(pair<int, int>(5, 50));
    a_map.insert(pair<int, int>(6, 50));
    a_map.insert(pair<int, int>(7, 10));

    // for loop output
    cout << "****************** for loop output **********************" << endl;a_map.insert(pair<int, int>(2, 30));
    cout << "The map a_map is: " << endl;
    cout << "\tKEY\tELEMENT" << endl;
    for(pair<int, int> num : a_map){
        cout << '\t' << num.first
             << '\t' << num.second << endl;
    }

    //iteration loop output
    cout << "****************** iteration loop output **********************" << endl;a_map.insert(pair<int, int>(2, 30));
    map<int, int>::iterator itr;
    cout << "The map a_map is: \n";
    cout << "\tKEY\tELEMENT\n";
    for(itr = a_map.begin(); itr != a_map.end(); ++itr){
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    return 0;
}
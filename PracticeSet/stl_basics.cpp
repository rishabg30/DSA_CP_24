#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}
/*-------------------Write code downwards--------------------------------------------------------------*/

signed main()
{
    //Basics of STL

    //vectors: dynamic arrays with the ability to insert elements or pop elements from the back.
    //no need to specify the size in the beginning
    cout << "Vector: " << endl;
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printArray_1D(v);

    v.pop_back(); //removes last element of vector
    printArray_1D(v);


    //queue [FIFO: first in first out]
    cout << "Queue: " << endl;
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << " " << endl; //prints the first element of the queue
    q.pop(); //removes topmost [first] element of the queue
    cout << q.front() << " " << endl;

    //pair [used to store pair of elements]
    cout << "Pair: " << endl;
    pair<int, int>p;
    p.first = 10;
    p.second = 20;
    cout << p.first << " " << p.second << endl;

    //datatypes in pair can be different also
    pair<string, int>p2;
    p2.first = "Rishab";
    p2.second = 23;
    cout << p2.first << " " << p2.second << endl;
    //can be used to return multiple values from a function
    //can be used to associate two values together {wt,cost}

    //set [used in storing unique elements only in sorted order]
    //syntax - set<data_type>set_name
    //implemented using self-balancing-binary-search-trees [ofter red black trees]
    //insertion, deletion, search - O(logn) time
    cout << "Set: " << endl;
    set<int>s;
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(300); //do not include as it's a duplicate
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
    s.insert(400);
    s.erase(200); //removes element from a set
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
    //there is a count function present which return 0/1 whether element is present in set or not
    cout << "Is 100 present in set: " << s.count(100) << endl;
    cout << "Is 500 present in set: " << s.count(500) << endl;
    //s.clear(); //makes set empty

    //iterators in set: begin(), end()
    //iterator is the pointer to the element in the container
    //begin() - returns an iterator to the first element
    //end() - returns an iterator to the element after the last element
    //*iterator - returns value at the iterator
    //iterator++ - moves to the next element
    //iterator-- - moves to the previous element
    set<int>s2;
    s2.insert(1000);
    s2.insert(2000);
    s2.insert(3000);
    s2.insert(4000);
    auto it = s2.begin(); //gives the pointer pointing to first element of set
    cout << *it << endl; // returns value pointing to first element of set which is 1000
    it++;
    cout << *it << endl; //2000
    it--;
    cout << *it << endl; //1000
    auto it2 = s2.end();
    it2--;
    cout << *it2 << endl; //4000

    //way to iterate over the containers datatype [like set, map]
    for (auto it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    /*
    --------------Algorithms---------------
    */

    //sorting
    //sort() - sort the element of the container
    //sort(start_address, end_address)
    //end_address - address of the place after the last element.

    //sort(v.begin(), v.end()) - sorts v vector in ascending order
    //sort(v.begin(),v.end(),greater<int>()) - sorts v vector in descending order
    cout << "Sorting: " << endl;
    sort(v.begin(), v.end());
    printArray_1D(v);
    sort(v.begin(), v.end(), greater<int>());
    printArray_1D(v);

    //sort(v.begin(),v.end(),compare) - sort using custom compare functions
    vector<pair<int, int>>pairVectorForSort;
    pairVectorForSort.push_back({15, -2});
    pairVectorForSort.push_back({12, 1});
    pairVectorForSort.push_back({3, 4});
    pairVectorForSort.push_back({15, 10});
    //compare function
    //FOCUS ON THIS: return true if a should come before b

    //lets say we have pair{int,int} and asked to sort according to second value
    sort(pairVectorForSort.begin(), pairVectorForSort.end(), [](pair<int, int>&a, pair<int, int>&b) {
        if (a.second < b.second) {
            return true;
        }
        else return false;
    });
    //[{12,1},{15,10},{15,-2},{3,4}]
    //after sorting with respect to 2nd element
    //ans should be [{15,-2},{12,1},{3,4},{15,10}]
    //lets say we have comp(a = {12,1}, b = {15,-2})
    //(1 < -2) : returned false
    //FOCUS ON THIS: return true if a should come before b [therefore as we returned false a should not come before b]


    //lets solve a problem using these concepts
    vector<pair<string, int>>studentMarks;
    studentMarks.push_back({"Rishab", 87});
    studentMarks.push_back({"Khushi", 91});
    studentMarks.push_back({"Jatin", 69});
    sort(studentMarks.begin(), studentMarks.end());
    for (int i = 0; i < 3; i++) {
        cout << studentMarks[i].first << " " << studentMarks[i].second << endl; //sorted according to naming conventions
    }

    //what if we want to sort on basis of decreasing order of marks
    sort(studentMarks.begin(), studentMarks.end(), [](pair<string, int>&a, pair<string, int>&b) {
        if (a.second > b.second) {
            return true;
        }
        else return false;
    });
    for (int i = 0; i < 3; i++) {
        cout << studentMarks[i].first << " " << studentMarks[i].second << endl; //sorted according to naming conventions
    }

    //lower_bound() - returns iterator to first element >= x
    //upper_bound() - returns iterator to first element > x
    //both functions returns end if element is not present
    //O(logn) time complexity - implemented using binary search
    set<int>s3;
    s3.insert(11);
    s3.insert(12);
    s3.insert(23);
    auto it3 = s3.lower_bound(12);
    cout << "lower_bound of 12: " << *it3 << endl; //returns 12
    auto it4 = s3.upper_bound(15);
    cout << "upper_bound of 15: " << *it4 << endl; //returns 23
    auto it5 = s3.upper_bound(30);
    // cout << "upper_bound of 30: " << *it5 << endl; //returns garbage value

    //therefore instead of this, we can use find function to find exactly if element is present in set or not
    if (s3.find(23) != s3.end()) {
        cout << "23 is present" << endl;
    }
    else {
        cout << "23 is not present" << endl;
    }

    //multisets - can contain multiple copies of same element
    //syntax - multiset<data_type>multiset_name
    //insertion,deletion,search operations takes O(logN) time only
    //deleting all copies of a element takes O((logN) + K) time
    multiset<int>ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    for (auto it : ms) {
        cout << it << " "; //1,2,3
    }
    cout << endl;
    ms.insert(2);
    for (auto it : ms) {
        cout << it << " "; //1,2,2,3
    }
    cout << endl;
    ms.erase(2); //erases all copies of 2
    for (auto it : ms) {
        cout << it << " "; //1,3
    }
    cout << endl;
    //here count() function is useful as it returns number of copies of a element
    ms.insert(3);
    cout << ms.count(3) << endl;

    //what if, we want to delete only 1 copy of a element
    auto it_d = ms.lower_bound(3);
    ms.erase(it_d);
    for (auto it : ms) {
        cout << it << " "; //1,3
    }
    cout << endl;

    //maps : stores key,value pair
    //syntax: map<key_type,value_type>map_name
    //ofter implemented using self balancing binary search trees
    //insertion,deletion,search in O(logN) time
    cout << "Maps: " << endl;
    map<string, int>mp;

    //lets say we have a list of colors
    //count counts with their frequencies
    vector<string>colors = {"red", "blue", "red", "yellow", "yellow", "red"};
    for (auto it : colors) {
        mp[it]++;
    }

    //iterating over a map
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
    auto it_m = mp.find("orange");
    cout << it_m->second << endl; // error throws a garbage value as orange is not present similar to set
}
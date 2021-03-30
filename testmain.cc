#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std; 
#include "FileGetter.cpp"


int main() 
{ 
    /*vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
  
    sort(v.begin(), v.end(), greater<int>()); 
  
    cout << "Sorted \n"; 
    for (auto x : v) 
        cout << x << " "; 
  
    return 0; 

    FileGetter turnip = FileGetter("testtext.txt");
    FileGetter("emptytext.txt");
*/
    string testname;
    //cout << "Please intput file name: ";
    //cin >> testname;

//    ifstream filenameText(testname);

    string tname;
    FileGetter rasberry;
    cout << "Please intput file name2: ";
    cin >> tname;
    rasberry.setName(tname);
    cout << "The selected ext is called: " << rasberry.getName() << endl;
} 
#include <iostream>
#include <fstream>

using namespace std;

#ifndef FileGetter_H
#define FileGetter_H



class FileGetter
{
    public:
        //Constructor with nothing in it- it exists
        //FileGetter()=delete;

        FileGetter();
        FileGetter(std::string filename_with_text);
        void setName(string fname);
        string getName();

    private:
        std:: unordered_map<string, vector<int>> filetext;
        std:: string filename_;

};


#endif
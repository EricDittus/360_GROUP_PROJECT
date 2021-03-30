// reading a text file

#include <string>
#include <unordered_map>
#include <vector>
using namespace std; 

#include "FileGetter.h"
#ifndef FileGetter_C
#define FileGetter_C

FileGetter::FileGetter(){
    filename_= "";
}

FileGetter::FileGetter(std::string filename_with_text){
    filename_ = filename_with_text;

    //---------------------------------//
    //--------   Check Input   --------//
    //---------------------------------//

    std::fstream FwTex;
    FwTex.open (filename_with_text, std::fstream::in | std::fstream::out | std::fstream::app);
    if (filename_with_text.empty() != false) {
        cerr << "Can't open text file  / file is empty" << filename_with_text << endl;
        cout << "line reached" << endl;
        exit(1);
    }



    //---------------------------------//
    //-- Make unordered_map text --//
    //---------------------------------//

    std::ifstream filenameText(filename_with_text);
    std::cout << filenameText.is_open() << "\n";

    char chrtr;                   
    std::string teststring;
    vector<int> countof(1);
    countof[0] = 1;            //if the vector gets called at all its because there is at least 1 version of it in file.
                                //number of lines starts at 1
    
    filetext.insert({"new line", countof});


    while (filenameText.get(chrtr)){         // loop getting single characters
        if(isalpha(chrtr))         // is the character part of the alphabet?
        {
        teststring+=chrtr;          //add character to teststring
        }
        else
        {
        if (chrtr == '\n')
        {
            int pineL = filetext.find("new line")->second.at(0);
            pineL++;
            filetext.find("new line")->second.at(0) = pineL;
        }
        
        for (auto& x: {teststring}) {
            if (filetext.count(x)>0){
            
            int pine = filetext.find(teststring)->second.at(0);
            pine++;
            filetext.find(teststring)->second.at(0) = pine;
            }
        }
        filetext.insert({teststring, countof});
        
        teststring.clear();
        }
    }

    filenameText.close(); //we are no longer in the filetext file

    //there could still be 1 word left in file- this is to get that last word
    for (auto& x: {teststring}) {
            if (filetext.count(x)>0){
            int pine = filetext.find(teststring)->second.at(0);
            pine++;
            filetext.find(teststring)->second.at(0) = pine;
            }
        }
    filetext.insert({teststring, countof});
    teststring.clear();

    cout << "print this " << endl;
}

void FileGetter::setName(string fname){
    filename_ = fname;
}

string FileGetter::getName(){
    return filename_;
}
#endif
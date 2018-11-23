/**

// basic file operations
#include <iostream>
#include <fstream>
using namespace std;


// to transform an int to a string
string str(int n) {
    stringstream ss;
    ss << n;
    string s = ss.str();
    return s;
}

//have a different text file for each level
// so the arguments are the string that desribes the level
// and the level number
//file name will be by ex : "level1.txt"

//problem here we must have created all the files in advance!!!
// bc this function only writes in a file it does not create it 

void add_level(string text, int levelnb){
    ofstream myfile;
    myfile.open (strcat(str("level",str(levelnb),".txt")));
    my file << text;
    my file << "\n";
    myfile.close();
    return 0;
}

//this must return the text string that is in the file
string get_level (int levelnb){
    ifstream myReadFile;
    myReadFile.open(strcat(str("level",str(levelnb),".txt")));

    string temp;

    if (myReadFile.is_open()) {
    while (!myReadFile.eof()) {
        getline (myReadFile, temp); 
    }
    }
    myReadFile.close();
    return temp;
}


int main () {
  
  return 0;
}

**/

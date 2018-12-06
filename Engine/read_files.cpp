#include <iostream>
#include <fstream>
using namespace std;

//QUESTION: what is thwe type of the object we are putting in the matrix that represents each level?



//THE FILE NAME IF "LEVEL1.TXT"
// the file is presneted as follows:
// first line holds three integers: height length boxsize
// then we have the matrix describing the level

//STORE MATRIX WITH 0,0 AT TOP LEFT

vector<string>get_level (int levelnb){

    ifstream myReadFile;
    myReadFile.open(strcat(str("level",str(levelnb),".txt")));
    string line;
    vector<string> lines;

    if (myReadFile.is_open()) {
    while (!myReadFile.eof()) {
        getline (myReadFile, line);
        lines.push_back(line);
    }
    }
    myReadFile.close();
    return lines;
}


vector<int> first_line (vector<string> lines){
    string first= lines[0];
    int i =0;
    vector<int> allthree;

    for (int k=0; k<3; k++){
        int j=i+1;
        while (first[j]!=' '){
            j++; }

        allthree.push_back(first.substr(i,j-1));  //check if j is included in
        i=j+1;
     }


    return allthree;
//this is a list, at index o is the height ondex 1 the length and index 2 the boxsize
}

object read_rest(vector<string> lines,vector<int> allthree){
    int height=allthree[0];
    int length=allthree[1];
    //now we can built the matrix

    object mat [height][length];     //IS THIS THE GOOD TYPE TO STORE ALL POSSIBLE OBJECTS IN THE LEVEL?

    object trans;

    lines.erase(lines.begin());   //to remove first line we have already delt with
    char character;
    for (int i=0; i < height; i++) {
        for (int j=0; j<length; j++){  // A LINE IS STORED AS CHARACTER SPACE CHARACTER SPACE... IF ONLY CHARACTER CHARCATER.. CHANGE +2 TO +1
            character=lines[i].substr(j, j+1); //OR [j]
            //HERE TRANSLATE CHARACTER INTO OBJECT AND PLACE IT IN MATRIX THAT REPRESENTS LEVEL its pos in the matrix is i,j
            // we build the level line by line stating atc 0 which will be the groung but in the representation is at the top
            trans=translate(character);          //MUST WRITE FUNCTION TRANSLATE
            mat[i][j]=trans;
        }

    return mat
}

//IF WORKS WELL ADD POINTER TO PERAMETERS

object translate (char character){
    object=trans;
    //use  case rather than a bunch of for loops!

    switch(character){

        case a:
        return //the object corresponding to a!!!
        break;

        case b:


    }


    /* STRUCTURE:
    switch(expression) {
   case constant-expression  :  //constant-expression is the thing expression will be compared to
      statement(s);
      break; //put this!!! to exit switch once you have found correspondance
   case constant-expression  :
      statement(s);
      break; //optional

   // you can have any number of case statements.
   default : //this is if you found no correspondance
      statement(s);  */
}


    return trans;
}
//must decide on code from ASCII the correspondance to the objects we have created:
//here are the objects that need to have a code, must fill in the ASCII correspondance when we have it and build
// the function "TRANSLATE"

//REPLACE MY CODE WITH ASCII each should have only 1 character
// 0--> empty
// 1 block category      11--> block permanant  12--> block alive      13--> block active
// 2 projectile category 211--> baguette alive  212--> baguette dead   213--> baguette vanish
//                       221--> smoke alive     222-> smoke dead       223--> smoke vanish
//                       231--> wine alive      232--> wine dead       233--> wine vanish
// 3 collectables categ  31 --> coin            32--> powerup



int main(){
    int levelnb;
    cin<< levelnb;
    vector<string> lines= get_level (levelnb)
    vector<int> allthree = first_line (lines)
    object mat = read_rest(lines,allthree)

}

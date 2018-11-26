#include <QApplication>
#include "object.h"
#include "screen.h"

Screen* screen;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    screen = new Screen();

    screen->show();

    return application.exec();
}



/**
 AGATHE's STUFF


#include <iostream>



//structure: this will return a matrix descrining a level this will be translated to a string
// so then write it in a level txt file

//legend: the idea is that a colomn of the matrix is a colomn of the game its height is 10
// the length og=f the game ie the nb of colomns myst be given
// then the lists as composed of integers which each represent =something

// legend:
// 0--> empty
// 1 block category      11--> block permanant  12--> block alive      13--> block active
// 2 projectile category 211--> baguette alive  212--> baguette dead   213--> baguette vanish
//                       221--> smoke alive     222-> smoke dead       223--> smoke vanish
//                       231--> wine alive      232--> wine dead       233--> wine vanish
// 3 collectables categ  31 --> coin            32--> powerup

//--TO DO FUNCTION WHICH TRANSLATED THE CNUMBER INTO THE OBJECT IT REPRESENTS




//create the matrix and set every thing to 0 ie empty

int create_matrix(int length ){
    int mat [10][length];

    //setting everything to 0 well allow to have every unchanged block already set to empty
    for (int j=0; j<10; j++){
        for (int i=0; i<length; i++){
            mat [j][i]=0;
    }
    }
}


// this function creates a defaul floor the 2 bottom boxes are by defaut s=floor block or permanant blocks
// attention they have index 8 and 9 not 0 and 1
// the marameter L is a list of the exceptions. it gives the coorf=dinates at which by default there
//is a floor block but for this particular level we do not want one
// exception is an array of pairs. it is a length "length" ie will be mostly empty

//--TO FIX: HOW CAN I NOT HAVE TO GIVEW THE LENGTH OF EXCEPTION--
int create_floor (int length, int mat [10][length], int exceptions[length]){

    // put all the floor blocks then we will remove them
    for (int i=0; i<length; i++){
        mat[0][i]=11;
        mat [1][i]=11;
}

// REMOVE EXCEPTIONS
    std::list<exceptions>::iterator it;
    // -- CHECK IF ITERATION WORKS--
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    for (it = exceptions.begin(); it != exceptions.end(); it++){
        int x=it.first;
        int y= it.first;
        mat[x][y]=0;
    }

}


// this will allow to create each colomn by typing into the consol the code
// in parameters we specify which colomn we are creating
// since the floor blocks have already bden designed we do not do them again

int create_colomn (int mat, int col_nb){
    std::cout << "Enter one by one elements of the colomn starting at index 0 (the top): "<< std::endl;
    for (int j=0; j<8; j++){
        std::cout << "enter element at index "<< j << std::endl;
        std:: cin>> mat[j][col_nb];
    }

}

int main(){
    int length, height, boxsize;
    std::cout << "Enter length, width and box size for the level" <<std::endl;
    std::cin >> height >> length >> boxsize;
    // we had decided height =10 but alexis changed that
    // he aslso said the boxsize would be usefull
    create_matrix(length);
    int exceptions
    std::count << "Enter list of pairs of exceptions for the floor" << std::endl;
    std::cin >> exceptions;
    create_floor (length, mat[10][length], exceptions[length])

    for(int i=0, i<length, i++){
       create_colomn (mat, i)
    }
}

**/



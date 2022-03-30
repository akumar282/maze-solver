#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "maze.h"

using namespace std;

class Creature { 
    public: 

        //Creature();
        Creature(int row, int column); // constructor for creature
        //Creature(const Creature &other);
        
        string Solve(Maze &maze); //solve method 

        //all four directional methods
        string goNorth(Maze &maze);
        string goSouth(Maze &maze);
        string goWest(Maze &maze);
        string goEast(Maze &maze); 


        bool isExit(Maze &maze); // check if at exit

        //getter for row and column 
        int getRow() const; 
        int getColumn() const;

        //ostream for creature
        friend ostream &operator<<(ostream &output, const Creature &creature);
    
    private:
        int row; 
        int column;
        string Path; //path variable to display
};




#endif 
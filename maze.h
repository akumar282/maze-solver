/* Abhimanyu Kumar 
* This file is the header for the Maze class
*
*/
#ifndef MAZE_H
#define MAZE_H

#include <iostream> 


using namespace std; 

class Maze { 
    public:

        friend class Creature;

        explicit Maze(string &mazeFile); 
        //Maze(const Maze &other);

        bool IsClear(int row, int column) const; //check if path is clear
        bool IsWall(int row, int column) const; // check if its a X
        bool IsPath(int row, int column) const; // check if its a *
        bool IsVisited(int row, int column) const; // check if its a +

        void MarkAsPath(int row, int column); // mark location with *
        void MarkAsVisited(int row, int column); //mark location with +
        
        friend ostream &operator<<(ostream &out, const Maze &maze); //ostream for maze


    private:

        static const int MAX_SIZE = 100; //define max size 
        char field[MAX_SIZE][MAX_SIZE]; //2D char array with max size 100
        int width;
        int height; 
        int exRow;
        int exColumn;

};

#endif 

/*
*/
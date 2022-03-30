/* Abhimanyu Kumar ;
* This file contains all the implentations for the Maze functions
*/
#include <iostream>
#include <fstream>
#include "maze.h"
using namespace std; 

// main constructor for Maze class
Maze::Maze(string &mazeFile){
    try{               //use a try catch block to open file
        ifstream inFile;
        inFile.open(mazeFile);
        string temp;
        inFile >> width >> height; // read in maze specs 
        inFile >> exRow >> exColumn;
        getline(inFile, temp);
        for(int i = 0; i<height; i++){ // read maze into 2D array 
            for(int j = 0; j<width; j++){
                inFile.get(field[i][j]);
            }
        getline(inFile, temp);  
        }
        inFile.close(); // close file 
    } catch (out_of_range const&) {  //if file is not opened catch and display message
        cerr << "File was not opened";
    }
}
//check if path is clear 
bool Maze::IsClear(int row, int column) const{
    return field[row][column] == ' ';
}
//check if there is a wall
bool Maze::IsWall(int row, int column) const{
    return field[row][column] == 'X';
}
// check if you are on a registered path 
bool Maze::IsPath(int row, int column) const{
    return field[row][column] == '*';
}
// check if you have visited this location before
bool Maze::IsVisited(int row, int column) const{
    return field[row][column] == '+';
}
//mark maze with * if correct path
void Maze::MarkAsPath(int row, int column){
    field[row][column] = '*'; 
}
// mark maze with + if have visited location
void Maze::MarkAsVisited(int row, int column){ 
    field[row][column] = '+';
}

// output the maze 
ostream &operator<<(ostream &output, const Maze &maze){
    for(int i = 0; i<maze.height; i++){
            for(int j = 0; j<maze.width; j++){
                output<< maze.field[i][j];
            }
            output << endl;
        }
        return output;
}



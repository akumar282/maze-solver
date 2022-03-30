/* Abhimanyu Kumar 
* This file contains all the impementations of the creature functions
*/
#include <iostream>
#include <fstream>
#include "creature.h"
using namespace std; 

//constructor for creature
Creature::Creature(int row, int column): row(row), column(column){
    Path = ""; //intialize the path to be empty

}
// directional method to go north or up
string Creature::goNorth(Maze &maze){
    if(maze.IsClear(row - 1, column)){
        row--; 
        Path.append("N"); //add direction to path string if it works
        maze.MarkAsPath(row, column);
        if(isExit(maze)){
            return Path;
        } else {  // if it doesnt work call other directions
            Path = goNorth(maze);
            if(!isExit(maze)){
                Path = goEast(maze);
                if(!isExit(maze)){
                    Path = goWest(maze);
                    if(!isExit(maze)){
                        maze.MarkAsVisited(row, column); //mark with +
                        row++;
                        Path.erase(Path.size()-1);
                    }
                }
            }
        }
    }
    return Path;
}
// directional method to go south
string Creature::goSouth(Maze &maze){
    if(maze.IsClear(row + 1, column)){
        row++; 
        Path.append("S"); //add direction to path string if it works
        maze.MarkAsPath(row, column);
        if(isExit(maze)){
            return Path;
        } else {  // if it doesnt work call other directions
            Path = goSouth(maze);
            if(!isExit(maze)){
                Path = goEast(maze);
                if(!isExit(maze)){
                    Path = goWest(maze);
                    if(!isExit(maze)){
                        maze.MarkAsVisited(row, column); //mark with +
                        row--;
                        Path.erase(Path.size()-1);
                    }
                }
            }
        }
    }
    return Path;
}
// directional method to go west
string Creature::goWest(Maze &maze){
    if(maze.IsClear(row, column-1)){
        column--; 
        Path.append("W"); //add direction to path string if it works
        maze.MarkAsPath(row, column);
        if(isExit(maze)){
            return Path;
        } else { // if it doesnt work call other directions
            Path = goWest(maze);
            if(!isExit(maze)){
                Path = goSouth(maze);
                if(!isExit(maze)){
                    Path = goNorth(maze);
                    if(!isExit(maze)){
                        maze.MarkAsVisited(row, column); //mark with +
                        column++;
                        Path.erase(Path.size()-1);
                    }
                }
            }
        }
    }
    return Path;

}
// directional method to go east or right
string Creature::goEast(Maze &maze){
    if(maze.IsClear(row, column + 1)){
        column++; 
        Path.append("E"); //add direction to path string if it works
        maze.MarkAsPath(row, column);
        if(isExit(maze)){
            return Path;
        } else { // if it doesnt work call other directions
            Path = goEast(maze);
            if(!isExit(maze)){
                Path = goSouth(maze);
                if(!isExit(maze)){
                    Path = goNorth(maze);
                    if(!isExit(maze)){
                        maze.MarkAsVisited(row, column); //mark with +
                        column--;
                        Path.erase(Path.size()-1);
                    }
                }
            }
        }
    }
    return Path;
}
// solve function to solve the maze and return the path
string Creature::Solve(Maze &maze){
    //check if creature spawned on top of a wall or other illegal position
    if(!maze.IsClear(row, column)){ 
        Path.append("Creature Spawned at Invalid Location");
        return Path;
    }
    // check if creature spawned on top of the exit
    if(isExit(maze)){
        Path = "At Exit";
    }
    Path = goNorth(maze); //go through all the directions
    if(Path.empty()){ 
        Path = goSouth(maze);
        if(Path.empty()){
            Path = goEast(maze);
            if(Path.empty()){
                Path = goWest(maze);
            }
        }
    }
    //if there is no exit to the maze 
    if(!isExit(maze)){
        Path = "No exit";
    }
    return Path;
}
// check if creature is at the exit
bool Creature::isExit(Maze &maze){
    if(maze.exRow == row && maze.exColumn == column){
        return true; 
    }
    return false;
}
// getter method to get row 
int Creature::getRow() const{
    return row;
}
// getter method to get column
int Creature::getColumn() const{
    return column;
}
//ostream for creature to output
ostream &operator<<(ostream &output, const Creature &creature){
    output << "C(" << creature.row << creature.column << ")" << endl;
    return output;
}
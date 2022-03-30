/* Abhimanyu Kumar 
* This file is the driver responsible for testing the 
* functions of both the Maze and Creature class to solve a given
* maze in a text file
*/

#include <iostream>
#include "creature.h"
#include "maze.h"
// Provided test
void test1() {
    cout << "Test 1" << endl;
    string path = "maze.txt";
    Maze M(path);
    Creature C(2, 14); //creature spawn location
    cout << "Maze before: " << endl; //print mazes before solve
    cout << M << endl;
    cout << "Solved Maze: " << endl;  //print solved maze
    cout << "Path: " << C.Solve(M) << endl;
    cout << M << endl;
    cout << "" << endl; //formating space 
    cout << "" << endl;
}

void test2(){
    cout << "Test 2" << endl;
    string path = "maze.txt";
    Maze M(path);
    Creature C(0, 0); //creature spawn location
    cout << "Test for Invalid Spawn" << endl;
    cout << "Maze before: " << endl; //print mazes before solve
    cout << M << endl;
    cout << "Solved Maze: " << endl; //print solved maze
    cout << "Path: " << C.Solve(M) << endl;
    cout << M << endl;
    cout << "" << endl;
    cout << "" << endl;
}

void test3() {
    cout << "Test 3" << endl;
    string path = "maze0.txt";
    Maze M(path);
    Creature C(2, 7); //creature spawn location
    cout << "Maze before: " << endl; //print mazes before solve
    cout << M << endl;
    cout << "Solved Maze: " << endl; //print solved maze
    cout << "Path: " << C.Solve(M) << endl;
    cout << M << endl;
    cout << "" << endl;
    cout << "" << endl;
}

void test4() {
    cout << "Test 4" << endl;
    string path = "mazeNoExit1.txt";
    Maze M(path);
    Creature C(1, 6); //creature spawn location
    cout << "Maze before: " << endl; //print mazes before solve
    cout << M << endl;
    cout << "Solved Maze: " << endl; //print solved maze
    cout << "Path: " << C.Solve(M) << endl;
    cout << M << endl;
    cout << "" << endl;
    cout << "" << endl;
}

void test5() {
    cout << "Test 6" << endl;
    cout << "Second Test for no exit" << endl;
    string path = "mazeblock.txt";
    Maze M(path);
    Creature C(1, 1); //creature spawn location
    cout << "Maze before: " << endl; //print mazes before solve
    cout << M << endl;
    cout << "Solved Maze: " << endl; //print solved maze
    cout << "Path: " << C.Solve(M) << endl;
    cout << M << endl;
    cout << "" << endl;
    cout << "" << endl;
}

void test6() {
    cout << "Test 5" << endl;
    string path = "mazeSimple.txt";
    Maze M(path);
    Creature C(1, 6); //creature spawn location
    cout << "Maze before: " << endl; //print mazes before solve
    cout << M << endl;
    cout << "Solved Maze: " << endl; //print solved maze
    cout << "Path: " << C.Solve(M) << endl;
    cout << M << endl;
    cout << "" << endl;
    cout << "" << endl;
}

// Main test functions
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "Done!" << std::endl;
    return 0;
}
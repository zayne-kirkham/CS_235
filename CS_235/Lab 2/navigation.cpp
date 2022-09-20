#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Navigation.h"
using namespace std;


// This function reads in the contents of the file _mapName.
// The function can assume that the contents of the specified conform with the specs given in the README.txt file
// Returns true if the file is read in successfully, false otherwise
Navigation::readNetwork(string _mapName){
    
    ifstream input;
    input.open(_mapName);
    if (input.is_open()){
        num_nodes = (int) getline(input, 0);
        
        for (int i = 1; i <num_nodes+1; i++){
            cout << getline(input, i) << endl;
            // tasks.push_back(line);
        }
        // Closes the file
        input.close();
        return true;
    }
    else{
        // Escapes if there is no list file
        cout << _mapName << " not found" <<endl;
        return false;
    }
    
}


// This function computes and returns the least-cost path from node indexed _startInd to node indexed as _endInd
// for the map that was last read (in the readMap function).  The resulting path must be stored in an integer queue
// with each entry in the queue denoting the next node in the path.  First front of the queue should be _startInd
// and the back of the queue should be _endInd.
// For example, in map1.txt, solveMap(13, 1) should return the shortest path from node 13 to node 1, which is:
//      13, 9, 10, 7, 3, 2, 1
// You can assume that readNetwork(_mapName) is called before this function and that a path from _startInd to _endInd exists
Navigation::computeShortestPath(int _startInd, int _endInd){
    cout << endl;
}

// prints out to the console the path stored in _path
Navigation::printPath(queue<int> _path){
    cout << endl;
}
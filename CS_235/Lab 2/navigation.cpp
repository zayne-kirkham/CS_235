#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Navigation.h"
using namespace std;



// This function reads in the contents of the file _mapName.
// The function can assume that the contents of the specified conform with the 
// specs given in the README.txt file
// Returns true if the file is read in successfully, false otherwise
bool Navigation::readNetwork(string _mapName){
    
    ifstream input;
    input.open(_mapName);
    if (input.is_open()){
        // getline(input, num_nodes);
        string s;
        getline(input, s);
        num_nodes = stoi(s);
        
        string line;
        // Loops through each line of the network
        for (int i = 1; i < num_nodes+1; i++){
            getline(input, line);
            cout << line << endl;
            
            
            
            string delimiter = "  ";
            size_t pos = 0;
            int token;
            
            // loops through each entry in the line
            while ((pos = line.find(delimiter)) != string::npos) {
                token = stoi(line.substr(0, pos));
                cout << "token: " << token << endl;
                line.erase(0, pos + delimiter.length());

                // check if the link is valid
                if (token != -1){
                    // get primary node location
                    int node_location = i;
                    // get node link connection
                    int node_link = stoi(pos);
                    // get node link cost
                    int temp_cost = token;
                    // define node
                     
                    Node current;
                    current.cost = temp_cost;
                    current.path.push(node_location); //fixme
                    
                    // add node to priority queue
                    
                    myPriorityQueue.push(current);
                        
                    // myPriorityQueue.push(node)
                }
            }
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


// This function computes and returns the least-cost path from node indexed 
// _startInd to node indexed as _endInd
// for the map that was last read (in the readMap function).  The resulting path must be stored in an integer queue
// with each entry in the queue denoting the next node in the path.  First front of the queue should be _startInd
// and the back of the queue should be _endInd.
// For example, in map1.txt, solveMap(13, 1) should return the shortest path from node 13 to node 1, which is:
//      13, 9, 10, 7, 3, 2, 1
// You can assume that readNetwork(_mapName) is called before this function and that a path from _startInd to _endInd exists
queue<int> Navigation::computeShortestPath(int _startInd, int _endInd){
    
    //Define priority queue myPriorityQueue
    priority_queue<Node, vector<Node>, Node> myPriorityQueue;
    
    Node current;
    current.cost = 0;
    current.path.push(_startInd); //fixme
    
    // add node to priority queue
    
    myPriorityQueue.push(current);
    
    current = myPriorityQueue.top();
    myPriorityQueue.pop();
    
    while (current.path.back() != _endInd){
        //add new nodes to pq
        int curInd = current.path.back();
        for (int i=-, 9 < theCoords.size(); i++){
            
        }
    }
    
    
    cout << endl;
    return myPriorityQueue;
}

// prints out to the console the path stored in _path
void Navigation::printPath(queue<int> _path){
    cout << endl;
}
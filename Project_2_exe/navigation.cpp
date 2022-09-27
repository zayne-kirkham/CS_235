#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Navigation.h"
using namespace std;

queue<int> copy_queue(queue<int> to_copy){
    queue<int> temp;
//    cout << "copying " << endl;
    while(!to_copy.empty()){
//        cout << "to_copy.front(): " << to_copy.front()<< endl;
        temp.push(to_copy.front());
        to_copy.pop();
    }
    return temp;
}

// This function reads in the contents of the file _mapName.
// The function can assume that the contents of the specified conform with the 
// specs given in the README.txt file
// Returns true if the file is read in successfully, false otherwise
bool Navigation::readNetwork(string _mapName){
    
    ifstream input;
    input.open(_mapName);
    if (input.is_open()){
        string s;
        input >> num_nodes;
        
        int x;
        // Loops through each line of the network
        for (int i = 0; i < num_nodes; i++){
            vector<int> row;
            
            for(int j=0; j <num_nodes; ++j){
                int cur_int;
                input >> cur_int;
                //cout << cur_int << " ";
                row.push_back(cur_int);
            }
            theCosts.push_back(row);
            //cout << endl;
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
    // (1)   PriorityQueue<Node> PQ 
    priority_queue<Node, vector<Node>, Node> myPriorityQueue;
    
    //(2)  Create Node n, with n.cost = 0 and n.path = the start index 
    Node current;
    current.cost = 0;
    current.path.push(_startInd);

    //(4) Loop while the top Node in PQ does not contain a 
    //     path that ends in the destination
    while(current.path.back() != _endInd){
        
        //  (6)  Set last to be the last destination in current.path 
        int last = current.path.back();
        //cout <<"last: "<< last << endl;

        //  (7) For each neighbor j of last (i.e., Cost(last,j) > 0), 
        //         insert a new Node (denoted nn) into PQ
        for(int j = 0; j < num_nodes; j++){
            if(theCosts.at(last).at(j) > 0){
                Node nn;

                // nn.cost = current.cost+Cost(last,j)
                nn.cost = current.cost + theCosts.at(last).at(j);

                // Copy path
                nn.path = copy_queue(current.path);
                nn.path.push(j);

                //Add to priority queue
                myPriorityQueue.push(nn);
            }
        }
        //  (5) Pop the top item off the priority queue and
        //   store it in current (see programming hint 3)

        if(!myPriorityQueue.empty()) {
            current = myPriorityQueue.top();
            myPriorityQueue.pop();
        }
    }

    // (8)   Return the path (which is a queue of integers) of the top Node in PQ
    return current.path;
}

// prints out to the console the path stored in _path
void Navigation::printPath(queue<int> _path){
    while(!_path.empty()){
        cout <<_path.front() << " ";
        _path.pop();
    }
        
    cout << endl;
}
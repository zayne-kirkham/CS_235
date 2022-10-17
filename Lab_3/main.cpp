#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <list>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

    // process the inputs from the command line
    if (argc != 2) {
        cout << "Incorrect amount of parameters" << endl;
        return 0;
    }

//    string file_name = argv[1];
//    cout << file_name << endl;

    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line

    ifstream input;
    string filename = argv[1];
    input.open(filename);

//    cout << argv[1] << endl;
//    cout << input.is_open() << endl;

    while (getline(input, next_line)) {
//        cout << "here" << endl;
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
//            cout << token<<endl;
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation
                if (isalpha(c)) {
                    nopunct +=c;
                }
            }
            transform(nopunct.begin(), nopunct.end(), nopunct.begin(), ::tolower);
            tokens.push_back(nopunct);
            unique.insert(nopunct);
//            cout << token<<endl;
        }
    }
    input.close();
//    cout << "Number of words "<<tokens.size()<<endl;
//    cout << "Number of unique words "<<unique.size()<<endl;


    // Set file
    ofstream setfile(filename+"_set.txt");
    for(set<string>::iterator it = unique.begin(); it!=unique.end(); ++it){
        setfile << *it << endl;
    }
    setfile.close();

    // Vector File
    ofstream vectorfile(filename+"_vector.txt");
    for(int i = 0; i < tokens.size(); i++){
//        cout << tokens.at(i) << endl;
        vectorfile << tokens.at(i) << endl;
    }
    vectorfile.close();

    // create map
//    map<string, vector<string>> wordmap;
//    string last="";
//    for(vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
//        wordmap[last].push_back(*it);
//        last = *it;
//    }
    map<list<string>, vector<string> > wordmap;
    list<string> state;
    int M = 2;

    for (int i = 0; i < M; i++) {
        state.push_back("");
    }

    for(vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
        wordmap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }


    // Map file
//    ofstream mapfile(filename+"_map.txt");
//    for(map<string, vector<string>>::iterator it = wordmap.begin(); it!=wordmap.end(); ++it){
//        mapfile << it->first;
//        for (int i=0;  i < it->second.size(); i++){
//            mapfile << ", " << it->second.at(i);
//        }
//        mapfile << endl;
//    }
//    mapfile.close();




    state.clear();
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap[state].size();
        cout << wordmap[state][ind]<<" ";
        state.push_back(wordmap[state][ind]);
        state.pop_front();
    }

    return 0;
}

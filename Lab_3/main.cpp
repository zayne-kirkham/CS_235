#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {

    // process the inputs from the command line
    if (argc != 2) {
        cout << "Incorrect amount of parameters" << endl;
        return 0;
    }

//    string file_name = argv[1];
//    cout << file_name << endl;

    ifstream input;
    input.open(argv[1]);

    set<string> set_of_words;
    for(int i; i < input.size(); i++)

    return 0;
}

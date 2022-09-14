#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> readFile(){
  // read dad joke into vector
  ifstream input;
  input.open("dadjokes.txt");
  
  if(!input){
    cout << "dadjokes.txt not found" <<endl;
    exit(-1);
  }
  
  vector<string> theJokes;
  while(!input.eof()){
    string linea;
    getline(input, linea);
    if (linea.size() >=2)
      theJokes.push_back(linea);
  }
  
  
  input.close();
  
  for (int i = 0; i < theJokes.size(); i++){
    cout << "joke " << i << ": "<< theJokes[i]<< endl;
  }
  return theJokes;
}

// ./chiste [add/remove/read] [optional ]
int main(int argc, char *argv[]) {
//  This prints out all of the args 
//  for(int i=0; i<argc; i++){
//    cout << argv[i] << endl;
//  }
  
  if (argc < 2){
    cout << "ERROR: Wrong Arg Format" << endl;
    exit(-1);
  }

  string command;
  command = argv[1];
  
  if (command == "add"){
    if (argc < 3){
      cout << "No Dad Joke Supplied" << endl;
      exit(-1);
    }
    cout << "The new Dad joke is: " << argv[2] << endl;
    
    ofstream output;
    output.open("dadjokes.txt", ios::app);  // Appends the joke at the end of the file
    output << argv[2] << endl;
    output.close();
    cout << "Dad Joke Saved"<<endl;
  }
  else if (command == "remove"){
    //check if joke is there to remove
    if (argc < 3){
      cout << "No Dad Joke Supplied" << endl;
      exit(-1);
    }
    
    vector<string> theJokes = readFile();
     
    // Remove joke
    string badDadJoke = argv[2];
    int index;
    for (index = 0; index < theJokes.size(); index++){
      if (theJokes[index].find(badDadJoke) != string::npos){
        break;
      }
    }
    
    //Remove index
    if (index < theJokes.size()){
      cout << "Removing: " << theJokes[index] << endl;
      theJokes.erase(theJokes.begin() + index);
    }
    
    //Overwrite the file
    
    ofstream output;
    output.open('dadjokes.txt');  // FIXME HERE
    
    for (int i=0; i < theJokes.size(); i++){
      output << theJokes[i] << endl;
    }
    output.close();
    
  }
  else if (command == 'read'){
    // read in file
    vector<string> theJokes = readFile();
    // generate random number
    srand(time(NULL));
    int num = rand() % theJokes.size();
    // read joke
    cout << theJokes[num];
  }
  else {
    cout << "Command not found"<< endl;
    exit(-1);
  }
  
  return 0;
}

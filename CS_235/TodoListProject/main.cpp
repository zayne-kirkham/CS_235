#include <iostream>
#include <string>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[]) {
  // creates object
  TodoList *todo = new TodoList();
  
  // Checks if there are args
  if (argc <= 1){
    cout << "not enough input"<< endl;
  }
  else{
    string command = argv[1];
    
    if (command == "add"){
      cout << "adding" << endl;
      //checks the num args
      if (argc > 3){
        string date = argv[2];
        string task = argv[3];
        
        todo->add(date, task);
        
      }
      else{
        cout << "Not enough information" << endl;
      }
    }
    else if (command == "remove"){
      // cout << "removing" << endl;
      //checks the num args
      if (argc > 2){
        string task = argv[2];
        todo->remove(task);
      }
      else{
        cout << "Not enough information" << endl;
      }
    }
    else if (command == "printList"){
      // cout << "printing list"<< endl;
      todo->printTodoList();
    }
    else if (command == "printDay") {
      // cout << "printing tasks for a day" << endl;
      
      //checks the num args
      if (argc > 2){
        string date = argv[2];
        todo->printDaysTasks(date);
      }
      else{
        cout << "Not enough information" << endl;
      }
      }
    else{
      cout << "Incorrect command arg"<< endl;
    }
  }
    
  // Closing down the program
  delete todo;
  return 0;
}


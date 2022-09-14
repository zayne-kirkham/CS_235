#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "TodoList.h"

using namespace std;

//todo:
//  - add a way to tell whether something is a task or a date

TodoList::TodoList(){
  // cout << "constucting" << endl;
  
  ifstream input;
  input.open("TODOList.txt");
  if (input.is_open()){
    string line;
    while(getline(input, line)){
      // cout << line << endl;
      if (line.size() >=2)
        tasks.push_back(line);
    }
    // Closes the file
    input.close();
  }
  else{
    // Escapes if there is no list file
    cout << "TODOList.txt not found" <<endl;
    exit(-1);
  }
  
}

TodoList::~TodoList(){
  // cout << "destructing" << endl; 
  
  ofstream output;
  output.open("TODOList.txt", ios::trunc);
  
  for(int i = 0; i < tasks.size(); i++){
    // cout << "task["<<i<<"]: "<< tasks[i]<< endl;
    output << tasks[i] << endl;
  }
  output.close();
}

/*Adds an item to the todo list with the data specified by the string
  "_date" and the task specified by "_task"
  */
void TodoList::add(string _duedate, string _task){
  cout << "date:  "<< _duedate << endl;
  cout << "task:  " << _task << endl;
  
  tasks.push_back(_duedate);
  tasks.push_back(_task);
}

/*Removes an item from the todo list with the specified task name
 *Returns 1 if it removes an item, 0 otherwise
 */
int TodoList::remove(string _task){
  // cout << "task: " << _task << endl;
  
  // find index of 
  string task = _task;
  int index;
  for (index = 0; index < tasks.size(); index++){
    if (tasks[index].find(task) != string::npos){
      break;
    }
  }
  
  //Remove index 
  if (index < tasks.size()){
    cout << "Removing task: " << tasks[index] << endl;
    tasks.erase(tasks.begin() + index);
    tasks.erase(tasks.begin() + index - 1);
    return 1;
  }
  else{
    cout << "Task not in list" << endl;
    return 0;
  }
}

/*Prints out the full todo list to the console
 */
void TodoList::printTodoList(){
  cout << "printing list: " << endl;
  for(int i = 0; i < tasks.size(); i++){
    cout << tasks[i]<< endl;
  }
}

/*Prints out all items of a todo list with a particular due date (specified
 by _date)
 */
void TodoList::printDaysTasks(string _date){
  cout << "printing tasks for: " << _date << endl;
  
  // find index of 
  string date = _date;
  vector<int> index;
  for (int i = 0; i < tasks.size(); i++){
    if (tasks[i].find(date) != string::npos){
      index.push_back(i);
    }
  }
  // Checks if there are any matches
  if (index.size() > 0){
    // checks for overflow
    if (index[i]+1 < tasks.size()){
      // loops through all the matches
      for (int i = 0; i < index.size(); i++){
        cout << tasks[index[i]]<< endl;
        // cout << "index[i]: " << index[i] <<endl;
        // cout << "i: " << i << endl;
        cout << tasks[index[i] + 1] << endl;
      }
    }
    else{
      cout << date << " has no task and is at the end of the file"<< endl;
    }
  }
  else{
    cout << "Date is not in the list" << endl;
  }
}
















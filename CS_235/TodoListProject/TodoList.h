#ifndef TODOLIST   // preprocesser instructions, kind of like key signatures in sheet music
#define TODOLIST   // 

#include <iostream>
#include <string>
#include <vector>
#include "TodoListInterface.h"
using namespace std;


class TodoList :  public TodoListInterface{
public:
  // holds the file
  vector <string> tasks;
  
  TodoList();    // Constructor
  ~TodoList();   // Deconstructor
  
  /*Adds an item to the todo list with the data specified by the string
   "_duedate" and the task specified by "_task"
   */
  void add(string _duedate, string _task);
  
  /*Removes an item from the todo list with the specified task name
   *Returns 1 if it removes an item, 0 otherwise
   */
  int remove(string _task);
  
  /*Prints out the full todo list to the console
   */
  void printTodoList();
  
  /*Prints out all items of a todo list with a particular due date (specified
   by _duedate)
   */
  void printDaysTasks(string _date);
};

#endif //CS_235_TODOLIST_H

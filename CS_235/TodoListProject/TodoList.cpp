#include <iostream>
#include <sstream>
#include <string>
#include "TodoList.h"

using namespace std;

TodoList::TodoList(){
  
}

TodoList::~TodoList(){
  
}

/*Adds an item to the todo list with the data specified by the string
  "_duedate" and the task specified by "_task"
  */
void TodoList::add(string _duedate, string _task);

/*Removes an item from the todo list with the specified task name
 *Returns 1 if it removes an item, 0 otherwise
 */
int TodoList::remove(string _task);

/*Prints out the full todo list to the console
 */
void TodoList::printTodoList();

/*Prints out all items of a todo list with a particular due date (specified
 by _duedate)
 */
void TodoList::printDaysTasks(string _date);
};





























// 
// /*
//  * Reads in the file
//  */
// vector<string> readFile(){
//   // reads file into vector
//   
//   // Opens File
//   ifstream input;
//   input.open("TODOList.txt");
//   
//   // Checks if it opened
//   if(!input){
//     cout << "TODOList.txt not found" <<endl;
//     exit(-1);
//   }
//   
//   // Gets the contents of the file
//   vector<string> todoList;
//   while(!input.eof()){
//     string linea;
//     getline(input, linea);
//     if (linea.size() >=2)
//       todoList.push_back(linea);
//   }
//   
//   // Closes the file
//   input.close();
//   
//   return todoList;
// }
// 
// 
// TodoList::TodoList(){
//   // Construct class / file
//   
//   ifstream output;
//   output.open("TODOList.txt", ios::app);  
//   output << argv[2] << endl;
//   output.close();
// }
// 
// TodoList::~TodoList(){
//   
// }
// 
// /*Adds an item to the todo list with the data specified by the string
//  "_duedate" and the task specified by "_task"
//  */
// void TodoList:add(string _duedate, string _task){
//   // fix me add stuff to the todo list
//   
//   cout << "Adding Due Date" << argv[2] << endl;
//   
//   ofstream output;
//   output.open("dadjokes.txt", ios::app);  // Appends the joke at the end of the file
//   output << argv[2] << endl;
//   output.close();
//   cout << "Dad Joke Saved"<<endl;
//   
// }
// 
// int TodoList:remove(string _task){
//   // Removes items from the Todo List
//   
//   
//   vector<string> todoList = readFile();
//   int removed = 0;
//   
//   // Remove joke
//   string itemToRemove = argv[2];
//   int index;
//   for (index = 0; index < todoList.size(); index++){
//     if (todoList[index].find(itemToRemove) != string::npos){
//       break;
//     }
//   }
//   
//   //Remove index
//   if (index < todoList.size()){
//     cout << "Removing: " << todoList[index] << endl;
//     todoList.erase(todoList.begin() + index);
//     removed = 1
//   }
//   else {
//     removed = 0
//   }
//   
//   //Overwrite the file
//   
//   // Opens the file
//   ofstream output;
//   output.open('TODOList.txt');  
//   
//   //Writes to the file
//   for (int i=0; i < todoList.size(); i++){
//     output << todoList[i] << endl;
//   }
//   
//   // Closes the file
//   output.close();
//   
//   return removed
// }
// 
// void TodoList:printTodoList(){
//   // read in file
//   vector<string> todoList = readFile();
//   
//   // generate random number
//   srand(time(NULL));
//   int num = rand() % theJokes.size();
//   // read joke
//   cout << theJokes[num];
// }
// 
// void TodoList:printDaysTasks(string _date){
//   // prints the tasks associated with the date
// }
## Recursive Boggle
To get this code working clone the repository and use "git clone ..." to copy it onto your instance.

Notice that the makefile is somewhat different than you are used to.
```
all:
	g++ -o boggle main.cpp boggle.cpp

clean:
	rm -f boggle
```
The all: target is not changed by the g++ compile statement so it will be compiled every time you type "make".  A clean: target is also specified that will remove the binary.  It is good to have a clean target in your makefile so that you can start over if you are moving to a new computer.  If no target is specified, the first one in the makefile is used, so if you just type "make", it will compile the directive for "all".

In this exercise you are going to work through an example that is very similar to the lab, so even if you are copying and pasting code from "v1", it should help you to understand recursion and the way the lab works.

Start by looking at main.cpp.  The program requires you to run it with at board file, a dictionary file and minimum word length.
```
cout << "Usage: ./boggle <board_file> <dictionary_file> <min_word_length>" << endl;
```
Notice that the directory "boards" has three boggle boards in it.  For the next lab, you are going to try to find your way through a 3 dimensional submarine.  Finding a path through the boggle board is very similar.

Notice that the next part of main.cpp prints out the default board and a random board.  You will have to create a random maze in the lab, so it might be good to pay attention here too.
```
// Default board (should be all "a")
  Boggle boggle;
  cout << boggle.getBoardString() << endl << endl;

  // Random board
  boggle.createRandomBoard();
  cout << boggle.getBoardString() << endl << endl;
```
Now you import the board from the file specified in the command line 
```
// Import board (if import fails, then random board will be used)
  bool success = boggle.importBoard(argv[1]);
```
The board files are just two dimensional arrays that correspond to letters on a boggle board.
```
a r t s e
l e a n t
t s r i r
o l u s a
r n t e n
```
Now the main.cpp tests to make sure you can look words up in your dictionary
```
// Test isWord and isPrefix
  string tests[] = {"a", "and", "aard", "aardvark", "aaard", "mil", "mlead", "zymurgy", "zymurg", "zymany"};
  for(int i = 0; i < 10; i++)
  {
    bool isWord = boggle.isWord(tests[i]);
    if(isWord)
      cout << tests[i] << " is a word" << endl;
    else
      cout << tests[i] << " is NOT a word" << endl;
    bool isPrefix = boggle.isPrefix(tests[i]);
    if(isPrefix)
      cout << tests[i] << " is a prefix" << endl;
    else
      cout << tests[i] << " is NOT a prefix" << endl;
  }
  cout << endl;
```
And finally, main.cpp will make the call to print the board and solve it
```
// Solve the board
  cout << boggle.getBoardString() << endl << endl;
  set<string> words = boggle.solveBoard();
```
Notice that boggle.h has the class definition and descriptions of all the functions and what they should do. The file boggle.cpp has the class function implementations.  Lets fill a few in (from the v1 boggle.cpp file).

First, getBoardString() just returns a stringstream that can be sent to cout in main.cpp
```
string Boggle::getBoardString()
{
  int x, y = 0;
  stringstream boardStr;
  for(y = 0; y < SIZE; y++)
  {
    for(x = 0; x < SIZE; x++)
    {
      boardStr << board[x][y];
      if(x != SIZE-1)
        boardStr << " ";
    }
    if(y != SIZE-1)
      boardStr << endl;
  }
  return boardStr.str();
}
```
Next createRandomBoard() uses the current time to seed the random number generator, then fills the array with random letters from alpha.
```
void Boggle::createRandomBoard() creates a random two dimenional boggle board.
{
  srand(time(NULL));
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  int x, y = 0;
  for(x = 0; x < SIZE; x++)
  {
    for(y = 0; y < SIZE; y++)
    {
      board[x][y] = alpha[rand() % alpha.size()];
    }
  }
}
```
Then importBoard() reads in the board from a file (you will have to do this in your lab).
```
bool Boggle::importBoard(string file_name)
{
  ifstream ifs;
  string line;
  int x, y = 0;
  string boardValues[SIZE][SIZE];

  // Open file
  ifs.open(file_name, ifstream::in);
  if(!ifs.is_open())
  {
    cout << "file " << file_name << " failed to open" << endl;
    return false;
  }

  for(y = 0; y < SIZE; y++)
  {
    getline(ifs, line);
    if(ifs.bad() || ifs.fail())
    {
      cout << "line read fail" << endl;
      return false;
    }
    while(line[line.size()-1] == ' ' || line[line.size()-1] == '\n' || line[line.size()-1] == '\r')
      line = line.substr(0, line.size()-1);
    if(line.size() != SIZE*2-1)
    {
      cout << "line wrong size: actual " << line.size() << ", expected: " << SIZE*2-1 << endl;
      return false;
    }
    for(x = 0; x < SIZE; x++)
    {
      boardValues[x][y] = line[x*2];
    }
  }

  // Check for no extra lines
  getline(ifs, line);
  if(!ifs.bad() && !ifs.fail())
  {
    cout << "too many extra lines found" << endl;
    return false;
  }

  setBoard(boardValues);
  return true;
}
```
You will then need to implement importDictionary and a bunch of other helper functions that allow you to check if a word is in the dictionary.
```
bool Boggle::importDictionary(string file_name)
{
  ifstream ifs;
  string line;

  // Open file
  ifs.open(file_name, ifstream::in);
  if(!ifs.is_open())
    return false;

  while(getline(ifs, line))
  {
    while(line[line.size()-1] == ' ' || line[line.size()-1] == '\n' || line[line.size()-1] == '\r')
      line = line.substr(0, line.size()-1);
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    dictionary.push_back(line);
  }
  return true;
}

void Boggle::setMinWordLength(int length)
{
  minWordLength = length;
}

bool Boggle::isWord(string word)
{
  return findPrefix(word, 0, dictionary.size(), true);
}

bool Boggle::isPrefix(string prefix)
{
  return findPrefix(prefix, 0, dictionary.size(), false);
}

bool Boggle::findPrefix(string root, int start, int end, bool fullWordOnly)
{
  // Return false if indexes become invalid
  if(start > end)
    return false;

  int mid = (start+end)/2;
  string middle = dictionary[mid];

  // Return true if is valid word and is at least minWordLength
  if(middle == root && root.size() >= minWordLength)
    return true;

  // Return true if is valid prefix and fullWordOnly is false
  if(!fullWordOnly && middle.substr(0, root.size()) == root)
    return true;

  // Recursive call
  if(root > middle)
    return findPrefix(root, mid+1, end, fullWordOnly);
  else
    return findPrefix(root, start, mid-1, fullWordOnly);
}
```
Now we get into the recursion.  We will first need to have a starter function to solve the maze.  It will make a call to the recursive function findWords(). 
```
set<string> Boggle::solveBoard()
{
  set<string> words;
  int x, y = 0;

  // Start search at each possible starting position
  for(x = 0; x < SIZE; x++)
  {
    for(y = 0; y < SIZE; y++)
    {
      unordered_set<string> path;
      findWords("", path, words, x, y);
    }
  }

  return words;
}
```
Notice that findWords() calls itself recursively with a smaller subset of the boggle board every time.  It recursively calls itself by looking left, right, up, down, NorthWest, NE, SW, SE.  
```
void Boggle::findWords(string root, unordered_set<string> path, set<string>& wordsFound, int x, int y)
{
  // If position not on board, return
  if(x < 0 || x >= SIZE)
    return;
  if(y < 0 || y >= SIZE)
    return;

  // If position has already been visited for this root, return
  stringstream ss;
  ss << "(" << x << ", " << y << ")";
  string pos = ss.str();
  if(path.find(pos) != path.end())
    return;

  // Add position to path and add the character to root string
  path.insert(pos);
  root = root.append(board[x][y]);

  // If root is a word, add it to solution set
  if(isWord(root))
    wordsFound.insert(root);

  // If it is a prefix, recursively check all paths
  if(isPrefix(root))
  {
    findWords(root, path, wordsFound, x-1, y); // Left
    findWords(root, path, wordsFound, x+1, y); // Right
    findWords(root, path, wordsFound, x, y+1); // Down
    findWords(root, path, wordsFound, x, y-1); // Up
    findWords(root, path, wordsFound, x-1, y-1); // NW
    findWords(root, path, wordsFound, x+1, y-1); // NE
    findWords(root, path, wordsFound, x-1, y+1); // SW
    findWords(root, path, wordsFound, x+1, y+1); // SE
  }
}
```
And finally, you need to implement some additional helper functions
```
void Boggle::clear()
{
  dictionary.clear();
  minWordLength = 3;
  int x, y = 0;
  for(x = 0; x < SIZE; x++)
  {
    for(y = 0; y < SIZE; y++)
    {
      board[x][y] = "a";
    }
  }
}

void Boggle::setBoard(string boardValues[SIZE][SIZE])
{
  int x, y = 0;
  for(x = 0; x < SIZE; x++)
  {
    for(y = 0; y < SIZE; y++)
    {
      board[x][y] = boardValues[x][y];
    }
  }
}
```
Now lets see how it works (if you got lost, copy v1/boggle.cpp into boggle.cpp)

Run it with somethiing like
```
./boggle boards/board3.txt dictionary.txt 4
```
The code will first print out the default board and the random board that was generated and all of the words to test the dictionary.
```
a a a a a
a a a a a
a a a a a
a a a a a
a a a a a

c i r m p
u e a h h
q u i m s
s p x p e
e p y b g

success importing boards/board3.txt
a is NOT a word
a is a prefix
and is NOT a word
and is a prefix
aard is NOT a word
aard is a prefix
aardvark is a word
aardvark is a prefix
aaard is NOT a word
aaard is NOT a prefix
mil is NOT a word
mil is a prefix
mlead is NOT a word
mlead is NOT a prefix
zymurgy is a word
zymurgy is a prefix
zymurg is NOT a word
zymurg is a prefix
zymany is NOT a word
zymany is NOT a prefix
```
Then it will print out the board and all of 4 character words it found.  I bet you didnt find that many words on the boggle board.
```
a r t s e
l e a n t
t s r i r
o l u s a
r n t e n

Found 402 words:
aint
airer
aires
airest
airs
alert
...
```

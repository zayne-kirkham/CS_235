#include <iostream>

using namespace std;


bool solveMazeRec(int x, int y, int maze[10][10]) {
    // base case(s)
    if ((x < 0) || (x > 9) || (y < 0) || (y > 9))
        return false;
    if (maze[y][x] == 2) {
        // add it to our path
        return true;
    }
    if (maze[y][x] == 0)
        return false;
    if (maze[y][x] == 3)
        return false;
    
    maze[y][x] = 3;

    // add (x, y) to the path

    // recursive step(s) (call(s))
    bool right = solveMazeRec(x+1, y, maze);
    bool left = solveMazeRec(x-1, y, maze);
    bool down = solveMazeRec(x, y+1, maze);
    bool up = solveMazeRec(x, y-1, maze);

    if (right || left || down || up) {
        return true;
    }
    else {
        // remove off the end of the path

        return false;
    }
}

void solveMaze() {
    int maze[10][10] = {{1,1,1,1,0,0,1,1,1,1},
                        {0,1,0,0,0,0,1,0,0,1},
                        {1,1,1,0,0,0,1,1,0,1},
                        {0,0,1,0,0,0,0,1,0,1},
                        {0,0,1,1,1,1,1,1,0,1},
                        {0,0,0,0,0,1,0,1,1,0},
                        {0,0,0,1,0,1,0,0,1,1},
                        {0,0,0,1,0,1,0,0,0,0},
                        {0,2,0,1,0,1,0,0,0,0},
                        {0,1,1,1,1,1,1,1,1,1}};

    if (solveMazeRec(0, 0, maze))
        cout << "Maze is solvable" << endl;
    else
        cout << "Maze is NOT solvable" << endl;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

int fib(int N) {
    cout << "fib(" << N << ") is called but not chosen" << endl;
    // base cases
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;

    // recursive
    return fib(N-2) + fib(N-1);
}

// Principles of Recursion:
//  (1) Have a good base case or base cases
//  (2) Make sure all recursive calls work toward the base case
//  (3) Have Faith
//  (4)

int sumRec(int N) {
    // cout << "called sumRec(" << N << ")" << endl;

    // base case
    if (N <= 0) {
        // cout << "return sumRec(" << N << ") = 0" << endl;
        return 0;
    }

    // recursive step
    int answer = N + sumRec(N-1);
    // cout << "return sumRec(" << N << ") = " << answer << endl;
    return answer;
}

int sum(int N) {
    int s = 0;
    for (int j = 1; j <= N; j++)
        s += j;

    return s;
}

int main(int argc, char *argv[]) {
    // if (argc < 2) {
    //     cout << "No `n' supplied" << endl;
    //     exit(1);
    // }
    // int N = atoi(argv[1]);

    // sumRec(N);
    // cout << "The sum of the first " << N << " integers is " << sum(N) << endl;

    // fib(N);
    // cout << "fib(" << N << ") = " << fib(N) << endl;

    solveMaze();

    return 0;
}
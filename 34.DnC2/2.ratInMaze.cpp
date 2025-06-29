 #include<iostream>
using namespace std;

    //$ Function that will handle all the below mentioned possibilities:
            //@ there are two possibilities now 
                //@ -> path close ho 
                //@ -> out of bound move kr rhe ho means at the edge pr khade hai
                //@ -> check if position is already visited and do not visit the visited postion again
                
    bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>> &visited){
        if((newx >= 0 && newx < row) && 
        (newy >= 0 && newy < col) &&
        maze[newx][newy] == 1 && 
        visited[newx][newy] == false ){
            return true;
        }
        else {
            return false;
        }
    }

    void printAllPath(int maze[][4],int row,int col,int srcx,int srcy,string &output, vector<vector<bool>> &visited){

        // Base case
        // Destination cordinates are [row-1],[col-1]
        if(srcx == row-1 && srcy == col-1){
            // reached the destination
            cout << output << endl;
            return;
        }

        // 1 case solve kro baki recursion kr dega

            // there are possibilities now 
                // -> path close ho 
                // -> out of bound move kr rhe ho means at the edge pr khade hai
                // -> check if position is already visited and do not visit the visited postion again
            // we are making a function for this -> isSafe()

        //$ UP
        int newx = srcx-1;
        int newy = srcy;
        if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
            // Mark the position visited
            visited[newx][newy] = true;
            // call recursion for further
            output.push_back('U');
            printAllPath(maze, row, col, newx, newy, output, visited);
            // backtracking to mark the position not visited
            output.pop_back();
            visited[newx][newy] = false;
        }

        //$ RIGHT
        newx = srcx;
        newy = srcy+1;
        if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
            // Mark the position visited
            visited[newx][newy] = true;
            // call recursion for further
            output.push_back('R');
            printAllPath(maze, row, col, newx, newy, output, visited);
            // backtracking to mark the position not visited
            output.pop_back();
            visited[newx][newy] = false;
        }

        //$ DOWN 
        newx = srcx+1;
        newy = srcy;
        if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
            // Mark the position visited
            visited[newx][newy] = true;
            // call recursion for further
            output.push_back('D');
            printAllPath(maze, row, col, newx, newy, output, visited);
            // backtracking to mark the position not visited
            output.pop_back();
            visited[newx][newy] = false;
        }

        //$ LEFT
        newx = srcx;
        newy = srcy-1;
        if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
            // Mark the position visited
            visited[newx][newy] = true;
            // call recursion for further
            output.push_back('L');
            printAllPath(maze, row, col, newx, newy, output, visited);
            // backtracking to mark the position not visited
            output.pop_back();
            visited[newx][newy] = false;
        }
    }

int main(){
    
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };

    int row = 4;
    int col = 4;

    int srcx = 0;
    int srcy = 0;
    string output = "";

    // created visited 2d array

    vector<vector<bool> > visited(row, vector<bool>(col,false));
    
    if(maze[0][0] == 0){
        // means src position is closed, iska mtlb kya hai means RAT connot move
        cout << "No Path Exists" << endl;
    } else {
        visited[srcx][srcy] = true;
        printAllPath(maze,row,col,srcx,srcy,output,visited);
    }

    return 0;
}

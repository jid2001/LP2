#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> soln, int n){
     int x = row, y = col;
     // checking prev  rows
    while(y--){
        if(soln[x][y] == 'Q'){
            return false;
        }
    }
    // checking upper diagonal
    x = row;
    y = col;
    while(x>=0 && y>=0){
        if(soln[x][y] == 'Q' ){
          return false;   
        }
        x--;
        y--; 
    }
    //checking lower diagonal
    x = row; y = col;
    while(x<n && y>=0){
        if(soln[x][y] == 'Q' ){
          return false;   
        }
        x++;
        y--; 
    }
    return true; 
}
     

void solve(int col,vector<string> soln,  vector<vector<string>> &ans, int n){

    //base case 
    if(col == n){
        // cout <<"col " << col <<endl;
        ans.push_back(soln);
        return;
    }
    for(int row = 0; row <n ; row++){
        if(isSafe(row,col,soln,n)){
            // cout << row <<" "<<col <<endl;
            soln[row][col] = 'Q';
            solve(col+1,soln,ans,n);
            soln[row][col] = '.';
        }
    }

}
  
  vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> soln(n,s);
        solve(0,soln,ans, n);
        // for(auto x : soln) cout << x <<endl;
        return ans;
    }
    
int main(){
    int n;
    cout << "Enter no of Queens : ";
    cin>> n;
    vector<vector<string>> sol = solveNQueens(n);
    int cnt =1;
    for(auto x : sol){
        cout << "Solution "<< cnt++ << endl;
        for(auto y : x){
            cout << y <<endl;
        }
        cout <<endl;
    }
    return 0;
}


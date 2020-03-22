#include<bits/stdc++.h>
using namespace std;
const int n=4;
int sol[4][4];
void print_board(int sol[4][4],int n ){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<sol[i][j]<<" ";

        }
        cout<<"\n";
    }
}
bool canPlace(int board[n][n],int N,int x,int y){
   if(x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 1)
        return true;

    return false;

}




bool find_path(int sol[4][4],int board[n][n],int n,int row,int col){

    if(row==n-1 && col==n-1){
        sol[row][col]=1;
        return true;
    }
    if(canPlace(board,n,row,col)==true){
        sol[row][col]=1;

        bool success=find_path(sol,board,n,row+1,col);
        if(success==true)
            return true;


      bool success2=find_path(sol,board,n,row,col+1);
        if(success2==true)
            return true;
        sol[row][col]=1;
        return false;

    }


return false;


}



int main(){

int board[4][4]= { {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1,1, 1}
    };
    int sol[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

bool success=find_path(sol,board,n,0,0);
if(success==true){
    print_board(sol,n);
}
else{

    cout<<"cannot find the solution";
}

return 0;
}

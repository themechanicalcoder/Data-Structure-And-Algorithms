#include<bits/stdc++.h>

using namespace std;


void print_board(int board[8][8],int n ){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<board[i][j]<<" ";

        }
        cout<<"\n";
    }
}


bool check(int board[8][8],int n,int r,int c){
    return
        r >= 0 && r < n &&
        c >= 0 && c < n &&
        board[r][c] == 0;
}
bool knight_tour(int board[8][8],int n,int moveno,int row,int col){

    if(moveno==n*n){
        return true;}

    int rowdir[]={+2, +1, -1, -2, -2, -1, +1, +2};
    int coldir[]={+1, +2, +2, +1, -1, -2, -2, -1};

    for(int i=0;i<8;i++){

            int next_row=row+rowdir[i];
            int next_col=col+coldir[i];
            if(check(board,n,next_row,next_col)==true){

                board[next_row][next_col]=moveno+1;

                bool success= knight_tour(board,n,moveno+1,next_row,next_col);

                if(success==true)return true;
                board[next_row][next_col]=0;
            }
    }


    return false;

}



int main(){
    int board[8][8]={0};
    int n;
    cin>>n;
    board[0][0]=1;
    bool t=knight_tour(board,n,1,0,0 );
    if(t==true)
        print_board(board, n);

    else{
        cout<<"this board cannot be printed";
    }

return 0;
}

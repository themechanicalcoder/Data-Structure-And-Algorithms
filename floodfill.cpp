#include<bits/stdc++.h>
using namespace std;
#define m 8
#define n 8
int c0=2;
int  c1=3;

void print_board(int  mat[8][8]){

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j];
        }
    cout<<"\n";
    }

}
void floodfill(int  mat[8][8],int row,int col){

    if(mat[row][col]!=c0||row<0||col<0||row>m||row>n)
        return ;
    mat[row][col]=3;

 int dr[] = {1,1,0,-1,-1,-1, 0, 1};
 int dc[] = {0,1,1, 1, 0,-1,-1,-1};
for(int i=0;i<8;i++){
    floodfill(mat,row+dr[i],col+dc[i]);
}

}

int main(){
int  mat[8][8]={{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                };
                cout<<mat[1][2]<<"\n";
int row=4,col=4;
cout<<"before flood fill"<<"\n";
print_board(mat);
floodfill(mat,row,col);
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        cout<<mat[i][j];
    }
    cout<<"\n";

}
cout<<"after flood fill";
print_board(mat);
return 0;



}


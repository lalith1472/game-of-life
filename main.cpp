#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define  CELLSIZE 10
#define ROW 100
#define COLUMN 100
using namespace std;

/*

original new state
0        0    0
1        0    1
0        1    2
1        1    3

*/

void input(vector<vector<int>> &grid){
  if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
    Vector2 mouse=GetMousePosition();
    if(!(mouse.y/CELLSIZE>=ROW ||mouse.x/CELLSIZE>=COLUMN)){
    grid[(mouse.y/CELLSIZE)][(mouse.x/CELLSIZE)]=1- grid[mouse.y/CELLSIZE][mouse.x/CELLSIZE];
  }
 }
}

int countneighbours(vector<vector<int>> &grid,int r,int c){
  int count=0;
  for(int i=-1;i<=1;i++){
    for(int j=-1;j<=1;j++){
      if(i==0 && j==0)continue;
      int row=(i+r+ROW)%ROW;
      int colm=(j+c+COLUMN)%COLUMN;
      if(grid[row][colm]==1 || grid[row][colm]==3)count++;
    }
  }
  return count;
}

void gameoflife(vector<vector<int>>&grid){
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COLUMN;j++){
      int count =countneighbours(grid,i,j);
      if(grid[i][j]==1){
        if(count==2 || count==3){
          grid[i][j]=3;
        }
      }
      else if(count==3)grid[i][j]=2;
      
    }
  }
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COLUMN;j++){
      if(grid[i][j]==1)grid[i][j]=0;
      if(grid[i][j]==2 || grid[i][j]==3)grid[i][j]=1;
    }
  }
}



vector<vector<int>> initialize(){
  vector<vector<int>> grid(ROW, vector<int>(COLUMN, 0));
  return grid;
}

void drawgrid(vector<vector<int>> grid){
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COLUMN;j++){
      if(grid[i][j]==1){
        Color neonGreen = {57, 255, 20, 255};
        DrawRectangle(CELLSIZE*j,CELLSIZE*i,CELLSIZE,CELLSIZE,neonGreen);
      }
      
    }
  }
}

int main()

{

    
    InitWindow(1000, 1000, "GAME OF LIFE");
  
    auto grid=initialize();
    float timer=0.0;
    bool start=false;
    bool reset=false;


    while (!WindowShouldClose())
    {   
      
      input(grid);
        if(IsKeyPressed(KEY_SPACE)){
          if(start)start=false;
          else start=true;
        }
        timer+=GetFrameTime();
        if (start==true  && timer>=0.1){
            gameoflife(grid);
            timer=0;
          }
        if(IsKeyPressed(KEY_R)){
        
        grid=initialize();
        }
      

        BeginDrawing();

        ClearBackground(BLACK);
        drawgrid(grid);
        EndDrawing();
    }
  
    CloseWindow();

    return 0;
}
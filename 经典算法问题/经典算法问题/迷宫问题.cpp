//回溯法解迷宫问题（'1'为路径，'0'为障碍，'Y'为走过的路）
#include <iostream>
using namespace std;

const int N = 5;     //迷宫大小
bool found = false;  //默认没找到路径（用find会导致意义不明确）

void printMaze(char arr[N][N])
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<< arr[i][j] << " ";
        }
        cout<<endl;
    }
}

//判断(row,col)在该区域是否可以移动
bool canMove(char arr[N][N], int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < N     //确保在迷宫范围内
                    && arr[row][col] != '0'    //不是障碍
                    && arr[row][col] != 'Y';   //未访问过
}                   

//起点为(row,col)，终点为(outrow,outcol)
void maze_puzzle(char arr[N][N], int row, int col, int outrow, int outcol)
{
    //将走过的各个区域标记为'Y'（确保一次过程中每个区域只走一次）
    arr[row][col] = 'Y';
    //如果到达终点，说明有路径，打印结果并返回
    if(row == outrow && col == outcol){
        cout << "成功走出迷宫，路线图为" << endl;
        found = true;    //用于main函数中是否能找到路径
        printMaze(arr);
        return;
    }
    //由于终点位于右下角，所以先尝试往右下移动
    //尝试向右移动
    if(canMove(arr, row, col + 1)){
        maze_puzzle(arr, row, col + 1, outrow, outcol);
        //如果程序不结束，表示此路不通，恢复该区域标记，下面同理
        arr[row][col+1] = '1';
    }
    //尝试向下移动
    if(canMove(arr, row + 1, col)){
        maze_puzzle(arr, row + 1, col, outrow, outcol);
        arr[row+1][col] = '1';
    }
    //尝试向左移动
    if(canMove(arr, row, col - 1)){
        maze_puzzle(arr, row, col - 1, outrow, outcol);
        arr[row][col-1] = '1';
    }
    //尝试向上移动
    if(canMove(arr, row - 1, col)){
        maze_puzzle(arr, row - 1, col, outrow, outcol);
        arr[row-1][col] = '1';
    }
}

int main()
{
    char arr[N][N] = {
        {'1','0','1','1','1'},
        {'1','1','1','0','1'},
        {'1','0','0','1','1'},
        {'1','0','0','1','0'},
        {'1','0','0','1','1'} };
    cout << "迷宫图为：" << endl;
    printMaze(arr);
    maze_puzzle(arr, 0, 0, N-1, N-1);
    if(!found){
        cout << "未找到路径！" <<endl;
    }
    return 0;
}
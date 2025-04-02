//���ݷ����Թ����⣨'1'Ϊ·����'0'Ϊ�ϰ���'Y'Ϊ�߹���·��
#include <iostream>
using namespace std;

const int N = 5;     //�Թ���С
bool found = false;  //Ĭ��û�ҵ�·������find�ᵼ�����岻��ȷ��

void printMaze(char arr[N][N])
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<< arr[i][j] << " ";
        }
        cout<<endl;
    }
}

//�ж�(row,col)�ڸ������Ƿ�����ƶ�
bool canMove(char arr[N][N], int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < N     //ȷ�����Թ���Χ��
                    && arr[row][col] != '0'    //�����ϰ�
                    && arr[row][col] != 'Y';   //δ���ʹ�
}                   

//���Ϊ(row,col)���յ�Ϊ(outrow,outcol)
void maze_puzzle(char arr[N][N], int row, int col, int outrow, int outcol)
{
    //���߹��ĸ���������Ϊ'Y'��ȷ��һ�ι�����ÿ������ֻ��һ�Σ�
    arr[row][col] = 'Y';
    //��������յ㣬˵����·������ӡ���������
    if(row == outrow && col == outcol){
        cout << "�ɹ��߳��Թ���·��ͼΪ" << endl;
        found = true;    //����main�������Ƿ����ҵ�·��
        printMaze(arr);
        return;
    }
    //�����յ�λ�����½ǣ������ȳ����������ƶ�
    //���������ƶ�
    if(canMove(arr, row, col + 1)){
        maze_puzzle(arr, row, col + 1, outrow, outcol);
        //������򲻽�������ʾ��·��ͨ���ָ��������ǣ�����ͬ��
        arr[row][col+1] = '1';
    }
    //���������ƶ�
    if(canMove(arr, row + 1, col)){
        maze_puzzle(arr, row + 1, col, outrow, outcol);
        arr[row+1][col] = '1';
    }
    //���������ƶ�
    if(canMove(arr, row, col - 1)){
        maze_puzzle(arr, row, col - 1, outrow, outcol);
        arr[row][col-1] = '1';
    }
    //���������ƶ�
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
    cout << "�Թ�ͼΪ��" << endl;
    printMaze(arr);
    maze_puzzle(arr, 0, 0, N-1, N-1);
    if(!found){
        cout << "δ�ҵ�·����" <<endl;
    }
    return 0;
}
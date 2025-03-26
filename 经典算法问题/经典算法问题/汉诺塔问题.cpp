#include <iostream>
using namespace std;

//圆盘数量 起始柱 目标柱 辅助柱
void hanoi(int  num, char sou, char tar, char aux)
{
	if (num == 1) {
		cout << sou << "->" << tar << endl;
	}
	else {
		hanoi(num - 1, sou, aux, tar);         //将上面n-1个圆盘从初始柱移动到辅助柱（借助目标柱）
		cout << sou << "->" << tar << endl;    //将最底下大圆盘从初始柱移动到目标柱
		hanoi(num - 1, aux, tar, sou);         //将上面n-1个圆盘从辅助柱移动到目标柱（借助初始柱）
	}
}

int main()
{
	//以移动 3 个圆盘为例，起始柱、目标柱、辅助柱分别用 A、B、C 表示
	hanoi(3, 'A', 'B', 'C');
	return 0;
}
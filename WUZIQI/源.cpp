#include<iostream>
#include<windows.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define PI 3.1415926
#define N 15 //自定义棋盘大小
using namespace std;

class location //定义棋子坐标类
{
public:
	int x; //直角坐标系横坐标
	int y; //直角坐标系纵坐标
}player1, player2; //玩家 1 为 O 形棋，玩家二为 X 形棋


int main(){
begin:
	std::cout << "*************************************************" <<
		endl;
	std::cout << "******************0、退出************************" << endl;
	std::cout << "******************1、玩家 VS 玩家******************" <<
		endl;
	std::cout << "*************************************************" <<
		endl;
	char a[N][N]; //棋盘数组
	char end = 0; //棋局结束时的判定
	int x, y; //横纵坐标变量
	int mode; //模式
	std::cout << "选择你想要游玩的模式：";
	std::cin >> mode;
	for (y = 0; y < N; y++) //棋盘初始化
		for (x = 0; x < N; x++)
			a[y][x] = '*';
	system("cls");
	for (y = 0; y < N; y++) //显示棋盘
	{
		if (y == 0)
		{
			std::cout << " ";
		for (x = 0; x < N; x++)
			std::cout << " " << x;
		std::cout << endl;
	}
	if (y < 10)
		std::cout << endl << " " << y;
	else if (y >= 10)
		std::cout << endl << " " << y;
	for (x = 0; x < N; x++)
	{
		if (x < 10)
			std::cout << " " << a[y][x];
		else if (x >= 10)
			std::cout << " " << a[y][x];
		if (x == (N - 1)) 
			std::cout << endl;
	}
}

	while (mode) //开始 PVP 模式
	{
		std::cout << endl << "请输入玩家 1（O 形棋子）的横、纵坐标，以空格分隔：";
		std::cin >> player1.x >> player1.y;
		system("cls");
		a[player1.y][player1.x] = 'O';
		for (y = 0; y < N; y++) //显示棋盘
		{
			if (y == 0)
			{
				std::cout << " ";
				for (x = 0; x < N; x++)
					std::cout << " " << x;
				std::cout << endl;
			}
			if (y < 10)
				std::cout << endl << " " << y;
			else if (y >= 10)
				std::cout << endl << " " << y;
			for (x = 0; x < N; x++)
			{
				if (x < 10)
					std::cout << " " << a[y][x];
				else if (x >= 10)
					std::cout << " " << a[y][x];
				if (x == (N - 1)) 
					std::cout << endl;
			}
		}

		if (
			(a[player1.y - 2][player1.x - 2] == 'O' && a[player1.y -
				1][player1.x - 1] == 'O' && a[player1.y][player1.x] == 'O' &&
				a[player1.y + 1][player1.x + 1] == 'O' && a[player1.y + 2][player1.x +
				2] == 'O')
			||
			(a[player1.y - 3][player1.x - 3] == 'O' && a[player1.y -
				2][player1.x - 2] == 'O' && a[player1.y - 1][player1.x - 1] == 'O' &&
				a[player1.y][player1.x] == 'O' && a[player1.y + 1][player1.x + 1] ==
				'O')
			||
			(a[player1.y - 4][player1.x - 4] == 'O' && a[player1.y -
				3][player1.x - 3] == 'O' && a[player1.y - 2][player1.x - 2] == 'O' &&
				a[player1.y - 1][player1.x - 1] == 'O' && a[player1.y][player1.x] ==
				'O')
			||
			(a[player1.y + 4][player1.x + 4] == 'O' && a[player1.y +
				3][player1.x + 3] == 'O' && a[player1.y + 2][player1.x + 2] == 'O' &&
				a[player1.y + 1][player1.x + 1] == 'O' && a[player1.y][player1.x] ==
				'O')
			||
			(a[player1.y + 3][player1.x + 3] == 'O' && a[player1.y +
				2][player1.x + 2] == 'O' && a[player1.y + 1][player1.x + 1] == 'O' &&
				a[player1.y][player1.x] == 'O' && a[player1.y - 1][player1.x - 1] ==
				'O')
			) //对角线连线胜利
		{
			std::cout << " Player1 Win!" << endl;
			system("color 1A");
			break;
		}

		if (
			(a[player1.y - 2][player1.x] == 'O' && a[player1.y -
				1][player1.x] == 'O' && a[player1.y][player1.x] == 'O' && a[player1.y +
				1][player1.x] == 'O' && a[player1.y + 2][player1.x] == 'O')
			||
			(a[player1.y - 3][player1.x] == 'O' && a[player1.y -
				2][player1.x] == 'O' && a[player1.y - 1][player1.x] == 'O' &&
				a[player1.y][player1.x] == 'O' && a[player1.y + 1][player1.x] == 'O')
			||
			(a[player1.y - 4][player1.x] == 'O' && a[player1.y -
				3][player1.x] == 'O' && a[player1.y - 2][player1.x] == 'O' &&
				a[player1.y - 1][player1.x] == 'O' && a[player1.y][player1.x] == 'O')
			||
			(a[player1.y + 4][player1.x] == 'O' && a[player1.y +
				3][player1.x] == 'O' && a[player1.y + 2][player1.x] == 'O' &&
				a[player1.y + 1][player1.x] == 'O' && a[player1.y][player1.x] == 'O')
			||
			(a[player1.y + 3][player1.x] == 'O' && a[player1.y +
				2][player1.x] == 'O' && a[player1.y + 1][player1.x] == 'O' &&
				a[player1.y][player1.x] == 'O' && a[player1.y - 1][player1.x] == 'O')
			) //竖列连线胜利
		{
			std::cout << " Player1 Win!" << endl;
			system("color 1A");
			break;
		}

		if (
			(a[player1.y][player1.x - 2] == 'O' &&
				a[player1.y][player1.x - 1] == 'O' && a[player1.y][player1.x] == 'O' &&
				a[player1.y][player1.x + 1] == 'O' && a[player1.y][player1.x + 2] ==
				'O')
			||
			(a[player1.y][player1.x - 3] == 'O' &&
				a[player1.y][player1.x - 2] == 'O' && a[player1.y][player1.x - 1] ==
				'O' && a[player1.y][player1.x] == 'O' && a[player1.y][player1.x + 1] ==
				'O')
			||
			(a[player1.y][player1.x - 4] == 'O' &&
				a[player1.y][player1.x - 3] == 'O' && a[player1.y][player1.x - 2] ==
				'O' && a[player1.y][player1.x - 1] == 'O' && a[player1.y][player1.x] ==
				'O')
			||
			(a[player1.y][player1.x + 4] == 'O' &&
				a[player1.y][player1.x + 3] == 'O' && a[player1.y][player1.x + 2] ==
				'O' && a[player1.y][player1.x + 1] == 'O' && a[player1.y][player1.x] ==
				'O')
			||
			(a[player1.y][player1.x + 3] == 'O' &&
				a[player1.y][player1.x + 2] == 'O' && a[player1.y][player1.x + 1] ==
				'O' && a[player1.y][player1.x] == 'O' && a[player1.y][player1.x - 1] ==
				'O')
			) //横行连线胜利

		{
			std::cout << " Player1 Win!" << endl;
			system("color 1A");
			break;
		}

		std::cout << endl << "请输入玩家 2（X 形棋子）横、纵坐标，以空格分隔：";
		std::cin >> player2.x >> player2.y;
		system("cls");
		a[player2.y][player2.x] = 'X';
		for (y = 0; y < N; y++) //显示棋盘
		{
			if (y == 0)
			{
				std::cout << " ";
				for (x = 0; x < N; x++)
					std::cout << " " << x;
				std::cout << endl;
			}
			if (y < 10)
				std::cout << endl << " " << y;
			else if (y >= 10)
				std::cout << endl << " " << y;
			for (x = 0; x < N; x++)
			{
				if (x < 10)
					std::cout << " " << a[y][x];
				else if (x >= 10)
					std::cout << " " << a[y][x];
				if (x == (N - 1)) 
					std::cout << endl;
			}
		}
		if (
			(a[player2.y - 2][player2.x - 2] == 'X' && a[player2.y -
				1][player2.x - 1] == 'X' && a[player2.y][player2.x] == 'X' &&
				a[player2.y + 1][player2.x + 1] == 'X' && a[player2.y + 2][player2.x +
				2] == 'X')
			||
			(a[player2.y - 3][player2.x - 3] == 'X' && a[player2.y -
				2][player2.x - 2] == 'X' && a[player2.y - 1][player2.x - 1] == 'X' &&
				a[player2.y][player2.x] == 'X' && a[player2.y + 1][player2.x + 1] ==
				'X')
			||
			(a[player2.y - 4][player2.x - 4] == 'X' && a[player2.y -
				3][player2.x - 3] == 'X' && a[player2.y - 2][player2.x - 2] == 'X' &&
				a[player2.y - 1][player2.x - 1] == 'X' && a[player2.y][player2.x] ==
				'X')
			||
			(a[player2.y + 4][player2.x + 4] == 'X' && a[player2.y +
				3][player2.x + 3] == 'X' && a[player2.y + 2][player2.x + 2] == 'X' &&
				a[player2.y + 1][player2.x + 1] == 'X' && a[player2.y][player2.x] ==
				'X')
			||
			(a[player2.y + 3][player2.x + 3] == 'X' && a[player2.y +
				2][player2.x + 2] == 'X' && a[player2.y + 1][player2.x + 1] == 'X' &&
				a[player2.y][player2.x] == 'X' && a[player2.y - 1][player2.x - 1] ==
				'X')
			) //对角线连线胜利
		{
			std::cout << " Player2 Win!" << endl;
			system("color 4A");
			break;
		}
		if (
			(a[player2.y - 2][player2.x] == 'X' && a[player2.y -
				1][player2.x] == 'X' && a[player2.y][player2.x] == 'X' && a[player2.y +
				1][player2.x] == 'X' && a[player2.y + 2][player2.x] == 'X')
			||
			(a[player2.y - 3][player2.x] == 'X' && a[player2.y -
				2][player2.x] == 'X' && a[player2.y - 1][player2.x] == 'X' &&
				a[player2.y][player2.x] == 'X' && a[player2.y + 1][player2.x] == 'X')
			||
			(a[player2.y - 4][player2.x] == 'X' && a[player2.y -
				3][player2.x] == 'X' && a[player2.y - 2][player2.x] == 'X' &&
				a[player2.y - 1][player2.x] == 'X' && a[player2.y][player2.x] == 'X')
			||
			(a[player2.y + 4][player2.x] == 'X' && a[player2.y +
				3][player2.x] == 'X' && a[player2.y + 2][player2.x] == 'X' &&
				a[player2.y + 1][player2.x] == 'X' && a[player2.y][player2.x] == 'X')
			||
			(a[player2.y + 3][player2.x] == 'X' && a[player2.y +
				2][player2.x] == 'X' && a[player2.y + 1][player2.x] == 'X' &&
				a[player2.y][player2.x] == 'X' && a[player2.y - 1][player2.x] == 'X')
			) //竖列连线胜利
		{
			std::cout << " Player2 Win!" << endl;
			system("color 4A");
			break;
		}
			
    if (
		(a[player2.y][player2.x - 2] == 'X' &&
		a[player2.y][player2.x - 1] == 'X' && a[player2.y][player2.x] == 'X' &&
		a[player2.y][player2.x + 1] == 'X' && a[player2.y][player2.x + 2] ==
		'X')
		||
		(a[player2.y][player2.x - 3] == 'X' &&
		a[player2.y][player2.x - 2] == 'X' && a[player2.y][player2.x - 1] ==
		'X' && a[player2.y][player2.x] == 'X' && a[player2.y][player2.x - 1] ==
		'X')
		||
		(a[player2.y][player2.x - 4] == 'X' &&
		a[player2.y][player2.x - 3] == 'X' && a[player2.y][player2.x - 2] ==
		'X' && a[player2.y][player2.x - 1] == 'X' && a[player2.y][player2.x] ==
		'X')
		||
		(a[player2.y][player2.x + 4] == 'X' &&
		a[player2.y][player2.x + 3] == 'X' && a[player2.y][player2.x + 2] ==
		'X' && a[player2.y][player2.x + 1] == 'X' && a[player2.y][player2.x] ==
		'X')
		||
		(a[player2.y][player2.x + 3] == 'X' &&
		a[player2.y][player2.x + 2] == 'X' && a[player2.y][player2.x + 1] ==
		'X' && a[player2.y][player2.x] == 'X' && a[player2.y][player2.x - 1] ==
		'X')
		) //横行连线胜利
			{
				std::cout << "Player2 Win!" << endl;
				system("color 4A");
				break;
			}
		}


		std::cout << "是否要重新开始新的一局（T/F）：";
		std::cin >> end;
		if (end == 'T')
		{
			system("color 0F");
			system("cls");
			goto begin;
		}
		else
			return 0;
	}
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
#define N 15 //�Զ������̴�С
using namespace std;

class location //��������������
{
public:
	int x; //ֱ������ϵ������
	int y; //ֱ������ϵ������
}player1, player2; //��� 1 Ϊ O ���壬��Ҷ�Ϊ X ����


int main(){
begin:
	std::cout << "*************************************************" <<
		endl;
	std::cout << "******************0���˳�************************" << endl;
	std::cout << "******************1����� VS ���******************" <<
		endl;
	std::cout << "*************************************************" <<
		endl;
	char a[N][N]; //��������
	char end = 0; //��ֽ���ʱ���ж�
	int x, y; //�����������
	int mode; //ģʽ
	std::cout << "ѡ������Ҫ�����ģʽ��";
	std::cin >> mode;
	for (y = 0; y < N; y++) //���̳�ʼ��
		for (x = 0; x < N; x++)
			a[y][x] = '*';
	system("cls");
	for (y = 0; y < N; y++) //��ʾ����
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

	while (mode) //��ʼ PVP ģʽ
	{
		std::cout << endl << "��������� 1��O �����ӣ��ĺᡢ�����꣬�Կո�ָ���";
		std::cin >> player1.x >> player1.y;
		system("cls");
		a[player1.y][player1.x] = 'O';
		for (y = 0; y < N; y++) //��ʾ����
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
			) //�Խ�������ʤ��
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
			) //��������ʤ��
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
			) //��������ʤ��

		{
			std::cout << " Player1 Win!" << endl;
			system("color 1A");
			break;
		}

		std::cout << endl << "��������� 2��X �����ӣ��ᡢ�����꣬�Կո�ָ���";
		std::cin >> player2.x >> player2.y;
		system("cls");
		a[player2.y][player2.x] = 'X';
		for (y = 0; y < N; y++) //��ʾ����
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
			) //�Խ�������ʤ��
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
			) //��������ʤ��
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
		) //��������ʤ��
			{
				std::cout << "Player2 Win!" << endl;
				system("color 4A");
				break;
			}
		}


		std::cout << "�Ƿ�Ҫ���¿�ʼ�µ�һ�֣�T/F����";
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
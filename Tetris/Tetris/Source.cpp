//#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>
//
//enum Status { Left, Right, Up, Down };
//
//struct Brick
//{
//	COORD pos;
//	int brick[4][3] = { 0 };
//	int num;
//	Status st;
//	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//	Brick()
//	{
//		num = 0;
//		pos.X = 1;
//		pos.Y = 1;
//	}
//};
//
//void Out(Brick b)
//{
//	COORD space;space = b.pos;
//	
//	space = b.pos;
//	if (b.num == 1)
//	{
//		b.brick[0][1] = 1;
//		b.brick[1][1] = 1;
//		b.brick[2][1] = 1;
//		b.brick[3][1] = 1;
//	}
//	else
//	{
//		if (b.num == 2)
//		{
//			b.brick[0][0] = 1;
//			b.brick[0][1] = 1;
//			b.brick[0][2] = 1;
//			b.brick[1][1] = 1;
//			b.brick[2][1] = 1;
//		}
//		else
//		{
//			if (b.num == 3)
//			{
//				b.brick[1][0] = 1;
//				b.brick[1][1] = 1;
//				b.brick[2][0] = 1;
//				b.brick[2][1] = 1;
//			}
//			else
//			{
//				if(b.num ==4)
//				{
//					b.brick[0][0] = 1;
//					b.brick[1][0] = 1;
//					b.brick[2][0] = 1;
//					b.brick[2][1] = 1;
//				}
//				else
//				{
//					if (b.num==5)
//					{
//						b.brick[0][1] = 1;
//						b.brick[1][1] = 1;
//						b.brick[2][1] = 1;
//						b.brick[2][0] = 1;
//					}
//					else
//					{
//						if (b.num == 6)
//						{
//							b.brick[0][1] = 1;
//							b.brick[0][2] = 1;
//							b.brick[1][1] = 1;
//							b.brick[2][0] = 1;
//							b.brick[2][1] = 1;
//						}
//						else
//						{
//							b.brick[0][0] = 1;
//							b.brick[0][1] = 1;
//							b.brick[1][1] = 1;
//							b.brick[2][1] = 1;
//							b.brick[2][2] = 1;
//						}
//					}
//				}
//			}
//		}
//	}
//	
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (b.brick[i][j] == 1)
//			{
//				SetConsoleCursorPosition(b.consoleHandle, space);
//				printf("%c",219);
//			}
//			else
//			{
//				printf(" ");
//				space.X++;
//			}
//			
//		}
//		
//		printf("\n");
//		space.X = 0;
//		space.Y++;
//		
//	}
//}
//
//void Rotate(Brick b)
//{
//
//}
//
//void Move(Brick &b)
//{
//	if (_kbhit())
//	{
//		char key = _getch();
//		if (key == 'a' || key == 'A')
//			b.st = Left;
//		else if (key == 'd' || key == 'D')
//			b.st = Right;
//		else if (key == 'w' || key == 'W')
//			b.st = Up;
//		else if (key == 's' || key == 'S')
//			b.st = Down;
//	}
//	if (b.st == Left)
//		b.pos.X--;
//	else
//	{
//		if (b.st == Right)
//			b.pos.X++;
//		else
//		{
//			if (b.st == Down)
//			{
//
//			}
//			else
//			{
//				if (b.st == Up)
//				{
//					Rotate(b);
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//
//	Brick a;
//	a.num = 1;
//	while (true)
//	{
//		system("cls");
//		Out(a);
//		Move(a);
//		Sleep(100);
//		
//	}
//	return 0;
//}
#include <Windows.h>
#include <stdio.h>
#include<conio.h>
#include <time.h>

#define Height 20
#define Width 20
#define Const 5
int field[Width][Height] = { 0 };
int figures[7][4] =
{
	1,3,5,7, //I
	2,4,5,7, //Z
	3,5,4,6, //S
	3,5,4,7, //T
	2,3,5,7, //L
	3,5,7,6, //J
	2,3,4,5, //O
};



bool check(COORD a[])
{
	for (int i = 0; i < 4; i++)
	{
		if (a[i].X<0 || a[i].Y >= Height ||a[i].X >=Width)
			return 0;
		else
		{
			if (field[a[i].Y][a[i].X])
				return 0;
		}
	}
	return 1;
}

int main()
{
	int speedcount = 0;
	int speed =0 ;
	int fps = 5;
	int deplay_time = 1000 / fps;
	int deltatime;
	bool fast = false;
	int m = 0;
	int num =1;
	int n;
	COORD screem;
	COORD brick[4] = { 0 }, temp[4];
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	while (true)
	{
		clock_t start = clock();
		srand(time(NULL));
		bool rotate = false;
		int dx = 0;
//-------------Set first position
		
		if (m == 0)
		{
			n = 3;
			for (int i = 0; i < 4; i++)
			{
				brick[i].X = figures[n][i] % 2 + 10;
				brick[i].Y = figures[n][i] / 2;
			}
		}
//-------------Move
		if (_kbhit())
		{
			char key = _getch();
			if (key == 'a' || key == 'A')
				dx = -1;
			else if (key == 'd' || key == 'D')
				dx = 1;
			else if (key == 'w' || key == 'W')
			{
				rotate = true;
			}
			else if (key == 's' || key == 'S')
			{
				fast = true;
			}
		}
		
//-------------Rotate
		if (rotate == true)
		{
			COORD temp1 = brick[1];
			for (int i = 0; i < 4; i++)
			{
				int x = brick[i].Y - temp1.Y;
				int y = brick[i].X - temp1.X;
				brick[i].X = temp1.X - x;
				brick[i].Y = temp1.Y + y;
			}
			if (!check(brick))
			{
				for (int i = 0; i < 4; i++)
				{
					brick[i] = temp[i];
				}
			}

		}
//----------Brick move left and right
		for (int i = 0; i < 4; i++)
		{
			temp[i] = brick[i];
			brick[i].X += dx;
			
		}
//----------limit Brick
		if (!check(brick))
		{
			for (int i = 0; i < 4; i++)
			{
				brick[i] = temp[i];
			}
		}
// Brick move down
		speedcount++;
		if (speedcount >= speed && fast ==false)
		{
			speedcount = 0;
			for (int i = 0; i < 4; i++)
			{
				brick[i].Y += m;
			}
		}
		if (fast == true)
		{
			for (int i = 0; i < 4; i++)
			{
				brick[i].Y += m;
			}
		}

//------------Create brick and set background	
		if(!check(brick))
		{ 
			fast = false;
			speed = Const;
	
			for (int  i = 0; i < 4; i++)
			{
				field[temp[i].Y][temp[i].X] = num;
			}
			num = 1 + rand() % 14;
			 n = rand() % 7;
			for (int i = 0; i < 4; i++)
			{
				brick[i].X = figures[n][i] % 2 + 10;
				brick[i].Y = figures[n][i] / 2;
			}
		}
	

//-----------full brick in cell
		int k = Height - 1;
		for (int i = Height - 1; i > 0; i--)
		{
			int count = 0;
			for (int j = 0; j < Width; j++)
			{
				if (field[i][j])
					count++;
				field[k][j] = field[i][j];

			}
			if (count < Width)
				k--;
		}

//----------Draw screem
		system("cls");
		for (int i = 0; i < 4; i++)
		{
			SetConsoleCursorPosition(consoleHandle, brick[i]);
			SetConsoleTextAttribute(consoleHandle, (0 << 4) | num);
			printf("%c", 219);

		}
		for (int i = 0;i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				COORD tempc;
				tempc.X = j;
				tempc.Y = i;
				if (field[i][j] == 0)
					continue;
				SetConsoleTextAttribute(consoleHandle, (0 << 4) | field[i][j]);
				SetConsoleCursorPosition(consoleHandle,tempc);
				printf("%c", 219);
			}
		}
		for (int i = 0; i < Height; i++)
		{
			screem.Y = i;
			screem.X = Width;
			SetConsoleCursorPosition(consoleHandle,screem );
			SetConsoleTextAttribute(consoleHandle, (0 << 4) | 15);
			printf("|");
			screem.X = i;
			screem.Y = Height;
			SetConsoleCursorPosition(consoleHandle, screem);
			SetConsoleTextAttribute(consoleHandle, (0 << 4) | 15);
			printf("-");
			if (i >= 10)
			{
				screem.Y = i;
				screem.X = Width;
				SetConsoleCursorPosition(consoleHandle, screem);
				SetConsoleTextAttribute(consoleHandle, (0 << 4) | 15);
				printf("|");
			}
		}
		/*screem.X = 100;
		screem.Y = 20;
		SetConsoleCursorPosition(consoleHandle, screem);*/
//---------Control FPS
		if (fast == true)
		{
			speed = speed / 3;
		}
		m = 1;
		deltatime = deplay_time - (clock() - start);
		if (deltatime > 0)
		{
			Sleep(deltatime);
		}
		fast = false;
		
	}
	return 0;
}
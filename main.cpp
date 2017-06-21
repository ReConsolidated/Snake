#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <conio.h>
#include "snake.h"
using namespace std;

enum Tiles
{
	blank = 0,
	apple = 1,
	head = 2,
	body = 3
};

void setupField(Tiles tile[20][20]);
void displayField(Tiles tile[20][20]);
void setApple(int &appleX, int &appleY);
void aktualizujHead(Snake &s_head);

int main()
{	
	Tiles tile[20][20];
	Snake s_head, nowhere;
	vector<Snake> part;
	int appleX, appleY;
	int punkty = 0;
	int direction = 3;


	srand(time(NULL));
	setupField(tile);
	displayField(tile);
	setApple(appleX, appleY);

	s_head.x = 10;
	s_head.y = 10;
	s_head.bx = 10;
	s_head.by = 10;
	
	part.push_back(nowhere);
	s_head.next = &part.at(0);
	s_head.hasNext = 1;
	part.at(0).x = 9;
	part.at(0).y = 10;
	


	while(1)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		setupField(tile);
		tile[appleX][appleY] = apple;
		for (int i = 0; i < part.size(); i++)
		{
 				tile[part.at(i).x][part.at(i).y] = body;

				
		}		
		tile[s_head.x][s_head.y] = head;
	
		if (s_head.x == appleX && s_head.y == appleY)
		{			
			part.push_back(nowhere);
			part.at(punkty).next = &part.at(punkty+1);
			part.at(punkty).hasNext = 1;
			s_head.next = &part.at(0);
			for (int i = 0; i < part.size()-1; i++)
			{
				part.at(i).next = &part.at(i + 1);

			}
			punkty++;
			setApple(appleX, appleY);
			
		}
		aktualizujHead(s_head);
		s_head.aktualizuj();
		if (_kbhit())
		{
			char x = _getch();
			if (x == 'w')
			{
				direction = 1;
			}
			if (x == 'd')
			{
				direction = 2;
			}
			if (x == 's')
			{
				direction = 3;
			}
			if (x == 'a')
			{
				direction = 4;
			}
		}
		if (direction == 1)
		{
			s_head.x--;
		}
		if (direction == 2)
		{
			s_head.y++;
		}
		if (direction == 3)
		{
			s_head.x++;
		}
		if (direction == 4)
		{
			s_head.y--;
		}
		for (int i = 0; i < part.size(); i++)
		{
			if (part.at(i).x == s_head.x && part.at(i).y == s_head.y)
			{
				cout << "Przegrales. Punkty: " << punkty << endl;
				system("pause");
				exit(0);
			}
		}
		if (s_head.x > 20 || s_head.x < -1 || s_head.y >20 || s_head.y < -1)
		{
			cout << "Przegrales. Punkty: " << punkty << endl;
			system("pause");
			exit(0);
		}
		
		system("cls");
		displayField(tile);
		

		
	}


}
		



void setupField(Tiles tile[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int o = 0; o < 20; o++)
		{
			tile[i][o] = blank;
		}
	}
}

void displayField(Tiles tile[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		cout << endl;
		for (int o = 0; o < 20; o++)
		{
			cout << tile[i][o];
		}
	}
	cout << endl << endl;
}

void setApple(int &appleX, int &appleY)
{
	appleX = rand() % 20;
	appleY = rand() % 20;
}


void aktualizujHead(Snake &s_head)
{
	s_head.bx = s_head.x;
	s_head.by = s_head.y;
}
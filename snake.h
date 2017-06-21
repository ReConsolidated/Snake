#pragma once


struct Snake
{
	int x = 0, y = 0;
	int bx = 0, by = 0;
	Snake *next;
	bool hasNext = 0;
	void aktualizuj()
	{
		if (hasNext == 1)
		{
			next->bx = next->x;
			next->x = bx;
			next->by = next->y;
			next->y = by;
			next->aktualizuj();
		}

	}
	
};


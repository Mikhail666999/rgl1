#include <ncurses.h>
#include <curses.h>
#include <string>
#include <unistd.h>
// #include "lib/Array2d.h"
#include "Player.cpp"

#define start initscr();start_color();keypad(stdscr, true);noecho();refresh();curs_set(0);

#define inp case
#define brk break;

#define color_player 1
#define color_button 2
#define color_wall   3

using std::string;

void drowButton(int cols, int rows, int keycode);
void pmove(int y, int x);
void input();
void dungeon(int dy, int dx, char (*map)[cols]);
void rooms(int dy, int dx, char (*map)[cols]);	

Player p;

int keycode = 0;
int work = true;

int main(void)
{
	p.name = "Yargus";
	p.i = '@';
	p.y = 20;
	p.x = 30;

	start
	
	init_pair(color_player, COLOR_GREEN, COLOR_BLACK);
	init_pair(color_wall,   COLOR_WHITE, COLOR_BLACK);
	init_pair(color_button,   COLOR_RED, COLOR_BLACK);

	int cols, rows;
	getmaxyx(stdscr, rows, cols);
	char map[rows][cols];
	// Array2D<int> map(rows, cols);

	
	while (work)
	{
		clear();
		dungeon(rows, cols, map);
		rooms(rows, cols, map);

		// drow player
		attron(COLOR_PAIR(color_player));
		mvaddch(p.y, p.x, p.i);
		attroff(COLOR_PAIR(color_player));

		// drowButton(rows, cols, keycode);

		input();
		sleep(0.5);	
	}
	endwin();
	return 0;
}

void pmove(int y, int x)
{
	if (y < 0)
	{
		if (map[p.y-1][p.x] == '#')
		{
			p.y += 0;
		}
		else
		{
			p.y += y;
		}
	}
	else if (y > 0)
	{
		if (map[p.y+1][p.x] == '#')
		{
			// p.y += y;
			p.y += 0;
		}
		else
		{
			p.y += y;
		}
	}
	
	if (x < 0)
	{
		if (map[p.y][p.x-1] == '#')
		{
			p.x += 0;
		}
		else
		{
			p.x += x;
		}
	}
	else if (x > 0)
	{
		if (map[p.y][p.x+1] == '#')
		{
			p.x += 0;
		}
		else
		{
			p.x += x;
		}
	}
}

void input()
{
	keycode = getch();
	switch (keycode)
	{
		inp KEY_LEFT:  pmove(0, -1);  brk
		inp KEY_RIGHT: pmove(0, 1);   brk
		inp KEY_UP:    pmove(-1, 0);  brk
		inp KEY_DOWN:  pmove(1, 0);  brk
		
		inp 'q': 
			work = false;
			brk
	}
}

void drowButton(int rows, int cols, int keycode)
{
	// attron(COLOR_PAIR(color_button));
	mvprintw(0, 0, "Cols: %d \nRows: %d", cols, rows);
	mvprintw(2, 0, "Key: '");
	printw("%c", keycode);
	printw("'");
	// attroff(COLOR_PAIR(color_button));
}

void dungeon(int rows, int cols, char (*map)[cols])
{
	for (int yy = 0; yy < rows; yy++)
	{
		for (int xx = 0; xx < cols; xx++)
		{
			attron(COLOR_PAIR(color_wall));
			map[yy][xx] = '#';
			mvprintw(yy, xx, "%c", map[yy][xx]);
			attroff(COLOR_PAIR(color_wall));
		}
	}
	
}

void rooms(int rows, int cols, char (*map)[cols])
{
	for (int yy = 10; yy < rows-5; yy++)
	{
		for (int xx = 15; xx < cols-20; xx++)
		{
			map[yy][xx] = '.';
			mvprintw(yy, xx, "%c", map[yy][xx]);
		}
	}
}











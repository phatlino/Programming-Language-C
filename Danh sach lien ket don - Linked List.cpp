#include<pthread.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

void xy(short x, short y);
int control(int num_control, int x, int y, const char* s[]);
void *_clock(void* time_clock);
void BGcolor(int code);

class my_time{
	public:
		int timeset, x, y;
	
		my_time(int times = 1000, int point_x = 0, int point_y = 0);
};

my_time::my_time(int times, int point_x, int point_y)
{
	timeset = times;
	x = point_x;
	y = point_y;
}



int main(void)
{
	/*const char *s[5] = { "Lua chon 1", "Lua chon 2", "Lua chon 3", "Lua chon 4", "Lua chon 5"};
	
	my_time a(1000, 0, 0);
	my_time b(500, 10, 0);
	pthread_t x, y;
	
	pthread_create(&x, NULL, _clock, &a);
	pthread_create(&y, NULL, _clock, &b);
	
	control(5, 0, 5, s);
	
	pthread_join(x, NULL);
	pthread_join(y, NULL);*/
	
	time_t start, end;
	start = clock();
	
	Sleep(1000);
	
	end = clock();
	
	printf("%d", end - start);
	
	return 0;
}
//==================================================
void *_clock(void* time_clock)
{
	my_time *a = (my_time*) time_clock;
	int count = 0;
	
	while(count < 100)
	{
		xy(a->x, a->y);
		printf("%d", count++);
		Sleep(a->timeset);
	}
}

int control(int num_control, int x, int y, const char* s[])
{//72 : len, 80 : xuong, 75 : trai, 77 : phai, 13 : enter, 27 : esc
	for (int i = 1; i < num_control; i++)
	{
		xy(x, y + i);
		printf("%s", s[i]);
	}
	
	int pick = 1;
	char c;
	bool check = true;
	do {
		xy(x, y + pick - 1);	BGcolor(142);	printf("%s", s[pick - 1]);
		c = getch();
		xy(x, y + pick - 1);	BGcolor(14);	printf("%s", s[pick - 1]);
		switch (c)
		{
		case 80: case 's':	(pick == num_control) ? pick = 1 : pick++;	break;
		case 72: case 'w':	(pick == 1) ? pick = num_control : pick--;	break;
		case 27:	pick = 0;	check = false;	break;
		case 13:	check = false;				break;
		}

	} while (check);
	return pick;
}

void BGcolor(int code)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

void xy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <conio.h>
int main()
{
	int repeat = 1;
	while(repeat)
	{
		printf("*");
		sleep(100);

		if(kbhit())
		{
			char ch = getch();
			switch(ch)
			{
				case 27:
				    repeat = 0;
				    break;
				case 32:
				    system("clear");
				    break;
			}
		}
	
	}
	return 0;
}

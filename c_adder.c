
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main()
{	
	srandom(time(NULL));
	int ones = 0;
	int tens = 0;
	int hunds = 0;
	int thous = 0;
	char guess[5] = "    \0"; 
				/* Search how does one represent an empty char?
				and How do I concatenate const/literal strings in C?
				Strings must end in an empty character. This solved
			q	an issue I was having with printing the string.*/

	bool gOnes = true;
	bool gTens = false;
	bool gHunds = false;
	bool gThous = false;
	bool maxedOut = false;
	int correct = 0;
	int guessed = 0;
	bool guessing = false;
	int count = 0;
	int exit = 0;
	initscr();			/* Start curses mode 		*/
	int row, col;
	getmaxyx(stdscr,row,col);
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..arar*/
	noecho();			/* Don't echo() while we do getch */
	int a,b,c,d;
    	printw(0,0,"Addition test!\n");
	while (exit==0)  {
	if (!guessing) {
		if (guess[3]!=32) {
			if (a+b+d==atoi(guess)) {
				correct++;
				mvprintw(5,1,"Correct! %i out of %i.\n",correct,guessed);
				
			} else {
				mvprintw(5,1,"Incorrect. %i out of %i.\n",correct,guessed);
			}
		}
		guess[0] = 32;
		guess[1] = 32;
		guess[2] = 32;
		guess[3] = 32;
		a = 100 + random() % 899;
		b = 100 + random() % 899;
		d = 100 + random() % 899;
		guessing = true;
		gOnes = true;
		guessed++;
	}
	mvprintw(1,1," %i\n",a);
	mvprintw(2,1," %i\n",b);
	attron(A_UNDERLINE);
	mvprintw(3,1,"+%i\n",d);
	attroff(A_UNDERLINE);
	mvprintw(4,1,"%s",guess);
	mvprintw(6,1,"Press esc to exit.");
	move(4,5);
	refresh();
	if (maxedOut) {
		c = getch();
		if (c == 127) {
			gThous = true;
			maxedOut = false;
			guess[0] = 32;
			mvprintw(4,1,"%s",guess);
			refresh();
		} if (c == 10) {
			guessing = false;
			maxedOut = false;
		} else if (c == 27) {
			exit = 1;
		}
	}
	if (gThous==true) {
		thous = getch();
		if (thous==127) {
			gThous = false;
			gHunds = true;
			guess[1] = 32;
			mvprintw(4,1,"%s",guess);
			refresh();
		} else if (thous==10) {
			guessing = false;
			gThous = false;
		} else if (thous >= 48 && thous <= 57) {
			gThous = false;
			guess[0] = thous;
			maxedOut = true;
		} else if (thous == 27) {
			exit = 1;
		}
	}
	if (gHunds==true) {
		hunds = getch();
		if (hunds==127) {
			gHunds = false;	
			gTens = true;
			guess[2] = 32;
			mvprintw(4,1,"%s",guess);
			refresh();
		} else if (hunds==10) {
			guessing = false;
			gHunds = false;
		} else if (hunds >= 48 && hunds <= 57) {
			gHunds = false;
			gThous = true;
			guess[1] = hunds;
		} else if (hunds == 27) {
			exit = 1;
		}
	}
	if (gTens==true) {
		tens = getch();
		if (tens==127) {
			gTens = false;
			gOnes = true;
			guess[3] = 32;
			mvprintw(4,1,"%s",guess);
			refresh();
		} else if (tens==10) {
			guessing = false;
			gTens = false;
		} else if (tens >= 48 && tens <=57) {
			gTens = false;
			gHunds = true;
			guess[2] = tens;
		} else if (tens == 27) {
			exit = 1;
		}
	}
	if (gOnes==true) {
		ones = getch();
		if (ones >= 48 && ones <=57) {
			gOnes = false;
			gTens = true;;
			guess[3] = ones;
		} else if (ones == 27) {
			exit = 1;
		}
	}
}
	erase();
	printw("TTFN.");
	refresh();
    	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}

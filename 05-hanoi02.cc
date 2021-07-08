#include<ncurses.h>
#include"Board.h"

using namespace std;


int main(){
    initscr();
    mvaddstr(0,0,"how many plate do they have?");
    int h;
    keypad(stdscr,false);
    h=getch()-48;

    Board hanoi(h);

    hanoi.help();
    mvaddstr(4,0,"(Type h for help)");
    hanoi.show2(h);
    char from_c,to_c;
    for(;;)
    {
        //get input
        from_c=getch();
        //Q or qなら抜ける
        if (from_c == 'Q' || from_c =='q'){
            break;
        }else if(from_c == 'H' || from_c =='h'){
            //initscr();
            hanoi.help();
            continue;
        }else if(from_c =='R'){
            hanoi.init_2(h);
            continue;
        }
        if(hanoi.step==100){
            break;
        }

        to_c=getch();
        hanoi.move(from_c,to_c);
        //mvaddstr(10,0,"moved");
        //move(from_c,to_c);
        hanoi.show2(h);
        //X Yなら移動度と表示
    }
    endwin();
}
"# hanoi" 

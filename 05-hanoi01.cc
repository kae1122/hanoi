
#include<ncurses.h>
#include<sstream>

using namespace std;
int board[3][6];
int step;
int plate_num[3];

void init(){
    step =1;
    board[2][0]=5;
    board[2][1]=4;
    board[2][2]=3;
    board[2][3]=2;
    board[2][4]=1;
    board[2][5]=0;
    for(int n=0;n<2;n++){
        for(int m=0;m<6;m++){
            board[n][m] =0;
        }
    }
    plate_num[0] =5;
    plate_num[1] =0;
    plate_num[2] =0;
    

}

void help(){
    //cout <<"X Y :  move from pole X to pole Y" <<endl;
    //cout <<"H   :  show this help" <<endl;
    //cout <<"Q   :  exit game" <<endl;
}

void show(){
    start_color();
    init_pair(1,COLOR_RED,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
    for(int x=0;x<5+1;x++){
        move(x,5);
        addstr("|");
    }
    for(int x=0;x<5+1;x++){
        move(x,5*3+1);
        addstr("|");
    }
    move(0,5*5+2);
    addstr("|");
    for(int x=1;x<5+1;x++){
        int y= 6-x;
        if(board[2][y-1]==0){
        move(x,5*5+2);
        addstr("|");           
        }else{
        attrset(COLOR_PAIR(1));
        for(int t=0;t<board[2][y-1]*2-1;t++){
        move(x,5*5+3-board[2][y-1]+t);
        addstr(" ");
        }            
        }
        attrset(COLOR_PAIR(2));
    }
    attrset(COLOR_PAIR(2));
    for(int y=0;y<5*6+3;y++){
        move(5+1,y);
        if(y==5|y==16|y==27){
            addstr("+");
        }else{
            addstr("-");
        }
    }
    mvaddstr(7,5,"A");
    mvaddstr(7,16,"B");
    mvaddstr(7,27,"C");       
}





int main(){
    initscr(); //新しい画面を作成する
    init();
    show();
     //文字列を表示する
    getch();//文字入力を待つ
    endwin();//作成した画面を削除する
}

"# hanoi" 
"# hanoi" 
"# hanoi" 

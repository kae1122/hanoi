#include<ncurses.h>
#include<vector>
#include<string>
#include<iostream>
#include"Plate.h"
#include"Pole.h"
#include"Board.h"


Board::Board(int x)
{
    step = 0;
    A = new Pole(x);
    B = new Pole(x);
    C = new Pole(x);
    A->init(x);
}
void Board::help()
{
    erase();
    mvaddstr(0,0,"X Y :  move from pole X to pole Y" );
    mvaddstr(1,0,"H   :  show this help");
    mvaddstr(2,0,"Q   :  exit game");
}

int Board::move(char from, char to)
{
    if (from == to) {
        return 0;
    }
    if (from == 'A') {
        if (to == 'B') {
            if (A->top() < B->top() || B->top() == 0) {
                int m = A->pop();
                B->sub(m);
                step++;
            }
        }
        if (to == 'C') {
            if (A->top() < C->top() || C->top() == 0) {
                int m = A->pop();
                C->sub(m);
                step++;
            }
        }
    }
    if (from == 'B') {
        if (to == 'C') {
            if (B->top() < C->top() ||C->top() == 0) {
                int m = B->pop();
                C->sub(m);
                step++;                    
            }

        }
        if (to == 'A') {
            if (B->top() < A->top()||A->top() == 0) {
                int m = B->pop();
                A->sub(m);
                step++;
            }                    
        }

    }
    if (from == 'C') {
        if (to == 'A') {
            if (C->top() < A->top()||A->top() == 0) {
                int m = C->pop();
                A->sub(m);
                step++;                    
            }
        }
        if (to == 'B') {
            if (C->top() < B->top()||C->top() == 0) {
                int m = C->pop();
                B->sub(m);
                step++;            
            }

        }
    }
    return 1;
}

void Board::show2(int h)
{
    erase();
    start_color();
    init_pair(1,COLOR_RED,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
    //move(0,h);
    mvaddstr(0,h,"|");
    for(int x=1;x<h+1;x++){
        int y= h+1-x;
        if(A->see(y-1)==0){
        //move(x,h);
        mvaddstr(x,h,"|");           
        }else{
        attrset(COLOR_PAIR(1));
        for(int t=0;t<A->see(y-1)*2-1;t++){
            //move(x,h-A->see(y-1)+t);
            mvaddstr(x,h+1-A->see(y-1)+t," ");
        }            
        }
        attrset(COLOR_PAIR(2));
    }
    //move(0,h*3+1);
    mvaddstr(0,h*3+1,"|");
    for(int x=1;x<h+1;x++){
        int y= h+1-x;
        if(B->see(y-1)==0){
        //move(x,h*3+1);
        mvaddstr(x,h*3+1,"|");           
        }else{
        attrset(COLOR_PAIR(1));
        for(int t=1;t<=B->see(y-1)*2-1;t++){
            //move(x,h*3+1-B->see(y-1)+t);
            mvaddstr(x,h*3+1-B->see(y-1)+t," ");
        }            
        }
        attrset(COLOR_PAIR(2));
    }
    //move(0,h*5+2);
    mvaddstr(0,h*5+2,"|");
    for(int x=1;x<h+1;x++){
        int y= h+1-x;
        if(C->see(y-1)==0){
        //move(x,h*5+2);
        mvaddstr(x,h*5+2,"|");           
        }else{
        attrset(COLOR_PAIR(1));
        for(int t=0;t<C->see(y-1)*2-1;t++){
            //move(x,h*5+3-C->see(y-1)+t);
            mvaddstr(x,h*5+3-C->see(y-1)+t," ");
        }            
        }
        attrset(COLOR_PAIR(2));
    }
    attrset(COLOR_PAIR(2));
    for(int y=0;y<h*6+3;y++){
        //move(7,y);
        if(y==h|y==h*3+1|y==h*5+2){
            mvaddstr(h+1,y,"+");
        }else{
            mvaddstr(h+1,y,"-");
        }
    }
    mvaddstr(7,h,"A");
    mvaddstr(7,h*3+1,"B");
    mvaddstr(7,h*5+2,"C");      
}          

void Board::init_2(int x){
    A->init(x);
    B->init_bc(x);
    C->init_bc(x);
    step =0;
}

"# hanoi" 

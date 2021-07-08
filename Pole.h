#ifndef Pole_H
#define Pole_H

#include<vector>
#include"Plate.h"

class Pole {
public:
    std::vector<Plate> ls;
    int plate_num; //枚数
    //int top_of_num; //topのplateの大きさ
    Pole(); //コンストラクタ(ダミー)
    Pole(int x);//引数付コンストラクタ(AとBとC)
    int init_bc(int m);

    int init(int m); //Aの配列を初期化する
    int top();//配列のトップを見る
    int pop(); //配列のトップを取り出す
    void sub(int n);//配列のトップの次に値を代入する

    int see(int i);
};


#endif /*Pole_H_*/"# hanoi" 

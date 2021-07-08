#include<vector>
#include<sstream>
#include<iostream>
#include"Pole.h"
#include"Plate.h"


Pole::Pole()
{

    } //コンストラクタ(ダミー)
Pole::Pole(int x)
{
    plate_num = 0;
    // top_of_num =0;
    for (int i = 0; i < x; i++) {
        ls.push_back(Plate(0));
    }
} //引数付コンストラクタ(AとBとC)
int Pole::init_bc(int m){
    plate_num =0;
    for(int i=0;i<m;i++){
        ls[i].setplate(0);
    }
}

int Pole::init(int m)
{
    plate_num = m;
    //top_of_num =m;
    for (int x = 0; x < m; x++) {
        ls[x].size = m - x;
    }
} //Aの配列を初期化する
int Pole::top()
{
    if(plate_num==0){
        return 0;
    }
    int i = ls[plate_num-1].size;
    return i;
} //配列のトップを見る
int Pole::pop()
{
    int s = ls[plate_num - 1].size;
    ls[plate_num - 1].size = 0;
    plate_num--;
    return s;
} //配列のトップを取り出す

void Pole::sub(int n)
{
    ls[plate_num].size = n;
    plate_num++;

} //配列のトップの次に値を代入する

int Pole::see(int i)
{
    int t = ls[i].size;
    return t;
}
"# hanoi" 

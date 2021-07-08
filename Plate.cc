#include<iostream>
#include"Plate.h"



Plate::Plate(int sz)
{ //コンストラクタで初期化している
    size = sz;
}
Plate::Plate(const Plate& plate1)
{
    size = plate1.size;
}
void Plate::setplate(int x){
    size =x;
}

"# hanoi" 

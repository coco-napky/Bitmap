#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;
#include "_bitmap.h"

int main()
{

    _Bitmap bitmap(10);
    bitmap.setBit(32*1);
    for(int c = 0 ; c<bitmap._size; c++)
    {
        int* _array = bitmap.getBitmap();
        int _int = _array[c];
        cout<<" " << c << " : ";
        bitset<32>bs((int)_int);
        cout<<bs<<endl;
    }


    getchar();
    getchar();
    return 0;
}

#include "_bitmap.h"


_Bitmap::_Bitmap()
{
    //ctor
}

_Bitmap::_Bitmap(int _size)
{
    this->_size = _size;
    _array = new int[_size];
    for(int c = 0;c<_size; c++)
        _array[c] = 0;
}

void _Bitmap::setBit(int _bit)
{
    int* _indexes = resolvePosition(_bit);
    int number_index = _indexes[0];
    int bit_index = _indexes[1];
    _array[number_index] = setBit(_array[number_index],bit_index);
}
void _Bitmap::resetBit(int _bit)
{
    int* _indexes = resolvePosition(_bit);
    int number_index = _indexes[0];
    int bit_index = _indexes[1];
    _array[number_index] = resetBit(_array[number_index],bit_index);
}
bool _Bitmap::checkBit(int _bit)
{
    int* _indexes = resolvePosition(_bit);
    int number_index = _indexes[0];
    int bit_index = _indexes[1];
    return checkBit(_array[number_index,bit_index]);
}

int* _Bitmap::resolvePosition(int _bit)
{
    int* _indexes = new int[2];
    _indexes[0] = floor(_bit/32); //index : array of integers
    _indexes[1] = _bit%32; //index : array of bits per int (32 bits; 0 - 31)
    return _indexes;
}

_Bitmap::~_Bitmap()
{
    //dtor
}

int _Bitmap::shiftBitLeft(int source, int n , int contador)
{
    return n>contador ?  shiftBitLeft(source<<1 , n , ++contador) : source;
}

int _Bitmap::shiftBitLeft(int source, int n )
{
    shiftBitLeft(source,n,0);
}

int _Bitmap::shiftBitRight(int source, int n , int contador)
{
    return n>contador ? shiftBitRight(source>>1 , n , ++contador) : source;
}

int _Bitmap::shiftBitRight(int source, int n )
{
    shiftBitRight(source,n,0);
}

bool _Bitmap::checkBit(int source, int position)
{
    return shiftBitLeft(1,position) & source;
}

int _Bitmap::setBit(int source, int position)
{
    return (checkBit(source,position)) ? source : shiftBitLeft(1,position) | source;
}

int _Bitmap::resetBit(int source, int position)
{
    return (checkBit(source,position)) ? ~(shiftBitLeft(1,position)) & source : source;
}

int* _Bitmap::getBitmap()
{
    return _array;
}



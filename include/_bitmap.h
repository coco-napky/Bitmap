#ifndef _BITMAP_H
#define _BITMAP_H
#include <math.h>
class _Bitmap
{
    public:
        _Bitmap();
        _Bitmap(int _size);
        int _size;
        virtual ~_Bitmap();
        void setBit(int _bit);
        void resetBit(int _bit);
        bool checkBit(int _bit);
        int* getBitmap();
    protected:
    private:
        int*_array;
        int shiftBitLeft(int source, int n);
        int shiftBitLeft(int source, int n, int contador);
        int shiftBitRight(int source, int n);
        int shiftBitRight(int source, int n, int contador);
        bool checkBit(int source, int position);
        int setBit(int source, int position);
        int resetBit(int source, int position);
        int* resolvePosition(int _bit);
};

#endif // _BITMAP_H

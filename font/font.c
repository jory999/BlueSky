#include "font.h"

extern const char font_code_global[94][16];

void DrawPoint(int x,int y,int color);//画一个点
void PutChar(int x,int y, char put_char, int color);//画一个字符

void DrawPoint(int x,int y,int color)
{
    char *p;
    p = (char*)(0xFD000000 + (800 * y + x) * 3);//计算某个像素的内存地址
    *(p+2) = (char)(color >> 16);//color是int型，4字节，最高字节保留不用，剩下为rgb，向右移动10位，把R值取出
    *(p+1) = (char)((color >> 8) & 0xFF);//向右移动8字节，然后 &0x11111111，得到G
    *p     = (char)(color & 0xFF);//同理，B值
    return;
}

void PutString(int x,int y, char* string, int color)//输出字符串，输出直到结尾为\0停止符
{
    int i=0;
    while(string[i] != '\0')
    {
        PutChar(x + 10 *i, y, *(string+i),color);//there are 2 pixels between char
        i++;
    }

}

void PutChar(int x,int y, char put_char, int color)//输出一个字符
{

    int i;
    if (put_char >= 0x21 && put_char <= 0x7e)
    {
        for (i=0;i<16;i++)//扫描点阵，从上到下16行
        {
            if((font_code_global[put_char-0x21][i] & 0x80) == 0x80) //compare font & 1000 0000
                DrawPoint(x+0,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x40) == 0x40) //compare font & 0100 0000
                DrawPoint(x+1,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x20) == 0x20) //compare font & 0010 0000
                DrawPoint(x+2,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x10) == 0x10) //compare font & 0001 0000
                DrawPoint(x+3,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x08) == 0x08) //compare font & 0000 1000
                DrawPoint(x+4,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x04) == 0x04) //compare font & 0000 0100
                DrawPoint(x+5,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x02) == 0x02) //compare font & 0000 0010
                DrawPoint(x+6,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x01) == 0x01) //compare font & 0000 0001
                DrawPoint(x+7,y+i,color);
        }
    }
}
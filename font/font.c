#include "font.h"



typedef int* va_list;
#define va_start(ap, A)   (ap = (int *)&(A) + 1)
#define va_arg(ap, T)     (*(T *)ap++)
#define va_end(ap)        ((void)0)
void DrawFontPoint(int x,int y,int color);
char *Int2String(int a, char *buf);
void PutCharHex(int x, int y, int color, char c);
void PutIntHex(int x,int y,int color, int a);
void PutChar(int x,int y, char put_char, int color);
//画出一个点
void DrawFontPoint(int x,int y,int color)
{
    char *p;
    p = (char*)(0xFD000000-0x8200 + (800 * y + x) * 3);
    *(p+2) = (char)(color >> 16);
    *(p+1) = (char)((color >> 8) & 0xFF);
    *p     = (char)(color & 0xFF);
    return;
}
//在(x,y)位置画一个字符
void PutChar(int x,int y, char put_char, int color)
{

    int i;
    if (put_char >= 0x21 && put_char <= 0x7e)
    {
        for (i=0;i<16;i++)
        {
            if((font_code_global[put_char-0x21][i] & 0x80) == 0x80) //compare font & 1000 0000
                DrawFontPoint(x+0,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x40) == 0x40) //compare font & 0100 0000
                DrawFontPoint(x+1,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x20) == 0x20) //compare font & 0010 0000
                DrawFontPoint(x+2,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x10) == 0x10) //compare font & 0001 0000
                DrawFontPoint(x+3,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x08) == 0x08) //compare font & 0000 1000
                DrawFontPoint(x+4,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x04) == 0x04) //compare font & 0000 0100
                DrawFontPoint(x+5,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x02) == 0x02) //compare font & 0000 0010
                DrawFontPoint(x+6,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x01) == 0x01) //compare font & 0000 0001
                DrawFontPoint(x+7,y+i,color);
        }
    }
}
//在x,y位置输出一个字符串
void PutString(int x, int y, int color, const char * s)
{
    int i=0;
    while (*s)
    {
        PutChar(x+8*i,y,*s++,color);
        i++;
    }
}
//把int转化为一个字符串
char *Int2String(int a, char *buf)
{
    int num = a;
    int i = 0;
    int len = 0;

    do 
    {
        buf[i++] = num % 10 + '0';
        num /= 10;        
    } while (num);
    buf[i] = '\0';

    len = i;
    for (i = 0; i < len/2; i++)
    {
        char tmp;
        tmp = buf[i];
        buf[i] = buf[len-i-1];
        buf[len-i-1] = tmp;
    }

    return buf;    
}

//输出一个16进制字符穿
void PutCharHex(int x, int y, int color, char c)
{
    char * hex = "0123456789ABCDEF";
    PutChar(x,y,hex[(c>>4) & 0x0F],color);
    PutChar(x+8,y,hex[(c>>0) & 0x0F],color);
}
//输出一个int的16进制字符串
void PutIntHex(int x,int y,int color, int a)
{
    PutCharHex(x,y,color, (a>>24) & 0xFF );
    PutCharHex(x+16,y,color, (a>>16) & 0xFF );
    PutCharHex(x+32,y,color, (a>>8) & 0xFF );
    PutCharHex(x+48,y,color, (a>>0) & 0xFF );
}
/* //printf主函数
int printf(int x, int y, int color, const char * format, ...)
{
    char c;    
    va_list ap;
    va_start(ap, format);
    int i=0;
    while ((c = *format++) != '\0')
    {
    i++;
        switch (c)
        {
            case '%':
                c = *format++;
                switch (c)
                {
                    char ch;
                    char * p;
                    int a;
                    char buf[100];            
                    case 'c':
                        ch = va_arg(ap, int);
                        PutChar(x+8*i,y,ch,color);
                        break;
                    case 's':
                        p = va_arg(ap, char *);
            PutString(x+8*i, y, color, p);
                        break;                    
                    case 'x':
                        a = va_arg(ap, int);
                        PutIntHex(x,y,color,a);
                        break;        
                    case 'd':
                        a = va_arg(ap, int);
                        Int2String(a, buf);
                        PutString(x+8*i, y, color, buf);
                        break;    

                    default:
                        break;
                }                
                break;        

            default:
                PutChar(x+8*i,y,c,color);
                break;
        }
    }
    return 0;    
} */
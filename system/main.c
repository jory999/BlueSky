#include "../font/font.h"

extern void FunctionCli(void);
extern void FunctionOut8(int port, int data);
extern int FunctionLoadEflags(void);
extern void FunctionStoreEflags(int eflags);

/* extern void DrawPoint(int x,int y,int color);//画一个点
extern void PutChar(int x,int y, char put_char, int color);//画一个字符
extern void PutString(int x,int y, char* string, int color);//输出字符串，输出直到结尾为\0停止符
 */
void InitPalette();
void DrawRectangle(int x1,int y1,int x2,int y2,int color);
#define PALETTE_NUMBER 14

void SysMain()
{
   //const char * p="hello world\0";

    //InitPalette();
     PutChar(100,130, 'A', 11);
     PutChar(100,20, 'C', 0xffffff);
    //PutString( 10, 10,0xffffff, "hello world\0" );

    //PutString(100, 100,"hello world\0" ,0xff0000);
    
    DrawRectangle(10,50,100,150,10);
    //DrawRectangle(100,10,200,100,12);
    DrawRectangle(50,100,150,200,11);
    DrawRectangle(100,100,200,200,9); 

    PutString( 100, 10,11, "hello world\0" );

    while(1);
}

void InitPalette()
{
    int i,eflags;
    static unsigned char table_rgb [PALETTE_NUMBER*3] = {
    0xFF,0xFF,0xFF, //0、白色
    0xDD,0xDD,0xDD, 
    0xC0,0xC0,0xC0,
    0x96,0x96,0x96,
    0x80,0x80,0x80,
    0x64,0x64,0x64,
    0x4B,0x4B,0x4B,
    0x24,0x24,0x24,
    0x00,0x00,0x00, //8.黑色
    0xFF,0xFF,0x00, //9、黄色
    0xFF,0xCC,0x00, //10、淡橙色
    0xFF,0x99,0x00, //11、深橙色
    0xFF,0x66,0x00, //12、更深的橙色
    0xFF,0x00,0x00  //13、红色
    };

    eflags = FunctionLoadEflags();
    FunctionCli();
    FunctionOut8(0x03c8,0);
    for (i=1;i<=PALETTE_NUMBER;i++)
    {
        FunctionOut8(0x03c9,table_rgb[3*i-3]);
        FunctionOut8(0x03c9,table_rgb[3*i-2]);
        FunctionOut8(0x03c9,table_rgb[3*i-1]);
    }
    FunctionStoreEflags(eflags);
    return;
}

void DrawRectangle(int x1,int y1,int x2,int y2,int color)
{
    int i,j;
    char *p;
    for (i=y1;i<=y2;i++)
    {

        for (j=x1;j<=x2;j++)
        {
            p = (char*)(0xa0000 + 320 * i + j);
            *p = color;
        }
    }
    return;
}
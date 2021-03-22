void DrawCursorPoint(int x,int y,int color);

 //type:0、箭头
void DrawCursor(int x,int y, int type)
{
    static char cursor_point[16][16] = {
        "**************  ",
        "*11111111111*   ",
        "*1111111111*    ",
        "*111111111*     ",
        "*11111111*      ",
        "*1111111*       ",
        "*1111111*       ",
        "*11111111*      ",
        "*1111**111*     ",
        "*111*  *111*    ",
        "*11*    *111*   ",
        "*1*      *111*  ",
        "*         *111* ",
        "           *111*",
        "            *11*",
        "             ***",
    };
    int i,j;
    int *cursor_type;
    char *point;
    if (type == 0)
    {
        point = &cursor_point[0][0];
    }

    for (i=0;i<16;i++)
    {
        for (j=0;j<16;j++)
        {
            if (*point == '*')
                DrawCursorPoint(x+j,y+i,0xffff00);
            if (*point == '1')
                DrawCursorPoint(x+j,y+i,0xffffff);
            point++;
        }


    }
}



void DrawCursorPoint(int x,int y,int color)
{
    char *p;
    p = (char*)(0xFD000000 + (800 * y + x) * 3);
    *(p+2) = (char)(color >> 16);
    *(p+1) = (char)((color >> 8) & 0xFF);
    *p     = (char)(color & 0xFF);
    return;
}
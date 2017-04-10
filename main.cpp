//Program to draw a Line using Bresenhem and DDA Algorithms.

/*
 * Created by Devashish Katoriya on 10-04-2017
 */

#include <math.h>
#include <iostream>
#include <graphics.h>

using namespace std;

int Sign(double x)
{
    if(x>0)
        return 1;
    else if(x<0)
        return -1;
    else
        return 0;
}

void DDALine(int x1,int y1,int x2,int y2)                       //DDA Line
{
    int i;
    double dx,dy,x,y,length;

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if(dx>=dy)
        length = dx;
    else
        length = dy;
    dx = (x2-x1)/length;
    dy = (y2-y1)/length;

    x = x1 + (0.5*Sign(dx));
    y = y1 + (0.5*Sign(dy));

    i = 1;
    while(i<=length)
    {
        x = x + dx;
        y = y + dy;
        delay(5);
        putpixel(int(x),int(y),WHITE);
        i++;
    }
}

void BresenhemLine(int x1,int y1,int x2,int y2)                 //Bresenhem Line
{
    int i,e,dx,dy,x,y,s1,s2,exchange;

    dx = abs(x2-x1);
    dy = abs(y2-y1);

    x = x1;
    y = y1;
    putpixel(x,y,WHITE);

    s1 = Sign(x2-x1);
    s2 = Sign(y2-y1);

    if(dy>dx)
        exchange = 1;
    else
        exchange = 0;
    e = (2*dy) - dx;
    for(i=1;i<=dx;i++)
    {
        while (e>=0)
        {
            if(exchange==1)
                x = x + s1;
            else
                y = y + s2;
            e = e - (2*dx);
        }
        if(exchange==1)
            y = y + s2;
        else
            x = x + s1;
        e = e + (2*dy);
        delay(5);
        putpixel(x,y,WHITE);
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int ch,x1,y1,x2,y2;

    cout<<"\nProgram to draw a Line using Bresenhem and DDA Algorithms.";
    do
    {
        ch = 0;
        cout<<"\n\n-------------------------------------";
        cout<<"\n 1 for Bresenhem Line";
        cout<<"\n 2 for DDA Line";
        cout<<"\n 0  to Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"-------------------------------------\n";
        switch(ch)
        {
            case 1: cout<<"\nEnter co-ordinates :- \n";
                    cin>>x1>>y1>>x2>>y2;
                    BresenhemLine(x1,y1,x2,y2);
                    cout<<"\nLine drawn Successfully!";
                    break;
            case 2: cout<<"\nEnter co-ordinates :- \n";
                    cin>>x1>>y1>>x2>>y2;
                    DDALine(x1,y1,x2,y2);
                    cout<<"\nLine drawn Successfully!";
                    break;
            case 0: break;
            default:cout<<"\nInvalid Option!";
        }
    }while(ch!=0);

    closegraph();
    cout<<"\nThank you for using this program :) \n\n";
    return 0;
}
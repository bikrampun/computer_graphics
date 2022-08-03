//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//using translation and scaling
int tx=100,ty=100;
float sx=0.4,sy=0.4;
#include<math.h>
float th=0.23;
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//2D viewing pipeline
    //this is the coordinates of required triangle
	int triangle[3][2]={{-50,0},{0,50},{50,0}};
    //Declare struct variable
    POINT p[3];
    Form1->Refresh();
    for(int i=0;i<3;i++){
    	/*
    	p[i].x=triangle[i][0]*sx+tx;
        //here minus - jst reflect the triangle
        p[i].y= -triangle[i][1]*sy+ty;
        //it stores the coords in p
        */
        p[i].x=triangle[i][0]*cos(th)-triangle[i][1]*sin(th)+tx;
        p[i].y= triangle[i][0]*sin(th)+triangle[i][1]*cos(th)+ty;
    }
    Form1->Canvas->Polygon(p,sizeof(p)/sizeof(POINT)-1);
    tx+=10;
    th+=0.23;
    //it moves triangle by 10points
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int triangle[8][2]={{30,50},{50,30},{50,-30},{30,-50},
    					{-30,-50},{-50,-30},{-50,30},{-30,50}};
    //Declare struct variable
    POINT p[8];
    Form1->Refresh();
    for(int i=0;i<8;i++){
    	/*
    	p[i].x=triangle[i][0]*sx+tx;
        //here minus - jst reflect the triangle
        p[i].y= -triangle[i][1]*sy+ty;
        //it stores the coords in p
        */
        p[i].x=(triangle[i][0]*cos(th)-triangle[i][1]*sin(th))*sx+tx;
        p[i].y=(triangle[i][0]*sin(th)+triangle[i][1]*cos(th))*sy+ty;
    }
    Form1->Canvas->Polygon(p,sizeof(p)/sizeof(POINT)-1);
    tx+=10;
    th+=0.23;
    POINT p1[8];
    for(int i=0;i<8;i++){
        p1[i].x=(triangle[i][0]*cos(th)-triangle[i][1]*sin(th))*sx+tx+110;
        p1[i].y=(triangle[i][0]*sin(th)+triangle[i][1]*cos(th))*sy+ty;
    }
    Form1->Canvas->Polygon(p1,sizeof(p1)/sizeof(POINT)-1);
    //movet0 started and lineto ending point
    Form1->Canvas->MoveTo(18+tx,100);
    Form1->Canvas->LineTo(88+tx,100);
    //middle line between polygon
    Form1->Canvas->MoveTo(135+tx,100);
    //start after polygon
	Form1->Canvas->LineTo(200+tx,100);

    Form1->Canvas->LineTo(200+tx,50);
    //change into y axis
    Form1->Canvas->LineTo(150+tx,50);
    Form1->Canvas->LineTo(150+tx,10);
    Form1->Canvas->LineTo(-32+tx,10);
    Form1->Canvas->LineTo(-32+tx,70);
    //making tail of vechile
    Form1->Canvas->LineTo(-48+tx,70);
    Form1->Canvas->LineTo(-48+tx,100);
    Form1->Canvas->LineTo(-32+tx,100);
}
//---------------------------------------------------------------------------
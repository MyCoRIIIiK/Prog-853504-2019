//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MineSweeper.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap *Picture;// ��� ������������ ��������
TPanel *ArrayOfPanels[2];//������ �������
TImage *ArrayOfImages[6];//������ ��������
TBitBtn *FaceButton;//������ � �����
bool isLose = 0,isWin = 0;//�������� �� �������� � �������
unsigned int BombCount = 10,Size = 9;//��� �������� �������� ������

class MineSweeper
{
public:
unsigned short int BombCount = 0;
unsigned int CountOfOpen = 0;
bool isBomb;
bool isEmpty;
bool isOpen;
bool isFlag;

};

MineSweeper MineSweeperArray[32][32];

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall  TForm1::CountBombsNearCells(unsigned int Size)////////////���������� ������ �������
{
	int num = 0;
	for(int j = 1; j < Size - 1 ; j++)
	{
		for(int i = 1;i < Size - 1; i++ ,num = 0)
		{
			if(MineSweeperArray[i+1][j].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i-1][j].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i][j+1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i][j-1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i+1][j+1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i+1][j-1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i-1][j-1].isBomb) //�����
			{
				num++;
			}
			if(MineSweeperArray[i-1][j+1].isBomb)
			{
				num++;
			}
			MineSweeperArray[i][j].BombCount = num;
		}
	}
		 for(int i = 1; i < Size - 1;i++,num = 0)
		 {
			if(MineSweeperArray[0][i-1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[0][i+1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[1][i-1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[1][i+1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[1][i].isBomb)
			{
				num++;
			}
			MineSweeperArray[0][i].BombCount = num;      //����� ����
		 }

		 for(int i = 1;i < Size - 1; i++ , num = 0)
		 {
			if(MineSweeperArray[Size-1][i-1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[Size-1][i+1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[Size-2][i-1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[Size-2][i+1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[Size-2][i].isBomb)//������ ����
			{
				num++;
			}
			MineSweeperArray[Size-1][i].BombCount = num;
		 }

		 for(int i = 1;i < Size - 1;i++,num = 0)
		 {
			if(MineSweeperArray[i-1][0].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i+1][0].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i+1][1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i][1].isBomb)
			{
				num++;
			}
			if(MineSweeperArray[i-1][1].isBomb)//����
			{
				num++;
			}
			MineSweeperArray[i][0].BombCount = num;
		 }
		 for(int i = 1;i < Size - 1;i++,num = 0)
		 {
				if(MineSweeperArray[i-1][Size-1].isBomb)
				{
					num++;
				}
				if(MineSweeperArray[i+1][Size-1].isBomb)
				{
					num++;
				}
				if(MineSweeperArray[i+1][Size-2].isBomb)
				{
					num++;
				}
				if(MineSweeperArray[i][Size-2].isBomb)
				{
					num++;
				}
				if(MineSweeperArray[i-1][Size-2].isBomb)
				{
					num++;
				}
				MineSweeperArray[i][Size-1].BombCount = num;      //���
		 }
		 num = 0;

		 if(MineSweeperArray[0][1].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[1][0].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[1][1].isBomb)
		 {
			num++;
		 }
		 MineSweeperArray[0][0].BombCount = num;

		 num = 0;

		 if(MineSweeperArray[0][Size-2].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[1][Size-2].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[1][Size-1].isBomb)
		 {
			num++;
		 }
		 MineSweeperArray[0][Size-1].BombCount = num;

		 num = 0;

		 if(MineSweeperArray[Size-2][0].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[Size-2][1].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[Size-1][1].isBomb)
		 {
		 num++;
		 }
		 MineSweeperArray[Size-1][0].BombCount = num;

		 num=0;

		 if(MineSweeperArray[Size-1][Size-2].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[Size-2][Size-2].isBomb)
		 {
			num++;
		 }
		 if(MineSweeperArray[Size-2][Size-1].isBomb)
		 {
			num++;
		 }
		 MineSweeperArray[Size-1][Size-1].BombCount = num;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PushBombs(unsigned int Size,unsigned int BombCount)
{
	randomize();
	TList*list=new TList();

		for(int i = 0;i < Size*(long)Size;i++)
		{
			list->Add((void*)i);
		}
		for(int i=0; i < BombCount;i++)
		{
			int pos = random(list->Count);
			int mesto = (int)list->Items[pos];
			list->Delete(pos);
			int y=mesto/Size;
			int x = mesto-(y*Size);
			MineSweeperArray[x][y].isBomb = true;
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CreateField(unsigned int Size,unsigned int BombCount)
{

int i = 0;
int j = 0;


PaintBox1->Canvas->Font->Size=13;
PaintBox1->Canvas->Font->Color=clWhite;
PaintBox1->Top = 70;
PaintBox1->Left = 10;
PaintBox1->Height = 1+15*Size;
PaintBox1->Width = 15*Size;

//////////////////////////////////////////////////������������� ������
for(j = 0; j < Size; j++)
{
	for(i = 0; i < Size; i++)
	{
		MineSweeperArray[i][j].isBomb = 0;
		MineSweeperArray[i][j].isOpen = 0;
		MineSweeperArray[i][j].isEmpty = 1;
		MineSweeperArray[i][j].isFlag = 0;
	}
}

/////////////���������� ����
PushBombs(Size,BombCount);

/////////////���������� ������ �������
CountBombsNearCells(Size);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawField(unsigned int Size)
{

	int i = 0;
	int j = 0;

	Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
	Picture->LoadFromFile("ButtonTypes\\Cell.bmp");

	for(j = 0; j < Size; j++)
	{
		for(i = 0; i < Size; i++)
		{

		PaintBox1->Canvas->Draw(i*15,j*15,Picture);
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::WhatIsNumber(int XPos,int YPos)
{
	if(MineSweeperArray[XPos][YPos].BombCount == 1)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\1.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}
if(MineSweeperArray[XPos][YPos].BombCount == 2)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\2.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}

if(MineSweeperArray[XPos][YPos].BombCount == 3)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\3.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}

if(MineSweeperArray[XPos][YPos].BombCount == 4)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\4.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}

if(MineSweeperArray[XPos][YPos].BombCount == 5)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\5.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}

if(MineSweeperArray[XPos][YPos].BombCount == 6)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\6.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}

if(MineSweeperArray[XPos][YPos].BombCount == 7)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\7.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}

if(MineSweeperArray[XPos][YPos].BombCount == 8)
{
Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("ButtonTypes\\8.bmp");
PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckRekursively(int x, int y)
{


		if((x > Size-1)||(x < 0)||(y > Size-1)||(y <0 ))
		{
		return;
		}

if(!MineSweeperArray[x][y].isOpen)
		{
		WhatIsNumber(x,y);
		MineSweeperArray[x][y].isOpen = true;
		++MineSweeperArray[x][y].CountOfOpen;//���������� � ���������� ������� �����
		if(MineSweeperArray[x][y].BombCount == 0)
				{
				Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
				Picture->LoadFromFile("ButtonTypes\\EmptyCell.bmp");
				PaintBox1->Canvas->Draw(x*15,y*15,Picture);
				CheckRekursively(x+1,y);
				CheckRekursively(x-1,y);
				CheckRekursively(x,y+1);
				CheckRekursively(x,y-1);

				CheckRekursively(x+1,y+1);
				CheckRekursively(x-1,y-1);
				CheckRekursively(x-1,y+1);
				CheckRekursively(x+1,y-1);
				}
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Win()
{
 int CountOfDigits = BombCount*9;
 int check = 0;

 for(int j = 0; j < Size; j++)
 {
	for(int i = 0; i < Size; i++)
	{
	 if(MineSweeperArray[i][j].BombCount != 0 && MineSweeperArray[i][j].isFlag == false && MineSweeperArray[i][j].isBomb == false)
	 {
	 ++check;
	 }
	}
 }

 if(CountOfDigits == check)
 {
  isWin = 1;
 }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::OpenAll()
{
 for(int j = 0; j < Size; j++)
 {
	for(int i = 0; i < Size; i++)
	{
		if(!MineSweeperArray[i][j].isOpen)
		{

			if(MineSweeperArray[i][j].isBomb == true && MineSweeperArray[i][j].isFlag == true)//���� ����� ������ ����,��������� ����
			{
				Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
				Picture->LoadFromFile("ButtonTypes\\Flag.bmp");
				PaintBox1->Canvas->Draw(i*15,j*15,Picture);
			}
			if(MineSweeperArray[i][j].isBomb == false && MineSweeperArray[i][j].isFlag == true)//���� ���� ������ �� �����,������ ���������� �����
			{
				Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
				Picture->LoadFromFile("ButtonTypes\\CrossedOutBomb.bmp");
				PaintBox1->Canvas->Draw(i*15,j*15,Picture);
			}
			if(MineSweeperArray[i][j].isBomb == true && MineSweeperArray[i][j].isFlag == false)//���� ����� ����� �� ���������,������� �����.
			{
				Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
				Picture->LoadFromFile("ButtonTypes\\Bomb.bmp");
				PaintBox1->Canvas->Draw(i*15,j*15,Picture);
			}
			if(MineSweeperArray[i][j].BombCount == 0 && MineSweeperArray[i][j].isFlag == false && MineSweeperArray[i][j].isBomb == false )//���� ������ ������
			{
                Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
				Picture->LoadFromFile("ButtonTypes\\EmptyCell.bmp");
				PaintBox1->Canvas->Draw(i*15,j*15,Picture);
			}
			if(MineSweeperArray[i][j].BombCount != 0 && MineSweeperArray[i][j].isFlag == false && MineSweeperArray[i][j].isBomb == false)
			{
			WhatIsNumber(i,j);//�������� �����
			}
			MineSweeperArray[i][j].isOpen = true;
			++MineSweeperArray[i][j].CountOfOpen;//���������� � ���������� ������� �����
		}

	}
 }
}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
CreateField(9,10);
CreateGame(9);


}

void __fastcall TForm1::CreateGame(unsigned int Size)
{
//////////////////////////////////������� �������� �����
Form1->ClientHeight = 80+15*Size;
Form1->ClientWidth = 20+15*Size;
Form1->Color = clWhite;
///////////////////////////////////////������������ �������� ������
ArrayOfPanels[0]  = new TPanel (this);
ArrayOfPanels[0] ->Parent = this;
ArrayOfPanels[0] ->ParentBackground = false;//��� ���� ����� �������� ������
ArrayOfPanels[0] ->BorderStyle = bsSingle;//������ ���������� ��������
ArrayOfPanels[0] ->Color = cl3DLight;
ArrayOfPanels[0] ->Top = 0;
ArrayOfPanels[0] ->Left = 0;
ArrayOfPanels[0] ->Height = 65;
ArrayOfPanels[0] ->Width = 21+15*Size;
ArrayOfPanels[0] ->OnMouseDown = FaceButtonMouseDown;//������� �������
ArrayOfPanels[0] ->OnMouseUp =  FaceButtonMouseUp;//������� �������
///////////////////////////////////////������������ �������� ������
ArrayOfPanels[1] = new TPanel (this);
ArrayOfPanels[1]->Parent = this;
ArrayOfPanels[1]->BorderStyle = bsSingle;//������ ���������� ��������
ArrayOfPanels[1]->Color = clWhite;
ArrayOfPanels[1]->Top = 12;
ArrayOfPanels[1]->Left = 10;
ArrayOfPanels[1]->Height = 40;
ArrayOfPanels[1]->Width = 15*Size;
ArrayOfPanels[1]->OnMouseDown = FaceButtonMouseDown;//������� �������
ArrayOfPanels[1]->OnMouseUp =  FaceButtonMouseUp;//������� �������

/////////////////////////������������ �������� ������ � ����� �� ������� ������

Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
Picture->LoadFromFile("Emotions\\Smile.bmp");

FaceButton = new TBitBtn (this);
FaceButton->Parent = this;
FaceButton->Top = 17;
FaceButton->Left = ((15*Size) - 30)/2 + 10;
FaceButton->Height = 30;
FaceButton->Width = 30;
FaceButton->Glyph = Picture;
FaceButton->OnClick = New1Click;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::New1Click(TObject *Sender)
{
CreateGame(Size);
CreateField(Size,BombCount);
DrawField(Size);
isLose = 0;
isWin = 0;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Beginner1Click(TObject *Sender)
{
BombCount = 10,Size = 9;
CreateGame(Size);
CreateField(Size,BombCount);
DrawField(Size);
isLose = 0;
isWin = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Intermediate1Click(TObject *Sender)
{
BombCount = 40,Size = 16;
CreateGame(Size);
CreateField(Size,BombCount);
DrawField(Size);
isLose = 0;
isWin = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Expert1Click(TObject *Sender)
{
BombCount = 135,Size = 32;
CreateGame(Size);
CreateField(Size,BombCount);
DrawField(Size);
isLose = 0;
isWin = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Close();
}
void __fastcall TForm1::IFDead()
{
 Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
 Picture->LoadFromFile("Emotions\\Lose.bmp");
 FaceButton->Glyph = Picture;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FaceButtonMouseDown(TObject *Sender, TMouseButton Button,TShiftState Shift, int X, int Y)
{
	Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
	Picture->LoadFromFile("Emotions\\Click.bmp");
	FaceButton->Glyph = Picture;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FaceButtonMouseUp(TObject *Sender, TMouseButton Button,TShiftState Shift, int X, int Y)
{
	if(isLose == 0)
	{
	Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
	Picture->LoadFromFile("Emotions\\Smile.bmp");
	FaceButton->Glyph = Picture;
	}
	if(isLose == 1)
	{
	Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
	Picture->LoadFromFile("Emotions\\Lose.bmp");
	FaceButton->Glyph = Picture;
	}
	if(isWin == 1)
	{
	Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
	Picture->LoadFromFile("Emotions\\Win.bmp");
	FaceButton->Glyph = Picture;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox1MouseDown(TObject *Sender, TMouseButton Button,TShiftState Shift, int X, int Y)
{

	int XPos=X/15;
	int YPos=Y/15;

if(MineSweeperArray[XPos][YPos].isOpen == 1)
{
	return;
}

if(Button == mbLeft)
{
	FaceButtonMouseDown(Sender,Button,Shift,X,Y);//��� ��������� �������� ������ � �����



	if(MineSweeperArray[XPos][YPos].BombCount == 0)
	{
		CheckRekursively(XPos, YPos);//���� ������ ������ ������
	}

	if(MineSweeperArray[XPos][YPos].isBomb == true)
	{

	Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
	Picture->LoadFromFile("ButtonTypes\\RedBomb.bmp");
	PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
	MineSweeperArray[XPos][YPos].isOpen = true;
    isLose = 1;
	OpenAll();

	}
	else
	{
	WhatIsNumber(XPos,YPos);//�������� �����
	Win();
	}
}
	if(Button == mbRight)//���� ������ �������
	{
		if(MineSweeperArray[XPos][YPos].isFlag == 1)
		{
		Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
		Picture->LoadFromFile("ButtonTypes\\Cell.bmp");
		PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
		MineSweeperArray[XPos][YPos].isFlag = 0;
		return;
		}

		if(MineSweeperArray[XPos][YPos].isFlag == 0)
		{
		Picture = new Graphics::TBitmap();//��� ���� ����� ��������� ��������
		Picture->LoadFromFile("ButtonTypes\\Flag.bmp");
		PaintBox1->Canvas->Draw(XPos*15,YPos*15,Picture);
		MineSweeperArray[XPos][YPos].isFlag = 1;
		}
	}
}

void __fastcall TForm1::About1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------


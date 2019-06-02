//---------------------------------------------------------------------------

#ifndef MineSweeperH
#define MineSweeperH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Game1;
	TMenuItem *New1;
	TMenuItem *Beginner1;
	TMenuItem *Intermediate1;
	TMenuItem *Expert1;
	TMenuItem *Exit1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TPaintBox *PaintBox1;
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CreateGame(unsigned int Size);
	void __fastcall CountBombsNearCells(unsigned int Size);
	void __fastcall PushBombs(unsigned int Size,unsigned int BombCount);
	void __fastcall CreateField(unsigned int Size,unsigned int BombCount);
	void __fastcall New1Click(TObject *Sender);
	void __fastcall Beginner1Click(TObject *Sender);
	void __fastcall Intermediate1Click(TObject *Sender);
	void __fastcall Expert1Click(TObject *Sender);
	void __fastcall DrawField(unsigned int Size);
	void __fastcall WhatIsNumber(int XPos,int YPos);
	void __fastcall CheckRekursively(int x, int y);
	void __fastcall IFDead();
    void __fastcall Win();
	void __fastcall FaceButtonMouseDown(TObject *Sender,
	TMouseButton Button,TShiftState Shift, int X, int Y);
	void __fastcall FaceButtonMouseUp(TObject *Sender,
	TMouseButton Button,TShiftState Shift, int X, int Y);
	void __fastcall PaintBox1MouseDown(TObject *Sender,
	TMouseButton Button,TShiftState Shift, int X, int Y);
	void __fastcall OpenAll();
	void __fastcall About1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

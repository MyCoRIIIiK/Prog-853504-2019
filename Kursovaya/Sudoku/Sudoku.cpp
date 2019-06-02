// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <fstream.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
	DoubleBuffered = true;
}
// ---------------------------------------------------------------------------

bool cellSelected = true;
int numSelected;
int col, row;
int enteredCol, enteredRow;
int tally[10] ={0};

void clear(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Form1->StringGrid1->Cells[i][j] = "";
		}
	}
}

void drawLines(void)
{
	Form1->StringGrid1->Canvas->Pen->Color = clBlack;
	Form1->StringGrid1->Canvas->Pen->Width = 3;
	Form1->StringGrid1->Canvas->MoveTo(0, 92);
	Form1->StringGrid1->Canvas->LineTo(282, 92);
	Form1->StringGrid1->Canvas->MoveTo(0, 184);
	Form1->StringGrid1->Canvas->LineTo(282, 184);
	Form1->StringGrid1->Canvas->MoveTo(92, 0);
	Form1->StringGrid1->Canvas->LineTo(92, 282);
	Form1->StringGrid1->Canvas->MoveTo(184, 0);
	Form1->StringGrid1->Canvas->LineTo(184, 282);
	Application->ProcessMessages();
}

void errorFound(void)
{
	Form1->Color = clRed;
	Application->ProcessMessages();
	Sleep(200);
	Application->ProcessMessages();
	Form1->Color = clBtnFace;
	Form1->StringGrid1->Cells[enteredCol][enteredRow] = "";
	drawLines();
	Application->ProcessMessages();
}

void clearTally(void)
{
	for (int i = 0; i < 10; i++)
		tally[i] = 0;
}

void checkForErrors(void)
{

	// check columns
	for (int col = 0; col < 9; col++)
	{
		clearTally();
		for (int row = 0; row < 9; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check rows
	for (int row = 0; row < 9; row++)
	{
		clearTally();
		for (int col = 0; col < 9; col++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 1:
	clearTally();
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 2:
	clearTally();
	for (int col = 3; col < 6; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 3:
	clearTally();
	for (int col = 6; col < 9; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 4:
	clearTally();
	for (int col = 0; col < 3; col++)
	{
		for (int row = 3; row < 6; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 5:
	clearTally();
	for (int col = 3; col < 6; col++)
	{
		for (int row = 3; row < 6; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 6:
	clearTally();
	for (int col = 6; col < 9; col++)
	{
		for (int row = 3; row < 6; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 7:
	clearTally();
	for (int col = 0; col < 3; col++)
	{
		for (int row = 6; row < 9; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 8:
	clearTally();
	for (int col = 3; col < 6; col++)
	{
		for (int row = 6; row < 9; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}

	// check block 9:
	clearTally();
	for (int col = 6; col < 9; col++)
	{
		for (int row = 6; row < 9; row++)
		{
			if (Form1->StringGrid1->Cells[col][row] != "")
			{
				int num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				tally[num]++;
				if (tally[num] > 1)
					errorFound();
			}
		}
	}
	drawLines();
}

void saveStuff(void)
{
	if (Form1->SaveDialog1->Execute())
	{
		ofstream outfile(Form1->SaveDialog1->FileName.c_str());
		int num;
		for (int row = 0; row < 9; row++)
		{
			for (int col = 0; col < 9; col++)
			{
				if (Form1->StringGrid1->Cells[col][row] == "")
					num = 0;
				else
					num = StrToInt(Form1->StringGrid1->Cells[col][row]);
				outfile << num << " ";
			}
			outfile << endl;
		}
		outfile.close();
	}
}

void openStuff(void)
{
	if (Form1->OpenDialog1->Execute())
	{
		ifstream infile(Form1->OpenDialog1->FileName.c_str());
		int num;
		for (int row = 0; row < 9; row++)
		{
			for (int col = 0; col < 9; col++)
			{
				infile >> num;
				if (num == 0)
					Form1->StringGrid1->Cells[col][row] = "";
				else
					Form1->StringGrid1->Cells[col][row] = num;
			}
		}
		infile.close();
	}
}

void __fastcall TForm1::ButtonClearClick(TObject *Sender)
{
	clear();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpenClick(TObject *Sender)
{
	openStuff();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSaveClick(TObject *Sender)
{
	saveStuff();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1KeyUp(TObject *Sender, WORD &Key,
	TShiftState Shift)

{
	drawLines();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow,
	TRect &Rect, TGridDrawState State)
{
	drawLines();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1SetEditText(TObject *Sender, int ACol,
	int ARow, const UnicodeString Value)
{
	if (Value == "1" || Value == "2" || Value == "3" || Value == "4" ||
		Value == "5" || Value == "6" || Value == "7" || Value == "8" ||
		Value == "9")
	{
		enteredCol = ACol;
		enteredRow = ARow;
		checkForErrors();
	}
	else
	{
		StringGrid1->Cells[ACol][ARow] = "";
	}
}
// ---------------------------------------------------------------------------

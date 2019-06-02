
#include <vcl.h>
#pragma hdrstopFlag

#include "Unit1.h"
#include <stdlib.h>
#include "math.h"                          // Для рандома
#include "time.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define EMPTY 0
#define SNAKE 1
#define FOOD 2
#define POISON 3
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
		: TForm(Owner)
{

}

// ==========================================================================
//                                                                  переменные
// ==========================================================================

bool ateFood = false;

int world[25][25];

int east, south, relativeE, relativeS, wrappedE, wrappedS;

int snakeE[650], snakeS[650];
int snakeHeadE, snakeHeadS;
int snakeTailE, snakeTailS;
int snakeLength;
int segment;
int direction, lastDirection, reverseDirection;
int span;
int maxSize = 25;
int iterations = 0;

// ==========================================================================
//                                                                  функции
// ==========================================================================


void render(void) {




   Form1->ImageHeadUp->Visible = false;
   Form1->ImageHeadRight->Visible = false;
   Form1->ImageHeadDown->Visible = false;
   Form1->ImageHeadLeft->Visible = false;

   Application->ProcessMessages();

   for (east=0; east<maxSize; east++) {
	  for (south=0; south<maxSize; south++) {
		 switch (world[east][south]) {
			case EMPTY:                                        // пустое место
			   Form1->Canvas->Pen->Color=clWhite;
			   Form1->Canvas->Brush->Color=clWhite;
			   Form1->Canvas->Rectangle
				  (east*20,south*20,east*20+20,south*20+20);
			   break;
			case SNAKE:                                        // змея
			   Form1->Canvas->Pen->Color=clLime;
			   Form1->Canvas->Brush->Color=clLime;
			   Form1->Canvas->Rectangle
				  (east*20,south*20,east*20+20,south*20+20);
			   break;
			case FOOD:                                        // еда
			   Form1->Canvas->Pen->Color=clGreen;
			   Form1->Canvas->Brush->Color=clGreen;
			   Form1->Canvas->Rectangle
				  (east*20,south*20,east*20+20,south*20+20);
			   break;
			case POISON:                                        // яд
			   Form1->Canvas->Pen->Color=clRed;
			   Form1->Canvas->Brush->Color=clRed;
			   Form1->Canvas->Rectangle
				  (east*20,south*20,east*20+20,south*20+20);
			   break;
		 }
	  }
   }
	//перемещениее змейки

   switch (direction) {
	  case UP: {
		 Form1->ImageHeadUp->Top = snakeHeadS * 20;
		 Form1->ImageHeadUp->Left = snakeHeadE * 20;
		 Form1->ImageHeadUp->Visible = true;
		 Form1->ImageHeadUp->Repaint();
		 break;
	  }
	  case RIGHT: {
		 Form1->ImageHeadRight->Top = snakeHeadS * 20;
		 Form1->ImageHeadRight->Left = snakeHeadE * 20;
		 Form1->ImageHeadRight->Visible = true;
		 Form1->ImageHeadRight->Repaint();
		 break;
	  }
	  case DOWN: {
		 Form1->ImageHeadDown->Top = snakeHeadS * 20;
		 Form1->ImageHeadDown->Left = snakeHeadE * 20;
		 Form1->ImageHeadDown->Visible = true;
		 Form1->ImageHeadDown->Repaint();
		 break;
	  }
	  case LEFT: {
		 Form1->ImageHeadLeft->Top = snakeHeadS * 20;
		 Form1->ImageHeadLeft->Left = snakeHeadE * 20;
		 Form1->ImageHeadLeft->Visible = true;
		 Form1->ImageHeadLeft->Repaint();
		 break;
	  }
   }
}


void gameOver (void) {
   Form1->Timer1->Enabled = false;
   render();
   Application->ProcessMessages();
}


void clearAll (void) {
   for (east=0; east<maxSize; east++) {
	  for (south=0; south<maxSize; south++) {
		 world[east][south]=false;
	  }
   }
	  for (int i = 0; i < 650; i++) {
		 snakeE[i] = -1;
		 snakeS[i] = -1;
	  }
   render();
}

//---------------------------------------------------------- рандомизация еды
void makeRandomFood (void) {
   // make 30 random food
   for (int i = 0; i < 30; i++) {
	  world[random(25)][random(25)] = FOOD;
   }
}

//-------------------------------------------------------- рандомный яд
void makeRandomPoison (void) {
   // make 20 random poison
   for (int i = 0; i < 20; i++) {
	  world[random(25)][random(25)] = POISON;
   }
}

//--------------------------------------------------------- позиция змейки в начале игры


void makeRandomSnake (void) {
   Randomize();

   lastDirection = 1;
   int flip = random(2);
   switch (flip) {
	  case 0:
		 direction = 0;
		 break;
	  case 1:
		 direction = 2;
		 break;
   }
   // рандомная позиция головы
   snakeHeadE = 1 + random(15);
   snakeHeadS = 1 + random(23);

   snakeLength = 3;
   //построение тела змейки
   for (int span = 0; span < snakeLength; span++) {
	  world[snakeHeadE + span][snakeHeadS] = SNAKE;
	  snakeE[span] = snakeHeadE + span;
	  snakeS[span] = snakeHeadS;
   }
   snakeTailE = snakeHeadE + snakeLength - 1;
   snakeTailS = snakeHeadS;
   Form1->Timer1->Enabled = true;
}


void step (void) {
   reverseDirection = direction + 2;
   if (reverseDirection > 3) reverseDirection = reverseDirection - 4;
   if (lastDirection == reverseDirection) direction = lastDirection;
   // направление головы в зависимости от кнопки
	  switch (direction) {
		 case UP:
			snakeHeadS--;
			if (snakeHeadS < 0) snakeHeadS = 24;   //если за пределы вышел, появляется в противоположном месте
			break;
		 case RIGHT:
			snakeHeadE++;
			if (snakeHeadE > 24) snakeHeadE = 0;
			break;
		 case DOWN:
			snakeHeadS++;
			if (snakeHeadS > 24) snakeHeadS = 0;
			break;
		 case LEFT:
			snakeHeadE--;
			if (snakeHeadE  <0) snakeHeadE = 24;
			break;
	  }
   // если сьел себя или яд гг
   if (world[snakeHeadE][snakeHeadS] == 3) gameOver();
   if (world[snakeHeadE][snakeHeadS] == 1) gameOver();
   // если сьел еду
   if (world[snakeHeadE][snakeHeadS] == 2) ateFood = true;
   world[snakeHeadE][snakeHeadS] = SNAKE;
   // перемещает тело змейки
   for (segment = snakeLength + 1; segment > 0; segment --) {
	  snakeE[segment] = snakeE[segment - 1];
	  snakeS[segment] = snakeS[segment - 1];
   }
   // тоже перемещает
   snakeE[segment] = snakeHeadE;
   snakeS[segment] = snakeHeadS;
   // удаляет хвост змеи, если не была сьедена еда
   if (!ateFood) {
	  snakeTailE = snakeE[snakeLength ];
	  snakeTailS = snakeS[snakeLength ];
   }
   if (ateFood) {
	  snakeLength++;
	  ateFood = false;
   }
   lastDirection = direction;
   world[snakeTailE][snakeTailS] = false;
   render();
   // длина змейки
   Form1->EditLength->Text = snakeLength;
}


void begin (void) {
   clearAll();
   makeRandomFood();
   makeRandomPoison();
   makeRandomSnake();
   render();
}

void __fastcall TForm1::FormShow(TObject *Sender)
{
   randomize();
}

void __fastcall TForm1::ButtonBeginClick(TObject *Sender)
{
   begin();
   EditLength->SetFocus();       // чтобы управление было змейков через стрелки
}


//                   таймер для ходьбы змейки
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   step();
   Application->ProcessMessages();
}

//------------------------------------------------------------- нажатие клавишь
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
   if (Key == VK_LEFT) direction = 3;
   if (Key == VK_RIGHT) direction = 1;
   if (Key == VK_UP) direction = 0;
   if (Key == VK_DOWN) direction = 2;
   if (Key == VK_NUMPAD0) begin();
}








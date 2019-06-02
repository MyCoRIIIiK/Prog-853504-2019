//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
   TEdit *EditLength;
   TPanel *PanelBegin;
   TButton *ButtonBegin;
   TTimer *Timer1;
   TImage *ImageHeadUp;
   TImage *ImageHeadDown;
   TImage *ImageHeadRight;
   TImage *ImageHeadLeft;
		void __fastcall ButtonBeginClick(TObject *Sender);
   void __fastcall Timer1Timer(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

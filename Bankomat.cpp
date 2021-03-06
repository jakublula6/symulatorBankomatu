//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Bankomat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    user1.setAccount("1234", 10000, 1200); //Inicjacja konta user1
    withdraw.setState(100, 100, 100, 100,100,100);
	pinScene(); //Uruchomienie sceny z wprowadzeniem pinu
}
//---------------------------------------------------------------------------


//Moje funckcje
void TForm1:: clear()
{
    //Wyczyszczenie p?l
	Edit1 -> Visible = false;
    Label3 -> Visible = false;
    Edit1 -> Text = "";
	Label2 -> Text = "";
	Button1 -> Text = "";
	Button2 -> Text = "";
	Button3 -> Text = "Menu";
	Button4 -> Text = "";
	Button5 -> Text = "";
	Button6 -> Text = "";
	Button7 -> Text = "Wyjd?";
	Button8 -> Text = "";
	Label4 -> Visible = false;
	Label5 -> Visible = false;
	Label6 -> Visible = false;
	Label4 -> Text = "";
	Label5 -> Text = "";
	Label6 -> Text = "";
}
void TForm1:: pinScene()
{
	Label2 -> Visible = true;
	Edit1 -> Visible = true;
    Edit1 -> Password = true;
	Label2 -> Text = "Podaj Pin:";
	Button4 -> Text = "Popraw";
	Button8 -> Text = "Zatwierd?";
}
void TForm1:: menuScene()
{
	clear();
	scene = 2;
	Label2 -> Text = "Wybierz opcj?";
	Button1 -> Text = "Stan Konta";
	Button2 -> Text = "Zmie? PIN";
	Button3 -> Text = "";
	Button5 -> Text = "Wyp?ata PLN";
}
void TForm1:: balanceScene()
{
  clear();
  scene = 3;
  Label2 -> Text = "Tw?j stan konta:";
  Label3 -> Text = user1.checkBalance();
  Label3 -> Visible = true;
}
void TForm1:: newPinScene()
{
	scene = 4;
    clear();
	Label2 -> Visible = true;
	Edit1 -> Visible = true;
	Label2 -> Text = "Podaj nowy Pin:";
	Button4 -> Text = "Popraw";
	Button8 -> Text = "Zatwierd?";
}
void TForm1:: ammountScene()
{
   scene = 5;
   clear();
   Edit1 -> Visible = true;
   Edit1 -> Password = false;
   Label2 -> Visible = true;
   Label2 -> Text = "Podaj kwot? wyp?aty:";
   Button8 -> Text = "Zatwierd?";
   Button4 -> Text = "Popraw";
}
void TForm1:: withdrawScene()
{
	scene = 6;
	Button8 -> Text = "";
	Button4 -> Text = "";
	withdraw.handleWithdraw(Edit1 ->Text.ToInt());
	user1.handleWithdraw(Edit1 ->Text.ToInt());
	Edit1 -> Visible = false;
    Edit1-> Text = "";
	Label2 -> Visible = true;
	Label2 -> Text = "Wyp?acone Banknoty";
    Label4 -> Visible = true;
	Label5 -> Visible = true;
	Label6 -> Visible = true;
	Label4 -> Text = "10: " + IntToStr(withdraw.billsWithdrawed.ten) + "  20: " +
	IntToStr(withdraw.billsWithdrawed.twenty);
	Label5 -> Text = "50: " + IntToStr(withdraw.billsWithdrawed.fifty) + "  100: " +
	IntToStr(withdraw.billsWithdrawed.hundred);
	Label6 -> Text = "200: " + IntToStr(withdraw.billsWithdrawed.twoHundred) + "  500: "
	+ IntToStr(withdraw.billsWithdrawed.fifeHundred);
	//withdraw.billsWithdrawed.ten;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//
	if(scene !=1)
	{
		balanceScene();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//
	if(scene !=1)
	{
		newPinScene();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
//
	if(scene !=1 && scene !=2)
	{
        menuScene();
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
//
    Edit1-> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
//
    ammountScene();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
//
	if(scene != 1)
	{
        clear();
		scene = 1;
		Button3 -> Text = "";
        Button7 -> Text = "";
		pinScene();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	switch(scene)
	{
		case 1:
		if(user1.isPinCorrect(Edit1->Text) && !user1.isBlocked)
		{
			menuScene();
		}
		else
		{
			if(user1.isBlocked)
			{
			   Label2 -> Text = "Trzy razy wpisano b??dny Pin!";
			   Label3 -> Visible = true;
			   Label3 -> Text = "Karta zosta?a zablokowana";
			   Edit1 ->  Visible = false;
			   Edit1-> Text = "";
			   Button4 -> Text = "";
			   Button8 -> Text = "";
			}
			else
			{
				Label2 -> Text = "B??dny Pin! Spr?buj ponownie!";
				Edit1-> Text = "";
			}
			
		}
		break;
		case 4:
		if(user1.changePin(Edit1 ->Text))
		{
		   clear();
		   Label2 -> Text = "Zmieniono";
		}
		else
		{
			Label2 -> Text ="Nowy Pin musi byc inny!";
			Edit1-> Text = "";
		}
		break;
		case 5:
		if(!withdraw.isCorrect(Edit1 ->Text.ToInt()))
		{
			Label2 -> Text = "Bankomat nie wyp?aca bilon?w!";
			Edit1 -> Text = "";
        }
		else if(!user1.isLowerThanLimit(Edit1->Text.ToInt()))
		{
		   Label2 -> Text = "Podana kwota jest wy?sza ni? limit wyp?aty!";
		   Edit1 -> Text = "";
		}
		else if(!user1.isLowerThanBalance(Edit1 ->Text.ToInt()))
		{
		   Label2 -> Text = "Podana kwota jest wy?sza ni? stan konta!";
		   Edit1 -> Text = "";
		}
		else
		{
			withdrawScene();
        }
		break;
		default:
		break;
	}
}
//---------------------------------------------------------------------------


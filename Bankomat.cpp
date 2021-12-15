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
	pinScene(); //Uruchomienie sceny z wprowadzeniem pinu
}
//---------------------------------------------------------------------------


//Moje funckcje
void TForm1:: clear()
{
    //Wyczyszczenie p�l
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
	Button7 -> Text = "";
	Button8 -> Text = "";
}
void TForm1:: pinScene()
{
	Label2 -> Visible = true;
	Edit1 -> Visible = true;
	Label2 -> Text = "Podaj Pin:";
	Button4 -> Text = "Popraw";
	Button8 -> Text = "Zatwierd�";
}
void TForm1:: menuScene()
{
	clear();
	scene = 2;
	Label2 -> Text = "Wybierz opcj�";
	Button1 -> Text = "Stan Konta";
	Button2 -> Text = "Zmie� PIN";
	Button3 -> Text = "";
	Button5 -> Text = "Wyp�ata PLN";
}
void TForm1:: balanceScene()
{
  clear();
  scene = 3;
  Label2 -> Text = "Tw�j stan konta:";
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
	Button8 -> Text = "Zatwierd�";
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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	switch(scene)
	{
		case 1:
		if(user1.isPinCorrect(Edit1->Text))
		{
			menuScene();
		}
		else
		{
			Label2 -> Text = "B��dny Pin! Spr�buj ponownie!";
			Edit1-> Text = "";
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
		default:
		break;
	}
}
//---------------------------------------------------------------------------

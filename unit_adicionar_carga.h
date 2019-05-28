/*
 *  Copyright (C) 2010  José Janaílton da Silva
 *	<josejanailton@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

//---------------------------------------------------------------------------

#ifndef unit_adicionar_cargaH
#define unit_adicionar_cargaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "../../main_header/main_header.h"

//---------------------------------------------------------------------------
class Tform_adicionar_carga : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *gb_carga_concentrada;
	TLabel *Label1;
	TEdit *edit_carga_concentrada;
	TLabel *Label2;
	TEdit *edit_cota;
	TGroupBox *gb_carga_distribuida;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *edit_carga_distribuida;
	TEdit *edit_cota_inicial;
	TLabel *Label5;
	TGroupBox *GroupBox3;
	TButton *btn_ok;
	TButton *btn_cancelar;
	TGroupBox *GroupBox4;
	TRadioButton *rbtn_carga_concentrada;
	TRadioButton *rbtn_carga_distribuida;
	TEdit *edit_extensao;
	void __fastcall rbtn_carga_concentradaClick(TObject *Sender);
	void __fastcall rbtn_carga_distribuidaClick(TObject *Sender);
	void __fastcall btn_okClick(TObject *Sender);
	void __fastcall btn_cancelarClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_adicionar_carga(TComponent* Owner);

	Carga * carga;
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_adicionar_carga *form_adicionar_carga;
//---------------------------------------------------------------------------

Carga * __stdcall show_form_adicionar_carga( const AnsiString & form_title )
{
	Tform_adicionar_carga * form_adicionar_carga = new Tform_adicionar_carga( Application );
	form_adicionar_carga->Visible = false;
	form_adicionar_carga->Caption = form_title;
	form_adicionar_carga->ShowModal();

	Carga * c =  form_adicionar_carga->carga;

	form_adicionar_carga->Free();

	return c;
}

#endif

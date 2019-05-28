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

#include <vcl.h>
#pragma hdrstop

#include "unit_adicionar_carga.h"

#include <sstream>
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_adicionar_carga *form_adicionar_carga;
//---------------------------------------------------------------------------
__fastcall Tform_adicionar_carga::Tform_adicionar_carga(TComponent* Owner)
	: TForm(Owner)
{
	carga = NULL;
}
//---------------------------------------------------------------------------
void __fastcall Tform_adicionar_carga::rbtn_carga_concentradaClick(TObject *Sender)

{
	 gb_carga_concentrada->Enabled = true;
	 edit_cota->Enabled = true;
	 edit_carga_concentrada->Enabled = true;

	 gb_carga_distribuida->Enabled = false;
	 edit_carga_distribuida->Enabled = false;
	 edit_cota_inicial->Enabled = false;
	 edit_extensao->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall Tform_adicionar_carga::rbtn_carga_distribuidaClick(TObject *Sender)

{
	 gb_carga_concentrada->Enabled = false;
	 edit_cota->Enabled = false;
	 edit_carga_concentrada->Enabled = false;

	 gb_carga_distribuida->Enabled = true;
	 edit_carga_distribuida->Enabled = true;
	 edit_cota_inicial->Enabled = true;
	 edit_extensao->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall Tform_adicionar_carga::btn_okClick(TObject *Sender)
{
	if( rbtn_carga_concentrada->Checked ) // Se é uma carga concentrada
	{

	std::string str = edit_cota->Text.c_str();
	str = str + " " +  edit_carga_concentrada->Text.c_str() ;
	std::istringstream is( str );

	double cota_aux , carga_aux;
	is >> cota_aux;
	is >> carga_aux;

	carga = new carga_concentrada( carga_aux , cota_aux );
	//ShowMessage( " carga = " + AnsiString( carga->obter_carga() ) + " | cota = " + AnsiString( carga->obter_cota() ) );

	}
	else  // Se é uma carga distribuída
	{
	std::string str = edit_cota_inicial->Text.c_str();
	str = str + " " +  edit_extensao->Text.c_str() ;
	str = str + " " +  edit_carga_distribuida->Text.c_str() ;
	std::istringstream is( str );

	double cota_inicial , extensao , carga_aux;
	is >> cota_inicial;
	is >> extensao;
	is >> carga_aux;

	carga = new carga_distribuida( carga_aux , cota_inicial , extensao );
	//ShowMessage( " carga = " + AnsiString( carga->obter_carga() ) + " | cota = " + AnsiString( carga->obter_cota() ) );


	}

	Close();
}
//---------------------------------------------------------------------------
void __fastcall Tform_adicionar_carga::btn_cancelarClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall Tform_adicionar_carga::FormActivate(TObject *Sender)
{
	rbtn_carga_concentradaClick( Sender );

/*
	gb_carga_distribuida->Enabled = false;
	gb_carga_concentrada->Enabled = true;
*/
}
//---------------------------------------------------------------------------




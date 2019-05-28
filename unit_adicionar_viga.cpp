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

#include "unit_adicionar_viga.h"
#include <sstream>
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_adicionar_viga *form_adicionar_viga;
//---------------------------------------------------------------------------
__fastcall Tform_adicionar_viga::Tform_adicionar_viga(TComponent* Owner)
	: TForm(Owner)
{
	v1 = NULL;
}
//---------------------------------------------------------------------------
void __fastcall Tform_adicionar_viga::btn_okClick(TObject *Sender)
{
	if( edit_comprimento->Text == '0' )
	{
		ShowMessage( "O comprimento do vão deve ser maior do que zero!" );
		v1 = NULL;
		return;
	}


	std::string str = edit_comprimento->Text.c_str();
	std::istringstream is( str );

	double comp_vao = 0;
	is >> comp_vao;

	v1 = new viga_isostatica( comp_vao );

	Close();
}
//---------------------------------------------------------------------------
void __fastcall Tform_adicionar_viga::btn_cancelarClick(TObject *Sender)
{
    v1 = NULL;
	Close();
}
//---------------------------------------------------------------------------




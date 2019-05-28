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

#ifndef unit_adicionar_vigaH
#define unit_adicionar_vigaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "../../main_header/main_header.h"

//---------------------------------------------------------------------------
class Tform_adicionar_viga : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *gb_carga_concentrada;
	TLabel *Label1;
	TEdit *edit_comprimento;
	TButton *btn_ok;
	TButton *btn_cancelar;
	void __fastcall btn_okClick(TObject *Sender);
	void __fastcall btn_cancelarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_adicionar_viga(TComponent* Owner);

	viga_isostatica * v1;
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_adicionar_viga *form_adicionar_viga;
//---------------------------------------------------------------------------

Viga *  __stdcall show_form_adicionar_viga( const AnsiString & form_title )
{
		Tform_adicionar_viga * form_adicionar_viga = new Tform_adicionar_viga( Application );
		form_adicionar_viga->Visible = false;
		form_adicionar_viga->Caption = form_title;
		form_adicionar_viga->ShowModal();

		Viga * v = form_adicionar_viga->v1;

		form_adicionar_viga->Free();

		return v;
}

#endif

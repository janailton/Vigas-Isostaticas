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

#ifndef unit_form_principalH
#define unit_form_principalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ArrowCha.hpp"
#include "Chart.hpp"
#include "Series.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>

#include "../../main_header/main_header.h"
#include <vector>

//---------------------------------------------------------------------------
class Tform_principal : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TArrowSeries *Series1;
	TMainMenu *MainMenu1;
	TMenuItem *menu_estrutura;
	TMenuItem *menu_nova_viga;
	TMenuItem *N1;
	TMenuItem *menu_fechar;
	TMenuItem *menu_calculo;
	TMenuItem *menu_adicionar_carga;
	TMenuItem *menu_calcular_reacoes;
	TMenuItem *N2;
	TMenuItem *menu_diagrama_momento_fletor;
	TMenuItem *menu_diagrama_esforco_cortante;
	TMenuItem *menu_remover_carga;
	void __fastcall menu_fecharClick(TObject *Sender);
	void __fastcall Chart1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall menu_adicionar_cargaClick(TObject *Sender);
	void __fastcall menu_nova_vigaClick(TObject *Sender);
	void __fastcall menu_calcular_reacoesClick(TObject *Sender);
	void __fastcall menu_diagrama_momento_fletorClick(TObject *Sender);
	void __fastcall menu_diagrama_esforco_cortanteClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall menu_remover_cargaClick(TObject *Sender);
private:	// User declarations

	double limite_inferior;
	double limite_superior;

	Viga * v1;
	std::vector< Carga * > carga;

	void __fastcall desenhar_chart();

public:		// User declarations
	__fastcall Tform_principal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_principal *form_principal;
//---------------------------------------------------------------------------

void __stdcall show_form_viga_isostatica( const AnsiString & form_title )
{
	Tform_principal * form_principal = new Tform_principal( Application );
	form_principal->Visible = false;
	form_principal->Caption = form_title;
	form_principal->ShowModal();
	form_principal->Free();
}

#endif

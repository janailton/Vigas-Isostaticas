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

#ifndef unit_form_diagramaH
#define unit_form_diagramaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Chart.hpp"
#include "Series.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>

#include "../../main_header/main_header.h"

//---------------------------------------------------------------------------
class Tform_diagrama : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TAreaSeries *Series1;
	TSaveDialog *SaveDialog;
	TMainMenu *MainMenu1;
	TMenuItem *menu_arquivo;
	TMenuItem *Salvarcomo1;
	TMenuItem *N1;
	TMenuItem *Fechar1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Salvarcomo1Click(TObject *Sender);
	void __fastcall Fechar1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_diagrama(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_diagrama *form_diagrama;
//---------------------------------------------------------------------------


#endif

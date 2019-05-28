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

#include "unit_form_diagrama.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "Series"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
Tform_diagrama *form_diagrama;
//---------------------------------------------------------------------------
__fastcall Tform_diagrama::Tform_diagrama(TComponent* Owner)
	: TForm(Owner)
{
	Series1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall Tform_diagrama::Button1Click(TObject *Sender)
{
	/*

	Series1->Clear();

	viga_isostatica v1( 600 );
	carga_concentrada q1( 4000 , -150 ) , q2( 5000 , 180 ) , q3( 6000 , 300 );

	v1.adicionar_carga( &q1 );
	v1.adicionar_carga( &q2 );
	v1.adicionar_carga( &q3 );
	v1.calcular_reacoes();

	//Chart1->BottomAxis->SetMinMax( -10000, 10000);
	//Chart1->LeftAxis->SetMinMax(  -10000, 10000);


	for( int i=-500; i<1000; i++)
	{
		Series1->AddXY( i , v1.momento( i ) );
		//Series1->AddXY( i , v1.cortante( i )  );

		//Series1->Add( v1.cortante( i ) );
    	//Application->ProcessMessages();
	}

	*/

}
//---------------------------------------------------------------------------
void __fastcall Tform_diagrama::FormResize(TObject *Sender)
{
	Chart1->Width = Width - 25;
	Chart1->Height = Height - 70;
}
//---------------------------------------------------------------------------

void __fastcall Tform_diagrama::Salvarcomo1Click(TObject *Sender)
{
	SaveDialog->Filter = "bmp|*.bmp";

	if( SaveDialog->Execute( ) )
	{
        AnsiString str;
		str = SaveDialog->FileName;

		if (ExtractFileExt(str) == ".bmp" )
        {
            str.SetLength( str.Length() - 4 );
        }

		Chart1->SaveToBitmapFile( str + ".bmp" );
	}
}
//---------------------------------------------------------------------------

void __fastcall Tform_diagrama::Fechar1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


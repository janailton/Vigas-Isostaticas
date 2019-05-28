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


#include "unit_form_principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ArrowCha"
#pragma link "Chart"
#pragma link "Series"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
Tform_principal *form_principal;
//---------------------------------------------------------------------------
__fastcall Tform_principal::Tform_principal(TComponent* Owner)
	: TForm(Owner)
{
	v1 = NULL;

	limite_inferior = 0.0;
	limite_superior = 0.0;
	menu_adicionar_carga->Enabled = false;
	menu_calcular_reacoes->Enabled = false;
	menu_diagrama_momento_fletor->Enabled = false;
	menu_diagrama_esforco_cortante->Enabled = false;
	Series1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::menu_fecharClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::Chart1Click(TObject *Sender)
{
	/*
	Series1->AddArrow( 10 , 5 , 10 , 0, "A" , clRed );
	Series1->AddArrow( -200 , 0 , 800 , 0 , clBlue );
	*/
}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::FormResize(TObject *Sender)
{
	Chart1->Width = Width - 25;
	Chart1->Height = Height - 70;
}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::menu_adicionar_cargaClick(TObject *Sender)
{

	Carga * c = show_form_adicionar_carga( "Adicionar Carga" );

	if( c != NULL )
	{
		carga.push_back( c );
		menu_calcular_reacoes->Enabled = true;
		desenhar_chart();
	}
}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::menu_nova_vigaClick(TObject *Sender)
{
	Viga * v_aux = show_form_adicionar_viga( "Nova Viga" );

	if( v_aux != NULL )
	{
		if( v1 != NULL )
		{
            v1->deletar_cargas();
			delete v1;
		}
		v1 = v_aux;

		limite_inferior = 0.0;
		limite_superior = 0.0;
		carga.clear();
		menu_adicionar_carga->Enabled = true;
		menu_calcular_reacoes->Enabled = false;
		menu_diagrama_momento_fletor->Enabled = false;
		menu_diagrama_esforco_cortante->Enabled = false;
		desenhar_chart();

		// ShowMessage( "numedo de carga = " + AnsiString( carga.size() ) );
	}

}

//---------------------------------------------------------------------------

void __fastcall Tform_principal::desenhar_chart()
{


		Series1->Clear();

		double origem = 0;
		double offset = v1->obter_comprimento_do_vao();

		// Variável para controle da altura da representação das cargas
		const double altura_desenho = offset;

		int p = 1; // Número da carga

		for( int i = 0; i< carga.size(); i++, p++)
		{
			int j = carga[i]->existe_minicarga();
			if( j > 0 )
			{
				std::vector< Carga * > c = carga[i]->obter_minicarga();
				for( int h = 0 ; h < j ; h++ , p++ )
				{
					if( c[h]->obter_cota() > offset)
						offset = c[h]->obter_cota();

					if( c[h]->obter_cota() < origem)
						origem = c[h]->obter_cota();

					if( c[h]->obter_carga() < 0 )
						Series1->AddArrow(  c[h]->obter_cota() , - ( altura_desenho / 15 ) , c[h]->obter_cota() , 0 , "P[" + IntToStr( p ) + "]" , clWebDarkMagenta );
					else
						Series1->AddArrow( c[h]->obter_cota() ,( altura_desenho / 15 ) , c[h]->obter_cota() , 0 , "P[" + IntToStr( p ) + "]" , clWebDarkMagenta );
				}
			}
			else
			{
				if( carga[i]->obter_cota() > offset)
					offset = carga[i]->obter_cota();

				if( carga[i]->obter_cota() < origem)
					origem = carga[i]->obter_cota();

				if( carga[i]->obter_carga() < 0 )
					Series1->AddArrow(  carga[i]->obter_cota() , - ( altura_desenho / 10 ) , carga[i]->obter_cota() , 0 , "P[" + IntToStr( p ) + "]" , clRed );
				else
					Series1->AddArrow( carga[i]->obter_cota() ,( altura_desenho / 10 ) , carga[i]->obter_cota() , 0 , "P[" + IntToStr( p ) + "]" , clRed );
			}
		}

		double comprimento_v1 = v1->obter_comprimento_do_vao();

        // Desenha a "viga"
		Series1->AddArrow( origem , 0 , offset , 0 , "" , clBlue );
		Series1->AddArrow( 0 , -( comprimento_v1 / 10 ) , 0 , 0 , "A" , clGreen );
		Series1->AddArrow( comprimento_v1 , -( comprimento_v1 / 10 ) , comprimento_v1 , 0 , "B" , clGreen );

		// Dá um "Zoom"
		Chart1->BottomAxis->SetMinMax( ( origem -( offset / 2 ) ) , offset + ( offset / 2 ) );
		Chart1->LeftAxis->SetMinMax(  ( origem -( offset / 2 ) ) , offset + ( offset / 2 )  );

        // limite "físico" da viga após adicionada as cargas
		limite_inferior = origem;
		limite_superior = offset;
}

void __fastcall Tform_principal::menu_calcular_reacoesClick(TObject *Sender)
{

	if( v1 == NULL ) return;

	// É preciso remover as cargas no começo da função
	// porque os diagramas só podem ser feitos depois
	// que as reações tiverem sido calculadas.
	v1->remover_cargas();

	for( int i = 0; i< carga.size(); i++)
		v1->adicionar_carga( carga[i] );

	if( v1->calcular_reacoes() )
	{
		ShowMessage(
		"Reação no apoio A = " + AnsiString( v1->obter_reacao( 0 ) ) + " Kg"
		+ "\nReação no apoio B = " + AnsiString( v1->obter_reacao( 1 ) ) + " Kg"
		);

		menu_diagrama_momento_fletor->Enabled = true;
		menu_diagrama_esforco_cortante->Enabled = true;
	}

}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::menu_diagrama_momento_fletorClick(TObject *Sender)

{
	if( limite_superior != 0.0 )
	{
		Tform_diagrama *form_diagrama_momento_fletor = new Tform_diagrama( Application );
		form_diagrama_momento_fletor->Caption = "Diagrama de Momento Fletor";
		form_diagrama_momento_fletor->Visible = false;

		double y = 0.0;
		for( int i = limite_inferior; i<= limite_superior; i++)
		{
			y = v1->momento( i );
			form_diagrama_momento_fletor->Series1->AddXY( i , -y );

		}

		form_diagrama_momento_fletor->ShowModal();
		form_diagrama_momento_fletor->Free();
	}

}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::menu_diagrama_esforco_cortanteClick(TObject *Sender)

{
	if( limite_superior != 0.0 )
	{
		Tform_diagrama *form_diagrama_esforco_cortante = new Tform_diagrama( this );
		form_diagrama_esforco_cortante->Caption = "Diagrama de Esforço Cortante";
		form_diagrama_esforco_cortante->Visible = false;

		double y = 0.0;
		for( int i = limite_inferior; i< limite_superior+1; i++)
		{
			y = v1->cortante(i);
			form_diagrama_esforco_cortante->Series1->AddXY( i , y );

		}

		form_diagrama_esforco_cortante->ShowModal();
		form_diagrama_esforco_cortante->Free();
	}

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall Tform_principal::FormClose(TObject *Sender, TCloseAction &Action)

{
	if( v1 != NULL )
	{
		v1->deletar_cargas();
		delete v1;
	}
}
//---------------------------------------------------------------------------

void __fastcall Tform_principal::menu_remover_cargaClick(TObject *Sender)
{
	show_form_remover_carga();
}
//---------------------------------------------------------------------------


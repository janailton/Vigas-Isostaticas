//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_remover_carga.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_remover_carga *form_remover_carga;
//---------------------------------------------------------------------------
__fastcall Tform_remover_carga::Tform_remover_carga(TComponent* Owner)
	: TForm(Owner) , item_removido ( -1 )
{

}
//---------------------------------------------------------------------------
void __fastcall Tform_remover_carga::btn_remover_cargaClick(TObject *Sender)
{
	for( int i = 0; i<  ListBox1->Count; i++)
		if( ListBox1->Selected[i] )
			item_removido = i;
			else item_removido = -1;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#ifndef Unit_remover_cargaH
#define Unit_remover_cargaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tform_remover_carga : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TButton *btn_remover_carga;
	void __fastcall btn_remover_cargaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tform_remover_carga(TComponent* Owner);

	int item_removido;
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_remover_carga *form_remover_carga;
//---------------------------------------------------------------------------

int __fastcall show_form_remover_carga()
{
	int i = -1;
	Tform_remover_carga *form_remover_carga = new Tform_remover_carga( Application );
	form_remover_carga->ShowModal();

	return i;
}


#endif

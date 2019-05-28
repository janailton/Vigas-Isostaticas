object form_adicionar_viga: Tform_adicionar_viga
  Left = 0
  Top = 0
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsToolWindow
  Caption = 'Nova Viga'
  ClientHeight = 87
  ClientWidth = 328
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object gb_carga_concentrada: TGroupBox
    Left = 8
    Top = 8
    Width = 313
    Height = 73
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 146
      Height = 13
      Caption = 'Comprimento do v'#227'o livre (cm)'
    end
    object edit_comprimento: TEdit
      Left = 16
      Top = 35
      Width = 146
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object btn_ok: TButton
      Left = 216
      Top = 11
      Width = 81
      Height = 25
      Caption = '&OK'
      TabOrder = 1
      OnClick = btn_okClick
    end
    object btn_cancelar: TButton
      Left = 216
      Top = 42
      Width = 81
      Height = 25
      Caption = '&Cancelar'
      TabOrder = 2
      OnClick = btn_cancelarClick
    end
  end
end

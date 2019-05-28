object form_remover_carga: Tform_remover_carga
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'Remover Carga'
  ClientHeight = 329
  ClientWidth = 269
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 251
    Height = 257
    ItemHeight = 13
    TabOrder = 0
  end
  object btn_remover_carga: TButton
    Left = 184
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Remover'
    TabOrder = 1
    OnClick = btn_remover_cargaClick
  end
end

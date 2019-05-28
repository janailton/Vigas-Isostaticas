object form_adicionar_carga: Tform_adicionar_carga
  Left = 0
  Top = 0
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsToolWindow
  Caption = 'Adicionar Carga'
  ClientHeight = 241
  ClientWidth = 482
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object gb_carga_concentrada: TGroupBox
    Left = 8
    Top = 8
    Width = 289
    Height = 97
    Caption = 'Carga Concentrada'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 35
      Width = 96
      Height = 13
      Caption = 'Carga   (Kg)         = '
    end
    object Label2: TLabel
      Left = 16
      Top = 63
      Width = 94
      Height = 13
      Caption = 'Cota    (cm)         = '
    end
    object edit_carga_concentrada: TEdit
      Left = 144
      Top = 29
      Width = 113
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object edit_cota: TEdit
      Left = 144
      Top = 56
      Width = 113
      Height = 21
      TabOrder = 1
      Text = '0'
    end
  end
  object gb_carga_distribuida: TGroupBox
    Left = 8
    Top = 111
    Width = 290
    Height = 122
    Caption = 'Carga Distribu'#237'da'
    Enabled = False
    TabOrder = 1
    object Label3: TLabel
      Left = 16
      Top = 35
      Width = 107
      Height = 13
      Caption = 'Carga   (Kg/cm)       = '
    end
    object Label4: TLabel
      Left = 16
      Top = 63
      Width = 107
      Height = 13
      Caption = 'Cota inicial  (cm)      = '
    end
    object Label5: TLabel
      Left = 16
      Top = 91
      Width = 107
      Height = 13
      Caption = 'Extens'#227'o  (cm)        = '
    end
    object edit_carga_distribuida: TEdit
      Left = 145
      Top = 29
      Width = 113
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object edit_cota_inicial: TEdit
      Left = 145
      Top = 56
      Width = 113
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object edit_extensao: TEdit
      Left = 145
      Top = 83
      Width = 113
      Height = 21
      TabOrder = 2
      Text = '0'
    end
  end
  object GroupBox3: TGroupBox
    Left = 304
    Top = 117
    Width = 169
    Height = 116
    TabOrder = 2
    object btn_ok: TButton
      Left = 40
      Top = 32
      Width = 97
      Height = 25
      Caption = '&OK'
      TabOrder = 0
      OnClick = btn_okClick
    end
    object btn_cancelar: TButton
      Left = 40
      Top = 71
      Width = 97
      Height = 25
      Caption = '&Cancelar'
      TabOrder = 1
      OnClick = btn_cancelarClick
    end
  end
  object GroupBox4: TGroupBox
    Left = 304
    Top = 15
    Width = 169
    Height = 89
    TabOrder = 3
    object rbtn_carga_concentrada: TRadioButton
      Left = 24
      Top = 23
      Width = 113
      Height = 17
      Caption = 'Carga Concentrada'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = rbtn_carga_concentradaClick
    end
    object rbtn_carga_distribuida: TRadioButton
      Left = 24
      Top = 46
      Width = 113
      Height = 17
      Caption = 'Carga Distribu'#237'da'
      TabOrder = 1
      OnClick = rbtn_carga_distribuidaClick
    end
  end
end

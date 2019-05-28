object form_principal: Tform_principal
  Left = 0
  Top = 0
  Caption = 'Vigas Isost'#225'ticas'
  ClientHeight = 446
  ClientWidth = 692
  Color = clMenuBar
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 8
    Top = 8
    Width = 676
    Height = 430
    BackWall.Visible = False
    BottomWall.Visible = False
    LeftWall.Visible = False
    Legend.Visible = False
    RightWall.Visible = True
    Title.Text.Strings = (
      '')
    BottomAxis.LabelsFont.Color = 4194304
    BottomAxis.TickLength = 1
    Chart3DPercent = 1
    DepthAxis.Automatic = False
    DepthAxis.AutomaticMaximum = False
    DepthAxis.AutomaticMinimum = False
    DepthAxis.Maximum = 0.530000000000005600
    DepthAxis.Minimum = -0.469999999999990200
    DepthAxis.Visible = True
    DepthTopAxis.Automatic = False
    DepthTopAxis.AutomaticMaximum = False
    DepthTopAxis.AutomaticMinimum = False
    DepthTopAxis.Maximum = 0.530000000000005600
    DepthTopAxis.Minimum = -0.469999999999990200
    DepthTopAxis.Visible = True
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 1931.679999999983000000
    LeftAxis.Minimum = 75.679999999980740000
    LeftAxis.Visible = False
    RightAxis.Automatic = False
    RightAxis.AutomaticMaximum = False
    RightAxis.AutomaticMinimum = False
    RightAxis.Visible = False
    TopAxis.Visible = False
    View3D = False
    BevelOuter = bvNone
    Color = clMenuBar
    TabOrder = 0
    OnClick = Chart1Click
    ColorPaletteIndex = 5
    object Series1: TArrowSeries
      HorizAxis = aBothHorizAxis
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Frame.Visible = False
      Marks.Transparent = True
      Marks.Visible = False
      ClickableLine = False
      Pointer.InflateMargins = False
      Pointer.Style = psRectangle
      Pointer.Visible = True
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      ArrowPercent = 100
      EndXValues.DateTime = False
      EndXValues.Name = 'EndX'
      EndXValues.Order = loNone
      EndYValues.Name = 'EndY'
      EndYValues.Order = loNone
      StartXValues.DateTime = False
      StartXValues.Name = 'X'
      StartXValues.Order = loAscending
      StartYValues.Name = 'Y'
      StartYValues.Order = loNone
    end
  end
  object MainMenu1: TMainMenu
    Left = 512
    Top = 32
    object menu_estrutura: TMenuItem
      Caption = 'Estrutura'
      object menu_nova_viga: TMenuItem
        Caption = '&Nova Viga'
        OnClick = menu_nova_vigaClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object menu_fechar: TMenuItem
        Caption = '&Fechar'
        OnClick = menu_fecharClick
      end
    end
    object menu_calculo: TMenuItem
      Caption = 'C'#225'lculo'
      object menu_adicionar_carga: TMenuItem
        Caption = 'Adicionar Carga...'
        Enabled = False
        OnClick = menu_adicionar_cargaClick
      end
      object menu_remover_carga: TMenuItem
        Caption = 'Remover Carga'
        Enabled = False
        OnClick = menu_remover_cargaClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object menu_calcular_reacoes: TMenuItem
        Caption = 'Calcular Rea'#231#245'es'
        OnClick = menu_calcular_reacoesClick
      end
      object menu_diagrama_momento_fletor: TMenuItem
        Caption = 'Diagrama de Momento Fletor'
        OnClick = menu_diagrama_momento_fletorClick
      end
      object menu_diagrama_esforco_cortante: TMenuItem
        Caption = 'Diagrama de Esfor'#231'o Cortante'
        OnClick = menu_diagrama_esforco_cortanteClick
      end
    end
  end
end

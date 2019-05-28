object form_diagrama: Tform_diagrama
  Left = 0
  Top = 0
  Caption = 'Diagrama'
  ClientHeight = 361
  ClientWidth = 697
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 8
    Top = 8
    Width = 681
    Height = 305
    Border.Visible = True
    Gradient.Direction = gdFromTopLeft
    LeftWall.Visible = False
    Legend.CurrentPage = False
    Legend.Font.Shadow.Visible = False
    Legend.Shadow.Visible = False
    Legend.Symbol.Visible = False
    Legend.Title.Visible = False
    Legend.Visible = False
    PrintProportional = False
    SubFoot.AdjustFrame = False
    SubFoot.Shadow.Smooth = False
    SubFoot.Shadow.Visible = False
    SubFoot.Visible = False
    SubTitle.AdjustFrame = False
    SubTitle.Text.Strings = (
      '')
    SubTitle.Visible = False
    Title.Text.Strings = (
      '')
    Chart3DPercent = 1
    DepthAxis.Labels = False
    Shadow.Smooth = False
    Shadow.Visible = False
    View3D = False
    View3DOptions.Orthogonal = False
    View3DOptions.Zoom = 500
    Color = clWhite
    TabOrder = 0
    PrintMargins = (
      22
      36
      10
      24)
    ColorPaletteIndex = 1
    object Series1: TAreaSeries
      HorizAxis = aCustomHorizAxis
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Callout.Length = 20
      Marks.Font.Shadow.Visible = False
      Marks.Shadow.Color = 8750469
      Marks.Shadow.Visible = False
      Marks.Style = smsXY
      Marks.Visible = False
      SeriesColor = 7124735
      ShowInLegend = False
      AreaLinesPen.Visible = False
      ClickableLine = False
      DrawArea = True
      Pointer.InflateMargins = True
      Pointer.Style = psTriangle
      Pointer.Visible = False
      UseYOrigin = True
      XValues.Name = 'X'
      XValues.Order = loNone
      YValues.Name = 'Y'
      YValues.Order = loNone
      Data = {
        00060000000000000000607D400000000000D87D400000000000487C40000000
        0000B880400000000000A881400000000000D88340}
    end
  end
  object SaveDialog: TSaveDialog
    Left = 264
    Top = 328
  end
  object MainMenu1: TMainMenu
    Left = 360
    Top = 336
    object menu_arquivo: TMenuItem
      Caption = '&Arquivo'
      object Salvarcomo1: TMenuItem
        Caption = '&Salvar como...'
        OnClick = Salvarcomo1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Fechar1: TMenuItem
        Caption = '&Fechar'
        OnClick = Fechar1Click
      end
    end
  end
end

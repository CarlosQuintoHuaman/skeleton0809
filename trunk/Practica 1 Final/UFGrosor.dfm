object UFG: TUFG
  Left = 305
  Top = 224
  Width = 214
  Height = 169
  Caption = 'Grosor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LGrosor: TLabel
    Left = 16
    Top = 24
    Width = 137
    Height = 13
    Caption = 'Introduzca el grosor(en float):'
  end
  object BOk: TButton
    Left = 16
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 0
    OnClick = BOkClick
  end
  object BCancel: TButton
    Left = 104
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = BCancelClick
  end
  object EGrosor: TEdit
    Left = 40
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 1
  end
end

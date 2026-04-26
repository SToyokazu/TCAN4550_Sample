# アプリケーション層
### 概要
ドライバ層を利用して製品を実現する層。

### ファイル名
- TCAN4550_Sample.ino

### 機能
- HAL層の初期化実施
- ドライバ層の初期化実施
- CAN送信
- CAN受信
- エラーの取得

# ドライバ層
## TCAN4550のドライバ
### 概要
アプリケーション層にCAN送信、CAN受信、エラー取得のインターフェースを提供する。  
TCAN4550固有のレジスタ読み書きや制御を実装する。  
MCANモジュールを利用し、CAN送信、CAN受信、エラー処理を実現する。  

### ファイル名
- tcan4550.h
- tcan4550.c

### 機能
- TCAN4550固有の初期化
- CAN送信インターフェース
- CAN受信インターフェース
- エラー取得インターフェース
- SPI通信を用いたレジスタ読み取り
- SPI通信を用いたレジスタ書き込み
- TCAN4550の制御
- MCANモジュールの更新
- MCANモジュールに提供するレジスタ読み取り処理
- MCANモジュールに提供するレジスタ書き込み処理
- MCANモジュールに提供するMRAM読み取り処理
- MCANモジュールに提供するMRAM書き込み処理

## MCANモジュール
### 概要
MCANはBosch社により規格化されたCAN通信をするための機能である。  
MCAN自体は他のCAN通信対応の装置でも流用できるためモジュールとして独立させる。  
CAN送信、CAN受信、エラー取得のインターフェースを提供する。  
MRAMの設定、CAN設定、CAN通信、エラー処理を実現する。  
ただし、MCAN固有のレジスタやMRAMのアクセス方法は外部から提供される。  

### ファイル名
- mcan.h
- mcan.c

### 機能
- MRAM設定
- CAN設定
- CAN送信インターフェース
- CAN受信インターフェース
- エラー取得インターフェース
- CAN送受信の制御
- エラー処理

# HAL(Hardware Abstraction Layer)層
### 概要
利用するマイコンの違いを吸収するために、GPIOとSPI通信のインターフェースを提供する。  

### ファイル名
- platform_gpio.h
- platform_spi_master.h
- platform_gpio.c
- platform_spi_master.c

### 機能
- GPIOの初期化
- GPIOの入力
- GPIOの出力
- GPIOの割り込み処理
- SPI通信の初期化
- SPI通信の送信

# BSP(Board Support Package)層
### 概要
使用するHardwareのピン割り当ての定義。  
tcan4550_config.hはプリプロセッサマクロでincludeするtcan4550_config_ボード名.hを切り替えるファイル。  

### ファイル名
- tcan4550_config.h
- tcan4550_config_esp32.h
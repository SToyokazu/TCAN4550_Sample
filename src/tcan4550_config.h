// 使用するHardwareの定義
// プリプロセッサマクロでincludeするtcan4550_config_<board>.hを切り替える

#ifndef TCAN4550_CONFIG_H
#define TCAN4550_CONFIG_H

#define CONFIG_TARGET_ESP32    //ターゲットによって書き換える

#if defined(CONFIG_TARGET_ESP32)
#include "tcan4550_config_esp32.h"
#else
#error "Unsupported board. Add a tcan4550_config_<board>.h and update tcan4550_config.h"
#endif

#endif

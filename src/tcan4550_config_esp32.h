//ESP32-WROOM-32UE-N4のHardware設定

#ifndef TCAN4550_CONFIG_ESP32_H
#define TCAN4550_CONFIG_ESP32_H

#define CONFIG_BOARD_NAME          "ESP32"

#define CONFIG_PIN_SPI_SCK         19
#define CONFIG_PIN_SPI_MISO        17
#define CONFIG_PIN_SPI_MOSI        18
#define CONFIG_PIN_SPI_CS          16
#define CONFIG_SPI_CLOCK_HZ        2000000UL

#define CONFIG_PIN_INT    4
#define CONFIG_PIN_RST    22
#define CONFIG_PIN_GPIO1  21
#define CONFIG_PIN_GPO2   34

#endif

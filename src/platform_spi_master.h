#ifndef PLATFORM_SPI_MASTER_H
#define PLATFORM_SPI_MASTER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct  
{
    uint8_t pin_sck; 
    uint8_t pin_miso; 
    uint8_t pin_mosi; 
    uint8_t pin_cs; 
    //CPOL：アイドル時のクロック極性(0:LOW, 1:HIGH)
    //CPHA：サンプリングとシフトのタイミング(0:立ち上がりエッジでサンプリング、立下りエッジでシフト, 1:立下りエッジでサンプリング、立ち上がりエッジでシフト)
    //mode  CPOL    CPHA
    //0     0       0
    //1     0       1
    //2     1       0
    //3     1       1
    uint8_t mode;
    uint8_t bitOrder;   //0:LSBFIRST, 1:MSBFIRST
    uint32_t frequency; //[Hz]
} PLAT_SPI_MST_CONFIG;

void plat_spi_mst_init(PLAT_SPI_MST_CONFIG config);
uint8_t* plat_spi_mst_transfer(uint8_t* data, uint8_t size);

#endif

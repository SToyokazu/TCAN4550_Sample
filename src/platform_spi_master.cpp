#include "platform_spi_master.h"

#include <Arduino.h>
#include <SPI.h>

PLAT_SPI_MST_CONFIG spi_mst_config;
SPIClass *vspi = NULL;
uint8_t receive_data[UINT8_MAX + 1] = {0};

void plat_spi_mst_init(PLAT_SPI_MST_CONFIG config)
{
    spi_mst_config = config;

    vspi = new SPIClass(VSPI);
    vspi->begin(spi_msg_confg.pin_sck, spi_msg_confg.pin_miso, spi_msg_confg.pin_mosi, spi_msg_confg.pin_cs); 
    vspi->setHwCs(true);    //CS端子をHardwareで自動的に実施
    pinMode(vspi->pinSS(), OUTPUT); 
}

uint8_t* plat_spi_mst_transfer(uint8_t* data, uint8_t size)
{
    uint8_t i = 0;

    memset(receive_data, 0, UINT8_MAX + 1);
    vspi->beginTransaction(SPISettings(spi_mst_config.frequency, spi_mst_config.bitOrder, spi_mst_config.mode));
    for (i = 0; i < size; i++)
    {
        receive_data[i] = vspi->ransfer(data[i]);
    }
    vspi->endTransaction();

    return receive_data;
}
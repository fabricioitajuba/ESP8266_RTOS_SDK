/* 
 Programa: Blink1
 Autor: Fabrício Ribeiro
 Data: 27/12/23
*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#include "esp_log.h" //monitor

#define TRUE 1
#define FALSE 0
#define DEBUG TRUE

static const char *TAG = "main"; //monitor

#define GPIO_OUTPUT_IO_2    2
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_2)

void app_main()
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO2
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    while (1){
        
        gpio_set_level(GPIO_OUTPUT_IO_2, 0);
        
        //monitor
        if(DEBUG)
            ESP_LOGI(TAG, "Led on");

        vTaskDelay(1000 / portTICK_RATE_MS);

        gpio_set_level(GPIO_OUTPUT_IO_2, 1);

        //monitor
        if(DEBUG)
            ESP_LOGI(TAG, "Led off");

        vTaskDelay(1000 / portTICK_RATE_MS);        
    }

}

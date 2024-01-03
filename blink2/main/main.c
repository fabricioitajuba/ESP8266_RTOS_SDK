/* 
 Programa: Blink2
 Autor: Fabrício Ribeiro
 Data: 03/01/24
*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#include "esp_log.h" //monitor

#define TRUE 1
#define FALSE 0
#define DEBUG TRUE

static const char *TAG = "main"; //monitor

#define LED_BUILDING 2
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<LED_BUILDING)

const char * msg[2] = {"on", "off"};

void app_main()
{
    int cont=0;

    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO2
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    while(TRUE){
        
        cont++;

        gpio_set_level(LED_BUILDING, cont % 2);
        
        //monitor
        if(DEBUG)
            ESP_LOGI(TAG, "Led = : %s", msg[cont % 2]);

        vTaskDelay(1000 / portTICK_RATE_MS);

    }

}

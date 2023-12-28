/*
Exemplo de task
Autor: Fabrício Ribeiro
Data: 27/12/23

*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t xTask_1_Handle;
TaskHandle_t xTask_2_Handle;

//Função chamada na Task_1
void task1(void *arg){

    while(true){

        printf("Task1 executada!\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

//Função chamada na Task_2
void task2(void *arg){

    while(true){

        printf("Task2 executada!\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    printf("Exemplo utilizando Task.\n");

    //Criação da Task_1
    xTaskCreate(task1, "Task_1", 1024, NULL, 1, &xTask_1_Handle);
    //Criação da Task_2
    xTaskCreate(task2, "Task_2", 1024, NULL, 1, &xTask_2_Handle);
}

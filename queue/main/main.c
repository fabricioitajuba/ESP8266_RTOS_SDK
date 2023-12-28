/*
Exemplo de queue ou fila
A fila passa parâmetros entre duas ou mais task
Autor: Fabrício Ribeiro
Data: 27/12/23

*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

TaskHandle_t xTask_1_Handle;
TaskHandle_t xTask_2_Handle;
QueueHandle_t xQueue;

//Função chamada na Task_1
void task1(void *arg){

    int value;

    while(true){
        
        value = rand() % 101; //gera números entre 0 a 100

        //Envia para a task2 somente os múmeros maiores que 50 para imprimir
        if(value > 50){
            xQueueSendToBack(xQueue, &value, 0);
        }
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

//Função chamada na Task_2
void task2(void *arg){

    int receivedValue;

    while(true){

        if(xQueueReceive(xQueue, &receivedValue, portMAX_DELAY)){
            //Imprime os valores enviados pela task1
            printf("Valor lido da Queue: %d\n", receivedValue);
        }
    }
}

void app_main()
{
    printf("Exemplo utilizando Queue ou Fila.\n");

    //Criação da Queue
    xQueue = xQueueCreate(3, sizeof(int));

    //Criação da Task_1
    xTaskCreate(task1, "Task_1", 1024, NULL, 1, &xTask_1_Handle);
    //Criação da Task_2
    xTaskCreate(task2, "Task_2", 1024, NULL, 1, &xTask_2_Handle);
}

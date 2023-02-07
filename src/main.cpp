#include <Arduino.h>
#include "FS.h"
#include "get_led.h"

#define red 27
#define yellow 26
#define green 25
#define button 33
TaskHandle_t task_a = NULL;
TaskHandle_t task_b = NULL;
TaskHandle_t task_c = NULL;
int led_delay = 0;

void get_delay(void *param){
  while (1)
  {
    led_delay = Get_Led();
    vTaskDelay(5000/portTICK_PERIOD_MS);
  }  
}

void led_change(void *param){
  while (1)
  {
    digitalWrite(yellow, HIGH);
    vTaskDelay(led_delay/portTICK_PERIOD_MS);
    digitalWrite(yellow, LOW);
    vTaskDelay(led_delay/portTICK_PERIOD_MS);
  }
  
}



void setup() {
  // put your setup code here, to run once:
  pinMode(yellow, OUTPUT);
  Serial.begin(115200);
  Connect_Wifi();

  xTaskCreatePinnedToCore(get_delay,"get_delay", 10000,NULL,1,&task_a,0);
  xTaskCreatePinnedToCore(led_change,"Blinked LED", 10000, NULL,1, &task_b,1);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(count_a, count_b);

}
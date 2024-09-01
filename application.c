/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"





segment_t seg_1={
    .segment_pins[0].port=PORTC_INDEX,
    .segment_pins[0].pin=GPIO_PIN0,
    .segment_pins[0].direction=GPIO_DIRECTION_OUTPUT,
    .segment_pins[0].state=GPIO_STATE_LOW,
    
    .segment_pins[1].port=PORTC_INDEX,
    .segment_pins[1].pin=GPIO_PIN1,
    .segment_pins[1].direction=GPIO_DIRECTION_OUTPUT,
    .segment_pins[1].state=GPIO_STATE_LOW,
    
    .segment_pins[2].port=PORTC_INDEX,
    .segment_pins[2].pin=GPIO_PIN2,
    .segment_pins[2].direction=GPIO_DIRECTION_OUTPUT,
    .segment_pins[2].state=GPIO_STATE_LOW,
    
    .segment_pins[3].port=PORTC_INDEX,
    .segment_pins[3].pin=GPIO_PIN3,
    .segment_pins[3].direction=GPIO_DIRECTION_OUTPUT,
    .segment_pins[3].state=GPIO_STATE_LOW,
    
    .segment_type=SEGMENT_COMMON_ANODE,
    
};

pin_config_t seg_1_enable={.port=PORTD_INDEX,
                           .pin=GPIO_PIN0,
                           .direction=GPIO_DIRECTION_OUTPUT,
                           .state=GPIO_STATE_LOW,
};
pin_config_t seg_2_enable={.port=PORTD_INDEX,
                           .pin=GPIO_PIN1,
                           .direction=GPIO_DIRECTION_OUTPUT,
                           .state=GPIO_STATE_LOW,
};

//uint8 num[10]={0,1,2,3,4,5,6,7,8,9};
uint8 num=67;
Std_RetrunType ret=E_NOK;

int main() {
    app_init();
    while(1){
        
       
            seven_segment_display_number(&seg_1,(uint8)(num%10));
            ret=gpio_pin_write(&seg_1_enable,GPIO_STATE_HIGH);
            __delay_ms(1);  
            ret=gpio_pin_write(&seg_1_enable,GPIO_STATE_LOW);
            
            
            
            seven_segment_display_number(&seg_1,(uint8)(num/10));
            ret=gpio_pin_write(&seg_2_enable,GPIO_STATE_HIGH);
            __delay_ms(1);  
            ret=gpio_pin_write(&seg_2_enable,GPIO_STATE_LOW);
            
             
        


    }
        return (EXIT_SUCCESS);
}

void app_init(void){
  

     ret=seven_segment_init(&seg_1);
     ret=gpio_pin_init(&seg_1_enable);
     ret=gpio_pin_init(&seg_2_enable);
}
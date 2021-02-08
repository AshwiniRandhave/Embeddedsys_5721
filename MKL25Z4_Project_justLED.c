/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    MKL25Z4_Project_justLED.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {
#define BOARD_RED_LED_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_RED_LED_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_RED_LED_PIN 5U /*!<@brief PORTB pin index: 5*/
	int i=0;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

//#define LED1 (5)
   // GPIO_WritePinOutput(GPIOA,5U, 1);
    //When Pump Signal starts Only Blue LED is ON
        GPIOA -> PSOR = 1U >> 5U; //Turn OFF Red Led
        GPIOA -> PSOR = 1U >> 12U;// Turn OFF Yellow LED
        GPIOA -> PSOR = 1U << 13U; // Turn ON Blue LED
        GPIOA -> PSOR = 1U >> 16U;// Turn OFF Green LED
        PRINTF("Water Pump is Running");


     //When water enters in the tank Only Green and Blue LED is ON
        GPIOA -> PSOR = 1U >> 5U; //Turn OFF Red Led
        GPIOA -> PSOR = 1U >> 12U;// Turn OFF Yellow LED
        GPIOA -> PSOR = 1U << 13U; // Turn ON Blue LED
        GPIOA -> PSOR = 1U << 16U;// Turn ON Green LED
        PRINTF("\n Water has entered in the tank");


     //When tank level is high, yellow and Blue LED is ON
        GPIOA -> PSOR = 1U >> 5U; //Turn OFF Red Led
        GPIOA -> PSOR = 1U << 12U;// Turn ON Yellow LED
        GPIOA -> PSOR = 1U << 13U; // Turn ON Blue LED
        GPIOA -> PTOR &= ~16U;// Turn OFF Green LED
        GPIO_ClearPinsOutput (GPIOA, 16U);
        PRINTF("\n Tank Level is full");


        //When tank level drops, yellow and Blue LED is ON
        GPIOA -> PSOR = 1U >> 5U; //Turn OFF Red Led
        GPIOA -> PSOR = 1U >> 12U;// Turn ON Yellow LED
        GPIOA -> PSOR = 1U << 13U; // Turn ON Blue LED
        GPIOA -> PSOR = 1U << 16U;// Turn ON Green LED
        PRINTF("\n Tank Level is normal");


        //When Overflow occurs only red LED ON
         GPIOA -> PSOR = 1U << 5U; //Turn ON Red Led
         GPIOA -> PSOR = 1U >> 12U;// Turn OFF Yellow LED
         GPIOA -> PSOR = 1U << 13U; // Turn OFF Blue LED
         GPIOA -> PSOR = 1U << 16U;// Turn OFF Green LED
         PRINTF("\n Overflow ");


         //When Overflow stops all LEDs except red
                  GPIOA -> PSOR = 1U >> 5U; //Turn OFF Red Led
                  GPIOA -> PSOR = 1U << 12U;// Turn ON Yellow LED
                  GPIOA -> PSOR = 1U << 13U; // Turn ON Blue LED
                  GPIOA -> PSOR = 1U << 16U;// Turn ON Green LED
                  PRINTF("\n Overflow stop ");



   // GPIOA -> PSOR = 1U << 5U; //Turn On Red Led
   // GPIOA -> PSOR = 1U << 12U;// Turn On Yellow LED
   // GPIOA -> PSOR = 1U << 13U; // Trun ON Blue LED
   // GPIOA -> PSOR = 1U << 16U;// Turn On Green LED
    //PRINTF("Hello World\n");

    /* Force the counter to be placed into memory. */

    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}

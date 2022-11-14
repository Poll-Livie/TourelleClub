//-----------------------------------------------------------------------------
// PCA_Lib_8bitCenterPWM.c
//-----------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// This program sends two center-aligned PWM waveforms out of two I/O pins
// using the PCA's 8-bit Center-Aligned PWM Output Mode. The duty cycles of
// the waveforms are modified periodically within the main loop, and the
// waveforms are increasing/decreasing opposite of each other.
//
// In this example, PCA Modules 0 and 1 are used to generate the waveforms, and
// the crossbar is configured to send the CEX0 signal out on P1.4 and the CEX1
// signal out on P1.5.
//
// Resources:
//   SYSCLK - 24.5 MHz HFOSC / 1
//   PCA    - 8-bit PWM
//   P0.0   - SPI SCK
//   P0.1   - SPI MISO
//   P0.2   - SPI MOSI
//   P0.3   - SPI NSS
//   UART0  - 115200 baud, 8-N-1
//   Timer1 - UART0 clock source
//   P0.4   - UART0 TX
//   P0.5   - UART0 RX
//   P1.4   - PCA CEX0 / LED
//
//-----------------------------------------------------------------------------
// How To Test: EFM8BB1 LCK
//-----------------------------------------------------------------------------
// 1) Connect the EFM8BB1 LCK board to a PC using a micro USB cable.
// 2) Compile and download code to the EFM8BB1 LCK board.
//    In Simplicity Studio IDE, select Run -> Debug from the menu bar,
//    click the Debug button in the quick menu, or press F11.
// 3) Run the code.
//    In Simplicity Studio IDE, select Run -> Resume from the menu bar,
//    click the Resume button in the quick menu, or press F8.
// 4) Place an oscilloscope probe on P1.4 and P1.5.
// 5) Verify that the duty cycle of the waveforms vary smoothly between
//    minimum and maximum values.
//
// Target:         EFM8BB1
// Tool chain:     Generic
//
// Release 0.1 (ST)
//    - Initial Revision
//    - 10 OCT 2014
//

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "bsp.h"
#include "InitDevice.h"

/*
 * #include "SPI0_Lib_Slave.h"
 * #include "spi_0.h"
 * #include <string.h>
 *
 */
#include "uart_0.h"

#include "pca_0.h"

#include "direction.h"

//-----------------------------------------------------------------------------
// Global Constants
//-----------------------------------------------------------------------------
#define BUFFER_LENGTH   4

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
SI_SEGMENT_VARIABLE(buffer[BUFFER_LENGTH], uint8_t, SI_SEG_XDATA);

tourelle_uart_protocol dataFromRaspberry;

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // Disable the watchdog here
}

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main(void)
{
  // uint8_t command;

  enter_DefaultMode_from_RESET();
  UART0_init(UART0_RX_ENABLE, UART0_WIDTH_8, UART0_MULTIPROC_DISABLE);

  init_portsIn();
  IE_EA = 1;

  while (1)
    {
      if ((UART0_rxBytesRemaining() == 0) && (UART0_txBytesRemaining() == 0))
      {
         UART0_readBuffer(buffer, BUFFER_LENGTH);
      }
      if (dataFromRaspberry.bufferedData[0] != 0){
        switch (dataFromRaspberry.bufferedData[0]) {
          case FORWARD_PROTOCOL_LETTER:
            dataFromRaspberry.orderedDirection = forward;
            dataFromRaspberry.speed = dataFromRaspberry.bufferedData[1];
            break;
          case BACKWARD_PROTOCOL_LETTER:
            dataFromRaspberry.orderedDirection = backward;
            dataFromRaspberry.speed = dataFromRaspberry.bufferedData[1];
            break;
          case TURN_LEFT_PROTOCOL_LETTER:
            dataFromRaspberry.orderedDirection = turnLeft;
            dataFromRaspberry.speed = dataFromRaspberry.bufferedData[1];
            break;
          case TURN_RIGHT_PROTOCOL_LETTER:
            dataFromRaspberry.orderedDirection = turnRight;
            dataFromRaspberry.speed = dataFromRaspberry.bufferedData[1];
            break;
          default:
            break;
        }
        dataFromRaspberry.bufferedData[0] = 0;
        dataFromRaspberry.bufferedData[1] = 0;
        dataFromRaspberry.speed = 0;
      }

    }
}


//-----------------------------------------------------------------------------
// UART ISR Callbacks
//-----------------------------------------------------------------------------
void UART0_receiveCompleteCb()
{
   uint8_t i;
   unsigned char byte;



   for (i = 0; i<BUFFER_LENGTH; i++)
   {
      byte = buffer[i];

      /*
       * Place to put Command Analysis
       */
      if (i == 0 || i == 1){
          dataFromRaspberry.bufferedData[i] = (uint8_t)byte;
      }

      buffer[i] = byte;
   }
   UART0_writeBuffer(buffer, BUFFER_LENGTH);
   // analyseCommandFromRaspberry();
}

void UART0_transmitCompleteCb ()
{
}



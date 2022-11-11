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

#include "SPI0_Lib_Slave.h"
#include "spi_0.h"
#include <string.h>

#include "pca_0.h"

#include "direction.h"
//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

uint8_t TransferByte(uint8_t tx);

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

SI_SEGMENT_VARIABLE(SPI_TxBuf[MAX_BUFFER_SIZE+1],
                    uint8_t,
                    EFM8PDL_SPI0_TX_SEGTYPE);
SI_SEGMENT_VARIABLE(SPI_RxBuf[MAX_BUFFER_SIZE+1],
                    uint8_t,
                    EFM8PDL_SPI0_RX_SEGTYPE);

uint8_t test_value_rx = 0;
uint8_t test_array_rx[MAX_BUFFER_SIZE];

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

// Receive a byte from the master
uint8_t ReceiveCommand(void)
{
  // Send dummy byte and read command byte
  return TransferByte(0xFF);
}

// Send and receive a byte
uint8_t TransferByte(uint8_t tx)
{
  // Send tx byte
  SPI0_writeByte(tx);

  // Return rx byte
  while (SPI0_isRxEmpty());
  return SPI0_readByte();
}

// Send the response for the specified command (if necessary)
void SendResponse(uint8_t command)
{
  uint8_t i;

  switch (command)
  {
    case SPI_WRITE:
      test_value_rx = TransferByte(0xFF);
      break;

    case SPI_READ:
      TransferByte(test_value_rx);
      break;

    case SPI_WRITE_BUFFER:
      for (i = 0; i < MAX_BUFFER_SIZE; i++)
        {
          test_array_rx[i] = TransferByte(0xFF);
        }
      break;

    case SPI_READ_BUFFER:
      for (i = 0; i < MAX_BUFFER_SIZE; i++)
        {
          TransferByte(test_array_rx[i]);
        }
      break;

    case SLAVE_LED_ON:
      BSP_LED0 = BSP_LED_ON;
      break;

    case SLAVE_LED_OFF:
      BSP_LED0 = BSP_LED_OFF;
      break;
  }
}

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


  uint8_t command;


  enter_DefaultMode_from_RESET();
  init_portsIn();

  while (1)
    {
      // command = ReceiveCommand();

      // Send the command response to the master
      // SendResponse(command);


    }
}

void test_moteur(){
  uint16_t delay_count;               // Used to implement a delay
  uint8_t duty_direction0 = 1;        // Module 0: 0 = Decrease; 1 = Increase
  bool duty_direction1 = 0;           // Module 1: 0 = Increase; 1 = Decrease

  uint8_t duty_cycle0 = 0x80;
  uint8_t duty_cycle1 = 0xFF;
  for (delay_count = 30000; delay_count > 0; delay_count--);

  if (duty_direction1 == 1 ){
      duty_cycle0 = duty_cycle0 + duty_direction0;
      go_backward(duty_cycle0);

      if (duty_cycle0 == 0x2F) {
          duty_direction0 = -1;
          duty_direction1 = 0;
      }
      if (duty_cycle0 == 0x00) {
          duty_direction0 = 1;
      }
  }
  else {
      duty_cycle0 = duty_cycle0 + duty_direction0;
      go_forward(duty_cycle0);

      if (duty_cycle0 == 0x2F) {
          duty_direction0 = -1;
          duty_direction1 = 1;
      }
      if (duty_cycle0 == 0x00) {
          duty_direction0 = 1;
      }
  }
}


/*
 * // Wait
    for (delay_count = 30000; delay_count > 0; delay_count--);

    // Module 0
    if (duty_direction0 == 1)               // Direction = Increase
    {
      // First, check the ECOM0 bit
      if ((PCA0CPM0 & PCA0CPM0_ECOM__BMASK) == PCA0CPM0_ECOM__DISABLED)
      {
        PCA0CPM0 |= PCA0CPM0_ECOM__BMASK;   // Set ECOM0 if it is '0'
      }
      else                                  // Increase duty cycle otherwise
      {
        duty_cycle0--;                      // Increase duty cycle

        PCA0_writeChannel(PCA0_CHAN0, duty_cycle0 << 8);

        if (duty_cycle0 == 0x00)
        {
          duty_direction0 = 0;              // Change direction for next time
        }
      }
    }
    else                                    // Direction = Decrease
    {
      if (duty_cycle0 == 0xFF)
      {
        PCA0CPM0 &= ~PCA0CPM0_ECOM__BMASK;  // Clear ECOM0
        duty_direction0 = 1;                // Change direction for next time
      }
      else
      {
        duty_cycle0++;                      // Decrease duty cycle

        PCA0_writeChannel(PCA0_CHAN0, duty_cycle0 << 8);
      }
    }

    // Module 1
    if (duty_direction1 == 1)               // Direction = Decrease
    {
      // First, check the ECOM1 bit
      if ((PCA0CPM1 & PCA0CPM1_ECOM__BMASK) == PCA0CPM1_ECOM__DISABLED)
      {
        PCA0CPM1 |= PCA0CPM1_ECOM__BMASK;   // Set ECOM1 if it is '0'
      }
      else                                  // Increase duty cycle otherwise
      {
        duty_cycle1++;                      // Decrease duty cycle

        PCA0_writeChannel(PCA0_CHAN1, duty_cycle1 << 8);

        if (duty_cycle1 == 0xFF)
        {
          duty_direction1 = 0;              // Change direction for next time
        }
      }
    }
    else                                    // Direction = Increase
    {
      if (duty_cycle1 == 0x00)
      {
        PCA0CPM1 &= ~PCA0CPM1_ECOM__BMASK;  // Clear ECOM1
        duty_direction1 = 1;                // Change direction for next time
      }
      else
      {
        duty_cycle1--;                      // Increase duty cycle

        PCA0_writeChannel(PCA0_CHAN1, duty_cycle1 << 8);
      }
    }
 */

/*
 * direction.c
 *
 *  Created on: 10 nov. 2022
 *      Author: paul_leveque
 */

#include <SI_EFM8BB1_Register_Enums.h>
#include "pca_0.h"
#include "direction.h"

// Permet d'aller dans la direction voulue :
// void go_direction(tank_direction maDirection);

void init_portsIn(void){
  P1MDOUT |= P1MDOUT_B0__PUSH_PULL| P1MDOUT_B1__PUSH_PULL | P1MDOUT_B2__PUSH_PULL
      | P1MDOUT_B3__PUSH_PULL;
  // Set Pins P1.0 to P1.3 as Output for controlling IN 1,2,3,4 ;
}


// Permet d'avancer a une vitesse donnée (valeur a mettre dans le PWM)
void go_forward(uint8_t speed){
  // TODO Ajouter le changement de valeur des ports
  P1 |=   0x0A;   // 1010
  P1 &=  ~0x05;   // 0101

  if ((PCA0CPM0 & PCA0CPM0_ECOM__BMASK) == PCA0CPM0_ECOM__DISABLED)
  {
    PCA0CPM0 |= PCA0CPM0_ECOM__BMASK;   // Set ECOM0 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN0, speed << 8);
  }

  if ((PCA0CPM1 & PCA0CPM1_ECOM__BMASK) == PCA0CPM1_ECOM__DISABLED)
  {
    PCA0CPM1 |= PCA0CPM1_ECOM__BMASK;   // Set ECOM1 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN1, speed << 8);
  }

  // + set pins IN(1:4) low or high accordingly

}

// Permet de reculer a une vitesse donnée (valeur a mettre dans le PWM)
void go_backward(uint8_t speed){

  P1 |=   0x05;   // 0101
  P1 &=  ~0x0A;   // 1010

  if ((PCA0CPM0 & PCA0CPM0_ECOM__BMASK) == PCA0CPM0_ECOM__DISABLED)
  {
    PCA0CPM0 |= PCA0CPM0_ECOM__BMASK;   // Set ECOM0 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN0, speed << 8);
  }

  if ((PCA0CPM1 & PCA0CPM1_ECOM__BMASK) == PCA0CPM1_ECOM__DISABLED)
  {
    PCA0CPM1 |= PCA0CPM1_ECOM__BMASK;   // Set ECOM1 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN1, speed << 8);
  }
  // + set pins IN(1:4) low or high accordingly

}

// Permet de tourner a droite a une vitesse donnée (valeur a mettre dans le PWM)
void turn_right(uint8_t speed){
  P1 |=   0x06;   // 0110
  P1 &=  ~0x09;   // 1001

  if ((PCA0CPM0 & PCA0CPM0_ECOM__BMASK) == PCA0CPM0_ECOM__DISABLED)
  {
    PCA0CPM0 |= PCA0CPM0_ECOM__BMASK;   // Set ECOM0 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN0, speed << 8);
  }

  if ((PCA0CPM1 & PCA0CPM1_ECOM__BMASK) == PCA0CPM1_ECOM__DISABLED)
  {
    PCA0CPM1 |= PCA0CPM1_ECOM__BMASK;   // Set ECOM1 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN1, speed << 8);
  }
  // + set pins IN(1:4) low or high accordingly

}

// Permet de tourner a gauche a une vitesse donnée (valeur a mettre dans le PWM)
void turn_left(uint8_t speed){
  P1 |=   0x09;   // 1001
  P1 &=  ~0x06;   // 0110

  if ((PCA0CPM0 & PCA0CPM0_ECOM__BMASK) == PCA0CPM0_ECOM__DISABLED)
  {
    PCA0CPM0 |= PCA0CPM0_ECOM__BMASK;   // Set ECOM0 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN0, speed << 8);
  }

  if ((PCA0CPM1 & PCA0CPM1_ECOM__BMASK) == PCA0CPM1_ECOM__DISABLED)
  {
    PCA0CPM1 |= PCA0CPM1_ECOM__BMASK;   // Set ECOM1 if it is '0'
  }
  else {
    PCA0_writeChannel(PCA0_CHAN1, speed << 8);
  }
  // + set pins IN(1:4) low or high accordingly

}

// permet d'arreter les moteurs
void stop(){
  PCA0CPM0 &= ~PCA0CPM0_ECOM__BMASK;  // Clear ECOM0
  PCA0CPM1 &= ~PCA0CPM1_ECOM__BMASK;  // Clear ECOM0
  // + set pins IN(1:4) low or high accordingly

}

void test_moteur(void){
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

void analyseCommandFromRaspberry(void){
  switch (dataFromRaspberry.buffereData[0]) {
    case FORWARD_PROTOCOL_VAL:
      dataFromRaspberry.orderedDirection = forward;
      dataFromRaspberry.speed = dataFromRaspberry.buffereData[1];
      break;
    case BACKWARD_PROTOCOL_VAL:
      dataFromRaspberry.orderedDirection = backward;
      dataFromRaspberry.speed = dataFromRaspberry.buffereData[1];
      break;
    case TURN_LEFT_PROTOCOL_VAL:
      dataFromRaspberry.orderedDirection = turnLeft;
      dataFromRaspberry.speed = dataFromRaspberry.buffereData[1];
      break;
    case TURN_RIGHT_PROTOCOL_VAL:
      dataFromRaspberry.orderedDirection = turnRight;
      dataFromRaspberry.speed = dataFromRaspberry.buffereData[1];
      break;
    default:
      break;
  }
}


/*
 * direction.c
 *
 *  Created on: 10 nov. 2022
 *      Author: paul_leveque
 */

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
void go_backwards(uint8_t speed){
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

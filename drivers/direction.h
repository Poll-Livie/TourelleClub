/*
 * direction.h
 *
 *  Created on: 10 nov. 2022
 *      Author: paul_leveque
 */

#ifndef DRIVERS_DIRECTION_H_
#define DRIVERS_DIRECTION_H_

#include "bsp.h"
#include "InitDevice.h"
#include "pca_0.h"

typedef enum {
  North,
  NortEast,
  East,
  SouthEast,
  South,
  SouthWest,
  West,
  NordWest
} direction ;

typedef enum {
  Forward,
  Backward,
  turnRight,
  turnLeft
} tank_direction;

// fonction settant duty cycle du PWM :
// PCA0_writeChannel(PCA0_CHAN0, duty_cycle0 << 8);


/*
 * Motor Driver working on PWM signal and 2 IN Signals to turn CW, CCW, stop
 *            IN1         IN2
 *    CW      0           1
 *    CCW     1           0
 *    Stop    x           x
 *
 */

// Permet d'initialiser les 4 ports INs
// TODO et l'interface avec le uC de Console/IHM
void init_ports(void);


// Permet d'aller dans la direction voulue :
void go_direction(tank_direction maDirection);

// Permet d'avancer a une vitesse donnée (valeur a mettre dans le PWM)
void go_forward(uint8_t speed);

// Permet de reculer a une vitesse donnée (valeur a mettre dans le PWM)
void go_backwards(uint8_t speed);

// Permet de tourner a droite a une vitesse donnée (valeur a mettre dans le PWM)
void turn_right(uint8_t speed);

// Permet de tourner a gauche a une vitesse donnée (valeur a mettre dans le PWM)
void turn_left(uint8_t speed);

// permet d'arreter les moteurs
void stop(void);

#endif /* DRIVERS_DIRECTION_H_ */

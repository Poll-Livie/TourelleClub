/*
 * direction.h
 *
 *  Created on: 10 nov. 2022
 *      Author: paul_leveque
 */

#ifndef DRIVERS_DIRECTION_H_
#define DRIVERS_DIRECTION_H_

// #include "bsp.h"
// #include "InitDevice.h"
// #include "pca_0.h"

#define FORWARD_PROTOCOL_VAL "f"
#define BACKWARD_PROTOCOL_VAL "b"
#define TURN_LEFT_PROTOCOL_VAL "l"
#define TURN_RIGHT_PROTOCOL_VAL "r"

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
  forward,
  backward,
  turnRight,
  turnLeft
} tank_direction;

typedef struct tourelle_uart_protocol {
  uint8_t buffereData[2];
  tank_direction orderedDirection;
  uint8_t speed;
} tourelle_uart_protocol;

const uint8_t Nbdata = 2;


tourelle_uart_protocol dataFromRaspberry;

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
void init_portsIn(void);


// Permet d'aller dans la direction voulue :
void go_direction(tank_direction maDirection);

// Permet d'avancer a une vitesse donnée (valeur a mettre dans le PWM)
void go_forward(uint8_t speed);

// Permet de reculer a une vitesse donnée (valeur a mettre dans le PWM)
void go_backward(uint8_t speed);

// Permet de tourner a droite a une vitesse donnée (valeur a mettre dans le PWM)
void turn_right(uint8_t speed);

// Permet de tourner a gauche a une vitesse donnée (valeur a mettre dans le PWM)
void turn_left(uint8_t speed);

// permet d'arreter les moteurs
void stop(void);

// permet de tester le fonctionnement des moteurs
void test_moteur(void);

// Permet de traiter le signal reçu du Raspberry
void analyseCommandFromRaspberry(void);

#endif /* DRIVERS_DIRECTION_H_ */

#ifndef HEADER_H_
#define HEADER_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED1 PORTB0
#define LED2 PORTB2
#define LED3 PORTB3

#define OPEN_B PORTB3
#define CLOSE_B PORTB4
#define LOCK_B PORTB5
#define RESET_B PORTD0

#define LED1_ON PORTB |= (1<<LED1)
#define LED2_ON PORTB |= (1<<LED2)
#define LED3_ON PORTB |= (1<<LED3)

#define LED1_OFF PORTB &= ~(1<<LED1)
#define LED2_OFF PORTB &= ~(1<<LED2)
#define LED3_OFF PORTB &= ~(1<<LED3)

#define LEDS_ON |= (1<<LED1) | (1<<LED2) | (1<<LED3)
#define LEDS_OFF &= ~((1<<LED1) | (1<<LED2) | (1<<LED3))

#define OPEN_B_PRESSED ((PINB & (1<<OPEN_B))
#define CLOSE_B_PRESSED ((PINB & (1<<CLOSE_B))
#define LOCK_B_PRESSED ((PINB & (1<<LOCK_B))
#define RESET_B_PRESSED ((PIND & (1<<RESET_B))

typedef enum {false = 0, true = 1} bool;
extern bool state;

typedef enum DOOR_STATE{
	DOOR_STATE_OPEN,
	DOOR_STATE_CLOSED,
	DOOR_STATE_LOCKED,
	DOOR_STATE_ERROR	
} door_t;
door_t door_state;

void setup (void);
void fsm_reset (void);
void fsm_update (void);
void fsm_set_output (void);

#endif /* HEADER_H_ */
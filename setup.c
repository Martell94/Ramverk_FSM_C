#include "header.h"

static inline void init_interrupts (void);
static inline void init_io (void);

static bool state = false;
door_t door_state = DOOR_STATE_CLOSED;

void setup (void){
	
	init_ports();
	init_interrupts();
	fsm_reset();
	return;	
}

static inline void init_ports (void){
	
	DDRB = (1<<LED1 | 1<<LED2 | 1<<LED3);
	PORTB = (1<<OPEN_B) | (1<<CLOSE_B) | (1<<LOCK_B);
	PORTD = (1<< RESET_B);
	return;
}

static inline void init_interrupts (void){
	
	asm("SEI");
	PCICR = (PCIE0);
	PCMSK0 = (1<<OPEN_B) | (1<<CLOSE_B) | (1<<LOCK_B);
	
	EICRA = (1<<ISC00) | (1ISC01);
	EIMSK = (1<<INT0);
	
	return;
}
#include "header.h"

static door_t door_state = DOOR_STATE_CLOSED; //Dörr stängd vid start

void fsm_reset (void){ //Defaultar till closed
	
	door_state = DOOR_STATE_CLOSED;
	LED1_OFF;
	LED2_ON;
	LED3_OFF;
	return;
}

void fsm_update (void){ //Uppdaterar tillståndet baserat på door_state-variabeln
	
	switch (door_state){
		
		case DOOR_STATE_OPEN:{
			
			if (CLOSE_B_PRESSED){
				door_state = DOOR_STATE_CLOSED;
			} 
			else if (LOCK_B_PRESSED){
				door_state = DOOR_STATE_ERROR;
			}
			break;			
		}
		
		case DOOR_STATE_CLOSED:{
			
			if (OPEN_B_PRESSED){
				door_state = DOOR_STATE_OPEN;
			}
			else if (LOCK_B_PRESSED){
				door_state = DOOR_STATE_LOCKED;
			}
			break;
		}
		
		case DOOR_STATE_LOCKED:{
			
			if (CLOSE_B_PRESSED){
				door_state = DOOR_STATE_CLOSED;
			}
			else if (OPEN_B_PRESSED){
				door_state = DOOR_STATE_ERROR;
			}
			break;
		}
		case DOOR_STATE_ERROR:{
			fsm_update();
		}
	}
	return;
}

void fsm_set_output (void){
	
	return;
}

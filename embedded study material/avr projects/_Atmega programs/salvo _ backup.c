#include <salvo.h>
typedef unsigned char t_boolean;
typedef unsigned char t_temp;
/* Local flag. */
t_boolean warm = FALSE;
/* Seat temperature functions. */
extern t_temp UserTemp( void );
extern t_temp SeatTemp( void );
extern t_boolean CtrlTemp( t_temp user, seat );
/* Moderate-priority (i.e. 8) task (i.e. #1) */
/* to maintain seat temperature. CtrlTemp() */
/* returns TRUE only if the seat is at the */
/* the desired (user) temperature. */
void TaskControl( void )
{
	while (1) 
	{
		warm = CtrlTemp(UserTemp(), SeatTemp());
		OS_Yield();
	}
}


/* High-priority (i.e. 3) task (i.e. #2) to */
/* generate pulses. System ticks are 10ms. */

void TaskStatus( void )
{
	/* initialize pulse output (low). */
	
	TX_PORT &= ~0x01;
	while (1) 
	{
		OS_Delay(100);
		TX_PORT |= 0x01;
		OS_Delay(5);
		TX_PORT &= ~0x01;
	
		if (warm) 
		{
			OS_Delay(5);
			TX_PORT |= 0x01;
			OS_Delay(5);
			TX_PORT &= ~0x01;
		}
	}
}

/* Initialize Salvo, create and assign
 priorities to the tasks, and begin
 multitasking.*/

int main( void )
{
	OSInit();
	OSCreateTask(TaskControl, OSTCBP(1), 8);
	OSCreateTask(TaskStatus, OSTCBP(2), 3);
	while (1) {
	OSSched();
	}
}

#include "Arduino.h"
#include "moStepperlib.h"
#include "String.h"

moStepper::moStepper(char assA,char assA_bar,char assB,char assB_bar){
	A=assA;
	A_bar = assA_bar;
	B = assB;
	B_bar = assB_bar;
	
	pinMode(A,OUTPUT);
	pinMode(B,OUTPUT);
	pinMode(A_bar,OUTPUT);
	pinMode(B_bar,OUTPUT);
	
	a = amp;
	b_bar = amp + division;
	a_bar = amp + division*2;
	b = amp + division*3;
	
}


void  moStepper::stepForward(){
	curStep++;
	a++;
	b++;
	a_bar++;
	b_bar++;

	switch(curStep){
		case division:
			b = amp;
			break;
		case (division*2):
			a_bar = amp;
			break;
		case (division*3):
			b_bar = amp;
			break;
		case (division*4):
			a= amp;
			curStep=0;
			break;
		default:
			break;
	}
	setMotor();
}

void  moStepper::stepBack(){
	curStep--;
	a--;
	b--;
	a_bar--;
	b_bar--;

	switch(curStep){
		case (-1):
			a = &amp[(int)(numSteps-1)];
			curStep=numSteps-1;
			break;
		case (3*division-1):
			b_bar = &amp[(int)(numSteps-1)];
			break;
		case (2*division-1):
			a_bar = &amp[(int)(numSteps-1)];
			break;
		case (division-1):
			b = &amp[(int)(numSteps-1)];
			break;
		default:
			break;
	}
	setMotor();
}

void  moStepper::setMotor(){
	digitalWrite(A,*a);
	digitalWrite(B,*b);
	digitalWrite(A_bar,*a_bar);
	digitalWrite(B_bar,*b_bar);
}
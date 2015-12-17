#ifndef moStepperlib_h
#define moStepperlib_h

class moStepper;

class moStepper{
	public:
		moStepper(char assA,char assA_bar,char assB,char assB_bar);
		//void initialize(char A,char A_bar,char B,char B_bar);
		void stepForward();
		void stepBack();
		void setMotor();
	private:
		static const unsigned char numSteps = 8;
		unsigned char amp[numSteps] = {1,1,1,0,0,0,0,0};
		static const unsigned char division = numSteps/4;
		char curStep = 0;
		unsigned char *a,*b,*a_bar,*b_bar;
		unsigned char A,B,A_bar,B_bar;
};

#endif
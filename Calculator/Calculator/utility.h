#include "calculator.h"

class Utility : public Calculator
{
private:
	int xPos;
	int yPos;	//cursor's position in x/y in console
public:
	Utility() : xPos(0), yPos(0) {};
	Utility(int xpos, int ypos);
	//only Utility method
	void SetPos(int xpos, int ypos);	//set cursor value
	void RefreshConsole(void);			//erase everything in console and print two lines(basic UI)
	void WaitforSec(double seconds);	//wait console in seconds
	void PrintTitle(double seconds);	//print title "CALCULATOR"
	int InstantReadKey(void);			//read keyboard input without buffer(instantly input value)
	template <typename contents> void PrintConsole(contents);

	virtual void PrintGuide(void);	//basic guide : explain program
	virtual void PrintMode(string setting);	//basic mode : calculation || matrix || Base_N
	virtual int SelectMode(string setting);
	void ExitCalc(void);				//show "terminated" string and terminate whole program
	void ExitCalc(string error);		//when the program terminated with error message
};
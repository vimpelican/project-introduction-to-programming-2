#include "calculator.h"

class Utility : public Calculator
{
private:
	double result;
public:
	//only Utility method
	void RefreshConsole(void);			//erase everything in console and print two lines(basic UI)
	void WaitforSec(double seconds);	//wait console in seconds
	void PrintTitle(double seconds);	//print title "CALCULATOR"
	int InstantReadKey(void);			//read keyboard input without buffer(instantly input value)
	template <typename contents> void PrintAt(int xpos, int ypos, contents);

	virtual void PrintGuide(int xpos, int ypos);	//basic guide : explain program
	virtual void PrintMode(void);	//basic mode : calculation || matrix || Base_N
	void ExitCalc(void);			//show "terminated" string and terminate whole program
};

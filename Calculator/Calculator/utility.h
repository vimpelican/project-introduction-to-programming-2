#include "calculator.h"

class Utility : public Calculator
{
private:
	int xPos;
	int yPos;	//cursor's position in x/y in console
public:
	Utility() : xPos(0), yPos(0) {};
	Utility(int x, int y);
	//only Utility method
	void RefreshConsole(void);			//erase everything in console and print two lines(basic UI)
	void WaitforSec(double seconds);	//wait console in seconds
	void PrintTitle(double seconds);	//print title "CALCULATOR"
	int InstantReadKey(void);			//read keyboard input without buffer(instantly input value)
	template <typename contents> void PrintAt(int xpos, int ypos, contents);

	virtual void PrintGuide(int xpos, int ypos);	//basic guide : explain program
	virtual void PrintMode(int xpos, int ypos, string mode);		//basic mode : calculation || matrix || Base_N
	virtual int SelectMode(void);
	void ExitCalc(int xpos, int ypos);				//show "terminated" string and terminate whole program
	void ExitCalc(int xpos, int ypos, string error);//when the program terminated with error	
};
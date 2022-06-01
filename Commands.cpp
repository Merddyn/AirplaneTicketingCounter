#include "Commands.h"
#include "ReadString.h"
#include <string>

char * CommandNames [] = {
	"Alfa",
	"Bravo",
	"Lounge",
	"Fly",
	"Arrive",
	"Shutdown"
};

Commands GetCmd()
{
	char * Cmd;
	
	Cmd = ReadString(); // get back a dynamic string of characters from ReadString
	Commands WhichCmd;

	for (WhichCmd = CmdAlfa; WhichCmd < NumCmds; WhichCmd = (Commands)(WhichCmd + 1))
	{
		if (_strcmpi(Cmd, CommandNames[WhichCmd]) == 0) // find which command we just read
		{
			delete[] Cmd; // need to make sure we clean up dynamic memory
			return WhichCmd;
		}
		else;
	}
	delete[] Cmd;
	return InvalidCmd;
}
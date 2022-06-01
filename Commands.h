#ifndef COMMANDS_H
#define COMMANDS_H

enum Commands { 
				InvalidCmd = -1,
				CmdAlfa, 
				CmdBravo,	
				CmdLounge,	
				CmdFly,		
				CmdArrive, 
				CmdShutdown,

				NumCmds // Keep as the last command
				};

Commands GetCmd();

#endif

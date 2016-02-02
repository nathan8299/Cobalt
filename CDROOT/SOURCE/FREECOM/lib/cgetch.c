/*	$Id: cgetch.c,v 1.2 2004/02/01 13:52:17 skaus Exp $

	Get a character out-of-band and honor Ctrl-Break characters
	Invisible.

	This file bases on MISC.C of FreeCOM v0.81 beta 1.

	$Log: cgetch.c,v $
	Revision 1.2  2004/02/01 13:52:17  skaus
	add/upd: CVS $id$ keywords to/of files
	
	Revision 1.1  2001/04/12 00:33:52  skaus
	chg: new structure
	chg: If DEBUG enabled, no available commands are displayed on startup
	fix: PTCHSIZE also patches min extra size to force to have this amount
	   of memory available on start
	bugfix: CALL doesn't reset options
	add: PTCHSIZE to patch heap size
	add: VSPAWN, /SWAP switch, .SWP resource handling
	bugfix: COMMAND.COM A:\
	bugfix: CALL: if swapOnExec == ERROR, no change of swapOnExec allowed
	add: command MEMORY
	bugfix: runExtension(): destroys command[-2]
	add: clean.bat
	add: localized CRITER strings
	chg: use LNG files for hard-coded strings (hangForEver(), init.c)
		via STRINGS.LIB
	add: DEL.C, COPY.C, CBREAK.C: STRINGS-based prompts
	add: fixstrs.c: prompts & symbolic keys
	add: fixstrs.c: backslash escape sequences
	add: version IDs to DEFAULT.LNG and validation to FIXSTRS.C
	chg: splitted code apart into LIB\*.c and CMD\*.c
	bugfix: IF is now using error system & STRINGS to report errors
	add: CALL: /N
	
 */

#include "../config.h"

#include <conio.h>

#include "../include/command.h"
#include "../include/keys.h"
#include "../include/misc.h"

int cgetchar(void)
{	int c;

	if((c = getch()) == 0)
		c = SCANCODE(getch());		/* Scan code */

	if(c == KEY_CTL_C) {
		ctrlBreak = 1;
	}

	return c;
}
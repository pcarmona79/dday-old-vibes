/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /var/lib/cvs/dday42sk/src/g_svcmds.c,v $
 *   $Revision: 1.1.1.1 $
 *   $Date: 2003/10/06 22:57:04 $
 *
 ***********************************

Copyright (C) 2002 Vipersoft

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "g_local.h"

extern int countdownTimer;
extern int countdownStart;

int PlayerCountForTeam (int team_number);//faf

void	Svcmd_Test_f (void)
{
	gi.cprintf (NULL, PRINT_HIGH, "Svcmd_Test_f()\n");
}

void Svcmd_Mapinfo_f (void)
{
	gi.dprintf("%s (%i) ---\n",		team_list[0]->teamname, PlayerCountForTeam(0));//faf team_list[0]->total);
	gi.dprintf("  Score: %i/%i\n",	team_list[0]->score, team_list[0]->need_points);
	gi.dprintf("  Kills: %i/%i\n",	team_list[0]->kills, team_list[0]->need_kills);
	gi.dprintf("%s (%i) -----\n", team_list[1]->teamname, PlayerCountForTeam(1));//faf team_list[1]->total);
	gi.dprintf("  Score: %i/%i\n",	team_list[1]->score, team_list[1]->need_points);
	gi.dprintf("  Kills: %i/%i\n",	team_list[1]->kills, team_list[1]->need_kills);
}

void Svcmd_Countdown_f(void)
{
	if (gi.argc() < 3)
	{
		if (countdownStart == 0 && countdownTimer > 0)
		{
			// show countdown time left
			int secs = countdownTimer / 10;
			int mins = secs / 60;
			secs = secs - mins * 60;
			gi.bprintf(PRINT_HIGH, "Remaining time: %d mins %d secs.\n", mins, secs);
		}
		else
		{
			gi.cprintf(NULL, PRINT_HIGH, "Usage: sv countdown <minutes>\n");
		}
		return;
	}

	int minutes = atoi(gi.argv(2));
	if (minutes <= 0)
	{
		gi.cprintf(NULL, PRINT_HIGH, "Warning: the countdown must be at least 1 minute at least.\n");
		return;
	}

	// this timer is in hundredths of a second
	countdownTimer = minutes * 600 + 1;
	countdownStart = 51; // 5 seconds to announce

	gi.bprintf(PRINT_HIGH, "Starting countdown of %d minutes.\n", minutes);
}

/*
=================
ServerCommand

ServerCommand will be called when an "sv" command is issued.
The game can issue gi.argc() / gi.argv() commands to get the rest
of the parameters
=================
*/
void	ServerCommand (void)
{
	char	*cmd;

	cmd = gi.argv(1);


	if (Q_stricmp (cmd, "test") == 0)
		Svcmd_Test_f ();
	else if (Q_stricmp (cmd, "maplist") == 0) 
		Svcmd_Maplist_f (); 
	else if (Q_stricmp (cmd, "mapinfo") == 0)
		Svcmd_Mapinfo_f ();
	else if (Q_stricmp(cmd, "countdown") == 0)
		Svcmd_Countdown_f();
	else
		gi.cprintf (NULL, PRINT_HIGH, "Unknown server command \"%s\"\n", cmd);
}

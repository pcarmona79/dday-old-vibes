/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /usr/local/cvsroot/dday/src/pol/pol_spawn.c,v $
 *   $Revision: 1.5 $
 *   $Date: 2002/06/04 19:49:50 $
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

#include "pol_main.h"

// g_spawn.c
// D-Day: Normandy Team Spawns

//no fancy spawning stuff here, just nice and easy

void SP_item_weapon_vis(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_vis", "pol"));
}

void SP_item_weapon_svt(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_svt", "pol"));
}

/*void SP_item_weapon_sten(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_sten", "pol"));
}*/
void SP_item_weapon_mors(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_mors", "pol"));
}

void SP_item_weapon_RKM(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_RKM", "pol"));
}

void SP_item_weapon_mg34(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_mg34", "pol"));
}

void SP_item_weapon_piat(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_piat", "pol"));
}

void SP_item_weapon_POL_mauser98ks(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_pol_m98ks", "pol"));
}

void SP_item_weapon_sabre(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_sabre", "pol"));
}

//ammo

void SP_item_ammo_grenades_pol(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_grenades_pol", "pol"));
}

void SP_item_ammo_vis(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_vis", "pol"));
}

void SP_item_ammo_svt(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_svt", "pol"));
}
/*
void SP_item_ammo_sten(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_sten", "pol"));
}
*/
void SP_item_ammo_mors(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_mors", "pol"));
}

void SP_item_ammo_RKM(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_RKM", "pol"));
}

void SP_item_ammo_pol_mauser98k(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_pol_m98k", "pol"));
}

void SP_item_ammo_mg34(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_mg34", "pol"));
}

void SP_item_ammo_piat(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_piat", "pol"));
}



spawn_t sp_pol[] =
{
    "weapon_vis", SP_item_weapon_vis,
	"weapon_svt",SP_item_weapon_svt,
//	"weapon_sten", SP_item_weapon_sten,
	"weapon_mors", SP_item_weapon_mors,
	"weapon_RKM", SP_item_weapon_RKM,
	"weapon_mg34", SP_item_weapon_mg34,
	"weapon_piat",SP_item_weapon_piat,
	"weapon_pol_m98ks",SP_item_weapon_POL_mauser98ks,
    "weapon_sabre", SP_item_weapon_sabre,
	"ammo_vis",SP_item_ammo_vis,
	"ammo_svt",SP_item_ammo_svt,
//	"ammo_sten",SP_item_ammo_sten,
	"ammo_mors",SP_item_ammo_mors,
	"ammo_pol_m98k",SP_item_ammo_pol_mauser98k,
	"ammo_RKM",SP_item_ammo_RKM,
	"ammo_mg34",SP_item_ammo_mg34,
	"ammo_piat",SP_item_ammo_piat,
	"ammo_grenades_pol", SP_item_ammo_grenades_pol
};

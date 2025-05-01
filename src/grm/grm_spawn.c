/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /var/lib/cvs/dday42sk/src/grm/grm_spawn.c,v $
 *   $Revision: 1.1.1.1 $
 *   $Date: 2003/10/06 22:58:10 $
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

#include "grm_main.h"

// g_spawn.c
// D-Day: Normandy Team Spawns

//no fancy spawning stuff here, just nice and easy

void SP_item_weapon_p38(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_p38", "grm"));
}

void SP_item_weapon_mauser98k(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_mauser98k", "grm"));
}

void SP_item_weapon_mp40(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_mp40", "grm"));
}

void SP_item_weapon_mp43(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_mp43", "grm"));
}

void SP_item_weapon_mg42(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_mg42", "grm"));
}

void SP_item_weapon_panzer(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_panzer", "grm"));
}

void SP_item_weapon_mauser98ks(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("weapon_mauser98ks", "grm"));
}

//ammo

void SP_item_ammo_grenades_grm(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_grenades_grm", "grm"));
}
void SP_item_ammo_p38(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_p38", "grm"));
}

void SP_item_ammo_mauser98k(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_mauser98k", "grm"));
}

void SP_item_ammo_mp40(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_mp40", "grm"));
}

void SP_item_ammo_mp43(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_mp43", "grm"));
}

void SP_item_ammo_mg42(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_mg42", "grm"));
}

void SP_item_ammo_rocketsG(edict_t *self)
{
    SpawnItem(self, FindItemByClassnameInTeam("ammo_rocketsG", "grm"));
}



spawn_t sp_grm[] =
{
    "weapon_p38", SP_item_weapon_p38,
	"weapon_mauser98k",SP_item_weapon_mauser98k,
	"weapon_mp40", SP_item_weapon_mp40,
	"weapon_mp43", SP_item_weapon_mp43,
	"weapon_mg42", SP_item_weapon_mg42,
	"weapon_panzer",SP_item_weapon_panzer,
	"weapon_mauser98ks",SP_item_weapon_mauser98ks,
	"ammo_p38",SP_item_ammo_p38,
	"ammo_mauser98k",SP_item_ammo_mauser98k,
	"ammo_mp40",SP_item_ammo_mp40,
	"ammo_mp43",SP_item_ammo_mp43,
	"ammo_mg42",SP_item_ammo_mg42,
	"ammo_rocketsG",SP_item_ammo_rocketsG,
	"ammo_grenades_grm", SP_item_ammo_grenades_grm,
};

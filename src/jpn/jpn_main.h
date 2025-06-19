/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /usr/local/cvsroot/dday/src/jpn/jpn_main.h,v $
 *   $Revision: 1.7 $
 *   $Date: 2002/07/23 21:11:37 $
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

#ifndef __JPN_MAIN_H__
#define __JPN_MAIN_H__

#define USER_EXCLUDE_FUNCTIONS 1

#include "jpn_defines.h"
#include "../g_local.h"
#include "../g_cmds.h"
#include "../g_dll.h"

int jpn_index;
byte *is_silenced;
edict_t *g_edicts;

//g_items.c
void InitItems(void);
qboolean (*Pickup_Weapon)(edict_t *, edict_t *);
void (*Drop_Weapon)(edict_t *, gitem_t *);

void(*Use_Weapon)(edict_t *, gitem_t *);
qboolean (*Pickup_Ammo)(edict_t *, edict_t *);
void (*Drop_Ammo)(edict_t *, gitem_t *);
//void (*Weapon_Grenade)(edict_t *ent);


//float *CVscope_setting;
//jpn.c

game_import_t *ptrgi;       // replaces gi. usage
game_export_t *ptrGlobals;  // replaces globals. usage
level_locals_t *ptrlevel;   // replaces level. usage
game_locals_t *ptrGame;     // replaces game. usage


void (*PlayerInsertCommands)(g_cmds_t *, int, char *);
void (*(*PlayerFindFunction)(char *t));
gitem_t *(*PlayerInsertItem)(gitem_t *it, spawn_t *spawn);
/*
void (*G_FreeEdict) (edict_t *ed);
edict_t *(*G_Spawn) (void);
*/
gitem_t *(*FindItem)(char *);
void (*SpawnItem)(edict_t *, gitem_t *);
gitem_t *(*FindItemByClassname)(char *);
gitem_t *(*FindItemByClassnameInTeam)(char *, char *);

// p_weapon.c

void (*Weapon_Generic)(edict_t *, int, int,int,int,int, int, int,int, int,int*, int*, void (*fire)(edict_t *ent));
void (*Weapon_Grenade)(edict_t *);
/*
void (*ifchangewep)(edict_t *ent);
void (*fire_gun)(edict_t *, vec3_t, vec3_t, int, int, int, int, int, qboolean);
void (*fire_bullet)(edict_t *, vec3_t, vec3_t, int, int, int, int, int, qboolean);
void (*ifchangewep)(edict_t *); 
void (*AngleVectors)(vec3_t , vec3_t, vec3_t, vec3_t);
void (*P_ProjectSource)(gclient_t *, vec3_t, vec3_t, vec3_t, vec3_t, vec3_t);
void (*PlayerNoise)(edict_t *, vec3_t, int);
qboolean (*Cmd_Reload_f)(edict_t *);
void (*fire_rifle)(edict_t *, vec3_t, vec3_t, int, int, int);
void (*VectorScale)(vec3_t, vec_t, vec3_t);
void (*fire_rocket)(edict_t *, vec3_t, vec3_t, int, int, float, int);

void (*VectorMA)(vec3_t, float, vec3_t, vec3_t);
void (*T_Damage)(edict_t *, edict_t *, edict_t *, vec3_t, vec3_t, vec3_t, int, int, int, int);
void (*T_RadiusDamage)(edict_t *, edict_t *, float, edict_t *, float, int);
void (*Play_Ricochet_Noise)(edict_t *, vec3_t);
void (*Smoke_Effect)(vec3_t, float);
void (*ThrowDebris)(edict_t *, char *, float, vec3_t);
void (*vectoangles) (vec3_t, vec3_t);
void (*Play_WepSound)(edict_t *, char *);
*/
// kernel: this comes from direct release
void (*Weapon_Pistol_Fire)(edict_t *);
void (*Weapon_Rifle_Fire)(edict_t *);
void (*Weapon_Submachinegun_Fire)(edict_t *);
void (*Weapon_LMG_Fire)(edict_t *);
void (*Weapon_HMG_Fire)(edict_t *);
void (*Weapon_Rocket_Fire)(edict_t *);
void (*Weapon_Sniper_Fire)(edict_t *);

void (*Weapon_Bren_Fire) (edict_t *ent);
void (*Weapon_Katana_Fire) (edict_t *ent);
void (*Weapon_Molotov_Fire) (edict_t *ent);
void (*Weapon_MG42_Fire) (edict_t *ent);

void Weapon_Nambu (edict_t *ent);
void Weapon_Arisaka(edict_t *ent);
void Weapon_Type_100(edict_t *ent);
void Weapon_Type_99(edict_t *ent);
//void Weapon_M1Carbine(edict_t *ent);
void Weapon_Arisakas(edict_t *ent);
void JPN_Weapon_MG42(edict_t *ent);

void Weapon_Katana (edict_t *ent);
void Weapon_Molotov(edict_t *ent);

#endif /* __JPN_MAIN_H__ */

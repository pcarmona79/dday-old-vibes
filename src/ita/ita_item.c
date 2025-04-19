/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /usr/local/cvsroot/dday/src/ita/ita_item.c,v $
 *   $Revision: 1.8 $
 *   $Date: 2002/07/23 22:48:29 $
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

#include "ita_main.h"

// g_items.c
// D-Day: Normandy Team Items
//qboolean	Pickup_Weapon (edict_t *ent, edict_t *other);
//void		Use_Weapon (edict_t *ent, gitem_t *inv);
//void		Drop_Weapon (edict_t *ent, gitem_t *inv);
//qboolean Pickup_Ammo (edict_t *ent, edict_t *other);
//void Drop_Ammo(edict_t * ent , gitem_t * item );
//void Weapon_Grenade (edict_t *ent);

extern GunInfo_t itaguninfo[];
extern spawn_t sp_ita[];

void L_Use_Weapon(edict_t *ent, gitem_t *item)
{
	Use_Weapon(ent,item);
}

qboolean L_Pickup_Weapon(edict_t *ent, edict_t *item)
{
	return(Pickup_Weapon(ent,item));
}

void L_Drop_Weapon (edict_t *ent, gitem_t *item)
{
	Drop_Weapon (ent, item);
}

qboolean L_Pickup_Ammo (edict_t *ent, edict_t *other)
{
	return(Pickup_Ammo(ent,other));
}

void L_Drop_Ammo(edict_t *ent, gitem_t *item)
{
	Drop_Ammo (ent,item);
}
void L_Weapon_Grenade(edict_t *ent)
{
	Weapon_Grenade(ent);
}

//////////////////////////////////////////////////////////////////////////////////////
//                              ITA.DLL ITEMS                                       //
//////////////////////////////////////////////////////////////////////////////////////


gitem_t itaitems[]=
{
/* Beretta M1934 becomes the standard issue weapon
*/
	{
		"weapon_b34",
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_B34,
		"misc/w_pkup.wav",
		"models/weapons/ita/g_b34/tris.md2", 0,
		"models/weapons/ita/v_b34/tris.md2",
		"w_b34", 
		"Beretta M1934",
		0,
		1,
		"b34_mag",
		IT_WEAPON,
		NULL,
		0,
		LOC_PISTOL,
		2,
		1,
		5000,
		100,
		"ita",
/* precache */ "ita/b34/fire.wav ita/b34/reload.wav ita/b34/unload.wav",
		&itaguninfo[B34_FRAME],
		0
},	
/*QUAKED weapon_carcano (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_carcano", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_Carcano,
		"misc/w_pkup.wav",
		"models/weapons/ita/g_carcano/tris.md2", 0, //EF_ROTATE
		"models/weapons/ita/v_carcano/tris2.md2",//faf:  tris2 for new mauser shake fix model
/* icon */		"w_carcano",
/* pickup */	"Carcano",
		0,
		1,
		"carcano_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_RIFLE,
		2,
		9,
		5000,
		100,
		"ita",
/* precache */ "ita/carcano/fire.wav ita/carcano/lastround.wav ita/carcano/reload.wav ita/carcano/unload.wav",
		&itaguninfo[CARCANO_FRAME],
		0
	},

/*QUAKED weapon_b38 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_b38", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_B38,
		"misc/w_pkup.wav",
		"models/weapons/ita/g_b38/tris.md2", 0,
		"models/weapons/ita/v_b38/tris.md2",
/* icon */		"w_b38",
/* pickup */	"MAB 1938",
		0,
		1,
		"b38_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_SUBMACHINEGUN,
		2,
		10,
		5000,
		100,
		"ita",
/* precache */ "ita/b38/fire.wav ita/b38/reload.wav ita/b38/unload.wav",
		&itaguninfo[B38_FRAME],
		0
	},

/*QUAKED weapon_k43 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_k43", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_K43,
		"misc/w_pkup.wav",
//		"models/weapons/g_bar/tris.md2", EF_ROTATE,
		"models/weapons/ita/g_k43/tris.md2", 0,
		"models/weapons/ita/v_k43/tris.md2",
/* icon */		"w_k43",
/* pickup */	"Gewehr 43",
		0,
		1,
		"k43_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_L_MACHINEGUN,
		2,
		20,
		5000,
		100,
		"ita",
/* precache */ "ita/k43/fire.wav ita/k43/reload.wav ita/k43/unload.wav",
		&itaguninfo[K43_FRAME],
		0
	},

	/*QUAKED weapon_b3842 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_3842", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_B3842,
		"misc/w_pkup.wav",
		"models/weapons/ita/g_b3842/tris.md2", 0,
		"models/weapons/ita/v_b3842/tris.md2",
/* icon */		"w_b3842",
/* pickup */	"Beretta 38/42",
		0,
		1,
		"b3842_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_SUBMACHINEGUN2,
		2,
		50,
		5000,
		100,
		"ita",
/* precache */ "ita/b3842/fire.wav ita/b3842/reload.wav ita/b3842/unload.wav",
		&itaguninfo[B3842_FRAME],
		0
	},


/*QUAKED weapon_panzer (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_panzerfaust",
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_Panzerfaust,
		"misc/w_pkup.wav",
//		"models/weapons/g_rocket/tris.md2", EF_ROTATE,
		"models/weapons/ita/g_panzer/tris.md2", 0,
		"models/weapons/ita/v_panzer/tris.md2",
/* icon */		"w_panzerf",
/* pickup */	"Panzerfaust",
		0,
		1,
		"ita_rockets",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_ROCKET,
		3,
		10,
		0,
		0,
		"ita",
/* precache */ "ita/panzer/fire.wav ita/panzer/reload.wav ita/panzer/rockfly.wav models/objects/rocket/tris.md2 models/objects/debris2/tris.md2",
		&itaguninfo[PANZER_FRAME],
		0
	},


/*QUAKED weapon_m98ks (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_m98ks", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		ITA_Weapon_m98ks,
		"misc/w_pkup.wav",
		"models/weapons/grm/g_m98ks/tris.md2", 0,
		"models/weapons/grm/v_m98ks/tris.md2",
/* icon */		"w_m98ks",
/* pickup */	"Mauser 98ks",
		0,
		1,
		"m98k_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_SNIPER,
		2,
		8,
		5000,
		100,
		"ita",
/* precache */ "grm/m98ks/fire.wav grm/m98ks/lastround.wav grm/m98ks/reload.wav grm/m98ks/unload.wav",
		&itaguninfo[M98KS_FRAME],
		0
	},
	/*QUAKED weapon_mg42 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_breda", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_Breda,
		"misc/w_pkup.wav",
		"models/weapons/ita/g_breda/tris.md2", 0,
		"models/weapons/ita/v_breda/tris.md2",
/* icon */		"w_breda",
/* pickup */	"Breda M30",
		0,
		1,
		"breda_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_H_MACHINEGUN,
		2,
		50,
		5000,
		100,
		"ita",
/* precache */ "ita/breda/fire.wav ita/breda/reload.wav ita/breda/unload.wav",
		&itaguninfo[BREDA_FRAME],
		0
	},


//////////////////////////////////////////////////////////////////////////////////////
//                                   AMMO                                           //
//////////////////////////////////////////////////////////////////////////////////////

/*QUAKED ammo_grenades (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_grenades_ita",
		L_Pickup_Ammo,
		L_Use_Weapon,
		L_Drop_Ammo,
		L_Weapon_Grenade,
		"misc/am_pkup.wav",
		"models/weapons/grm/g_masher/tris.md2", 0,
		"models/weapons/grm/v_masher/tris.md2",
/* icon */		"a_masher",
/* pickup */	"Potato Masher",
/* width */		3,
		5,
		"Potato Masher",
		IT_AMMO|IT_WEAPON,
		NULL,
		AMMO_GRENADES,
		LOC_GRENADES,
		0,
		0.25,
		0,
		0,
		"ita",
/* precache */ "weapons/hgrent1a.wav weapons/hgrena1b.wav weapons/hgrenb1a.wav weapons/hgrenb2a.wav weapons/throw.wav"
	},

/*QUAKED ammo_b34 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_b34",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/pistols/tris.md2", 0,
		NULL,
/* icon */		"a_b34",
/* pickup */	"b34_mag",
/* width */		3,
		B34_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_PISTOL,
		0,
		0,
		0.25,
		0,
		0,
		"ita",
/* precache */ ""
	},
	
/*QUAKED ammo_carcano (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_carcano",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/rifle/tris.md2", 0,
		NULL,
/* icon */		"a_carcano",
/* pickup */	"carcano_mag",
/* width */		3,
		CARC_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_RIFLE,
		0,
		0,
		0.25,
		0,
		0,
		"ita",
/* precache */ ""
	},

/*QUAKED ammo_b38 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_b38",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/smg/tris.md2", 0,
		NULL,
/* icon */		"a_b38",
/* pickup */	"b38_mag",
/* width */		3,
		B38_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_SUBMG,
		0,
		0,
		0.25,
		0,
		0,
		"ita",
/* precache */ ""
	},


/*QUAKED ammo_k43 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_k43",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/gbr/303mag/tris.md2", 0,
		NULL,
/* icon */		"a_k43",
/* pickup */	"k43_mag",
/* width */		3,
		K43_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_LMG,
		0,
		0,
		0.5,
		0,
		0,
		"ita",
/* precache */ ""
	},

/*QUAKED ammo_b3842 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_b3842",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/rus_pph43/tris.md2", 0,
		NULL,
/* icon */		"a_b3842",
/* pickup */	"b3842_mag",
/* width */		3,
		B3842_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_SUBMG,
		0,
		0,
		1,
		0,
		0,
		"ita",
/* precache */ ""
	},

	
/*QUAKED ammo_rocketsI (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_rocketsI",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/rockets/tris.md2", 0,
		NULL,
/* icon */		"a_panzer",
/* pickup */	"ita_rockets",
/* width */		3,
		PANZER_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_ROCKETS,
		0,
		0,
		3,
		0,
		0,
		"ita",
/* precache */ ""
	},

/*QUAKED ammo_mauser98k (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_mauser98k",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/rifle/tris.md2", 0,
		NULL,
/* icon */		"a_m98k",
/* pickup */	"m98k_mag",
/* width */		3,
		MC_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_RIFLE,
		0,
		0,
		0.25,
		0,
		0,
		"ita",
/* precache */ ""
	},

/*QUAKED ammo_mg42 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_breda",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/lmg1/tris.md2", 0,
		NULL,
/* icon */		"a_breda",
/* pickup */	"breda_mag",
/* width */		3,
		BREDA_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_HMG,
		0,
		0,
		1,
		0,
		0,
		"ita",
/* precache */ ""
	},

{
	NULL
},
};

void InitItems(void)
{
	int i;
	ptrgi->dprintf("  |-- ita_index: %i\n\n",ita_index);
	for(i=0;;i++)
	{
		if(!itaitems[i].classname) break;
		itaitems[i].mag_index=ita_index;
		PlayerInsertItem(&itaitems[i],&sp_ita[i]);
	}
}

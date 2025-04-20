/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /usr/local/cvsroot/dday/src/pol/pol_item.c,v $
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

#include "pol_main.h"

// g_items.c
// D-Day: Normandy Team Items
//qboolean	Pickup_Weapon (edict_t *ent, edict_t *other);
//void		Use_Weapon (edict_t *ent, gitem_t *inv);
//void		Drop_Weapon (edict_t *ent, gitem_t *inv);
//qboolean Pickup_Ammo (edict_t *ent, edict_t *other);
//void Drop_Ammo(edict_t * ent , gitem_t * item );
//void Weapon_Grenade (edict_t *ent);

extern GunInfo_t polguninfo[];
extern spawn_t sp_pol[];

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
//                              POL.DLL ITEMS                                       //
//////////////////////////////////////////////////////////////////////////////////////


gitem_t politems[]=
{
/* Vis becomes the standard issue weapon
*/
	{
		"weapon_vis",
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_Vis,
		"misc/w_pkup.wav",
		"models/weapons/pol/g_vis/tris.md2", 0,
		"models/weapons/pol/v_vis/tris.md2",
		"w_vis", 
		"Vis",
		0,
		1,
		"vis_mag",
		IT_WEAPON,
		NULL,
		0,
		LOC_PISTOL,
		2,
		1,
		5000,
		100,
		"pol",
/* precache */ "pol/vis/fire.wav pol/vis/reload.wav pol/vis/unload.wav",
		&polguninfo[VIS_FRAME],
		0
},	
/*QUAKED weapon_svt (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_svt", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_SVT,
		"misc/w_pkup.wav",
		"models/weapons/pol/g_svt/tris.md2", 0, //EF_ROTATE
		"models/weapons/pol/v_svt/tris.md2",
/* icon */		"w_svt",
/* pickup */	"SVT38",
		0,
		1,
		"svt38_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_RIFLE,
		2,
		9,
		5000,
		100,
		"pol",
/* precache */ "pol/svt/fire.wav pol/svt/lastround.wav pol/svt/reload.wav pol/svt/unload.wav",
		&polguninfo[SVT_FRAME],	
		0
},	
/*QUAKED weapon_sten (.3 .3 1) (-16 -16 -16) (16 16 16)
*/


//*QUAKED weapon_RKM (.3 .3 1) (-16 -16 -16) (16 16 16)

	{
		"weapon_RKM", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_RKM,
		"misc/w_pkup.wav",
		"models/weapons/pol/g_rkm/tris.md2", 0,
		"models/weapons/pol/v_rkm/tris.md2",
/* icon */		"w_rkm",
/* pickup */	"RKM",
		0,
		1,
		"rkm_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_L_MACHINEGUN,
		2,
		20,
		5000,
		100,
		"pol",
/* precache */ "pol/rkm/fire.wav pol/rkm/reload.wav pol/rkm/unload.wav",
		&polguninfo[RKM_FRAME],
		20
	},


	/*QUAKED weapon_mg34 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_mg34", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_MG34,
		"misc/w_pkup.wav",
		"models/weapons/pol/g_mg34/tris.md2", 0,
		"models/weapons/pol/v_mg34/tris.md2",
/* icon */		"w_mg34",
/* pickup */	"MG34",
		0,
		1,
		"mg34_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_H_MACHINEGUN,
		2,
		50,
		5000,
		100,
		"pol",
/* precache */ "pol/mg34/fire.wav pol/mg34/reload.wav pol/mg34/unload.wav",
	&polguninfo[MG34_FRAME],
	0
	},

	/*QUAKED weapon_PIAT (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_piat",
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		POL_Weapon_PIAT,
		"misc/w_pkup.wav",
		"models/weapons/pol/g_piat/tris.md2", 0,
		"models/weapons/pol/v_piat/tris.md2",
/* icon */		"w_piat",
/* pickup */	"PIAT",
		0,
		1,
		"pol_rockets",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_ROCKET,
		3,
		10,
		0,
		0,
		"pol",
/* precache */ "pol/piat/fire.wav pol/piat/reload.wav pol/piat/rockfly.wav models/objects/rocket/tris.md2 models/objects/debris2/tris.md2",
		&polguninfo[POL_PIAT_FRAME],
		0
	},

/*QUAKED weapon_mp40 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_mors", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_Mors,
		"misc/w_pkup.wav",
		"models/weapons/pol/g_mors/tris.md2", 0,
		"models/weapons/pol/v_mors/tris.md2",
/* icon */		"w_mors",
/* pickup */	"Mors",
		0,
		1,
		"mors_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_SUBMACHINEGUN,
		2,
		10,
		5000,
		100,
		"pol",
/* precache */ "pol/mors/fire.wav pol/mors/reload.wav pol/mors/unload.wav",
	&polguninfo[MORS_FRAME],
	0
	},

/*QUAKED weapon_POL_m98ks (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"weapon_POL_m98ks", 
		L_Pickup_Weapon,
		L_Use_Weapon,
		L_Drop_Weapon,
		Weapon_POL_m98ks,
		"misc/w_pkup.wav",
		"models/weapons/grm/g_m98ks/tris.md2", 0,
		"models/weapons/grm/v_m98ks/tris.md2",
/* icon */		"w_m98ks",
/* pickup */	"POL 98ks",
		0,
		1,
		"pol_98k_mag",
		IT_WEAPON|IT_STAY_COOP,
		NULL,
		0,
		LOC_SNIPER,
		2,
		8,
		5000,
		100,
		"pol",
/* precache */ "grm/m98ks/fire.wav grm/m98ks/lastround.wav grm/m98ks/reload.wav grm/m98ks/unload.wav",
	&polguninfo[POL_M98KS_FRAME],
	0
	},

/* Weapon_Sabre (sword)
*/
{
       "weapon_sabre", 
       L_Pickup_Weapon,
       L_Use_Weapon,                             //How to use
       L_Drop_Weapon,
       Weapon_Sabre,                           //What the function is
       "misc/w_pkup.wav",
       "models/weapons/pol/g_sabre/tris.md2", 0, 
       "models/weapons/pol/v_sabre/tris.md2",      //The models stuff
       "w_sabre",                                    //Icon to be used
       "Sabre",                                        //Pickup name
       0,
       1,
       "Sabre",
       IT_WEAPON,
       NULL,
       0,
	   LOC_KNIFE,
	   0,
	   0,
	   0,
		0,
		"pol",
       "",
		0,
	0
		},

//////////////////////////////////////////////////////////////////////////////////////
//                                   AMMO                                           //
//////////////////////////////////////////////////////////////////////////////////////

/*QUAKED ammo_grenades (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_grenades_pol",
		L_Pickup_Ammo,
		L_Use_Weapon,
		L_Drop_Ammo,
		L_Weapon_Grenade,
		"misc/am_pkup.wav",
		"models/weapons/pol/g_grenade/tris.md2", 0,
		"models/weapons/pol/v_grenade/tris.md2",
/* icon */		"a_pol_grenade",
/* pickup */	"POL Grenade",
/* width */		3,
		5,
		"POL Grenade",
		IT_AMMO|IT_WEAPON,
		NULL,
		AMMO_GRENADES,
		LOC_GRENADES,
		0,
		0.25,
		0,
		0,
		"pol",
/* precache */ "weapons/hgrent1a.wav weapons/hgrena1b.wav weapons/hgrenb1a.wav weapons/hgrenb2a.wav weapons/throw.wav"
	},

/*QUAKED ammo_vis (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_vis",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/vis/tris.md2", 0,
		NULL,
/* icon */		"a_vis",
/* pickup */	"vis_mag",
/* width */		3,
		VIS_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_PISTOL,
		0,
		0,
		0.25,
		0,
		0,
		"pol",
/* precache */ ""
	},
	
/*QUAKED ammo_mauser98k (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_pol_m98k",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/rifle/tris.md2", 0,
		NULL,
/* icon */		"a_m98k",
/* pickup */	"pol_98k_mag",
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
		"pol",
/* precache */ ""
	},

/*QUAKED ammo_mauser98k (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_SVT",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/svt/tris.md2", 0,
		NULL,
/* icon */		"a_svt",
/* pickup */	"svt38_mag",
/* width */		3,
		SVT_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_RIFLE,
		0,
		0,
		0.25,
		0,
		0,
		"pol",
/* precache */ ""
	},

/*QUAKED ammo_sten (.3 .3 1) (-16 -16 -16) (16 16 16)

  



/*QUAKED ammo_RKM (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_RKM",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/rkm/tris.md2", 0,
		NULL,
/* icon */		"a_rkm",
/* pickup */	"rkm_mag",
/* width */		3,
		RKM_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_LMG,
		0,
		0,
		0.5,
		0,
		0,
		"pol",
/* precache */ ""
	},

/*QUAKED ammo_mg34 (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_mg34",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/mg34/tris.md2", 0,
		NULL,
/* icon */		"a_mg34",
/* pickup */	"mg34_mag",
/* width */		3,
		MG34_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_HMG,
		0,
		0,
		1,
		0,
		0,
		"pol",
/* precache */ ""
	},

	/*QUAKED ammo_piat (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_piat",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/pol/piatrocks/tris.md2", 0,
		NULL,
/* icon */		"a_piat",
/* pickup */	"pol_rockets",
/* width */		3,
		PIAT_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_ROCKETS,
		0,
		0,
		3,
		0,
		0,
		"pol",
/* precache */ ""
	},

/*QUAKED ammo_mors (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
		"ammo_mors",
		L_Pickup_Ammo,
		NULL,
		L_Drop_Ammo,
		NULL,
		"misc/am_pkup.wav",
		"models/items/ammo/mors/tris.md2", 0,
		NULL,
/* icon */		"a_mors",
/* pickup */	"mors_mag",
/* width */		3,
		MORS_MAG,
		NULL,
		IT_AMMO,
		NULL,
		AMMO_SUBMG,
		0,
		0,
		0.25,
		0,
		0,
		"pol",
/* precache */ ""
	},

{
	NULL
},
};

void InitItems(void)
{
	int i;
	ptrgi->dprintf("  |-- pol_index: %i\n\n", pol_index);
	for(i=0;;i++)
	{
		if(!politems[i].classname) break;
		politems[i].mag_index=pol_index;
		PlayerInsertItem(&politems[i],&sp_pol[i]);
	}
}

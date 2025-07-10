/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /var/lib/cvs/dday42sk/src/rus/rus_weapon.c,v $
 *   $Revision: 1.1.1.1 $
 *   $Date: 2003/10/06 22:58:07 $
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

#include "rus_main.h"

// p_weapon.c
// D-Day: Normandy Player Weapon Code


/*
void Weapon_Generic (edict_t *ent, 
 int FRAME_ACTIVATE_LAST,	int FRAME_LFIRE_LAST,	int FRAME_LIDLE_LAST, 
 int FRAME_RELOAD_LAST,		int FRAME_LASTRD_LAST,	int FRAME_DEACTIVATE_LAST,
 int FRAME_RAISE_LAST,		int FRAME_AFIRE_LAST,	int FRAME_AIDLE_LAST,
 int *pause_frames,			int *fire_frames,		void (*fire)(edict_t *ent))
*/


/////////////////////////////////////////////////
// Tokarev TT33
/////////////////////////////////////////////////

void Weapon_Ppsh41_Fire (edict_t *ent);
void Weapon_Pps43_Fire (edict_t *ent);




void Weapon_tt33 (edict_t *ent)
{
	static int	pause_frames[]	= {0};//{13, 32,42};
	static int	fire_frames[1];	//= {4,59,0};

	fire_frames[0]=(ent->client->aim)?75:4;

	ent->client->p_fract= &ent->client->mags[rus_index].pistol_fract;
	ent->client->p_rnd= &ent->client->mags[rus_index].pistol_rnd;

	ent->client->crosshair = false;

if ((ent->client->weaponstate == WEAPON_FIRING || ent->client->weaponstate == WEAPON_READY)
			&& !ent->client->heldfire && (ent->client->buttons & BUTTON_ATTACK)
			&& ent->client->ps.gunframe!=((ent->client->aim)?74:3)
			&& ent->client->ps.gunframe!=((ent->client->aim)?75:4)
			&& ent->client->ps.gunframe!=((ent->client->aim)?76:5)
			&& ent->client->ps.gunframe!=((ent->client->aim)?77:6)
			//gotta do it this way for both firing modes
)
		{
			if (ent->client->ps.gunframe<4)
//				firetype = abs(5-ent->client->ps.gunframe);  unknown function
			ent->client->ps.gunframe = 4;
			ent->client->weaponstate = WEAPON_READY;
			ent->client->latched_buttons |= BUTTON_ATTACK;
			ent->client->heldfire = true;
		}
		else
		{
			ent->client->buttons &= ~BUTTON_ATTACK;
			ent->client->latched_buttons &= ~BUTTON_ATTACK;
		}
//else
//		ent->client->heldfire = false;  // have to comment out or else semi-auto doesn't work

	Weapon_Generic (ent, 
		 3,  6, 47, 
		62, 65, 69,
		74, 77, 88, 
		
		pause_frames, fire_frames, Weapon_Pistol_Fire);
}


/////////////////////////////////////////////////
// M91/30 Mosin Nagant
/////////////////////////////////////////////////

void Weapon_m9130 (edict_t *ent)
{
	static int	pause_frames[]	= {0};//{4,25, 50, 0};
	static int	fire_frames[1];// = {4};

	fire_frames[0]=(ent->client->aim)?86:4;
	
	ent->client->p_fract = &ent->client->mags[rus_index].rifle_fract;
	ent->client->p_rnd= &ent->client->mags[rus_index].rifle_rnd;

	ent->client->crosshair = false;

if ((ent->client->weaponstate == WEAPON_FIRING || 
	 ent->client->weaponstate == WEAPON_READY)
		&& !ent->client->heldfire && (ent->client->buttons & BUTTON_ATTACK)
			&& ent->client->ps.gunframe!=((ent->client->aim)?85:3)
			&& ent->client->ps.gunframe!=((ent->client->aim)?86:4)
			&& ent->client->ps.gunframe!=((ent->client->aim)?87:5)
			&& ent->client->ps.gunframe!=((ent->client->aim)?88:6)
			&& ent->client->ps.gunframe!=((ent->client->aim)?89:7)
			&& ent->client->ps.gunframe!=((ent->client->aim)?90:8)
			&& ent->client->ps.gunframe!=((ent->client->aim)?91:9)
			&& ent->client->ps.gunframe!=((ent->client->aim)?92:10)
			&& ent->client->ps.gunframe!=((ent->client->aim)?93:11)
			&& ent->client->ps.gunframe!=((ent->client->aim)?94:12)			
			&& ent->client->ps.gunframe!=((ent->client->aim)?95:13)
			&& ent->client->ps.gunframe!=((ent->client->aim)?96:14)
			&& ent->client->ps.gunframe!=((ent->client->aim)?97:15)
			&& ent->client->ps.gunframe!=((ent->client->aim)?98:16)
	//		&& ent->client->ps.gunframe!=((ent->client->aim)?0:17)
			
			//gotta do it this way for both firing modes
)
		{
//			if (ent->client->ps.gunframe<4)
//				firetype = abs(5-ent->client->ps.gunframe);  unknown function
		ent->client->ps.gunframe = (ent->client->aim)?98:16;
			ent->client->weaponstate = WEAPON_READY;
			ent->client->latched_buttons |= BUTTON_ATTACK;
			ent->client->heldfire = true;
		}
		else
		{
			ent->client->buttons &= ~BUTTON_ATTACK;
			ent->client->latched_buttons &= ~BUTTON_ATTACK;
		}
//else
//		ent->client->heldfire = false;  // have to comment out or else semi-auto doesn't work

	Weapon_Generic (ent, 
		3,  16, 56, 
		78, 78, 82, 
		85, 98, 105, 
		
		pause_frames, fire_frames, Weapon_Rifle_Fire);
}


/////////////////////////////////////////////////
// ppsh41
/////////////////////////////////////////////////

void Weapon_ppsh41 (edict_t *ent)
{

	static int	pause_frames[]	= {0};
	static int	fire_frames[2];//try to put stutter back in

	fire_frames[0]=(ent->client->aim)?89:4;
	fire_frames[1]=(ent->client->aim)?90:5;

	ent->client->p_fract= &ent->client->mags[rus_index].submg_fract;
	ent->client->p_rnd= &ent->client->mags[rus_index].submg_rnd;

	ent->client->crosshair = false;

	Weapon_Generic (ent, 
		 3,  5, 45, 
		81, 81, 85, 
		88, 90, 102, 
		
		pause_frames, fire_frames, Weapon_Ppsh41_Fire);

}


/////////////////////////////////////////////////
// pps43
/////////////////////////////////////////////////

void Weapon_pps43 (edict_t *ent)
{
	static int	pause_frames[]	= {0};//{23, 45, 0};
	static int	fire_frames[2];

	fire_frames[0]=(ent->client->aim)?79:4;
	fire_frames[1]=(ent->client->aim)?80:5;

	ent->client->p_fract= &ent->client->mags[rus_index].lmg_fract;
	ent->client->p_rnd= &ent->client->mags[rus_index].lmg_rnd;

	ent->client->crosshair = false;

	Weapon_Generic (ent, 
		 3,  5, 45, 
		71, 71, 75, 
		78, 80, 92, 

		
		pause_frames, fire_frames, Weapon_LMG_Fire);
}


/////////////////////////////////////////////////
// DPM
/////////////////////////////////////////////////

void Weapon_dpm (edict_t *ent)
{
	static int	pause_frames[]	= {0};//{38, 61, 0};
	static int	fire_frames[2];

//	fire_frames[0]=(ent->client->aim)?99:20;
	fire_frames[0]=(ent->client->aim)?86:21;
	fire_frames[1]=(ent->client->aim)?87:22;

	ent->client->p_rnd= &ent->client->mags[rus_index].hmg_rnd;

	ent->client->crosshair = false;

	Weapon_Generic (ent, 
		20, 22, 62, 
		79, 79, 82, 
		85, 87, 99, 
		
		pause_frames, fire_frames, Weapon_HMG_Fire);
}


/////////////////////////////////////////////////
// RPG1  //was panzershreck
/////////////////////////////////////////////////

//void Weapon_Psk (edict_t *ent)
void Weapon_RPG1 (edict_t *ent)
{
	static int	pause_frames[]	= {0};//{25, 33, 42, 50, 0};
	static int	fire_frames[1];

	fire_frames[0]=(ent->client->aim)?73:4;

	ent->client->p_rnd= &ent->client->mags[rus_index].antitank_rnd;

	ent->client->crosshair = false;

	Weapon_Generic (ent, 
		 3,  5, 45, 
		65, 65, 69,
		72, 75, 86, 
		
		pause_frames, fire_frames, Weapon_Rocket_Fire);
}


/////////////////////////////////////////////////
// M91/30 Sniper rifle
/////////////////////////////////////////////////

void Weapon_m9130s (edict_t *ent)
{
	static int	pause_frames[]	= {0};
	static int	fire_frames[4];

	fire_frames[0]=(ent->client->aim)?52:4;//fire here
	fire_frames[1]=(ent->client->aim)?60:0;//sniper bolt
	fire_frames[2]=(ent->client->aim)?75:0;//sniper start zoom
	fire_frames[3]=(ent->client->aim)?80:0;//sniper end zoom

	ent->client->p_fract= &ent->client->mags[rus_index].sniper_fract;
	ent->client->p_rnd= &ent->client->mags[rus_index].sniper_rnd;

	if (ent->client->aim) 
	{
		if ( (ent->client->ps.gunframe >= fire_frames[0] && ent->client->ps.gunframe <= fire_frames[1]) ||
			  ent->client->ps.gunframe >= fire_frames[3])
			ent->client->crosshair = true;
		else
			ent->client->crosshair = false;
	} 
	else
		ent->client->crosshair = false;

	if ((ent->client->weaponstate == WEAPON_FIRING || ent->client->weaponstate == WEAPON_READY)
			&& !ent->client->heldfire && (ent->client->buttons & BUTTON_ATTACK)
			&& ent->client->ps.gunframe!=((ent->client->aim)?51:3)
			&& ent->client->ps.gunframe!=((ent->client->aim)?52:4)
			&& ent->client->ps.gunframe!=((ent->client->aim)?53:5)
			&& ent->client->ps.gunframe!=((ent->client->aim)?54:6)
			&& ent->client->ps.gunframe!=((ent->client->aim)?55:7)
			&& ent->client->ps.gunframe!=((ent->client->aim)?56:8)
			&& ent->client->ps.gunframe!=((ent->client->aim)?57:9)
			&& ent->client->ps.gunframe!=((ent->client->aim)?58:10)
			&& ent->client->ps.gunframe!=((ent->client->aim)?59:11)
			&& ent->client->ps.gunframe!=((ent->client->aim)?60:12)
			&& ent->client->ps.gunframe!=((ent->client->aim)?61:13)
			&& ent->client->ps.gunframe!=((ent->client->aim)?62:14)
			&& ent->client->ps.gunframe!=((ent->client->aim)?63:15)
			&& ent->client->ps.gunframe!=((ent->client->aim)?64:16)
			&& ent->client->ps.gunframe!=((ent->client->aim)?65:17)
			&& ent->client->ps.gunframe!=((ent->client->aim)?66:18)
			&& ent->client->ps.gunframe!=((ent->client->aim)?67:19)
			&& ent->client->ps.gunframe!=((ent->client->aim)?68:20)
			&& ent->client->ps.gunframe!=((ent->client->aim)?69:21)
			&& ent->client->ps.gunframe!=((ent->client->aim)?70:22)
			&& ent->client->ps.gunframe!=((ent->client->aim)?71:23)
			&& ent->client->ps.gunframe!=((ent->client->aim)?72:24)
			&& ent->client->ps.gunframe!=((ent->client->aim)?73:25)
			&& ent->client->ps.gunframe!=((ent->client->aim)?74:26)
			&& ent->client->ps.gunframe!=((ent->client->aim)?75:3)
			&& ent->client->ps.gunframe!=((ent->client->aim)?76:4)
			&& ent->client->ps.gunframe!=((ent->client->aim)?77:5)
			&& ent->client->ps.gunframe!=((ent->client->aim)?78:6)
			&& ent->client->ps.gunframe!=((ent->client->aim)?79:7)
			&& ent->client->ps.gunframe!=((ent->client->aim)?80:8)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?81:9)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?82:10)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?83:11)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?84:12)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?85:13)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?86:14)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?87:15)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?88:16)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?89:17)
//			&& ent->client->ps.gunframe!=((ent->client->aim)?90:18)

			//gotta do it this way for both firing modes
)
		{
			if (ent->client->ps.gunframe<4)
//				firetype = abs(5-ent->client->ps.gunframe);  unknown function
			ent->client->ps.gunframe = 4;
			ent->client->weaponstate = WEAPON_READY;
			ent->client->latched_buttons |= BUTTON_ATTACK;
			ent->client->heldfire = true;
		}
		else
		{
			ent->client->buttons &= ~BUTTON_ATTACK;
			ent->client->latched_buttons &= ~BUTTON_ATTACK;
		}
//else
//		ent->client->heldfire = false;  // have to comment out or else semi-auto doesn't work

	Weapon_Generic (ent, 
		 3, 26, 26, 
		43, 43, 48, 
		51, 80, 80, 
		
		pause_frames, fire_frames, Weapon_Sniper_Fire);
}


void Weapon_Ppsh41_Fire (edict_t *ent)
{
	int	i;
	vec3_t		start;
	vec3_t		forward, right;
	vec3_t		angles;
	int			kick = 2;
	vec3_t		offset;
	GunInfo_t *guninfo=ent->client->pers.weapon->guninfo;	
	int mag_index=ent->client->pers.weapon->mag_index;
	int mod=guninfo->MeansOfDeath;
	int	damage = guninfo->damage_direct;



	if (ent->client->next_fire_frame > ptrlevel->framenum)
		return;

	if (!(ent->client->buttons & BUTTON_ATTACK))
	{
		ent->client->machinegun_shots = 0;
		ent->client->ps.gunframe++;
		return;
	}

	if(ent->client->aim)
	{
		if (ent->client->ps.gunframe == guninfo->LastAFire)
			ent->client->ps.gunframe = guninfo->LastAFire-1;
		else
			ent->client->ps.gunframe = guninfo->LastAFire;
	}

	else
	{
		if (ent->client->ps.gunframe == guninfo->LastFire)
			ent->client->ps.gunframe = guninfo->LastFire-1;
		else
			ent->client->ps.gunframe = guninfo->LastFire;
	}

	if (ent->client->mags[mag_index].submg_rnd <= 0)
	{
		ent->client->ps.gunframe = (ent->client->aim)?guninfo->LastAFire+1:guninfo->LastFire+1;
	
		if (ptrlevel->time >= ent->pain_debounce_time)
		{
			ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"), 1, ATTN_NORM, 0);
			ent->pain_debounce_time = ptrlevel->time + 1;
		}
		
/*
		if (auto_weapon_change->value) 
			NoAmmoWeaponChange (ent);
*/
		
		return;
	}

	if (!ent->client->aim)
	{
		for (i=0 ; i<3 ; i++)
		{
			// Thompson extra-kick (1.7 to 1.9)
			// rezmoth - changed for new firing system
			//ent->client->kick_origin[i] = (crandom() * 0.5)-1.5;
			//ent->client->kick_angles[i] = (crandom() * 1.9)-1.5;
		}

		// rezmoth - changed for new firing system
		//ent->client->kick_origin[0] = crandom() * 0.38;
		//ent->client->kick_angles[0] = ent->client->machinegun_shots * -1.8;

	}
	else
	{
		for (i=1 ; i<3 ; i++)
		{	
			// rezmoth - changed for new firing system
			//ent->client->kick_origin[i] = crandom() * 0.35;
			//ent->client->kick_angles[i] = crandom() * 0.7;
		}

		// rezmoth - changed for new firing system
		//ent->client->kick_origin[0] = crandom() * 0.35;
		//ent->client->kick_angles[0] = ent->client->machinegun_shots * -1.5;
	}

	// raise the gun as it is firing
//	if (!deathmatch->value)
//	{
	ent->client->machinegun_shots++;
	if (ent->client->machinegun_shots > 9)
		ent->client->machinegun_shots = 9;
//	}


	//faf: adding this to alternate firing sounds
	++ent->numfired;



	// vspread
	//VectorSet(offset, 0, (ent->client->aim)?0:8, ent->viewheight-8 + (crandom() * 15));
	// rezmoth - changed for new firing system
	//VectorSet(offset, 0, (ent->client->aim)?0:8, (ent->client->aim)?ent->viewheight-8:crandom() * 15);
	if (ent->client->pers.weapon->position == LOC_SUBMACHINEGUN)
		VectorSet(offset, 0, 0, ent->viewheight - 0);	//10
	else
		ptrgi->dprintf("*** Firing System Error\n");

//faf for testing	ptrgi->cprintf(ent, PRINT_HIGH, "%i randnum\n", randnum);

//	jamchance = rand() % 100;
/*	if (randnum == 5)
	{
		ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"), 1, ATTN_NORM, 0);
		ptrgi->centerprintf(ent, "Your gun jammed!\n");
		ent->client->mags[mag_index].submg_rnd= 0;
		return;
	} */


	// rezmoth - cosmetic recoil
	if (ptrlevel->framenum % 3 == 0)
	{
		if (ent->client->aim)
			ent->client->kick_angles[0] -= 1.5;
		else
			ent->client->kick_angles[0] = -3;
	}

	// pbowens: for darwin's 3.2 kick
	ent->client->kick_angles[0] = ent->client->machinegun_shots * -1;
//sten kick removed	ent->client->kick_angles[1] = ent->client->machinegun_shots * .3;

	// get start / end positions
	VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
	AngleVectors (angles, forward, right, NULL);
	
	P_ProjectSource (ent->client, ent->s.origin, offset, forward, right, start);

	/*	
	VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
	AngleVectors (angles, forward, right, NULL);
	VectorSet(offset, 0, 8, ent->viewheight-8);
	P_ProjectSource (ent->client, ent->s.origin, offset, forward, right, start);
*/

	fire_gun2(ent, start, forward, damage, kick, 0, 0, mod, false);


//faf:  a second bullet comes out every other time.  This combined with the 
//		sound effects creates the illusion of a higher (consistant) firing rate
	if (ent->numfired % 2 == 1)
	{
		for (i=0 ; i<3 ; i++)
		{
			//rezmoth - changed for new firing system
			ent->client->kick_origin[i] = crandom() * 0.35;
			ent->client->kick_angles[i] += crandom() * 0.7;
		}

		fire_gun2(ent, start, forward, damage, kick, 0, 0, mod, false);
	}




	if(ent->client->mags[mag_index].submg_rnd<=1) //faf ==
	{
		//Hard coded for reload only.
        ent->client->ps.gunframe=guninfo->LastReload+1;
        ent->client->weaponstate = WEAPON_END_MAG;
//		Play_WepSound(ent,guninfo->LastRoundSound);
		ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->LastRoundSound), 1, ATTN_NORM, 0);//faf

	
	}

	// rezmoth - changed to new firing code
	//fire_bullet (ent, start, forward, damage, kick, DEFAULT_BULLET_HSPREAD, DEFAULT_BULLET_VSPREAD, mod, false);
/*	
	    ent->client->anim_priority = ANIM_ATTACK;
    if (ent->client->ps.pmove.pm_flags & PMF_DUCKED)
    {
        ent->s.frame = FRAME_crattak1 - 1 + (ent->client->ps.gunframe % 3);
        ent->client->anim_end = FRAME_crattak9;
    }
    else
    {
        ent->s.frame = FRAME_attack1 - 1 + (ent->client->ps.gunframe % 3);
        ent->client->anim_end = FRAME_attack8;
    }
*/
	//gi.sound(ent, CHAN_WEAPON, gi.soundindex("weapons/machgf2b.wav"), 1, ATTN_NORM, 0);


//	Play_WepSound(ent,guninfo->FireSound);//PlayerNoise(ent, start, PNOISE_WEAPON);

	

	//faf
	if (ent->numfired % 2 == 1)
	{
		ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex("rus/ppsh41/firea.wav"), 1, ATTN_NORM, 0);//faf
	}
	else
	{
		ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex("rus/ppsh41/fireb.wav"), 1, ATTN_NORM, 0);//faf
	}




	
	ptrgi->WriteByte (svc_muzzleflash);
	ptrgi->WriteShort (ent-g_edicts);
	ptrgi->WriteByte (MZ_MACHINEGUN);//faf | is_silenced);
	ptrgi->multicast (ent->s.origin, MULTICAST_PVS);

	//faf
	if (ent->numfired % 2 == 1)
		ent->client->mags[mag_index].submg_rnd-=2;
	else
		ent->client->mags[mag_index].submg_rnd--;

	ent->client->next_fire_frame = ptrlevel->framenum + guninfo->frame_delay;
}


void Weapon_Pps43_Fire (edict_t *ent)
{
//	int	i;
	vec3_t		start;
	vec3_t		forward, right;
	vec3_t		angles;
	int			kick = 2;
	vec3_t		offset;
	GunInfo_t *guninfo=ent->client->pers.weapon->guninfo;	
	int mag_index=ent->client->pers.weapon->mag_index;
	int mod=guninfo->MeansOfDeath;
	int	damage = guninfo->damage_direct;

	if (ent->client->next_fire_frame > ptrlevel->framenum)
		return;

	if (!(ent->client->buttons & BUTTON_ATTACK))
	{
		ent->client->machinegun_shots = 0;
		ent->client->ps.gunframe++;
		return;
	}

	if(ent->client->aim)
	{
		if (ent->client->ps.gunframe == guninfo->LastAFire)
			ent->client->ps.gunframe = guninfo->LastAFire-1;
		else
			ent->client->ps.gunframe = guninfo->LastAFire;
	}

	else
	{
		if (ent->client->ps.gunframe == guninfo->LastFire)
			ent->client->ps.gunframe = guninfo->LastFire-1;
		else
			ent->client->ps.gunframe = guninfo->LastFire;
	}

	if (!ent->client->mags[mag_index].lmg_rnd)
	{
		ent->client->ps.gunframe = (ent->client->aim)?guninfo->LastAFire+1:guninfo->LastFire+1;
	
		if (ptrlevel->time >= ent->pain_debounce_time)
		{
			ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"), 1, ATTN_NORM, 0);
			ent->pain_debounce_time = ptrlevel->time + 1;
		}
		
/*
		if (auto_weapon_change->value) 
			NoAmmoWeaponChange (ent);
*/
		
		return;
	}


	// raise the gun as it is firing
//	if (!deathmatch->value)
//	{
//	if ((ent->stanceflags == STANCE_STAND) || (!ent->client->aim))
		ent->client->machinegun_shots++;

	if (ent->client->machinegun_shots > 9)
		ent->client->machinegun_shots = 9;

//	if ((!ent->stanceflags == STANCE_STAND) && (ent->client->aim))
//		ent->client->machinegun_shots = 0;

//	}

	// vspread
	//VectorSet(offset, 0, (ent->client->aim)?0:8, ent->viewheight-8 + (crandom() * 15));
	// rezmoth - changed for new firing system
	//VectorSet(offset, 0, (ent->client->aim)?0:8, (ent->client->aim)?ent->viewheight-8:crandom() * 15);
	if (ent->client->pers.weapon->position == LOC_L_MACHINEGUN)
		VectorSet(offset, 0, 0, ent->viewheight - 0);	//10
	else
		ptrgi->dprintf("*** Firing System Error\n");

	// rezmoth - cosmetic recoil
	if (ptrlevel->framenum % 3 == 0)
	{
		if (ent->client->aim)
			ent->client->kick_angles[0] -= 1.5;
		else
			ent->client->kick_angles[0] = -3;
	}

	// pbowens: for darwin's 3.2 kick
	ent->client->kick_angles[0] = ent->client->machinegun_shots * -1;

	// get start / end positions
	VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
	AngleVectors (angles, forward, right, NULL);
	
	P_ProjectSource (ent->client, ent->s.origin, offset, forward, right, start);

	/*	
	VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
	AngleVectors (angles, forward, right, NULL);
	VectorSet(offset, 0, 8, ent->viewheight-8);
	P_ProjectSource (ent->client, ent->s.origin, offset, forward, right, start);
*/

	fire_gun2(ent, start, forward, damage, kick, 0, 0, mod, false);

	if(ent->client->mags[mag_index].lmg_rnd==1)
	{
		//Hard coded for reload only.
        ent->client->ps.gunframe=guninfo->LastReload+1;
        ent->client->weaponstate = WEAPON_END_MAG;
//faf	Play_WepSound(ent,guninfo->LastRoundSound);
		ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->LastRoundSound), 1, ATTN_NORM, 0);//faf

	}

	// rezmoth - changed to new firing code
	//fire_bullet (ent, start, forward, damage, kick, DEFAULT_BULLET_HSPREAD, DEFAULT_BULLET_VSPREAD, mod, false);
/*	
	    ent->client->anim_priority = ANIM_ATTACK;
    if (ent->client->ps.pmove.pm_flags & PMF_DUCKED)
    {
        ent->s.frame = FRAME_crattak1 - 1 + (ent->client->ps.gunframe % 3);
        ent->client->anim_end = FRAME_crattak9;
    }
    else
    {
        ent->s.frame = FRAME_attack1 - 1 + (ent->client->ps.gunframe % 3);
        ent->client->anim_end = FRAME_attack8;
    }
*/
	//gi.sound(ent, CHAN_WEAPON, gi.soundindex("weapons/machgf2b.wav"), 1, ATTN_NORM, 0);


//faf	Play_WepSound(ent,guninfo->FireSound);//PlayerNoise(ent, start, PNOISE_WEAPON);
	ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->FireSound), 1, ATTN_NORM, 0);//faf

	ptrgi->WriteByte (svc_muzzleflash);
	ptrgi->WriteShort (ent-g_edicts);
	ptrgi->WriteByte (MZ_MACHINEGUN);// | is_silenced);
	ptrgi->multicast (ent->s.origin, MULTICAST_PVS);

	ent->client->mags[mag_index].lmg_rnd--;
	ent->client->next_fire_frame = ptrlevel->framenum + guninfo->frame_delay;
}


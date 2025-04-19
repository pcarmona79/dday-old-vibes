/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /usr/local/cvsroot/dday/src/ita/ita_weapon.c,v $
 *   $Revision: 1.13 $
 *   $Date: 2002/07/23 07:26:15 $
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

// p_weapon.c
// D-Day: Normandy Player Weapon Code





void Weapon_B3842_Fire (edict_t *ent)
{
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

	if (!ent->client->mags[mag_index].submg2_rnd)
	{
		ent->client->ps.gunframe = (ent->client->aim)?guninfo->LastAFire+1:guninfo->LastFire+1;
	
		if (ptrlevel->time >= ent->pain_debounce_time)
		{
			ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"), 1, ATTN_NORM, 0);
			ent->pain_debounce_time = ptrlevel->time + 1;
		}
		
		
		return;
	}


	// raise the gun as it is firing
//	if (!deathmatch->value)
//	{
	ent->client->machinegun_shots++;
	if (ent->client->machinegun_shots > 9)
		ent->client->machinegun_shots = 9;
//	}


//	if (ent->client->pers.weapon->position == LOC_SUBMACHINEGUN)
		VectorSet(offset, 0, 0, ent->viewheight - 0);	//10
//	else
//		ptrgi->dprintf("*** Firing System Error\n");

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


	fire_gun(ent, start, forward, damage, kick, 40, 40, mod, false);


	ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->FireSound), 1, ATTN_NORM, 0);

	ptrgi->WriteByte (svc_muzzleflash);
	ptrgi->WriteShort (ent-g_edicts);
	ptrgi->WriteByte (MZ_MACHINEGUN);// | is_silenced);
	ptrgi->multicast (ent->s.origin, MULTICAST_PVS);

	ent->client->mags[mag_index].submg2_rnd--;
	ent->client->next_fire_frame = ptrlevel->framenum + guninfo->frame_delay;
}







/*
void Weapon_Generic (edict_t *ent, 
 int FRAME_ACTIVATE_LAST,	int FRAME_LFIRE_LAST,	int FRAME_LIDLE_LAST, 
 int FRAME_RELOAD_LAST,		int FRAME_LASTRD_LAST,	int FRAME_DEACTIVATE_LAST,
 int FRAME_RAISE_LAST,		int FRAME_AFIRE_LAST,	int FRAME_AIDLE_LAST,
 int *pause_frames,			int *fire_frames,		void (*fire)(edict_t *ent))
*/


/////////////////////////////////////////////////
// Weapon_B34
/////////////////////////////////////////////////

void Weapon_B34 (edict_t *ent)
{
	static int	pause_frames[]	= {53};//{13, 32,42};
	static int	fire_frames[1];	//= {4,59,0};

	fire_frames[0]=(ent->client->aim)?71:4;

	ent->client->p_fract= &ent->client->mags[ita_index].pistol_fract;
	ent->client->p_rnd= &ent->client->mags[ita_index].pistol_rnd;

	ent->client->crosshair = false;

if ((ent->client->weaponstate == WEAPON_FIRING || ent->client->weaponstate == WEAPON_READY)
			&& !ent->client->heldfire && (ent->client->buttons & BUTTON_ATTACK)
			&& ent->client->ps.gunframe!=((ent->client->aim)?70:3)
			&& ent->client->ps.gunframe!=((ent->client->aim)?71:4)
			&& ent->client->ps.gunframe!=((ent->client->aim)?72:5)
			&& ent->client->ps.gunframe!=((ent->client->aim)?73:6)
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
		3,  6,  47, 
		58, 61, 65, 
		70, 73, 84, 
		
		pause_frames, fire_frames, Weapon_Pistol_Fire);
}


/////////////////////////////////////////////////
// Mauser 98(k)
/////////////////////////////////////////////////

void Weapon_Carcano (edict_t *ent)
{
	static int	pause_frames[]	= {67};//{4,25, 50, 0};
	static int	fire_frames[1];// = {4};

	fire_frames[0]=(ent->client->aim)?86:4;
	
	ent->client->p_fract = &ent->client->mags[ita_index].rifle_fract;
	ent->client->p_rnd= &ent->client->mags[ita_index].rifle_rnd;

	ent->client->crosshair = false;

	//faf
	if (ent->client->ps.gunframe == 9 ||
		ent->client->ps.gunframe == 92)
		ptrgi->sound(ent, CHAN_AUTO, ptrgi->soundindex("usa/m1903/bolt.wav"), 1, ATTN_NORM, 0);

	if (ent->client->weaponstate != WEAPON_RELOADING &&
		ent->client->ps.gunframe > 94 &&
		ent->client->ps.gunframe < 104 &&
		!ent->client->aim)
	{
		//ptrgi->dprintf ("%i\n",ent->client->weaponstate);
//		ent->client->ps.gunframe = 84;
//		ent->client->weaponstate = WEAPON_LOWER;
		ent->client->ps.gunframe = 18;
		ent->client->weaponstate = WEAPON_READY;
		return;
	}
	if (ent->client->ps.gunframe == 96)
	{
		ent->client->crosshair_offset_x = random() * 4 - 2;
		ent->client->crosshair_offset_y = random() * 2;
	}

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

//faf: bayonet code
	if (ent->client->ps.gunframe == 107)
	{
		ent->client->ps.gunframe = 18;
		return;
	}

	if (ent->client->ps.gunframe > 104)
	{
		ent->client->ps.gunframe++;
		return;
	}
//end bayonet
	Weapon_Generic (ent, 
		3,  16, 56, 
		78, 78, 82, 
		85, 98, 103, 
		
		pause_frames, fire_frames, Weapon_Rifle_Fire);


}


/////////////////////////////////////////////////
// b38
/////////////////////////////////////////////////

void Weapon_B38 (edict_t *ent)
{

	static int	pause_frames[]	= {58};
	static int	fire_frames[2];//try to put stutter back in

	fire_frames[0]=(ent->client->aim)?79:4;
	fire_frames[1]=(ent->client->aim)?80:5;

	ent->client->p_fract= &ent->client->mags[ita_index].submg_fract;
	ent->client->p_rnd= &ent->client->mags[ita_index].submg_rnd;

	ent->client->crosshair = false;

	Weapon_Generic (ent, 
		 3,  5, 45, 
		71, 71, 75, 
		78, 80, 92, 
		
		pause_frames, fire_frames, Weapon_Submachinegun_Fire);

}

void Weapon_K43_Fire (edict_t *ent)
{
	int	i;
	vec3_t		start;
	vec3_t		forward, right,up;
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

	/*
	if(ent->client->aim)
	{
		if(ent->client->ps.gunframe == guninfo->LastAFire)
			ent->client->ps.gunframe=guninfo->LastAFire-1;
		else ent->client->ps.gunframe=guninfo->LastAFire;
	}
	else
	{
		if (ent->client->ps.gunframe == guninfo->LastFire)
			ent->client->ps.gunframe = guninfo->LastFire-1;
		else
			ent->client->ps.gunframe = guninfo->LastFire;
	}
*/
	if (ent->client->mags[mag_index].lmg_rnd < 1)
	{
		ent->client->ps.gunframe = (ent->client->aim)?guninfo->LastAFire + 1:guninfo->LastFire + 1;
		ent->client->weaponstate = WEAPON_READY;

		if (ptrlevel->time >= ent->pain_debounce_time)
		{
			ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"), 1, ATTN_NORM, 0);
			ent->pain_debounce_time = ptrlevel->time + 1;
		}
//		if(auto_weapon_change->value) NoAmmoWeaponChange (ent);

		return;
	}

	ent->client->ps.gunframe++;

	if (!ent->client->aim)
	{
		for (i=0 ; i<3 ; i++)
		{
			//rezmoth - changed for new firing system
			//ent->client->kick_origin[i] = (crandom() * 0.5)-1.5;
			//ent->client->kick_angles[i] = (crandom() * 0.7)-1.5;
		}
		//rezmoth - changed for new firing system
		//ent->client->kick_origin[0] = crandom() * 0.35;
		//ent->client->kick_angles[0] = ent->client->machinegun_shots * -1.8;

		VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
		AngleVectors (angles, forward, right, up);
	}
	else
	{
		for (i=1 ; i<3 ; i++)
		{
			//rezmoth - changed for new firing system
			//ent->client->kick_origin[i] = crandom() * 0.30;
			//ent->client->kick_angles[i] = crandom() * 0.5;
		}
		//rezmoth - changed for new firing system
		//ent->client->kick_origin[0] = crandom() * 0.35;
		//ent->client->kick_angles[0] = ent->client->machinegun_shots * -1.0;

		VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
		AngleVectors (angles, forward, right, NULL);
	}

	// raise the gun as it is firing
//	if (!deathmatch->value)
//	{
		//ent->client->machinegun_shots++;
		//if (ent->client->machinegun_shots > 7)
			//ent->client->machinegun_shots = 7;
//	}

	// get start / end positions

	//rezmoth - changed for new firing system
	//VectorSet(offset, 0, (ent->client->aim)?0:8, ent->viewheight-8);

	if (ent->client->pers.weapon->position == LOC_L_MACHINEGUN)
		VectorSet(offset, 0, 0, ent->viewheight - 0);	//8
	else
		ptrgi->dprintf("*** Firing System Error\n");

	P_ProjectSource (ent->client, ent->s.origin, offset, forward, right, start);

	fire_gun(ent, start, forward, damage, kick, 0, 0, mod, false);

	// rezmoth - cosmetic recoil
	if (ptrlevel->framenum % 3 == 0)
	{
		if (ent->client->aim)
			ent->client->kick_angles[0] -= 1.5;
		else
			ent->client->kick_angles[0] = -3;
	}

	/*faf:  this  doesnt really add anything to the game
	if(ent->client->mags[mag_index].lmg_rnd==1)
	{
		//Hard coded for reload only.
        ent->client->ps.gunframe=guninfo->LastReload+1;
        ent->client->weaponstate = WEAPON_END_MAG;
		Play_WepSound(ent,guninfo->LastRoundSound);
	}
	*/

	// rezmoth - changed to new firing code
	//fire_bullet (ent, start, forward, damage, kick, DEFAULT_BULLET_HSPREAD, DEFAULT_BULLET_VSPREAD, mod, false);

	Play_WepSound(
		ent,
		guninfo->FireSound
	);

	ptrgi->WriteByte (svc_muzzleflash);
	ptrgi->WriteShort (ent-g_edicts);
	ptrgi->WriteByte (MZ_MACHINEGUN);// | is_silenced);
	ptrgi->multicast (ent->s.origin, MULTICAST_PVS);
	//PlayerNoise(ent, start, PNOISE_WEAPON);

	ent->client->mags[mag_index].lmg_rnd--;
	ent->client->next_fire_frame = ptrlevel->framenum + guninfo->frame_delay;
}

/////////////////////////////////////////////////
// K43
/////////////////////////////////////////////////

void Weapon_K43 (edict_t *ent)
{
	static int	pause_frames[]	= {54};//{47, 80};
	static int	fire_frames[1];
	
	fire_frames[0] = (ent->client->aim)?76:4;

	// Wheaty: Uncomment next line to allow topping off
	//ent->client->p_fract = &ent->client->mags[usa_index].rifle_fract
	ent->client->p_rnd= &ent->client->mags[ita_index].lmg_rnd;

	ent->client->crosshair = false;

if ((ent->client->weaponstate == WEAPON_FIRING || ent->client->weaponstate == WEAPON_READY)
			&& !ent->client->heldfire && (ent->client->buttons & BUTTON_ATTACK)
			&& ent->client->ps.gunframe!=((ent->client->aim)?75:3)
			&& ent->client->ps.gunframe!=((ent->client->aim)?76:4)
			&& ent->client->ps.gunframe!=((ent->client->aim)?77:5)
			&& ent->client->ps.gunframe!=((ent->client->aim)?78:6)
			//gotta do it this way for both firing modes
)
		{
			if (ent->client->ps.gunframe<4)
//				firetype = abs(5-ent->client->ps.gunframe);  unknown function
			ent->client->ps.gunframe = 4;
			ent->client->weaponstate = WEAPON_READY;
		//	ent->client->latched_buttons |= BUTTON_ATTACK;
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
		64, 67, 72, 
		75, 78, 89, 
		
		pause_frames, fire_frames, Weapon_K43_Fire);
}




/////////////////////////////////////////////////
// B3842
/////////////////////////////////////////////////


void Weapon_B3842 (edict_t *ent)
{

	static int	pause_frames[]	= {57};
	static int	fire_frames[2];//try to put stutter back in

	fire_frames[0]=(ent->client->aim)?79:4;
	fire_frames[1]=(ent->client->aim)?80:5;

	ent->client->p_fract= &ent->client->mags[ita_index].submg2_fract;
	ent->client->p_rnd= &ent->client->mags[ita_index].submg2_rnd;

	ent->client->crosshair = false;

	Weapon_Generic (ent, 
		 3,  5, 45, 
		71, 71, 75, 
		78, 80, 92, 
		
		pause_frames, fire_frames, Weapon_B3842_Fire);

}



/////////////////////////////////////////////////
// Panzerfaust
/////////////////////////////////////////////////

void rocket_touch (edict_t *ent, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	vec3_t		origin;
	int			n;

	if (other == ent->owner)
		return;

	if (surf && (surf->flags & SURF_SKY))
	{
		G_FreeEdict (ent);
		return;
	}

	if (ent->owner->client)
		PlayerNoise(ent->owner, ent->s.origin, PNOISE_IMPACT);

	// calculate position for the explosion entity
	VectorMA (ent->s.origin, -0.02, ent->velocity, origin);

	if (other->takedamage)
	{
		T_Damage (other, ent, ent->owner, ent->velocity, ent->s.origin, plane->normal, ent->dmg, 0, 0, MOD_ROCKET);
	}
	else
	{
		// don't throw any debris in net games
		//if (!deathmatch->value && !coop->value)
		//{
			if ((surf) && !(surf->flags & (SURF_WARP|SURF_TRANS33|SURF_TRANS66|SURF_FLOWING)))
			{
				n = rand() % 5;
				while(n--)
					ThrowDebris (ent, "models/objects/debris2/tris.md2", 2, ent->s.origin);
			}
		//}
	}

	T_RadiusDamage(ent, ent->owner, ent->radius_dmg, other, ent->dmg_radius, MOD_R_SPLASH);


	Play_Ricochet_Noise (ent, ent->s.origin);
	Smoke_Effect (ent->s.origin, .1);


	ptrgi->WriteByte (svc_temp_entity);
	if (ent->waterlevel)
		ptrgi->WriteByte (TE_ROCKET_EXPLOSION_WATER);
	else
		ptrgi->WriteByte (TE_ROCKET_EXPLOSION);
	ptrgi->WritePosition (origin);
	ptrgi->multicast (ent->s.origin, MULTICAST_PHS);

	G_FreeEdict (ent);
}

void panzerf_effect(edict_t *rocket)
{
	rocket->s.effects = EF_GRENADE;
	rocket->nextthink = ptrlevel->time + 12;
	rocket->gravity = .5;
	rocket->think = G_FreeEdict;
}

//faf:  adds gravity to the rocket (for piat)
void fire_rocket_panzerfaust (edict_t *self, vec3_t start, vec3_t dir, int damage, int speed, float damage_radius, int radius_damage, float gravity)
{
	edict_t	*rocket;

	rocket = G_Spawn();
	VectorCopy (start, rocket->s.origin);
	VectorCopy (dir, rocket->movedir);
	vectoangles (dir, rocket->s.angles);
	VectorScale (dir, speed, rocket->velocity);
	rocket->movetype = MOVETYPE_BOUNCE,//MOVETYPE_FLYMISSILE;
	rocket->clipmask = MASK_SHOT;
	rocket->solid = SOLID_BBOX;
	//rocket->s.effects |= EF_ROCKET;
	VectorClear (rocket->mins);
	VectorClear (rocket->maxs);
	rocket->s.modelindex = ptrgi->modelindex ("models/objects/panzrocket/tris.md2");
	rocket->owner = self;
	rocket->touch = rocket_touch;

	rocket->gravity =  gravity;//1;//.9; //faf
	
	rocket->nextthink = ptrlevel->time + 8000/speed;
	rocket->think = G_FreeEdict;
	
	//faf
	if (self->client && self->client->pers.weapon &&
		strcasecmp(self->client->pers.weapon->classname, "weapon_panzerfaust") == 0)
		//self->client->pers.weapon->classnameb == WEAPON_PANZERFAUST)
	{
		rocket->s.effects = EF_ROCKET;
		rocket->nextthink = ptrlevel->time + .6;
		rocket->think = panzerf_effect;
		rocket->gravity = .2;
	}
	else
	{
		rocket->s.effects |= EF_GRENADE;
		rocket->nextthink = rocket->nextthink = ptrlevel->time + 8000/speed;
		rocket->think = G_FreeEdict;
	}
	
	rocket->dmg = damage;
	rocket->radius_dmg = radius_damage;
	rocket->dmg_radius = damage_radius;
	rocket->s.sound = ptrgi->soundindex ("weapons/rockfly.wav");
	rocket->classname = "rocket";
	//rocket->classnameb = ROCKET;

	//faf:causing error and dont think is needed	if (self->client)
//faf		check_dodge (self, rocket->s.origin, dir, speed);

	ptrgi->linkentity (rocket);
}

void Weapon_Panzerfaust_Fire (edict_t *ent)
{
	vec3_t	offset, start;
	vec3_t	forward, right;

	GunInfo_t *guninfo=ent->client->pers.weapon->guninfo;	
	int mag_index=ent->client->pers.weapon->mag_index;
	int mod=guninfo->MeansOfDeath;
	int	radius_damage = guninfo->damage_radius; //The *damage* within the radius
	int	damage		= guninfo->damage_direct;

	float	damage_radius; // The *radius* of the damage

	// Nick 28/11/2002 - flag for incorrect firing.
	short int		firewrong;
	firewrong = 0;



	if (ent->client->next_fire_frame > ptrlevel->framenum)
		return;


		// Add the new ones.
		if (ptrgi->pointcontents(ent->s.origin) & MASK_WATER) {
			if (ent->client->machinegun_shots == 0)
				ptrgi->centerprintf(ent, "Get out the water to fire!!\n");
			firewrong = 1;
			ent->client->machinegun_shots = 1;
				}

		else if (!ent->client->aim) {

//			if (ent->client->machinegun_shots == 0)
//				ptrgi->centerprintf(ent, "You have gotta AIM it, Tommy Atkins!!\n");
			firewrong = 1;
			ent->client->machinegun_shots = 1;

				}

		else if ((ent->stanceflags == STANCE_STAND) || (ent->stanceflags == STANCE_CRAWL)) {

			if (ent->client->machinegun_shots == 0)
				ptrgi->centerprintf(ent, "You have to kneel to fire!\n");
			firewrong = 1;
			ent->client->machinegun_shots = 1;

				}

		//else if (ent->stanceflags == STANCE_CRAWL) {
		//	if (ent->client->machinegun_shots == 0)
		//		ptrgi->centerprintf(ent, "Get up on one knee, Tommy Atkins!!\n");
		//	firewrong = 1;
		//	ent->client->machinegun_shots = 1;
		//		}

		if (firewrong == 1) {
		//ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"),1, ATTN_NORM, 0);
		//ent->pain_debounce_time = ptrlevel->time + 1;
		//ent->client->ps.gunframe= (ent->client->aim)?guninfo->LastAFire + 1:
		//													guninfo->LastFire + 1;

		// Nick - 25/11/2002 Had to add this to allow the new 'empty' idle frames to work here.

			if (ent->client->mags[mag_index].antitank_rnd == 0) {
				ent->client->ps.gunframe = 46;
			} else {
			// Original code follows.
			ent->client->ps.gunframe= (ent->client->aim)?72:
										guninfo->LastFire + 1;
			}
		// End Nick

 		ent->client->weapon_sound = 0;
		ent->client->weaponstate=WEAPON_READY;
		return;
	}

	if (!(ent->client->buttons & BUTTON_ATTACK))
	{
		if (ent->client->aim)
			ent->client->ps.gunframe = guninfo->LastAFire+1;
		else
			ent->client->ps.gunframe = guninfo->LastFire+1;
		return;
	}

	ent->s.modelindex2 = ptrgi->modelindex ("players/ita/w_panzerfmt.md2");

	// pbowens: rasied rocket dmg from 175 to 225
	damage_radius = 175;//faf 225;

	AngleVectors (ent->client->v_angle, forward, right, NULL);
	VectorScale (forward, -2, ent->client->kick_origin);
	//ent->client->kick_angles[0] = -1;

//	VectorSet(offset, 8, 8, ent->viewheight-8);			//z,x,y
	VectorSet(offset, 0, 0, ent->viewheight-2);			//z,x,y
	P_ProjectSource (ent->client, ent->s.origin, offset, forward, right, start);

	if (!ent->client->mags[mag_index].antitank_rnd)
	 {

		ent->client->ps.gunframe = (ent->client->aim) ? guninfo->LastAFire+1 : guninfo->LastFire+1;
		 if (ptrlevel->time >= ent->pain_debounce_time)
		 {
			 ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"),1, ATTN_NORM, 0);
			 ent->pain_debounce_time = ptrlevel->time + 1;
		 }

//		if (auto_reload->value)
//			Cmd_Reload_f(ent);

		return;
	}
/* 
	if (ent->client->mags[mag_index].antitank_rnd == 1) { // last round fire sounds

		//Hard coded for reload only.
        ent->client->ps.gunframe=guninfo->LastReload+1;
        ent->client->weaponstate = WEAPON_END_MAG;
//		Play_WepSound(ent,guninfo->LastRoundSound);
		ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->LastRoundSound), 1, ATTN_NORM, 0);//faf

	} */
/*
	if (ent->client->pers.inventory[ent->client->ammo_index] == 1)
	{
		//Hard coded for reload only.
        ent->client->ps.gunframe=guninfo->LastReload+1;
        ent->client->weaponstate = WEAPON_END_MAG;
		Play_WepSound(ent,guninfo->LastRoundSound);
	}

	if (!ent->client->pers.inventory[ent->client->ammo_index])
	{
		ent->client->ps.gunframe = guninfo->LastFire;
		
		if (ptrlevel->time >= ent->pain_debounce_time)
		{
			ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"),1, ATTN_NORM, 0);
			ent->pain_debounce_time = ptrlevel->time + 1;
		}

		//Make the user change weapons MANUALLY!

		if(auto_weapon_change->value) 
			NoAmmoWeaponChange (ent);

		return;
	}
	*/

	// kernel: no need for this line
	//ent->client->last_fire_time = ptrlevel->time;//faf

	fire_rocket_panzerfaust (ent, start, forward, damage, 1600, damage_radius, radius_damage, .7);  
	// rezmoth - cosmetic recoil
	ent->client->kick_angles[0] -= 7;
	ent->client->kick_origin[2] -= 5;

//	Play_WepSound(ent,guninfo->FireSound);//PlayerNoise(ent, start, PNOISE_WEAPON);
	ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->FireSound), 1, ATTN_NORM, 0);//faf

	// send muzzle flash
	ptrgi->WriteByte (svc_muzzleflash);
	ptrgi->WriteShort (ent-g_edicts);
	ptrgi->WriteByte (MZ_ROCKET);
	ptrgi->multicast (ent->s.origin, MULTICAST_PVS);
	
	ent->client->ps.gunframe++;

	//ent->client->pers.inventory[ent->client->ammo_index]--;
	ent->client->mags[mag_index].antitank_rnd--;
	ent->client->next_fire_frame = ptrlevel->framenum + guninfo->frame_delay;
}

void Weapon_Panzerfaust (edict_t *ent)
{
	static int	pause_frames[]	= {0};//{25, 33, 42, 50, 0};
	static int	fire_frames[1];

	fire_frames[0]=(ent->client->aim)?73:4;

	ent->client->p_rnd= &ent->client->mags[ita_index].antitank_rnd;

	ent->client->crosshair = false;

// ptrgi->dprintf("%i\n",ent->client->ps.gunframe);

		if ((ent->client->ps.gunframe >= 46 && ent->client->ps.gunframe <60) ||
			(ent->client->ps.gunframe >= 73 && ent->client->ps.gunframe <80) ||
			(ent->client->ps.gunframe >= 87)) 
				ent->s.modelindex2 = ptrgi->modelindex ("players/ita/w_panzerfmt.md2");
		else
				ent->s.modelindex2 = ptrgi->modelindex ("players/ita/w_panzerf.md2");

	//faf
	if (ent->client->ps.gunframe == 79)//(last fire)
	{
		ent->client->weaponstate = WEAPON_LOWER;
		ent->client->aim = false;
	}

	if ((ent->client->p_rnd && *ent->client->p_rnd == 0) )
	{
		if (ent->client->weaponstate == WEAPON_ACTIVATING)
		{
			ent->client->ps.gunframe = 105;
			
			ent->client->weaponstate = WEAPON_READY;
		}

	}

	Weapon_Generic (ent, 
		 3,  5, 45, 
		65, 65, 69,
		72, 80, 86,//faf75, 86, 
		
		pause_frames, fire_frames, Weapon_Panzerfaust_Fire);

	if ((ent->client->p_rnd && *ent->client->p_rnd == 0))
	{
		if (ent->client->weaponstate == WEAPON_LOWER ||
			ent->client->weaponstate == WEAPON_READY)
		{
			if (ent->client->ps.gunframe < 106)
				ent->client->ps.gunframe = 106;

			if (ent->client->ps.gunframe > 108)
				ent->client->ps.gunframe = 105;

			ent->client->ps.gunframe++;

			return;
		}
	}
}


/////////////////////////////////////////////////
// Mauser 98(ks) Sniper Rifle
/////////////////////////////////////////////////

void ITA_Weapon_m98ks (edict_t *ent)
{
	static int	pause_frames[]	= {34};
	static int	fire_frames[4];

	fire_frames[0]=(ent->client->aim)?52:4;//fire here
	fire_frames[1]=(ent->client->aim)?59:0;//faf 60:0;//sniper bolt
	fire_frames[2]=(ent->client->aim)?75:0;//sniper start zoom
	fire_frames[3]=(ent->client->aim)?80:0;//sniper end zoom

	ent->client->p_fract= &ent->client->mags[ita_index].sniper_fract;
	ent->client->p_rnd= &ent->client->mags[ita_index].sniper_rnd;

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
/*			&& ent->client->ps.gunframe!=((ent->client->aim)?55:7)
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
			&& ent->client->ps.gunframe!=((ent->client->aim)?80:8)*/
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
		 3, 8, 26,//25, 27,//faf 26, 26, 
		43, 43, 48, 
		51, 80, 80, 
		
		pause_frames, fire_frames, Weapon_Sniper_Fire);
}


/////////////////////////////////////////////////
// MG42
/////////////////////////////////////////////////
//copy of bren
void Weapon_Breda_Fire (edict_t *ent)
{
	vec3_t		startc;
	vec3_t		forwardc, rightc;
	vec3_t		offsetc;
	vec3_t		up;
	trace_t tr; //faf
    vec3_t endc; //faf
	vec3_t g_offset; //faf
	
	vec3_t		forward, right,start;
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

	if (!ent->client->mags[mag_index].hmg_rnd)
	{
		ent->client->ps.gunframe = (ent->client->aim)?guninfo->LastAFire+1:guninfo->LastFire+1;
	
		if (ptrlevel->time >= ent->pain_debounce_time)
		{
			ptrgi->sound(ent, CHAN_VOICE, ptrgi->soundindex("weapons/noammo.wav"), 1, ATTN_NORM, 0);
			ent->pain_debounce_time = ptrlevel->time + 1;
		}
		
		return;
	}


	// raise the gun as it is firing
//	if (!deathmatch->value)
//	{
	if (//!ent->ai &&
		((ent->stanceflags == STANCE_STAND) || (!ent->client->aim)))
		ent->client->machinegun_shots++;

	if (ent->client->machinegun_shots > 9)
		ent->client->machinegun_shots = 9;

	if ((!ent->stanceflags == STANCE_STAND) && (ent->client->aim))
		ent->client->machinegun_shots = 0;

//	}

	if (ent->client->pers.weapon->position == LOC_H_MACHINEGUN)
		VectorSet(offset, 0, 0, ent->viewheight - 0);	//10
	else
		ptrgi->dprintf("*** Firing System Error\n");

	if (ent->client->aim)
	{
		if (ent->stanceflags == STANCE_STAND)
		{
		
			VectorCopy (vec3_origin,g_offset);

			AngleVectors (ent->client->v_angle, forwardc, rightc, NULL);
			VectorSet(offsetc, 24, 8, ent->viewheight-25);
			VectorAdd (offsetc, g_offset, offsetc);
			P_ProjectSource (ent->client, ent->s.origin, offsetc, forwardc, rightc, startc);
			VectorScale (forwardc, -2, ent->client->kick_origin);
			
			VectorMA (startc, 10, forwardc, endc);  //calculates the range vector  //faf: 10 = range
			tr = ptrgi->trace (ent->s.origin, NULL, NULL, endc, ent, MASK_SHOT);// figures out what in front of the player up till "end"

			if (tr.fraction >= 1.0 ||
				ent->client->v_angle[0] > 40)
			{
				int i;
				for (i=0 ; i<3 ; i++)
				{
					//rezmoth - changed for new firing system
					ent->client->kick_origin[i] = (crandom() * 3.35)-1.5;
					ent->client->kick_angles[i] += (crandom() * 13.7)-1.5;
				}
				//rezmoth - changed for new firing system
				ent->client->kick_origin[0] = crandom() * 0.35;
				ent->client->kick_angles[0] += ent->client->machinegun_shots * -1.8;
				// Raise HMG faster
				ent->client->machinegun_shots += 2;
				VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
				AngleVectors (angles, forward, right, up);				
			}

		}
	}
	else
	{
		int i;
		for (i=0 ; i<3 ; i++)
		{
			//rezmoth - changed for new firing system
			ent->client->kick_origin[i] = (crandom() * 3.35)-1.5;
			ent->client->kick_angles[i] += (crandom() * 13.7)-1.5;
		}
		//rezmoth - changed for new firing system
		ent->client->kick_origin[0] = crandom() * 0.35;
		ent->client->kick_angles[0] += ent->client->machinegun_shots * -1.8;
		// Raise HMG faster
		ent->client->machinegun_shots += 2;
		VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
		AngleVectors (angles, forward, right, up);
	}
	// get start / end positions
	VectorAdd (ent->client->v_angle, ent->client->kick_angles, angles);
	AngleVectors (angles, forward, right, NULL);

	P_ProjectSource (ent->client, ent->s.origin, offset, forward, right, start);

	fire_gun(ent, start, forward, damage, kick, 100, 100, mod, false);

	if(ent->client->mags[mag_index].hmg_rnd==1)
	{
		//Hard coded for reload only.
        ent->client->ps.gunframe=guninfo->LastReload+1;
        ent->client->weaponstate = WEAPON_END_MAG;
//faf	Play_WepSound(ent,guninfo->LastRoundSound);
		ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->LastRoundSound), 1, ATTN_NORM, 0);//faf

	}

//faf	Play_WepSound(ent,guninfo->FireSound);//PlayerNoise(ent, start, PNOISE_WEAPON);
	ptrgi->sound(ent, CHAN_WEAPON, ptrgi->soundindex(guninfo->FireSound), 1, ATTN_NORM, 0);//faf

	ptrgi->WriteByte (svc_muzzleflash);
	ptrgi->WriteShort (ent-g_edicts);
	ptrgi->WriteByte (MZ_MACHINEGUN);// | is_silenced);
	ptrgi->multicast (ent->s.origin, MULTICAST_PVS);

	ent->client->mags[mag_index].hmg_rnd--;
	ent->client->next_fire_frame = ptrlevel->framenum + guninfo->frame_delay;
}


void Weapon_Breda (edict_t *ent)
{
	static int	pause_frames[]	= {71};//{38, 61, 0};
	static int	fire_frames[2];

//	fire_frames[0]=(ent->client->aim)?99:20;
	fire_frames[0]=(ent->client->aim)?86:21;
	fire_frames[1]=(ent->client->aim)?87:22;

	ent->client->p_rnd= &ent->client->mags[ita_index].hmg_rnd;

	ent->client->crosshair = false;

	Weapon_Generic (ent, 
		20, 22, 62, 
		79, 79, 82, 
		85, 87, 99, 
		
		pause_frames, fire_frames, Weapon_Breda_Fire);
}

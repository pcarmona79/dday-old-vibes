/*       D-Day: Normandy by Vipersoft
 ************************************
 *   $Source: /var/lib/cvs/dday42sk/src/usa/usa_defines.h,v $
 *   $Revision: 1.1.1.1 $
 *   $Date: 2003/10/06 22:57:59 $
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

#ifndef __USA_DEFINES_H__
#define __USA_DEFINES_H__

#define COLT45MAG		7
#define THOMPSONMAG		30
#define M1_MAG			8
#define M1903_MAG		5
#define BAR_MAG			20
#define HMG_MAG			100
#define BAZOOKA_MAG		1
#define M1CARB_MAG		15

#define COLT45_FRAME	0
#define M1_FRAME		1
#define THOMPSON_FRAME	2
#define BAR_FRAME		3
#define BHMG_FRAME		4
#define BAZOOKA_FRAME	5
#define SNIPER_FRAME	6
#define M1CARB_FRAME	7

#define DAMAGE_COLT45		25
// rezmoth - was 33 before new locational damage
#define DAMAGE_M1			45	// Wheaty: Was 50 (One shot kills)
#define DAMAGE_THOMPSON		25 // wheaty: was 20
#define DAMAGE_BAR			35
#define DAMAGE_BHMG			50
#define DAMAGE_BAZOOKA_HIT	1000 // bridges default to 2000 with cast's maps =)
#define DAMAGE_BAZOOKA_RAD	500
#define DAMAGE_M1903		100
#define DAMAGE_M1CARB		30

#endif /* __USA_DEFINES_H__ */

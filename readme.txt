This is a modification of original D-Day: Normandy by Vipersoft and the
SHAEF team.

What's new in 4.6k-2
--------------------

 - Removes code blocks from Load_Weapon() of p_classes.c and
   Drop_Weapon() of p_weapon.c that was searching for specific
   "mauser98k_mag" ammo item. Also Drop_Weapon() will no longer sum
   bullets from the infantry and sniper rifles. This will fix bug of
   dropping an infantry rifle with more bullets than it can load.

 - Fixes player_die() of p_client.c to do not call TossClientWeapon() if
   the player was carrying a live TNT. This will fix bug when player was
   killed carrying a live TNT and leave a non-activated one.

What's new in 4.6k-1
--------------------

 - Fixes Drop_Flamed() of g_combat.c to allow TNT dropping. Functions
   weapon_grenade_fire() and weapon_tnt_fire() will drop the item if the
   player is burning and the "touch" functions will prevent burning
   players to pickup live tnt or grenades.
 - Fixes TossClientWeapon() of p_client.c to allow drop the TNT when the
   player has died. Also the call of this function is made after firing
   any live tnt or grenade in player_die().

What's new in 4.6k
------------------

 - Adds some extra animations from source version 5.x to
   Weapon_Generic() of p_generic_wep.c and G_SetClientFrame() of
   p_view.c.
 - Gives visual recoil to Gewehr K43 in Weapon_K43_Fire() of
   ita_weapon.c.
 - Fixes scoreboards in p_hud.c when there are too many players to be
   displayed.
 - Fixes ClientEndServerFrame() of p_view.c to only show original
   scoreboard when in intermision or not in observer mode.
 - Adds score to player id in chasing mode for better streaming
   experience.
 - Modifies Touch_Spawn_Protect() of g_func.c to not allow damage for
   rockets and airstrikes inside spawn areas when cvar "chile" is
   enabled.
 - Speed up and spread the airstrike around the target.
 - Enables TNT dropping.
 - Enable usage of function Drop_Flamed() from g_combat.c to drop weapon
   when player is burning.
 - Adds check for binoculars in function check_unscope() of g_weapon.c.
   This should fix bug of scoped view when changing too fast the
   binoculars.
 - Fixes comparison of probability of drop shot in T_Damage() of
   g_combat.c.
 - In turret_breach_die() and turret_base_die() of g_turret.c, adds
   check for freed entity before try to work in other entities of the
   current turret. Also fixes potential SIGSEGV in turret_base_die().
 - Fixes some calls to FindItemInTeam() to use pers.weapon struct
   instead of resp.team_on when getting the team DLL's name.
 - Removes empty function ifchangewep() from p_generic_wep.c.

What's new in 4.5k-2
--------------------

 - Fixes door_blocked() of g_func.c to avoid invoke door_go_up() when
   there is no activator.
 - Fixes undefined cvar "chile" in ita_main.c which was crashing maps
   with italian team when selecting classes.

What's new in 4.5k-1
--------------------

 - Adds Svcmd_TimeLeft_f() to implement new server command "sv timeleft"
   that will broadcast the time left if a countdown is running.
 - Adds DDay_LoadTextFile() and DDay_LoadMOTD() to g_maps.c to load
   motd.txt to a local buffer and read from this in every call to
   Cmd_MOTD(). This change has the objective to avoid open the file
   every time a client connects or execute a "motd" command.
 - Moves allied_sandbags and axis_sandbags to level_locals_t struct, so
   sandbag count is resetted on map change.

What's new in 4.5k
-------------------

 - Adds support for loading map ents, readed from .ent files in the
   "ents/" directory.
 - Adds support for spawn types "spawn_protect" and "spawn_toggle" adding
   code from 5.x source.
 - Adds mapclasslimits array to allow mappers to set the class limits.
 - Adds support for turrets from 5.x source.
 - Adds parachute spawn for special classes, copied from 5.x source code.
 - Cleans up code, removing duplicated and some unused functions.
 - Adds cvar "chile" to restrict some tweaks only when this cvar is
   enabled. The first tweak is to do not rise the submachine guns when
   firing and the british and japanese LMG now are using its original
   fire functions.
 - Remove unused functions from u_entmgr.c and fixes the buggy function
   InsertItem(), replacing it with a version which adds new elements to
   the end only if it was adding a new one. Also fixes for loops in
   FindItem* functions of g_items.c and other for loops involving
   game.num_items, to allow them to correctly reach the end of itemlist
   array.
 - Fixes buffer overflow when showing objective pic for maps with larger
   names, in G_SetStats() of p_hud.c
 - Adds cvar "force_limits" to limit classes with new cvars
   limit_<classname>, overriding map settings.
   * force_limits: Enable class limits.
   * limit_infantry, limit_officer, limit_lgunner, limit_hgunner,
     limit_sniper, limit_engineer, limit_medic, limit_special,
     limit_flamer: Maximum players allowed to spawn. If value is 0,
     class will be disabled.
 - Fixes functions Weapon_PIAT_Fire() of g_weapon.c and
   Weapon_Panzerfaust_Fire() of ita_weapon.c to have the same value for
   "damage_radius" as Weapon_Rocket_Fire() of g_weapon.c.

Whats new in 4.4k-1
-------------------

 - Fixes compile warnings about file usage and replaces the majority of
   fopen() calls by using new function DDay_OpenFullPathFile().

Whats new in 4.4k
-----------------

 - Imported italian, polish, japanese and US Marines teams from 5.x source.
 - Fixes frame animations of several rifles so does not get stuck when
   reloading and improves playability.
 - All light machineguns will use the same function to avoid that recoil
   moves the weapon up.
 - Adds sandbags to the engineer class from 5.x source.
 - TNT can be picked up if you pass over it, allowing you to throw it away.
 - Adds "mashup" cvar to mix allied and axis teams when loading a new map.
 - Adds a splitted scoreboard to observer mode which is more suitable for
   streaming. The scores's position can be controlled with the cvar
   "observer_bscore" to show the scores in the bottom of screen in observer
   mode when is in 1 or on top of each team's members list when is 0.
 - Fixes "fraglimit" by forcing to check the team's score than individual
   frags.
 - Adds new server command "sv countdown". This will allow to set a countdown
   to finish the map in the minutes passed as argument. Ex:
     sv countdown 20 - Sets a time limit of 20 minutes.
     sv countdown    - Shows remaining time to all players.
 - Adds server command "sv resetscore" to allow to reset teams scores and
   kill's count.
 - Implement server command "sv teams" to show information of teams members.
 - Improve observer mode from source 5.x
 - Enables to hit and blow the tank of the flamethrower class.
 - Searches in Q2PRO directories when loading team DLLs.

Whats new in 4.3k
-----------------

 - Added team killers detection and kick them
 - New cvars for teamkiller detection:
     teamkills_check: enables team killers detection
     teamkills_max: max teammates killed by a player in a interval
     teamkills_time: interval of time from first teammate killed
   To set a server to kick players who kill more than 5 teammates in 60
   seconds, add this to your server's configuration:
     set teamkills_check 1
     set teamkills_max 5
     set teamkills_time 60

Whats new in version 4.2sk
--------------------------

 - Deleted jump motion effect to 1st person view weapon when jumping ;)
 - Added smoke to rocket :D


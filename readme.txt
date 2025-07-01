This is a modification of original D-Day: Normandy by Vipersoft and the
SHAEF team.

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


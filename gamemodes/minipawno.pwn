/********************************************************/
/*      MINI PAWNO GAMEMODE
		Author:  promsters (Viral)
		Version: 0.1
		Website: pawno.pl
		Last modified: 20.04.2015
*/
/*******************************************************/
#include <a_samp>
#include <a_mysql>

#include <fixes>
#include <crashdetect>
#include <streamer>
#include <sscanf2>
#include <dini>
#include <CTime>

#include <YSI\y_iterate>
#include <YSI\y_timers>
#include <md5>
#include <kickfix>
#include <sprintf>
#include <zcmd>

#include <logprintf>
#include <dynamicgui>
#include <code_timer>
#include <color_management>


#include "minipawno/config.inc"
#include "minipawno/functions.inc"

main() {}

public OnGameModeInit()
{
	Code_ExTimer_Begin(GameModeInit);
	
	SetGameModeText("MiniPawno v"MP_VERSION);
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	ShowNameTags(1);
	SetNameTagDrawDistance(40.0);
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();
	SetWeather(2);
	SetWorldTime(11);

	// Player Class
	AddPlayerClass(298,1759.0189,-1898.1260,13.5622,266.4503,-1,-1,-1,-1,-1,-1);
	
	LoadConfiguration();
	if( !ConnectMysql() ) return 0;
	
	printf("[MiniPawno] MP Gamemode v"MP_VERSION" zostal wczytany pomyslnie [czas wykonania: %d ms]", Code_ExTimer_End(GameModeInit));
	return 1;
}

public OnGameModeExit()
{
	mysql_close(MySQL);
	return 1;
}

public OnPlayerConnect(playerid)
{
  	SendClientMessage(playerid, -1, "Witaj na serwerze MiniPawno!");
 	return 1;
}


public OnPlayerSpawn(playerid)
{
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
   	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{    
	return 0;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

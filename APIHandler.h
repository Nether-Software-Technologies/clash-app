/**
 * @
 * @
 * @
 */

//PREPROCESSOR DIRECTIVES
#pragma once
#include <string>
#include <iomanip>
#include <curl/curl.h>
#include "Champion.h"
#include "Summoner.h"
#include <rapidjson/document.h>

//NAMESPACE
namespace API {
	const std::string API_BASE_NA = "https://na1.api.riotgames.com/lol";
	const std::string API_KEY = "?api_key=RGAPI-c9b6c60e-b4a9-49bb-ad9b-028b56d646db";
	const std::string API_SUMMONER_NAME = "/summoner/v4/summoners/by-name/";
	const std::string API_MASTERY_SUMMONER = "/champion-mastery/v4/champion-masteries/by-summoner/";
	const std::string API_MASTERY_SCORE = "/champion-mastery/v4/scores/by-summoner/";
	const std::string BY_CHAMPION = "/by-champion/";
	const std::string CHAMPION_ROTATION = "/platform/v3/champion-rotations";
	const std::string CLASH_SUMMONER = "/clash/v1/players/by-summoner/";
	const std::string CLASH_TEAM = "/clash/v1/teams/";
	const std::string CLASH_TOURNAMENT_LIST = "/clash/v1/tournaments";
	const std::string CLASH_TOURNAMENT = "/clash/v1/tournaments/by-team/";
	const std::string SERVER_UPTIME = "/status/v3/shard-data";
	const std::string DDRAGON_CHAMPION_REQUEST = "http://ddragon.leagueoflegends.com/cdn/10.12.1/data/en_US/";
}
//CLASS DECLERATION
class APIHandler {
private:
	std::string region = "";
	std::string callAPI(std::string url);
	static std::size_t WriteCallback(const char* in, std::size_t size, std::size_t num, std::string* out);

public:
	APIHandler(const std::string& initRegion = "na1") : region(initRegion) {};
	//SUMMONER-V4
	Summoner getSummoner(const std::string& summonerID);
	//CHAMPION-MASTERY-V4
	void getChampionMastery(const std::string& encryptedSummonerID);
	void getMasteryScore(const std::string& encryptedSummonerID);
	void getChampionMasteryByChampion(const std::string& encryptedSummonerID, const long& championID);
	//CHAMPION-V3
	void getChampionRotation();
	//CLASH-V1
	void getClashBySummoner(const std::string& encryptedSummonerID);
	void getClashByTeam(const std::string& teamID);
	void getTournamentByTeam(const std::string& teamID);
	void getTournamentList();
	//LOL-STATUS-V3
	std::string getServerStatus();
	//DDRAGON-CHAMPION-JSON
	rapidjson::Document getChampions();
	Champion getChampionDetailed(const std::string& champion);
};


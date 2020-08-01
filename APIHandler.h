/**
 * @
 * @
 * @
 */

//PREPROCESSOR DIRECTIVES
#pragma once
#include <string>
#include <iomanip> //do we need?
#include <curl/curl.h>
#include "Champion.h"
#include "Summoner.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

//NAMESPACE
namespace API {
	const std::string API_BASE_NA = "https://na1.api.riotgames.com/lol";
	const std::string API_KEY = "?api_key=RGAPI-36620257-39d9-4a4a-8623-108883a2ed65";
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

//TYPEDEF
typedef rapidjson::Document JSON; 

//CLASS DECLERATION
class APIHandler {
private:
	std::string region = "";
	
	/**
     * @brief Core API handling function. This function deals with all requests to the API.
	 * @param url URL build off of the API namespace that's passed to Riot Games' API.
     * 
     */
	JSON callAPI(std::string url);
	static std::size_t WriteCallback(const char* in, std::size_t size, std::size_t num, std::string* out);
	void errorHandler(JSON& errorJSON);

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


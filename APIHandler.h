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
#include <nlohmann/json.hpp>

using JSON = nlohmann::json;

//NAMESPACE
namespace API {
	const std::string API_BASE_NA = "https://na1.api.riotgames.com/lol";
	const std::string API_KEY = "?api_key=RGAPI-edf47d94-fddc-4125-a81f-73de5aa3b85e";
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
	const std::string DDRAGON_CHAMPION_REQUEST = "http://ddragon.leagueoflegends.com/cdn/10.15.1/data/en_US/";
}

//TYPEDEF

//CLASS DECLERATION
class APIHandler {
private:
	std::string region = "";
	
	/**
     * @brief Core API handling function. This function deals with all requests to the API.
	 * @param url URL build off of the API namespace that's passed to Riot Games' API.
     * 
     */
	JSON callAPI(const std::string& url) const;
	static std::size_t WriteCallback(const char* in, std::size_t size, std::size_t num, std::string* out);
	void errorHandler(const JSON& errorJSON) const;

public:
	APIHandler(const std::string& initRegion = "na1") : region(initRegion) {};
	//SUMMONER-V4
	JSON getSummoner(const std::string& name) const;
	//CHAMPION-MASTERY-V4
	void getChampionMastery(const std::string& encryptedSummonerID) const;
	void getMasteryScore(const std::string& encryptedSummonerID) const;
	void getChampionMasteryByChampion(const std::string& encryptedSummonerID, const long& championID) const;
	//CHAMPION-V3
	void getChampionRotation() const;
	//CLASH-V1
	void getClashBySummoner(const std::string& encryptedSummonerID) const;
	void getClashByTeam(const std::string& teamID) const;
	void getTournamentByTeam(const std::string& teamID) const;
	void getTournamentList() const;
	//LOL-STATUS-V3
	void getServerStatus() const;
	//DDRAGON-CHAMPION-JSON
	JSON getChampions() const;
};


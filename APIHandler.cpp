/**
 * @
 * @
 * @
 */
//PREPROCESSOR DIRECTIVES
#include "APIHandler.h"
#include "Champion.h"
#include <iostream>

using namespace API;
using namespace rapidjson;



//CLASS DEFINITION
std::size_t APIHandler::WriteCallback(const char* in, std::size_t size, std::size_t num, std::string* out) {
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}
JSON* APIHandler::callAPI(std::string url) const {
    CURL* curl;
    CURLcode res;
    std::string readBuffer = "";
    JSON* toReturn = new JSON();
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&readBuffer);
        res = curl_easy_perform(curl);           
        curl_easy_cleanup(curl);
    }
    //std::cout << response_code << std::endl; //test cout for error codes //deprecated :(
	toReturn->Parse(readBuffer.c_str());
    if (toReturn->HasParseError())
        throw std::logic_error("Error parsing JSON!");
    if (toReturn->HasMember("status"))
        errorHandler(*toReturn);
	return toReturn;
}

void APIHandler::errorHandler(const JSON& errorJSON) const {
    throw std::runtime_error(errorJSON["status"]["message"].GetString() + static_cast<std::string>(", Error code ") + std::to_string(errorJSON["status"]["status_code"].GetInt()));
}

JSON* APIHandler::getSummoner(const std::string& name) const {
    std::string url_result = API_BASE_NA + API_SUMMONER_NAME + name + API_KEY;
    JSON* POE = callAPI(url_result);
    return POE;
}

void APIHandler::getChampionMastery(const std::string& encryptedSummonerID) const {
    std::string url_result = API_BASE_NA + API_MASTERY_SUMMONER + encryptedSummonerID + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getChampionMasteryByChampion(const std::string& encryptedSummonerID, const long& championID) const {
    std::string url_result = API_BASE_NA + API_MASTERY_SUMMONER + encryptedSummonerID + BY_CHAMPION + std::to_string(championID) + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getMasteryScore(const std::string& encryptedSummonerID) const {
    std::string url_result = API_BASE_NA + API_MASTERY_SCORE + encryptedSummonerID + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getChampionRotation() const {
    std::string url_result = API_BASE_NA + CHAMPION_ROTATION + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getClashBySummoner(const std::string& encryptedSummonerID) const {
    std::string url_result = API_BASE_NA + CLASH_SUMMONER + encryptedSummonerID + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getClashByTeam(const std::string& teamID) const {
    std::string url_result = API_BASE_NA + CLASH_TEAM + teamID + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getTournamentByTeam(const std::string& teamID) const {
    std::string url_result = API_BASE_NA + CLASH_TOURNAMENT + teamID + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getTournamentList() const {
    std::string url_result = API_BASE_NA + CLASH_TOURNAMENT_LIST + API_KEY;
    JSON* POE = callAPI(url_result);
}
void APIHandler::getServerStatus() const {
    std::string url_result = API_BASE_NA + SERVER_UPTIME + API_KEY;
    JSON* POE = callAPI(url_result);
}
JSON* APIHandler::getChampions() const {
    std::string url_result = DDRAGON_CHAMPION_REQUEST + "champion.json";
    JSON* POE = callAPI(url_result);
	return POE;
}
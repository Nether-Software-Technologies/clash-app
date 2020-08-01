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
JSON APIHandler::callAPI(std::string url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer = "";
    JSON toReturn;
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
	toReturn.Parse(readBuffer.c_str());
    if (toReturn.IsObject() || (toReturn.HasParseError())) {
        if (toReturn.HasMember("status")) 
            errorHandler(toReturn);
        else if (toReturn.HasParseError())
            throw std::logic_error("Error parsing JSON!");      
	}
	return toReturn;
}

std::string stringify(JSON& json) {
	StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);
	json.Accept(writer);
	return buffer.GetString();
}

void APIHandler::errorHandler(JSON& errorJSON) {
    throw std::runtime_error(errorJSON["status"]["message"].GetString() + static_cast<std::string>(", Error code ") + std::to_string(errorJSON["status"]["status_code"].GetInt()));
}

Summoner APIHandler::getSummoner(const std::string& summoner) {
	std::string url_result = API_BASE_NA + API_SUMMONER_NAME + summoner + API_KEY;
    JSON notJSON = callAPI(url_result);
    if (!notJSON.HasMember(summoner.c_str())) {
        throw std::invalid_argument("Summoner doesn't exist!");
    }
    return Summoner();
}
void APIHandler::getChampionMastery(const std::string& encryptedSummonerID) {
    std::string url_result = API_BASE_NA + API_MASTERY_SUMMONER + encryptedSummonerID + API_KEY;
    JSON notJSON = callAPI(url_result);
}
void APIHandler::getChampionMasteryByChampion(const std::string& encryptedSummonerID, const long& championID) {
    std::string url_result = API_BASE_NA + API_MASTERY_SUMMONER + encryptedSummonerID + BY_CHAMPION + std::to_string(championID) + API_KEY;
    JSON notJSON = callAPI(url_result);
}
void APIHandler::getMasteryScore(const std::string& encryptedSummonerID) {
    std::string url_result = API_BASE_NA + API_MASTERY_SCORE + encryptedSummonerID + API_KEY;
    JSON notJSON = callAPI(url_result);
}
void APIHandler::getChampionRotation() {
    std::string url_result = API_BASE_NA + CHAMPION_ROTATION + API_KEY;
    JSON notJSON = callAPI(url_result);
}
void APIHandler::getClashBySummoner(const std::string& encryptedSummonerID) {
    std::string url_result = API_BASE_NA + CLASH_SUMMONER + encryptedSummonerID + API_KEY;
    JSON notJSON = callAPI(url_result);
}
void APIHandler::getClashByTeam(const std::string& teamID) {
    std::string url_result = API_BASE_NA + CLASH_TEAM + teamID + API_KEY;
    JSON notJSON = callAPI(url_result);
}
void APIHandler::getTournamentByTeam(const std::string& teamID) {
    std::string url_result = API_BASE_NA + CLASH_TOURNAMENT + teamID + API_KEY;
    JSON notJSON = callAPI(url_result);
}
void APIHandler::getTournamentList() {
    std::string url_result = API_BASE_NA + CLASH_TOURNAMENT_LIST + API_KEY;
    JSON notJSON = callAPI(url_result);
}
std::string APIHandler::getServerStatus() {
    std::string url_result = API_BASE_NA + SERVER_UPTIME + API_KEY;
    JSON notJSON = callAPI(url_result);
    return stringify(notJSON);
}
JSON APIHandler::getChampions() {
    std::string url_result = DDRAGON_CHAMPION_REQUEST + "champion.json";
    JSON notJSON = callAPI(url_result);
    if (notJSON.HasParseError()) {
        throw std::logic_error("Error parsing notJSON!");
    }
    return notJSON;
}
Champion APIHandler::getChampionDetailed(const std::string& championName) {
    JSON notJSON = getChampions();
    Champion champ(championName);
    return champ.pullChampionData(notJSON);
}

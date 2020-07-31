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
std::string APIHandler::callAPI(std::string url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer = "";
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    //std::cout << res << std::endl; //test cout for error codes
    return readBuffer;
}
Summoner APIHandler::getSummoner(const std::string& summoner) {
	std::string url_result = API_BASE_NA + API_SUMMONER_NAME + summoner + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
    return Summoner();
}
void APIHandler::getChampionMastery(const std::string& encryptedSummonerID) {
    std::string url_result = API_BASE_NA + API_MASTERY_SUMMONER + encryptedSummonerID + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
void APIHandler::getChampionMasteryByChampion(const std::string& encryptedSummonerID, const long& championID) {
    std::string url_result = API_BASE_NA + API_MASTERY_SUMMONER + encryptedSummonerID + BY_CHAMPION + std::to_string(championID) + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
void APIHandler::getMasteryScore(const std::string& encryptedSummonerID) {
    std::string url_result = API_BASE_NA + API_MASTERY_SCORE + encryptedSummonerID + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
void APIHandler::getChampionRotation() {
    std::string url_result = API_BASE_NA + CHAMPION_ROTATION + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
void APIHandler::getClashBySummoner(const std::string& encryptedSummonerID) {
    std::string url_result = API_BASE_NA + CLASH_SUMMONER + encryptedSummonerID + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
void APIHandler::getClashByTeam(const std::string& teamID) {
    std::string url_result = API_BASE_NA + CLASH_TEAM + teamID + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
void APIHandler::getTournamentByTeam(const std::string& teamID) {
    std::string url_result = API_BASE_NA + CLASH_TOURNAMENT + teamID + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
void APIHandler::getTournamentList() {
    std::string url_result = API_BASE_NA + CLASH_TOURNAMENT_LIST + API_KEY;
    std::string json = callAPI(url_result);
    std::cout << json << std::endl;
}
std::string APIHandler::getServerStatus() {
    std::string url_result = API_BASE_NA + SERVER_UPTIME + API_KEY;
    std::string json = callAPI(url_result);
    return json;
}
Document APIHandler::getChampions() {
    std::string url_result = DDRAGON_CHAMPION_REQUEST + "champion.json";
    std::string jString = callAPI(url_result);
    Document toJSON;
    toJSON.Parse(jString.c_str());
    if (toJSON.HasParseError()) {
        throw std::logic_error("Error parsing JSON!");
    }
    return toJSON;
}
Champion APIHandler::getChampionDetailed(const std::string& champion) {
    Document JSON = getChampions();
    if (!JSON["data"].HasMember(champion.c_str())) {
        throw std::invalid_argument("Champion doesn't exist!");
    };
    const Value& tags = JSON["data"][champion.c_str()]["tags"];
    std::vector<std::string> cTags;
    for (SizeType i = 0; i < tags.Size(); i++) {
        cTags.push_back(tags[i].GetString());
    }
    //JSONs are nested
    std::string cBlurb = JSON["data"][champion.c_str()]["blurb"].GetString();
    std::string cName = JSON["data"][champion.c_str()]["name"].GetString();
    std::string cTitle = JSON["data"][champion.c_str()]["title"].GetString();
    int cDifficulty = JSON["data"][champion.c_str()]["info"]["difficulty"].GetInt();
    long cID = std::stol(JSON["data"][champion.c_str()]["key"].GetString());
    Champion champ(cID, cName, cTags, cTitle, cBlurb, cDifficulty);
    return champ;
}

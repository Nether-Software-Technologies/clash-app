/**
 * @
 * @
 * @
 */
#include "Summoner.h"
Summoner::Summoner(const std::string name){
    JSON* POE = API_LINK.getSummoner(name);
    this->pullSummonerData(*POE);
}

std::ostream& operator<<(std::ostream& os, const Summoner& smner) {
    os << smner.name << " " << smner.summonerLevel << std::endl;
    os << "Encrypted Summoner ID: " << smner.ID << std::endl;
    os << "Encrypted Account ID: " << smner.accountID << std::endl;
    os << "Player Unique User ID: " << smner.puuid << std::endl;
    return os;
}
std::string Summoner::getEncryptedSummonerID() {
    return ID;
}
std::string Summoner::getEncryptedAccountID() {
    return accountID;
}
std::string Summoner::getPuuid() {
    return puuid;
}
std::string Summoner::getName() {
    return name;
}
int Summoner::getProfileIconID() {
    return profileIconID;
}
long Summoner::getRevisionDate() {
    return revisionDate;
}
long Summoner::getSummonerLevel() {
    return summonerLevel;
}

Summoner& Summoner::pullSummonerData(const JSON& json) {
    name = json["name"].GetString();
    ID = json["id"].GetString();
    accountID = json["accountId"].GetString();
    profileIconID = json["profileIconId"].GetInt();
    puuid = json["puuid"].GetString();
    revisionDate = static_cast<long>(json["revisionDate"].GetInt64());
    summonerLevel = json["summonerLevel"].GetInt();
    return *this;
}
/**
 * @
 * @
 * @
 */
#include "Summoner.h"

Summoner::Summoner() {

}

Summoner::Summoner(const std::string& name){
    JSON POE = API_LINK.getSummoner(name);
    this->pullSummonerData(POE);
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
    name = json["name"].get<std::string>();
    ID = json["id"].get<std::string>();
    accountID = json["accountId"].get<std::string>();
    profileIconID = json["profileIconId"].get<int>();
    puuid = json["puuid"].get<std::string>();
    revisionDate = static_cast<long>(json["revisionDate"].get<int>());
    summonerLevel = json["summonerLevel"].get<int>();
    return *this;
}
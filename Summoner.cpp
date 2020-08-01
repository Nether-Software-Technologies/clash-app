/**
 * @
 * @
 * @
 */
#include "Summoner.h"
Summoner::Summoner() {
    ID = "_Ify1e4i75PjTrNTY_7MzuW25RgcSLweXYF6Vj4ZCBz9NUc";
    accountID = "0Esh1QsHwIJpYov6cZLO1KkCEoMQggSwpOK5eyhVMih7vvU";
    puuid = "Wr3-CKCas-_kOffXfBrRGR79AIsdmIKIHqiBAY-M_PSk2gI5EqMMCQY2xubOuMqW5LeO1tq6APOOcw";
    name = "DrWegener"; //andyW
    profileIconID = 4068;
    revisionDate = 1587944261;
    summonerLevel = 116;
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
    std::string sumName = name;
    const char* nameCStr = name.c_str();
    ID = json["id"].GetString();
    accountID = json["accountId"].GetString();
    profileIconID = json["profileIconId"].GetInt();
    puuid = json["puuid"].GetString();
    revisionDate = static_cast<long>(json["revisionDate"].GetInt64());
    summonerLevel = json["summonerLevel"].GetInt();
    return *this;
}
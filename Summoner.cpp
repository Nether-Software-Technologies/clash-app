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
    return this->ID;
}
std::string Summoner::getEncryptedAccountID() {
    return this->accountID;
}
std::string Summoner::getPuuid() {
    return this->puuid;
}
std::string Summoner::getName() {
    return this->name;
}
int Summoner::getProfileIconID() {
    return this->profileIconID;
}
long Summoner::getRevisionDate() {
    return this->revisionDate;
}
long Summoner::getSummonerLevel() {
    return this->summonerLevel;
}
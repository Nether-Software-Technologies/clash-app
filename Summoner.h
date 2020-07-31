/**
 * @
 * @
 * @
 */
#pragma once
#include <string>
#include <iostream>
#include <ctime>

class Summoner {
private:
    std::string accountID;
    int profileIconID;
    long revisionDate;
    std::string name;
    std::string ID;
    std::string puuid;
    long summonerLevel;
public:
    Summoner();
    Summoner(std::string initAccount, int initProfileIconID, long initRevisionDate, std::string initName,
    std::string initID, std::string initPuuid, long initSummonerLevel) : accountID(initAccount), profileIconID(initProfileIconID),
    revisionDate(initRevisionDate), name(initName), ID(initID), puuid(initPuuid), summonerLevel(initSummonerLevel) {};
    std::string getEncryptedSummonerID();
    std::string getEncryptedAccountID();
    std::string getPuuid();
    std::string getName();
    int getProfileIconID();
    long getRevisionDate();
    long getSummonerLevel();
    friend std::ostream& operator<<(std::ostream& os, const Summoner& smner);
};
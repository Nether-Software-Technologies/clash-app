/**
 * @
 * @
 * @
 */
#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <rapidjson/document.h>

using namespace rapidjson;

typedef rapidjson::Document JSON;

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

    /**
     * @brief Default constructor. Creates a %Summoner().
     * 
     */
    Summoner();

    /**
     * @brief Constructor with all variables initalized. Called from callAPI().
     * @param accountID Encrypted account ID has a max length of 56 characters.
     * @param profileIconID ID of the summoner icon associated with the summoner.
     * @param revisionDate Date summoner was last modified specified as epoch milliseconds.
     * @param name %Summoner name.
     * @param ID Encrypted summoner ID. Max length 63 characters.
     * @param puuid Encrypted PUUID. Exact length of 78 characters.
     * @param summonerLevel %Summoner level associated with the summoner.
     * 
     */
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
    Summoner& pullSummonerData(const JSON& json);
    friend std::ostream& operator<<(std::ostream& os, const Summoner& smner);
};
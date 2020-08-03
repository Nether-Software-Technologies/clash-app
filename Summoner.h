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
#include "APIHandler.h"

using namespace rapidjson;

typedef rapidjson::Document JSON;
extern const APIHandler API_LINK;

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
    Summoner(const std::string& name);
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
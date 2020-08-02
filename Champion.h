/**
 * @
 * @
 * @
 */
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/filewritestream.h>
#include "APIHandler.h"

typedef rapidjson::Document JSON;
extern const APIHandler API_LINK;

class Champion {
private:
    long champID;
    std::string champName;
    std::vector<std::string> champTags; //stuff like tank, fighter (bruiser), assassin, etc.
    std::string champTitle;
    std::string champBlurb; 
    int champDifficulty;

public:

    /**
     * @brief Default constructor. Creates a Champion() object of Nasus. PogChamp.
     */
    Champion();

    /**
     * @brief Assignment operator.
     * @param Other champion to be assigned to "this" champion.
     */
    Champion& operator=(const Champion& other);

    /**
     * @brief Constructor with champNumber defined.
     * @param Champion key, given by API.
     * @throw Throws an invalid_argument exception when champion is not found. Caught by error handler.
     */
    Champion(const long& ID);

    /**
     * @brief Constructor with champName defined.
     * @param Champion name.
     * @throw Throws an invalid_argument exception when champion is not found. Caught by error handler.
     */
    Champion(const std::string& champName);

    /**
     * @brief Finds the champion's name given the key.
     * @param Champion key.
     * @throw Throws a logic_error in the case that the champion name is not found (does not exist).
     * @return Returns champion name if found.
     */
    std::string findChampName(const int& champNum) const;

    /**
     * @brief Retrieves the champion key.
     */
    long getChampNumber() const;

    /**
     * @brief Retrieves the champion name.
     */ 
    std::string getChampName() const;

    /**
     * @brief Retrieves the champion blurb.
     */
    std::string getChampBlurb() const;

    /**
     * @brief Retrieves the champion tags.
     */
    std::vector<std::string> getChampTags() const;

    /**
     * @brief Retrieves the champion difficulty. aaaa
     */
    int getChampDifficulty() const;

    /**
     * @brief A pretty print of the champion.
     * @param The ostream and the champion to print. ostream is provided by operator <<. 
     */
    friend std::ostream& operator<<(std::ostream& os, const Champion& champ);

    Champion& pullChampionData(const char* json);

};

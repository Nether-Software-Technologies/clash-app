/**
 * @
 * @
 * @
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "APIHandler.h"
#include <algorithm>
#include <doctest/doctest.h>
//This file probably wont be used for anything other than testing until later xD

TEST_CASE("Champion Test") {
    Champion defaultC;
    CHECK(defaultC.getChampName() == "Nasus");
    CHECK(defaultC.getChampNumber() == 75);
    CHECK(defaultC.getChampBlurb() == "Nasus is an imposing, jackal-headed Ascended being from ancient Shurima, a heroic figure regarded as a demigod by the people of the desert. Fiercely intelligent, he was a guardian of knowledge and peerless strategist whose wisdom guided the ancient...");
    CHECK(defaultC.getChampDifficulty() == 6);
    std::vector<std::string> defaultTags;
    defaultTags.push_back("Fighter");
    defaultTags.push_back("Tank");
    bool tagCheck = std::equal(defaultTags.begin(), defaultTags.end(), defaultC.getChampTags().begin());
    CHECK(tagCheck == true);
}

TEST_CASE("APIGrab Champion Test") {
    APIHandler handler;
    
    Champion nasus = handler.getChampionDetailed("Nasus");
    
    //given by the JSON locally, the handler above pulls from API
    long nasusID = 75;
    int nasusDifficulty = 6;
    std::string nasusName = "Nasus";
    std::vector<std::string> nasusTags = { "Fighter", "Tank" };
    bool nasusTagTest = std::equal(nasusTags.begin(), nasusTags.end(), nasus.getChampTags().begin());
   
    CHECK(nasus.getChampName() == nasusName);
    CHECK(nasus.getChampNumber() == nasusID);
    CHECK(nasusTagTest == true);
    CHECK(nasus.getChampDifficulty() == nasusDifficulty);
    
    std::cout << "\n" << nasus << std::endl;
    
    Champion kled = handler.getChampionDetailed("Kled");
   
    //given by the JSON locally, the handler above pulls from API
    long kledID = 240;
    int kledDifficulty = 7;
    std::string kledName = "Kled";
    std::vector <std::string> kledTags = { "Fighter", "Tank" };
    bool kledTagTest = std::equal(kledTags.begin(), kledTags.end(), kled.getChampTags().begin());

    CHECK(kled.getChampName() == kledName);
    CHECK(kled.getChampNumber() == kledID);
    CHECK(kledTagTest == true);
    CHECK(kled.getChampDifficulty() == kledDifficulty);

    std::cout << kled << std::endl;
    
}
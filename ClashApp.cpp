/**
 * @
 * @
 * @
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define TEST 1
#include "APIHandler.h"
#include <algorithm>
#include <doctest/doctest.h>
//This file probably wont be used for anything other than testing until later xD
#ifdef TEST
TEST_CASE("Champion Test") {
    Champion defaultC;
    CHECK(defaultC.getChampName() == "Nasus");
    CHECK(defaultC.getChampNumber() == 75);
    CHECK(defaultC.getChampBlurb() == "Nasus is an imposing, jackal-headed Ascended being from ancient Shurima, a heroic figure regarded as a demigod by the people of the desert. Fiercely intelligent, he was a guardian of knowledge and peerless strategist whose wisdom guided the ancient...");
    CHECK(defaultC.getChampDifficulty() == 6);
	std::vector<std::string> defaultTags = {"Fighter", "Tank"};
	bool tagCheck = std::equal(defaultTags.begin(), defaultTags.end(), defaultC.getChampTags().begin());
	CHECK(tagCheck == true);
}

TEST_CASE("APIGrab Champion Test") {
    APIHandler handler;
    
    std::cout << "\n-------------NASUS CHECK-------------\n";

    Champion nasus = handler.getChampionDetailed("Nasus");
    
    //given by the JSON locally, the handler above pulls from API
    long nasusID = 75;
    int nasusDifficulty = 6;
    std::string nasusName = "Nasus";
    std::vector<std::string> nasusTags = { "Fighter", "Tank" };
    bool nasusTagTest = std::equal(nasusTags.begin(), nasusTags.end(), nasus.getChampTags().begin());
   
    CHECK(nasus.getChampName() == nasusName);
    CHECK(nasus.getChampNumber() == nasusID);
    CHECK(nasusTagTest);
    CHECK(nasus.getChampDifficulty() == nasusDifficulty);
    
    std::cout << "\n" << nasus << std::endl;
    
    std::cout << "\n-------------KLED CHECK-------------\n\n";
    
    Champion kled = handler.getChampionDetailed("Kled");
   
    //given by the JSON locally, the handler above pulls from API
    long kledID = 240;
    int kledDifficulty = 7;
    std::string kledName = "Kled";
    std::vector <std::string> kledTags = { "Fighter", "Tank" };
    bool kledTagTest = std::equal(kledTags.begin(), kledTags.end(), kled.getChampTags().begin());

    CHECK(kled.getChampName() == kledName);
    CHECK(kled.getChampNumber() == kledID);
    CHECK(kledTagTest);
    CHECK(kled.getChampDifficulty() == kledDifficulty);

    std::cout << kled << std::endl;

    std::cout << "\n-------------NON-EXISTING CHAMPION CHECK-------------\n\n";
    
    try {
        Champion notExist = handler.getChampionDetailed("Nocturne but with the really cool ghost skin");
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << "\n";
        CHECK(true);
    }
}

TEST_CASE("APIHandler errorHandler test") {
    
    std::cout << "\n-------------RATE LIMIT ERROR HANDLER CHECK-------------\n\n";
    
    while (true) {
		APIHandler handler;
        try {
            handler.getChampionRotation();
        } 
        catch(std::runtime_error& e) {
            std::cout << e.what() << "\n";
            CHECK(true);
            break;
		}
	}
}

TEST_CASE("Stringify test") {

    std::cout << "\n-------------STRINGIFY TEST-------------\n\n";

    APIHandler handler;
    
    CHECK(handler.getServerStatus() != "");

    std::cout << handler.getServerStatus();
}

TEST_CASE("Summoner test") {

    std::cout << "\n-------------SUMMONER TEST-------------\n\n";

    APIHandler handler;

    Summoner andy = handler.getSummoner("DrWegener");
    std::cout << "\n" << andy;

    CHECK(andy.getPuuid() == "Wr3-CKCas-_kOffXfBrRGR79AIsdmIKIHqiBAY-M_PSk2gI5EqMMCQY2xubOuMqW5LeO1tq6APOOcw");

    Summoner nether = handler.getSummoner("Netherless");
    std::cout << "\n" << nether;

    CHECK(nether.getPuuid() == "CchgrH5jgI8onfn4MgYyqd3G8mdzuxvW8BG_4KuEZxi3Y3huevAHW_5GA7FMOTfAsUJuA5asXYOtEw");

}
#endif
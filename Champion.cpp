/**
 * @
 * @
 * @
 */

#include "Champion.h"
using namespace rapidjson;

extern const JSON* CHAMPION_DATA = API_LINK.getChampions();

//"very basic lets add nasus pogchamp" -ep
Champion::Champion() { 
    // andyW
}

Champion::Champion(const long& ID) {
   champID = ID; //for testing
   champName = "Nasus";
   champTitle = "the Curator of the Sands";
   champBlurb = "Nasus is an imposing, jackal-headed Ascended being from ancient Shurima, a heroic figure regarded as a demigod by the people of the desert. Fiercely intelligent, he was a guardian of knowledge and peerless strategist whose wisdom guided the ancient...";
   champTags.push_back("Fighter");
   champTags.push_back("Tank");
}

Champion::Champion(const std::string& name) {
    pullChampionData(name.c_str());
}

std::ostream& operator<<(std::ostream& os, const Champion& champ) {
    os << champ.champID << std::endl << champ.champName << ", " << champ.champTitle << ".\n" << champ.champBlurb << "\n";
    return os;
}

Champion& Champion::operator=(const Champion& other) {
    if (this != &other) {
        this->champTags = other.champTags;
        this->champBlurb = other.champBlurb;
        this->champID = other.champID;
        this->champDifficulty = other.champDifficulty;
        this->champTitle = other.champTitle;
        this->champName = other.champName;
    }
    return *this;
}

std::string Champion::getChampName() const {
    return champName;
}

long Champion::getChampNumber() const {
    return champID;
}

std::vector<std::string> Champion::getChampTags() const {
    return champTags;
}

int Champion::getChampDifficulty() const {
    return champDifficulty;
}

std::string stringify(const JSON& json) {
	StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);
	json.Accept(writer);
	return buffer.GetString();
}

Champion& Champion::pullChampionData(const char* initName) {
	if (!(*CHAMPION_DATA)["data"].HasMember(initName)) {
        throw std::invalid_argument("Champion \"" + static_cast<std::string>(initName) + "\" doesn't exist!");
    }
    const Value& tags = (*CHAMPION_DATA)["data"][initName]["tags"];
    std::vector<std::string> cTags;
    for (SizeType i = 0; i < tags.Size(); i++) {
        cTags.push_back(tags[i].GetString());
    }
    champTags = cTags;
    champBlurb = (*CHAMPION_DATA)["data"][initName]["blurb"].GetString();
    champName = (*CHAMPION_DATA)["data"][initName]["name"].GetString();
    champTitle = (*CHAMPION_DATA)["data"][initName]["title"].GetString();
    champDifficulty = (*CHAMPION_DATA)["data"][initName]["info"]["difficulty"].GetInt();
    champID = std::stol((*CHAMPION_DATA)["data"][initName]["key"].GetString());
    return *this;
}

std::string Champion::getChampBlurb() const {
    return champBlurb;
}



from internal import APIHandler as API

class Summoner:
  #Initalizer - given a string, name != ""
  def __init__(self, name = None,  ID = None, accountID = None, profileIconID = None, PUUID = None, revisionDate = None, level = None):
    self._summonerName = name
    self._summonerID = ID
    self._summonerAccountID = accountID
    self._summonerProfileIconID = profileIconID
    self._summonerPUUID = PUUID
    self._summonerRevisionDate = revisionDate
    self._summonerLevel = level
  
  #General

  @classmethod
  def fromName(cls, name):
    #initalize JSON here, gets created when function ran, deleted when function leaves; API covers failed attempt
    JSON = API.getSummoner(name)
    sName = JSON["name"]
    sID = JSON["id"]
    sAccountID = JSON["accountId"]
    sPUUID = JSON["puuid"]
    sRevisionDate = JSON["revisionDate"]
    sLevel = JSON["summonerLevel"]
    return cls(sName, sID, sAccountID, 69, sPUUID, sRevisionDate, sLevel)
  
  #Getters
  def getSummonerName(self):
    return self._summonerName

  def getSummonerID(self):
    return self._summonerID
  
  def getSummonerAccountID(self):
    return self._summonerAccountID

  def getSummonerPUUID(self):
    return self._summonerPUUID

  def getSummonerRevisionDate(self):
    return self._summonerRevisionDate

  def getSummonerLevel(self):
    return self._summonerLevel

  #Overloads
  def __str__(self):
    return (self._summonerName + ", level " + str(self._summonerLevel) + "\n" + "Encrypted Summoner ID: " 
            + self._summonerID + "\n" + "Encrypted Account ID: " + self._summonerAccountID + "\n"
            + "Player Unique User ID: " + self._summonerPUUID + "\n")
            
    



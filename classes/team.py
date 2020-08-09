from internal import APIHandler as API
from classes.summoner import Summoner

class PlayerData:
  pass

class Team:
  def __init__(self, teamId = 0, tournamentId = 0, name = "", iconId = 0, tier = 0, captain = Summoner(), abbreviation = "", indivData = {}):
    if not teamId:
      print("Enter summoner name.")
      summonerName = input()
      summ = Summoner(summonerName)
      self._getTeamData(summ.getSummonerID())
    else:
      self._teamId = teamId
      self._tournamentId = tournamentId
      self._name = name
      self._iconId = iconId
      self._tier = tier
      self._captain = captain
      self._abbreviation = abbreviation
      self._memberData = [indivData]

  def _getTeamData(self, ID):
    #initalize JSON here, gets created when function ran, deleted when function leaves; API covers failed attempt
    try:
      JSON = API.getClashBySummoner(ID)[0]
    except KeyError:
      print("Summoner not found!")
      return
    tId = JSON["teamId"]
    self._teamId = tId
    JSON = API.getClashByTeam(tId)
    self._tournamentId = JSON["tournamentId"]
    self._name = JSON["name"]
    self._iconId = JSON["iconId"]
    self._tier = JSON["tier"]
    self._captain = Summoner(API.getSummonerNameById(JSON["captain"]))
    self._abbreviation = JSON["abbreviation"]
    self._memberData = JSON["players"]

  #Getters
  def getTeamId(self):
    return self._teamId

  def getTournamentId(self):
    return self._tournamentId

  def getName(self):
    return self._name

  def getIconId(self):
    return self._iconId

  def getTier(self):
    return self._tier

  def getCaptain(self):
    return self._captain    
 
  def getAbbreviation(self):
    return self._abbreviation

  def getPlayerData(self):
    return self._memberData

  #Overloads
  def __str__(self):
    return ("teamId: " + str(self._teamId) + "\ntournamentId: " + str(self._tournamentId)
            + "\nName: " + self._name + "\niconId: " + str(self._iconId)
            + "\nTier: " + str(self._tier) + "\nCaptain: " + self._captain.getSummonerName()
            + "\nAbbreviation: " + self._abbreviation)

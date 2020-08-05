import urllib.request
from urllib.error import HTTPError
import json

#these are all constants besides API_KEY, DO NOT CHANGE
API_BASE_NA = "https://na1.api.riotgames.com/lol"
API_KEY = "" #REDACTED
API_SUMMONER_NAME = "/summoner/v4/summoners/by-name/"
API_MASTERY_SUMMONER = "/champion-mastery/v4/champion-masteries/by-summoner/"
API_MASTERY_SCORE = "/champion-mastery/v4/scores/by-summoner/"
BY_CHAMPION = "/by-champion/"
CHAMPION_ROTATION = "/platform/v3/champion-rotations"
CLASH_SUMMONER = "/clash/v1/players/by-summoner/"
CLASH_TEAM = "/clash/v1/teams/"
CLASH_TOURNAMENT_LIST = "/clash/v1/tournaments"
CLASH_TOURNAMENT = "/clash/v1/tournaments/by-team/"
SERVER_UPTIME = "/status/v3/shard-data"
DDRAGON_CHAMPION_REQUEST = "http://ddragon.leagueoflegends.com/cdn/10.15.1/data/en_US/"

def callAPI(URL):
  req = urllib.request.urlopen(URL) #throws exception if HTTPError happens, catch it pls
  byte = req.read()
  jsonStr = byte.decode("utf-8")
  JSON = json.loads(jsonStr)
  return JSON

def getSummoner(name):
  url_concat = API_BASE_NA + API_SUMMONER_NAME + name + API_KEY
  POE = callAPI(url_concat)
  return POE

def getChampionMastery(encrySummonerID):
  url_concat = API_BASE_NA + API_MASTERY_SUMMONER + encrySummonerID + API_KEY
  POE = callAPI(url_concat)
  return POE

def getMasteryScore(encrySummonerID):
  url_concat = API_BASE_NA + API_MASTERY_SCORE + encrySummonerID + API_KEY
  POE = callAPI(url_concat)
  return POE

def getChampionRotation():
  url_concat = API_BASE_NA + CHAMPION_ROTATION + API_KEY
  POE = callAPI(url_concat)
  return POE

def getClashBySummoner(encrySummonerID):
  url_concat = API_BASE_NA + CLASH_SUMMONER + encryptedSummonerID + API_KEY
  POE = callAPI(url_concat)
  return POE

def getClashByTeam(teamID):
  url_concat = API_BASE_NA + CLASH_TEAM + teamID + API_KEY
  POE = callAPI(url_concat)
  return POE

def getTourneyByTeam(teamID):
  url_concat = API_BASE_NA + CLASH_TOURNAMENT + teamID + API_KEY
  POE = callAPI(url_concat)
  return POE

def getTourneyList():
  url_concat = API_BASE_NA + CLASH_TOURNAMENT_LIST + API_KEY
  POE = callAPI(url_concat)
  return POE

def getServerStatus():
  url_concat = API_BASE_NA + SERVER_UPTIME + API_KEY
  POE = callAPI(url_concat)
  return POE

def getChampions(): 
  url_concat = DDRAGON_CHAMPION_REQUEST + "champion.json"
  POE = callAPI(url_concat)
  return POE


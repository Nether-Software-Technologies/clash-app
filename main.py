from classes.champion import Champion
from classes.summoner import Summoner
from classes.team import Team
from internal import APIHandler as API
from urllib.error import HTTPError
from PySide2.QtWidgets import QApplication, QLabel, QWidget
from PySide2.QtCore import QRect
import unittest
import sys

spam = Champion('Fiora')

def spamTest():
  API.getChampionRotation()

class Test(unittest.TestCase):
  def testChampion(self):
    print('\n# NASUS CHECK')
    nasus = Champion.fromName('Nasus')
    self.assertEqual(nasus.getChampID(), 75)
    self.assertEqual(nasus.getChampTags(), ['Fighter', 'Tank'])
    self.assertEqual(nasus.getChampDifficulty(), 6)
    self.assertEqual(nasus.getChampName(), 'Nasus')
    print(nasus)

    print('\n# KLED CHECK')
    kled = Champion.fromName('Kled')
    self.assertEqual(kled.getChampID(), 240)
    self.assertEqual(kled.getChampTags(), ['Fighter', 'Tank'])
    self.assertEqual(kled.getChampDifficulty(), 7)
    self.assertEqual(kled.getChampName(), 'Kled')
    print(kled)

    print('\n# NON-EXISTING CHAMPION CHECK')
    try:
       notExist = Champion.fromName('Nocturne but with the really cool ghost skin')
    except KeyError:
       self.assertTrue(True)

  #def testErrorHandler(self):
    #print('\n\n# RATE LIMIT ERROR HANDLER CHECK')
    #while (True):
      #try:
        #spam.spamTest()
      #except HTTPError as e:
        #print(e)
        #self.assertTrue(True)
        #break

  def testSummoner(self):
    print('\n\n# SUMMONER CHECK')
    andy = Summoner.fromName('DrWegener')
    print(andy)
    #self.assertEqual(andy.getSummonerName(), 'DrWegener') 
    #self.assertEqual(andy.getSummonerAccountID(), '0Esh1QsHwIJpYov6cZLO1KkCEoMQggSwpOK5eyhVMih7vvU')
    #self.assertEqual(andy.getSummonerLevel(), 116)
    #self.assertEqual(andy.getSummonerPUUID(), 'Wr3-CKCas-_kOffXfBrRGR79AIsdmIKIHqiBAY-M_PSk2gI5EqMMCQY2xubOuMqW5LeO1tq6APOOcw')

  #def testTeam(self):
    #print('\n\n# TEAM CHECK')
    #teamTest = Team.fromName('trex2764')  
    #print(teamTest)
    #self.assertEqual(teamTest.getCaptain().getSummonerName(), 'trex2764')
    #self.assertEqual(teamTest.getAbbreviation(), 'HKC')
    #self.assertEqual(teamTest.getName(), 'Hong Kong Cleaver')
    #self.assertEqual(teamTest.getTier(), 4)
    #self.assertEqual(teamTest.getIconId(), 23)
    #self.assertEqual(teamTest.getTournamentId(), 2461)
    #teamPlayers = teamTest.getPlayerData()
    #print(*teamPlayers)
    #for x in range(len(teamPlayers)):
      #print("Summoners in team: " + API.getSummonerNameById(teamPlayers[x].get("summonerId")) + 
            #", position: " + teamPlayers[x].get("position"))
    
  def testTournament(self):
    print('\n\n# TOURNAMENT NAME CHECK')
    print('Tournament: ' + API.getTournamentName().upper() + ' CUP')
    self.assertEqual(API.getTournamentName(), 'ionia')

    
if __name__ == '__main__':
    unittest.main()
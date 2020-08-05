from classes.champion import Champion
from classes.summoner import Summoner
from urllib.error import HTTPError
import unittest

spam = Champion("Fiora")

def spamTest():
  API.getChampionRotation()

class Test(unittest.TestCase):
  def testChampion(self):
    print('\n# NASUS CHECK')
    nasus = Champion("Nasus")
    self.assertEqual(nasus.getChampID(), 75)
    self.assertEqual(nasus.getChampTags(), ["Fighter", "Tank"])
    self.assertEqual(nasus.getChampDifficulty(), 6)
    self.assertEqual(nasus.getChampName(), "Nasus")

    print('\n# KLED CHECK')
    kled = Champion("Kled")
    self.assertEqual(kled.getChampID(), 240)
    self.assertEqual(kled.getChampTags(), ["Fighter", "Tank"])
    self.assertEqual(kled.getChampDifficulty(), 7)
    self.assertEqual(kled.getChampName(), "Kled")

    print('\n# NON-EXISTING CHAMPION CHECK')
    try:
       notExist = Champion("Nocturne but with the really cool ghost skin")
    except KeyError:
       self.assertTrue(True)

  def testErrorHandler(self):
    print('\n\n# RATE LIMIT ERROR HANDLER CHECK')
    while (True):
      try:
        spam.spamTest()
      except HTTPError as e:
        print(e)
        self.assertTrue(True)
        break

  def testSummoner(self):
    print('\n\n# RATE LIMIT ERROR HANDLER CHECK')
    andy = Summoner("DrWegener")
    print(andy)
    self.assertEqual(andy.getSummonerName(), 'DrWegener') 
    
if __name__ == '__main__':
  unittest.main()
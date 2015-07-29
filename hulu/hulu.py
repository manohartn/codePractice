import urllib2
import json 
import random 
import time
import re
import operator

dictionary = open("dict.txt", "r")
results = [] 
guesses = []
guess =""
restart = True
data = []
def solve_hangman():
	global restart
	global data
	global results
	global guess
	global guesses

	if restart:
		print "restart"
		url = "http://gallows.hulu.com/play?code=manohar1008@gmail.com"
		gurl = "http://gallows.hulu.com/play?code=manohar1008@gmail.com"
		d = urllib2.urlopen(url)
		data = json.load(d)
		results=[]
		guesses=[]
		print data
		options={
			'status':data['status'],
			'token':data['token'],
			'remaining_guesses':data['remaining_guesses'],
			'state':data['state'],
			'results':results
		}
		restart = False

	while True:
		guess = formulate_guess(data['state'])
		url += '&token='+data['token']+'&guess='+guess
                d = urllib2.urlopen(url)
                data = json.load(d)
                results=[]
                guesses=[]
                options={
                        'status':data['status'],
                        'token':data['token'],
                        'remaining_guesses':data['remaining_guesses'],
                        'state':data['state'],
                        'results':results
                }
		url = gurl
	
		if data['status'] is 'DEAD':
			break

def formulate_guess(state):
	global guesses
	words = state.split()
	resultArray={}
	for word in words:
		temp = word
		if word.find("_") != -1:
			word = word.replace("_", "[a-z]")
			word+="$"
			word = "^" + word
			for line in dictionary:	
				if len(line) == len(temp)+1:
					result = re.search(word, line, re.IGNORECASE)
					if result is not None: 
						i = 0
						for c in temp:
							if temp[i] == '_':
								foundChar = result.group(0)[i].lower()
								if foundChar in resultArray: resultArray[foundChar] = resultArray[foundChar]+1
								else: resultArray[foundChar] = 1
							i = i+1
			dictionary.seek(0)
	maxChar = str(max(resultArray, key=resultArray.get))
	while maxChar.lower() in guesses:
		del resultArray[maxChar]
		maxChar = str(max(resultArray, key=resultArray.get))
	guess = maxChar
	return guess	

solve_hangman()

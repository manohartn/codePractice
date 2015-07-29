import urllib2
import json 
import random 
import time
import re
import operator

url = "http://gallows.hulu.com/play?code=manohar1008@gmail.com"
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

print data


print 'Hello World!'

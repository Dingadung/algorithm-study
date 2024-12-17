score = {
    'math': 97,
    'eng': 49,
    'kor': 89
}

print(score['math'])

score['math'] = 45

print(score['math'])

score['sci'] = 100

print(score['sci'])

print('music' in score)

if 'music' in score:
    print(score['math'])
else:
    score['music']=20

print('music' in score)
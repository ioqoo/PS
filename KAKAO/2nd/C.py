import sys
import random

T = int(sys.stdin.readline().rstrip("\n"))

for t in range(T):
    playlist = sys.stdin.readline().rstrip("\n").split("\t")
    artist = sys.stdin.readline().rstrip("\n").split("\t")
    H = dict()
    artistnum = 0
    for a in artist:
        if a in H:
            continue
        else:
            H[a] = artistnum
            artistnum += 1
    artistlist = [0 for n in range(artistnum)]
    song_per_artist = [[] for n in range(artistnum)]
    for i, song in enumerate(playlist):
        song_per_artist[H[artist[i]]].append(song)
    for a in H:
        artistlist[H[a]] = a
    
    ret = [0 for n in range(1000000)]
    firstoffset = [n for n in range(artistnum)]
    random.shuffle(firstoffset)
    for i, n in enumerate(firstoffset):
        ret[i] = song_per_artist[n][0]
    for i in range(10):
        print(ret[i])
        

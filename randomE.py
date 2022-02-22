def check(l, d, likerow, dislikerow, ingredients):
    k=0
    for i in range(1,l+1):
        if (likerow[i] in ingredients.keys() and ingredients[likerow[i]]>0):
            k+=1
        else:
            return False
    for i in range(1,d+1):
        if (dislikerow[i] in ingredients.keys()):
            return False
    if (k==l):
        return True
    else:
        return False

import random

maxyet=0
ingredientsyet = {}
w1=0
w2=0
bestcw=0
for i in range(100000):
    ingredients = {}
    f = open("e.txt", 'r')
    input = f.readlines()
    wl = random.uniform(0,2.2)
    wdl = random.uniform(0,2.2)
    t = int(input[0])
    m = 1
    cnw = random.uniform(0,1)
    while(m<2*t ):
        cw=1
        l = int(input[m][0])
        likerow = input[m].split()
        m+=1
        d = int(input[m][0])
        ca=l+d
        if(ca>7):
            cw=cnw
        for i in range(1,l+1):
            ltopping = likerow[i]
            if (ltopping in ingredients.keys()):
                ingredients[ltopping]+=1*wl*cw
            else:
                ingredients[ltopping]=1*cw
        
        
        dislikerow = input[m].split()
        for i in range(1,d+1):
            dtopping = dislikerow[i]
            if (dtopping in ingredients.keys()):
                ingredients[dtopping]-=wdl*cw
            else:
                ingredients[dtopping]=-1*cw
        m+=1
    f.close()

    f = open("e.txt", 'r')
    input = f.readlines()
    t = int(input[0])
    m = 1
    c=0
    while(m<2*t ):
        l = int(input[m][0])
        likerow = input[m].split()
        m+=1
        d = int(input[m][0])
        dislikerow = input[m].split()
        m+=1
        if (check(l,d, likerow, dislikerow, ingredients)==True):
            c+=1
    if (c>maxyet):
        maxyet = c
        ingredientsyet = ingredients
        w1=wl
        w2=wdl
        bestcw=cnw
    f.close()
print(maxyet)
print(w1)
print(w2)
print(cnw)
cnt = 0
for key in ingredientsyet:
    if(ingredientsyet[key] > 0):
        cnt+=1
print(cnt, end =" ")
for key in ingredientsyet:
    if(ingredientsyet[key] > 0):
        print(key, end= " ")

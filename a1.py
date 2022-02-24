f = open("a.txt", 'r')
input = f.readlines()
row = input[0].split()
c = int(input[0][0]) #no. of contributors
p = int(row[1]) #no of projs
line = 1
peopleread = 0
contributors = [] #list of people as (person, no. of skills)
while (peopleread < c):
    row = input[line].split()
    person = row[0]
    nskills = int(row[1])
    slist = [person, nskills, {}]
    k=0
    line+=1
    
    while k<nskills:
        row = input[line].split() #now reading the skills
        skillname = row[0]
        skillvalue = int(row[1])
        slist[2][skillname] = skillvalue
        k+=1
        line+=1
        #print(slist)
    contributors.append(slist)
    peopleread+=1
#print(contributors)

projectsread = 0
projlist = []
while(projectsread < p):
    
    #[project Days Score BestBefore nRoles {dict of Roles}]
    row = input[line].split()
    projname = row[0]
    days = int(row[1])
    score = int(row[2])
    bestbefore = int(row[3])
    nroles = int(row[4])
    proj = [projname, days, score, bestbefore, nroles, {}]
    j = 0
    line+=1
    while (j < nroles):
        row = input[line].split()
        skillname = row[0]
        skillvalue = int(row[1])
        proj[5][skillname] = skillvalue #this is reqd value
        j+=1
        line+=1
    projectsread+=1
    projlist.append(proj)
print(projlist)
print(contributors)      
    
    

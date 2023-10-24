import os

os.system("g++ -o main1 main1.cpp")
for i in range(5, 6):
    for j in range(0, 10):
        for k in range(0, 10):
            cmd = "./main1 " + str(i) + " " + str(j) + " " + str(k);
            print(i,j,k);
            os.system(cmd)
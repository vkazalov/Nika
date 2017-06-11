#import os
#import sys
#import struct
import matplotlib.pyplot as plt
import numpy as np


################krystall na FEU s opticheskoi smazkoi###############
Spc1=np.loadtxt("d:\\Cloud\\Dropbox\\G4\\RadioMan\\RM-b\\Debug\\RadioMan609keVCentr_500000.dat",usecols=[1], unpack=True)
################dlinnyi svetovod####################################
#Spc2=np.loadtxt("D:\\Work_DATA\\HPGe_Baksan\\SNEG.dat",usecols=[0], unpack=True)
################korodkii svetovod###################################


plt.figure(1)
plt.plot(Spc1,'r',linewidth = 1.5,drawstyle='steps')#dlinnyi svetovod#
plt.grid(True)
#plt.plot(Spc2,'k',linewidth = 1.5,drawstyle='steps')#dlinnyi svetovod bez linzy#
#plt.grid(True)

plt.show()

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov  4 00:33:14 2018

@author: Javier Alejandro Acevedo Barroso
"""


import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt


dat1 = np.loadtxt("sample_1.dat")
n = dat1[0]
dat1 = dat1[1:]
print(len(dat1))
#x = np.linspace(constantes[1]-3.5*constantes[2],constantes[1]+3.5*constantes[2],int(constantes[0]))

#plt.plot(x,gaussiana(x,constantes[1],constantes[2]))
#plt.hist(puntos,bins=int(constantes[0]//12),density=True)
#plt.savefig("sample.pdf")


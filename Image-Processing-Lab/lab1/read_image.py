# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 17:30:15 2022

@author: USER
"""
import cv2

import matplotlib.pyplot as plt

img = cv2.imread('lena.png', cv2.IMREAD_COLOR)

cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()

#plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
#plt.show()


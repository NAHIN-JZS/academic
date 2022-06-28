# -*- coding: utf-8 -*-
"""
Created on Wed Jun 22 11:11:46 2022

@author: NLP Lab
"""

import cv2
  
x_p =[]
y_p = []

def click_event(event, x, y, flags, params):
 
    # checking for left mouse clicks
    if event == cv2.EVENT_LBUTTONDOWN:
 
        # displaying the coordinates
        # on the Shell
        print(x, ' ', y)
        x_p.append(x)
        y_p.append(y)
 
        # displaying the coordinates
        # on the image window
        font = cv2.FONT_HERSHEY_SIMPLEX
        cv2.putText(img, str(x) + ',' +
                    str(y), (x,y), font,
                    1, (255, 0, 0), 2)
        cv2.imshow('image', img)
 
    # checking for right mouse clicks    
    if event==cv2.EVENT_RBUTTONDOWN:
 
        # displaying the coordinates
        # on the Shell
        print(x, ' ', y)
 
        # displaying the coordinates
        # on the image window
        font = cv2.FONT_HERSHEY_SIMPLEX
        b = img[y, x, 0]
        g = img[y, x, 1]
        r = img[y, x, 2]
        cv2.putText(img, str(b) + ',' +
                    str(g) + ',' + str(r),
                    (x,y), font, 1,
                    (255, 255, 0), 2)
        cv2.imshow('image', img)
    
 

   
img = cv2.imread('th_img2.jpg', 0)
cv2.imshow('image', img)   
cv2.setMouseCallback('image', click_event)  
cv2.waitKey(0) 
cv2.destroyAllWindows()

print(x_p, y_p)


import numpy as np
import matplotlib.pyplot as plt

imgg = cv2.imread('th_img2.jpg', 0)
plt.imshow(imgg,'gray')
plt.show()

#imgg = imgg//255
demo = np.zeros((imgg.shape[0],img.shape[1]), np.uint8)

demo[x_p[0]][y_p[0]] = 1

plt.imshow(demo,'gray')
plt.show()


kernel = cv2.getStructuringElement(cv2.MORPH_CROSS,(3,3))

print(kernel)

neg_imgg = 1-imgg
x0 = demo

while 1:
        
    temp = cv2.dilate(x0, kernel, iterations = 1)
    x1 = np.bitwise_and(temp, neg_imgg) 
    plt.imshow(x1, 'gray')
    plt.show()
    if(np.sum(x1) == np.sum(x0)):
        break
    x0 = x1
print(imgg)
for i in range(imgg.shape[0]):
    for j in range(imgg.shape[1]):
        if(x1[i][j] ==1):
            imgg[i][j] = x1[i][j]*255
print(x1)
plt.imshow(x1, 'gray')
plt.show()
    
out = np.bitwise_or(x1, imgg)
plt.imshow(imgg, 'gray')
plt.show()
plt.imshow(out, 'gray')
plt.show()
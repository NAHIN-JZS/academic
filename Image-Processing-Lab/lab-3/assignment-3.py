# -*- coding: utf-8 -*-
"""
Created on Mon May 23 16:23:22 2022

@author: USER
"""

import numpy as np
import cv2
import matplotlib.pyplot as plt

def guess_helper(x,mean = 2, std = 2):
    
    pixel_value = (1/np.sqrt(2*3.14*std**2))* np.exp(-(((x-mean)**2)/(2*std**2) ))
    return pixel_value



def guess_creation(std,mean,label= 256 ):
    
    guess = np.zeros(label,dtype='float32')
   
    for i in range(label):
      guess[i] = guess_helper(i,mean,std)
        
    return guess



def pdf_creation(image,image_lavel = 256):
    width,height = image.shape
    
    pdf = np.zeros(image_lavel, np.float32)
    
    for i in range(width):
        for j in range(height):
            pdf[image[i][j]]= pdf[image[i][j]] + 1
    pdf = pdf / (height*width)
    
    return pdf

def cdf_creation(pdf,lavel = 256):
    '''cdf = np.zeros(lavel, np.float32)
    cdf[0] = pdf[0]
    for i in range(1,len(pdf)):
        cdf [i] = cdf[i-1]+pdf[i]
    
    cdf = np.round((lavel - 1) * cdf)'''
    #print(cdf)
    
    cdf = np.cumsum(pdf)
    cdf = np.round((lavel - 1) * cdf)
    
    return cdf

def histogram_creation(image, name = 'histogram'):
    
    plt.title(name)
    plt.hist(image.ravel(),256,(0,1))
    plt.show()


def image_mapping(cdf1,cdf2):
    
    size = len(cdf1)
    print(size)
    mapped = np.zeros(size, np.float32)
    for i in range(size):
        
        for j in range(len(cdf2)):
            
            if (cdf1[i] == cdf2[j]):
                mapped[i] = j
            
            elif(cdf1[i]>cdf2[j]):
                
                if(abs(cdf1[i]-cdf2[j])<abs(cdf1[i]-cdf2[j-1])):
                    mapped[i]=j
                else:
                    mapped[i] = j-1
                
    return mapped
    
def recreation_image_from_ref(image_shape,cdf1,cdf2):
    output = np.zeros(image_shape)
    width,height = image_shape
    mapped = image_mapping(cdf1, cdf2)
    for i in range(width):
        for j in range(height):
            output[i][j]= mapped[image[i][j]]
    
    from skimage.exposure import rescale_intensity
    output = rescale_intensity(output, in_range=(0, 255))
    
    plt.title("Fig 3.    :Output image histogram")
    plt.hist(output.ravel(),256,(0,1))
    plt.show()
    
    cv2.imshow("output",output)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
    #plt.title("Output Image")
    #plt.imshow(cv2.cvtColor(output,cv2.COLOR_BGR2RGB))
    #plt.show()


std1 = 15
mean1 = 70

std2 = 10
mean2 = 150


image = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab3/histogram.jpg',cv2.IMREAD_GRAYSCALE)

plt.title("Fig 3.    :Original Image")
plt.imshow(cv2.cvtColor(image,cv2.COLOR_BGR2RGB))
plt.show()


plt.title("Fig 3.    :Input Image histogram")
plt.hist(image.ravel(),256,(0,256))
plt.show()

pdf1 = pdf_creation(image)
cdf1 = cdf_creation((pdf1))
#recreation_image(image, cdf1)

#pdf2 = pdf_creation(ref_image)
#cdf2 = cdf_creation(pdf2)




guess1 = guess_creation(std =  std1, mean = mean1, label = 256)

plt.title("Fig 3.    :Guess 1")
plt.plot(guess1)
plt.show()

guess2 = guess_creation(std= std2, mean = mean2, label = 256)

plt.title("Fig 3.    :Guess 2")
plt.plot(guess2)
plt.show()

guess = guess1 + guess2

guess_pdf = guess/guess.sum()


plt.title("Fig 3.    :Marged guess")
plt.plot(guess)
plt.show()

guess_cdf = cdf_creation(guess_pdf)


recreation_image_from_ref(image.shape, cdf1,guess_cdf)


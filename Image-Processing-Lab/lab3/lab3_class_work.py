# -*- coding: utf-8 -*-
"""
Created on Wed May 11 10:48:08 2022

@author: USER
"""
import numpy as np
import cv2
import matplotlib.pyplot as plt


def pdf_creation(image,image_lavel = 256):
    width,height = image.shape
    
    pdf = np.zeros(image_lavel, np.float32)
    
    for i in range(width):
        for j in range(height):
            pdf[image[i][j]]= pdf[image[i][j]] + 1
    pdf = pdf / (height*width)
    
    return pdf

def cdf_creation(pdf,lavel = 256):
    cdf = np.zeros(lavel, np.float32)
    cdf[0] = pdf[0]
    for i in range(1,len(pdf)):
        cdf [i] = cdf[i-1]+pdf[i]
    
    cdf = np.round((lavel - 1) * cdf)
    #print(cdf)
    return cdf

def recreation_image(image,cdf):
    output = np.zeros(image.shape)
    width,height = image.shape
    
    for i in range(width):
        for j in range(height):
            output[i][j]= cdf[image[i][j]]
    
    
    #histogram_creation(output,"output")
    from skimage.exposure import rescale_intensity
    output = rescale_intensity(output, in_range=(0, 255))
    #print(output)
    
    #plt.title("Fig 3.    :Output image histogram")
    plt.hist(output.ravel(),256,(0,1))
    plt.show()
    
    cv2.imshow("output",output)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
    #plt.title("Output Image")
    #plt.imshow(cv2.cvtColor(output,cv2.COLOR_BGR2RGB))
    #plt.show()
    

image = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab3/histogram.jpg',cv2.IMREAD_GRAYSCALE)

#plt.title("Fig 3.    :Original Image")
plt.imshow(cv2.cvtColor(image,cv2.COLOR_BGR2RGB))
plt.show()

#plt.title("Fig 3.     :Input Image histogram")
plt.hist(image.ravel(),256,(0,256))
plt.show()

pdf = pdf_creation(image)
cdf = cdf_creation((pdf))
recreation_image(image, cdf)



# -*- coding: utf-8 -*-
"""
Created on Wed May 11 00:46:14 2022

@author: USER
"""
import cv2
import numpy as np
import matplotlib.pyplot as plt


def histogram_gray_image(img):
  height, width = img.shape
  # outputImage = np.zeros((height, width))
  outputImage = img.copy()

  freq = np.zeros(256, dtype=np.int32)
  pdf = np.zeros(256, dtype=np.float32)
  cdf = np.zeros(256, dtype=np.float32)

  for row in range(height):
    for col in range(width):
      freq[img[row, col]] += 1
      
  for i in range(256):
    pdf[i] = freq[i] / (height*width)
  
  cdf[0] = pdf[0]
  for i in range(1, 256):
    cdf[i] = cdf[i] + pdf[i]

  for i in range(height):
    for j in range(width):
      outputImage[i, j] = cdf[img[i,j]] * 255

  return outputImage

img = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab1/lena.png',cv2.IMREAD_GRAYSCALE)


resultImage = histogram_gray_image(img)
plt.imshow(img, cmap='gray')
plt.show()


plt.imshow(resultImage, cmap='gray')
plt.show()



#color image
def histogram_color_image(img):
  height, width, channel = img.shape
  outputImage = img.copy()
  
  freq = np.zeros(256, dtype=np.int32)
  pdf = np.zeros(256, dtype=np.float32)
  cdf = np.zeros(256, dtype=np.float32)

  for row in range(height):
    for col in range(width):
      for ch in range(channel):
        freq[img[row, col, ch]] += 1

  for i in range(256):
    pdf[i] = freq[i] / (height*width*channel)
  
  cdf[0] = pdf[0]
  for i in range(1, 256):
    cdf[i] = cdf[i-1] + pdf[i]

  for i in range(height):
    for j in range(width):
      for k in range(channel):
        outputImage[i, j, k] = cdf[img[i,j,k]] * 255

  return outputImage



img = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab1/lena.png')
plt.imshow(img, cmap='gray')
plt.show()

resultImage = histogram_color_image(img)
plt.imshow(resultImage)



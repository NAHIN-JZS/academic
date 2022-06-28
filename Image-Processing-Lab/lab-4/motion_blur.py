# -*- coding: utf-8 -*-
"""
Created on Tue Jun 14 23:17:06 2022

@author: USER
"""

import numpy as np
import matplotlib.pyplot as plt
import cv2

def motion_filter(kernel_size = 5):
    kernel = np.zeros((kernel_size,kernel_size))
    kernel_mid = int(kernel_size/2)
    kernel[kernel_mid,:] = 1
    
    return kernel

def mean_filter(kernel_size = 5):
    #mean kernel function
    kernel = np.ones((kernel_size,kernel_size))
    
    return kernel
    

image = cv2.imread("F:/4.1/CSE 4128 Image Lab/lena.png",0)
image = cv2.resize(image, (128, 128))
#m_filter = mean_filter(kernel_size=13)

m_filter = motion_filter(kernel_size=13)
print(m_filter)

# computing the number of padding on one side
padding = int(image.shape[0]//2 - m_filter.shape[0]//2)
print(padding)
if padding %2:
    m_filter_pad = np.pad(m_filter, (padding,padding), 'constant', constant_values=(0))
else:
    m_filter_pad = np.pad(m_filter, (padding,padding-1), 'constant', constant_values=(0))
    


# computing the Fourier transforms

image_fourier = np.fft.fft2(image, axes=(0,1))

filter_fourier = np.fft.fft2(m_filter_pad, axes=(0,1))

plt.imshow(np.fft.fftshift(np.log(np.abs(image_fourier)+1)), 'gray')
plt.show()

plt.imshow(np.fft.fftshift(np.log(np.abs(filter_fourier)+1)), 'gray')
plt.show()

# convolution
blurry_image = np.multiply(image_fourier,filter_fourier)

# Inverse Transform

blurry_image_shown = np.fft.ifftshift(np.fft.ifft2(blurry_image).real)


plt.imshow(image, 'gray');
plt.title("original image")
plt.show()



# ### Inverse filter

image_back = np.divide(blurry_image,filter_fourier)

image_back = np.fft.ifft2(image_back).real


plt.imshow(blurry_image_shown, 'gray');
plt.title("degraded/blurred image")
plt.show()
plt.imshow(image_back, 'gray')
plt.title("restored image")
plt.show()




# -*- coding: utf-8 -*-
"""
Created on Sat May 21 10:17:48 2022

@author: USER
"""

import cv2
from matplotlib import pyplot as plt
import numpy as np
from skimage.exposure import rescale_intensity


def shift(image):
    shape = image.shape
    print(shape)
    
    output = np.zeros(shape)
    
    for i in range(shape[0]):
        for j in range(shape[1]):
            output[i][j] = image[i][j]*((-1)**(i+j))
    
    #output = np.rot90(np.rot90(output))
    return output
    

def transform(image):
    
    shifted_image = shift(image)
    #shifted_image = image
    
    dft = cv2.dft(np.float32(shifted_image), flags=cv2.DFT_COMPLEX_OUTPUT)

    #dft_shift = np.fft.fftshift(dft)
    dft_shift = dft


    magnitude_spectrum = 20 * np.log(cv2.magnitude(dft_shift[:,:,0], dft[:,:,1])+1)

    
    plt.imshow(magnitude_spectrum)
    plt.show()
    
    return dft_shift

def high_pass_filter(dft_shift,radius = 100):
    row, col,channel = dft_shift.shape
    crow,ccol = int(row/2) , int(col/2)
    
    mask = np.ones((row,col,2),np.uint8)
    r = radius
    center = [crow,ccol]
    x,y = np.ogrid[:row,:col]
    mask_area = (x-center[0]) ** 2 + (y - center[1]) ** 2 <= r*r
    mask[mask_area] = 0
    
    
    
    fshift = dft_shift * mask


    fshift_mask_mag = 2000 * np.log(cv2.magnitude(fshift[:, :, 0], fshift[:, :, 1])+1)
    
    plt.title("high pass mask")
    plt.imshow(fshift_mask_mag)
    plt.show()

    #f_ishift = np.fft.ifftshift(fshift)
    #img_back = cv2.idft(f_ishift)
    img_back = cv2.idft(fshift)
    img_back = cv2.magnitude(img_back[:, :, 0], img_back[:, :, 1])

    plt.title("High pass")
    plt.imshow(img_back,cmap='gray')
    plt.show()
    
    return fshift


def low_pass_filter(dft_shift,radius = 100):
    row, col,channel = dft_shift.shape
    crow,ccol = int(row/2) , int(col/2)
    
    mask = np.zeros((row,col,2),np.uint8)
    r = radius
    center = [crow,ccol]
    x,y = np.ogrid[:row,:col]
    mask_area = (x-center[0]) ** 2 + (y - center[1]) ** 2 <= r*r
    mask[mask_area] = 1
    

    
    fshift = dft_shift * mask


    fshift_mask_mag = 2000 * np.log(cv2.magnitude(fshift[:, :, 0], fshift[:, :, 1])+1)
    
    plt.title("Low pass mask")
    plt.imshow(fshift_mask_mag)
    plt.show()

    #f_ishift = np.fft.ifftshift(fshift)
    #img_back = cv2.idft(f_ishift)
    img_back = cv2.idft(fshift)
    img_back = cv2.magnitude(img_back[:, :, 0], img_back[:, :, 1])

    
    plt.title("low pass")
    plt.imshow(img_back,cmap='gray')
    plt.show()
    
    return fshift
    
    
'''x = np.arange(256)
#dx = 0.001
#x = np.arange(0,1,dx)
#y = np.sin(2*np.pi*50*x)
y = np.sin(2*np.pi* x/6)
y += max(y)

img = np.array([[y[j]*127 for j in range(256)] for i in range (256)], dtype = np.uint8)'''

#F:/4.1/CSE 4128 Image Lab/lab2/rubiks-cube.jpg
#F:/4.1/CSE 4128 Image Lab/lena.png
#F:/4.1/CSE 4128 Image Lab/lab3/pics/cheetah.jpg

img1 = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab3/pics/cheetah.jpg',cv2.IMREAD_GRAYSCALE)
img1 = cv2.resize(img1, (512,512))
img2 = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab2/rubiks-cube.jpg', cv2.IMREAD_GRAYSCALE)
img2 = cv2.resize(img2, (512,512))

plt.title("image-1 ")
plt.imshow(rescale_intensity( cv2.cvtColor(np.float32(img1), cv2.COLOR_BGR2RGB) ,in_range=(0,255)))
plt.show()

plt.title("image-2")
plt.imshow(rescale_intensity( cv2.cvtColor(np.float32(img2), cv2.COLOR_BGR2RGB) ,in_range=(0,255)))
plt.show()


#img = shift(img)
#img = shift(img)

#plt.title("after shifting", img)

#plt.imshow(rescale_intensity( cv2.cvtColor(np.float32(img), cv2.COLOR_BGR2RGB) ,in_range=(0,255)))
#plt.show()
#plt.imshow(img)
#plt.show()


dft_shift1 = transform(img1)

dft_shift2 = transform(img2)


high = high_pass_filter(dft_shift2,80)

low = low_pass_filter(dft_shift2,80)

marge = high + low

img_back = cv2.idft(marge)
img_back = cv2.magnitude(img_back[:, :, 0], img_back[:, :, 1])

plt.title("Marge")
plt.imshow(img_back,cmap='gray')
plt.show()



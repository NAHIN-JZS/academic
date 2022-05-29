# -*- coding: utf-8 -*-
"""
Created on Wed May 25 11:22:46 2022

@author: USER
"""

import cv2
from matplotlib import pyplot as plt
import numpy as np
from skimage.exposure import rescale_intensity




def homomorphic_filter(image, c,Lh,Ll,D0):
    
    cX,cY = image.shape
    H = np.zeros((cX,cY,2),np.uint8)
    
    
    for u in range(cX):
        for v in range(cY):
            #print(u,v)
            Duv = np.sqrt((u-cX/2)**2+(v-cY/2)**2)
            #print(Duv)
            H[u][v] = (Lh-Ll)*(1-np.exp(-c*(Duv**2))**2/(D0**2))+Ll
            
            #print((Lh-Ll)*(1-np.exp(-c*(Duv**2))**2/(D0**2))+Ll)
    
    
    
    #fshift_mask_mag = 2000 * np.log(cv2.magnitude(H[:, :, 0], H[:, :, 1])+1)
    
    #plt.title("Low pass mask")
    #plt.imshow(fshift_mask_mag)
    #plt.show()
    return H

img = cv2.imread('F:/4.1/CSE 4128 Image Lab/Lab 4/homo.jpg',cv2.IMREAD_GRAYSCALE)

plt.title("image-1 ")
plt.imshow(rescale_intensity( cv2.cvtColor(np.float32(img), cv2.COLOR_BGR2RGB) ,in_range=(0,255)))
plt.show()

img = np.float32(img)
log_img = np.log1p(img)


dft = cv2.dft(np.float32(log_img), flags=cv2.DFT_COMPLEX_OUTPUT)
dft_shift = np.fft.fftshift(dft)

magnitude_spectrum =  np.log(cv2.magnitude(dft_shift[:,:,0], dft_shift[:,:,1])+1)
plt.imshow(magnitude_spectrum),plt.title("fourier of input image")
plt.show()

homo_filter = homomorphic_filter(image=img, c = 0.1, Lh = 1.2, Ll=0.5, D0=50)


#magnitude_spectrum =  np.log(cv2.magnitude(homo_filter[:,:,0], homo_filter[:,:,1])+1)
#plt.imshow(magnitude_spectrum),plt.title("fourier of input image")
#plt.show()


output_f = dft_shift * homo_filter


img_back = np.fft.ifftshift(output_f)
img_back = cv2.idft(img_back)

img_back = cv2.magnitude(img_back[:, :, 0], img_back[:, :, 1])
#img_back = np.expm1(img_back)


plt.title("output")
plt.imshow(img_back,cmap='gray')
plt.show()




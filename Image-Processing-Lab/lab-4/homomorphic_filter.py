# -*- coding: utf-8 -*-
"""
Created on Sun May 22 10:51:10 2022

@author: USER
"""

import numpy as np
import cv2

# read input and convert to grayscale
img = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab2/rubiks-cube.jpg', cv2.IMREAD_GRAYSCALE)
hh, ww = img.shape[:2]

# take ln of image
img_log = np.log(np.float64(img)+1, dtype=np.float64)

# do dft saving as complex output
dft = np.fft.fft2(img_log, axes=(0,1))

# apply shift of origin to center of image
dft_shift = np.fft.fftshift(dft)

# create black circle on white background for high pass filter
#radius = 3
radius = 13
mask = np.zeros_like(img, dtype=np.float64)
cy = mask.shape[0] // 2
cx = mask.shape[1] // 2
cv2.circle(mask, (cx,cy), radius, 1, -1)
mask = 1 - mask

# antialias mask via blurring
#mask = cv2.GaussianBlur(mask, (7,7), 0)
mask = cv2.GaussianBlur(mask, (47,47), 0)

# apply mask to dft_shift
dft_shift_filtered = np.multiply(dft_shift,mask)

# shift origin from center to upper left corner
back_ishift = np.fft.ifftshift(dft_shift_filtered)

# do idft saving as complex
img_back = np.fft.ifft2(back_ishift, axes=(0,1))

# combine complex real and imaginary components to form (the magnitude for) the original image again
img_back = np.abs(img_back)

# apply exp to reverse the earlier log
img_homomorphic = np.exp(img_back, dtype=np.float64)

# scale result
img_homomorphic = cv2.normalize(img_homomorphic, None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_8U)

# write result to disk
cv2.imwrite("person_dft_numpy_mask.png", (255*mask).astype(np.uint8))
cv2.imwrite("person_dft_numpy_homomorphic.png", img_homomorphic)

cv2.imshow("ORIGINAL", img)
cv2.imshow("MASK", mask)
cv2.imshow("FILTERED DFT/IFT ROUND TRIP", img_back)
cv2.imshow("HOMOMORPHIC", img_homomorphic)
cv2.waitKey(0)
cv2.destroyAllWindows()
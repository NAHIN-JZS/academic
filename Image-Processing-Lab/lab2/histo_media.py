# -*- coding: utf-8 -*-
"""
Created on Wed May 11 00:25:16 2022

@author: USER
"""

import matplotlib.pyplot as plt
import numpy as np
import cv2

def generate_histogram(img, do_print):
    """
    @params: img: can be a grayscale or color image. We calculate the Normalized histogram of this image.
    @params: do_print: if or not print the result histogram
    @return: will return both histogram and the grayscale image 
    """
    if len(img.shape) == 3: # img is colorful, so we convert it to grayscale
        gr_img = np.mean(img, axis=-1)
    else:
        gr_img = img
    '''now we calc grayscale histogram'''
    gr_hist = np.zeros([256])

    for x_pixel in range(gr_img.shape[0]):
        for y_pixel in range(gr_img.shape[1]):
            pixel_value = int(gr_img[x_pixel, y_pixel])
            gr_hist[pixel_value] += 1
            
    '''normalizing the Histogram'''
    gr_hist /= (gr_img.shape[0] * gr_img.shape[1])
    if do_print:
        print_histogram(gr_hist, name="n_h_img", title="Normalized Histogram")
    return gr_hist, gr_img
  
def print_histogram(_histrogram, name, title):
  plt.figure()
  plt.title(title)
  plt.plot(_histrogram, color='#ef476f')
  plt.bar(np.arange(len(_histrogram)), _histrogram, color='#b7b7a4')
  plt.ylabel('Number of Pixels')
  plt.xlabel('Pixel Value')
  plt.savefig("hist_" + name)
  
def print_img(img,histo_new,histo_old, index):
    plt.title("Image")
    plt.imshow(cv2.cvtColor(img,cv2.COLOR_BGR2RGB))
    print_histogram(histo_new,"new histogram","new")
    print_histogram(histo_old,"old histogram","old")
    




def equalize_histogram(img, histo,L):
    index = 1
    eq_histo = np.zeros_like(histo)
    en_img = np.zeros_like(img)
    for i in range(len(histo)):
        eq_histo[i] = int((L - 1) * np.sum(histo[0:i]))
    print_histogram(eq_histo, name="eq_"+str(index), title="Equalized Histogram")
    '''enhance image as well:'''
    for x_pixel in range(img.shape[0]):
        for y_pixel in range(img.shape[1]):
            pixel_val = int(img[x_pixel, y_pixel])
            en_img[x_pixel, y_pixel] = eq_histo[pixel_val]
    '''creating new histogram'''
    hist_img, _ = generate_histogram(en_img, print=False, index=index)
    print_img(img=en_img, histo_new=hist_img, histo_old=histo, index=str(index))
    return eq_histo

main_image = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab1/lena.png',cv2.IMREAD_GRAYSCALE)

image_size = 220
image = cv2.resize(main_image,(image_size,image_size))
plt.title("Image")
plt.imshow(cv2.cvtColor(image,cv2.COLOR_BGR2RGB))
his = generate_histogram(image,1)
equalize_histogram(image,his,L = 8)
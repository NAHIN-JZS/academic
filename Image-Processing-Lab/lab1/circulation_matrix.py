# -*- coding: utf-8 -*-
"""
Created on Fri Apr  1 12:17:35 2022

@author: Nahin
"""

import numpy as np
import cv2
import matplotlib.pyplot as plt

#from PIL import Image as im


def one_row_creation(img_size, kernel):
    kernel_w = kernel.shape[0]
    
    mat_row_size = img_size *img_size
    dif = img_size - kernel_w
    one_row = []
    for j in range(kernel_w-1,-1,-1):
        for k in range (kernel_w-1,-1,-1):
            one_row.append(kernel[j][k])
        
        for z in range(dif):
            one_row.append(0)
            
    #adding rest of the value zero
    dif2 = mat_row_size - len(one_row)
    for i in range(dif2):
        one_row.append(0)
    #print(one_row)
    return one_row

def creating_block_circulation_matrix (image_size ,kernel):
        mat_size = image_size *image_size
        
        row = one_row_creation(image_size, kernel)
        b_c_matrix = []
        b_c_matrix.append(row)
        last_index = len(row) - 1
        #print(last_index)
        for i in range(mat_size-1):
            #print("before new_row\n",row)
            new_first_element = row[last_index]
            #print("last_element : ",new_first_element)
            new_row = np.insert(row,0,new_first_element)
            new_row = np.delete(new_row,last_index+1)
            #print("new_row\n",new_row)
            
            
            #new_row = new_row.tolist()
            b_c_matrix.append(new_row)
            row = new_row
        
        #print(b_c_matrix)
        return b_c_matrix
        
        
        
kernel = np.array([[0,-1,0],[-1,5,-1],[0,-1,0]])

#image = np.arange(25).reshape(5,5)
image = cv2.imread('F:/4.1/CSE 4128 Image Lab/lab1/lena.png',cv2.IMREAD_GRAYSCALE)
image1 = image
plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
plt.title("Figure 1.1: original image")
plt.show()
#cv2.imshow("adsfhd",image)
#cv2.waitKey(5)
#image = 
#print("image : \n",image)



#print("flatten image: \n{}",flatten_image)

#----------------Circulant matrix -------------------------

image_size = 220

image = cv2.resize(image, (image_size,image_size))
print("image shape: ",image.shape[0], image.shape[1])
image1 = cv2.resize(image1, (image_size,image_size))
#print(image1.shape[1])

flatten_image = image.flatten()

bcm = creating_block_circulation_matrix(image_size,kernel)

bcm = np.array(bcm)

#print("bcm : \n",bcm)
print("bcm : ",bcm.shape)
print("img : ",flatten_image.shape)

out_mat = np.matmul(bcm, flatten_image)

#print(out_mat)
#max_val = max(out_mat)
output = np.resize(out_mat,(image_size,image_size))

#output = output // max_val
output = cv2.cvtColor(np.float32(output), cv2.COLOR_BGR2RGB)
  
#print(output)

plt.imshow(output)
plt.title("Figure 1.4: Block circulation matrix implementation output")
plt.show()


#plt.imshow(cv2.cvtColor(output, cv2.COLOR_BGR2RGB))
#plt.show()


#data = im.fromarray(output)
#if data.mode != 'RGB':
    #print("sdffds")
    #data = data.convert('BGR')
    #data = data[:,:,::-1]
#output = np.float32(output)
#data = cv2.cvtColor(np.float32(data), cv2.COLOR_BGR2RGB)
    #plt.imshow(data)
    #plt.show()
    
#cv2.imshow("get: ",output)
#data.save('gfg_dummy_pic.png')


#kernel = np.array(([0,-1,0], [-1, 5, -1], [0,-1,0]), np.float32)
# kernel = np.transpose(kernel)





#----------------------------------Loop implementation --------------------------
kernel_size  = len(kernel)
print(kernel_size)
extra = (kernel_size-1)//2
img = cv2.copyMakeBorder(image1,extra,extra,extra,extra, cv2.BORDER_REPLICATE)

result = np.zeros((image_size, image_size), dtype='float32')
n = (kernel_size - 1)//2
for x in range(image_size):
  for y in range(image_size):
    sum = 0
    for j in range(kernel_size):
      for i in range(kernel_size):
        # print(kernel[i,j])
        # print(img[x-i-n, y-j-n])
        sum += kernel[i,j]*img[x-i-n, y-j-n]
        # print(sum)
    result[x, y] = sum
    # print(sum)


plt.imshow(cv2.cvtColor(result, cv2.COLOR_BGR2RGB))
plt.title("Figure 1.3: Loop implementation output")
plt.show()



#------------------------------------------CV2 build in function ------------------

img = cv2.filter2D(image1, -1, kernel)

img = cv2.cvtColor(np.float32(img), cv2.COLOR_BGR2RGB)

plt.imshow(img)
plt.title("Figure 1.2: cv2 filter2D function output")
plt.show()
#cv2.imshow("cv2:", img)


#cv2.waitKey()
#cv2.destroyAllWindows()
 

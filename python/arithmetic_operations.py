import numpy as np
import cv2 as cv 
from matplotlib import pyplot as plt


'''
img1 = cv.imread('/home/omer/omr-web/Image-Processing/python/deneme_image.jpg')
img2 = cv.imread('/home/omer/omr-web/Image-Processing/python/blending.jpg')

print(img1.shape)
print(img2.shape)


width = int(img1.shape[1])
height = int(img1.shape[0])
dim = (width, height)

img2 = cv.resize(img2,dim,interpolation = cv.INTER_AREA)

print(img1.shape)
print(img2.shape)
added_image = cv.addWeighted(img1,0.3,img2,0.7,0)

cv.imshow('dst',added_image)
cv.waitKey(0)
cv.destroyAllWindows()

'''

## Bitwise Operations 

img1 = cv.imread('/home/omer/omr-web/Image-Processing/python/messi5.jpg')
img2 = cv.imread('/home/omer/omr-web/Image-Processing/python/opencv-logo-white.png')

rows,cols,channels = img2.shape
roi = img1[0:rows,0:cols]

img2gray = cv.cvtColor(img2,cv.COLOR_BGR2GRAY)
ret,mask = cv.threshold(img2gray,10,255,cv.THRESH_BINARY)
mask_inv = cv.bitwise_not(mask)


# Now black-out the area of logo in ROI
img1_bg = cv.bitwise_and(roi,roi,mask = mask_inv)
# Take only region of logo from logo image.
img2_fg = cv.bitwise_and(img2,img2,mask = mask)

# Put logo in ROI and modify the main image
dst = cv.add(img1_bg,img2_fg)
img1[0:rows, 0:cols ] = dst
cv.imshow('res',img1)
cv.waitKey(0)
cv.destroyAllWindows()
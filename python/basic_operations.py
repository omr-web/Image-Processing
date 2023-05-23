import numpy as np
import cv2 as cv 
from matplotlib import pyplot as plt

img = cv.imread('/home/omer/omr-web/Image-Processing/python/messi5.jpg')


# pixel = img[100,100]
# print(pixel)
# print(type(img))
# print(img.shape)

# ball = img[280:340, 330:390]
# img[273:333, 100:160] = ball
# # cv.imshow('image',ball)
# cv.imshow('messi',img)

# b,g,r = cv.split(img) ## maliyetli bir iş 

# img[:,:,2] = 0
# cv.imshow('messi',img)

# cv.waitKey(0)
# cv.destroyAllWindows()

## Making Border

BLUE = [255,0,0]
img1 = cv.imread("/home/omer/omr-web/Image-Processing/python/OpenCV-01.png") 


replicate = cv.copyMakeBorder(img1,10,10,10,10,cv.BORDER_REPLICATE)
reflect = cv.copyMakeBorder(img1,10,10,10,10,cv.BORDER_REFLECT)
reflect101 = cv.copyMakeBorder(img1,10,10,10,10,cv.BORDER_REFLECT_101)
wrap = cv.copyMakeBorder(img1,10,10,10,10,cv.BORDER_WRAP)
constant= cv.copyMakeBorder(img1,10,10,10,10,cv.BORDER_CONSTANT,value=BLUE)

plt.subplot(231),plt.imshow(img1,'gray'),plt.title('ORIGINAL')
plt.subplot(232),plt.imshow(replicate,'gray'),plt.title('REPLICATE')
plt.subplot(233),plt.imshow(reflect,'gray'),plt.title('REFLECT')
plt.subplot(234),plt.imshow(reflect101,'gray'),plt.title('REFLECT_101')
plt.subplot(235),plt.imshow(wrap,'gray'),plt.title('WRAP')
plt.subplot(236),plt.imshow(constant,'gray'),plt.title('CONSTANT')

plt.show()

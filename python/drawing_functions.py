import numpy as np 
import cv2 as cv 


'''
img = np.zeros((512,512,3),np.uint8)

#cv.line(img,(0,0),(511,511),(255,255,255),1)
cv.rectangle(img,(384,0),(510,510),(0,255,0),3)

cv.circle(img,(447,63), 63, (255,255,255), -1)

cv.ellipse(img,(256,256),(100,50),0,0,180,255,-1)
 
font = cv.FONT_HERSHEY_SIMPLEX
cv.putText(img,'OpenCV',(10,500), font, 4,(255,255,255),2,cv.LINE_AA)

cv.imshow("Display window", img)


k = cv.waitKey(0)
if k == ord("s"):
    cv.imwrite("starry_night.png", img)
    '''

## Trackbar 
def nothing(x):
    pass
img = np.zeros((300,512,3),np.uint8)
cv.namedWindow('image')

cv.createTrackbar('R','image',0,255,nothing)
cv.createTrackbar('G','image',0,255,nothing)
cv.createTrackbar('B','image',0,255,nothing)

switch = '0: OFF \n1 : ON'
cv.createTrackbar(switch,'image',0,1,nothing)

while(1):
    cv.imshow('image',img)
    k = cv.waitKey(1) & 0xFF
    if k == 27:
        break

    r = cv.getTrackbarPos('R','image')
    g = cv.getTrackbarPos('G','image')
    b = cv.getTrackbarPos('B','image')
    s = cv.getTrackbarPos(switch,'image')

    if s == 0:
        img[:] = 0
    else:
        img[:] = [b,g,r]


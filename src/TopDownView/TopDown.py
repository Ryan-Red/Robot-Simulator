import cv2
import numpy as np



cap = cv2.VideoCapture(0)
for i in range(0,10):
    ret, frame = cap.read()


img_ori = frame
img = img_ori.copy()
base = np.zeros((img_ori.shape[:2]))

l = []
setup = True
m = 0

def getTransform(points):
    # from documentation linked above
    pts1 = np.float32(points)
    pts2 = np.float32([[0,0],[300,0],[300,300],[0,300]])

    return cv2.getPerspectiveTransform(pts1,pts2)

def processMouse(event,x,y,flags,params):
    global l,setup,m
    if setup:
        # create ROI + getTransform when 4 corners are clicked
        if event == cv2.EVENT_LBUTTONDOWN:
            l.append([x,y])
            cv2.circle(img, (x,y), 5,(255,0,0),3)
            cv2.imshow('IMG',img)
            if(len(l)) == 4:
                m = getTransform(l)
                setup = False
    else:
        # draw mouse position
        print(l)
        # with image
        img2 = img_ori.copy()
        cv2.circle(img2, (x,y), 5,(0,0,255),-1)
        dst =   cv2.warpPerspective(np.float32(img2), m, (300,300))
        dst = np.array(dst, dtype='uint8')
        cv2.imshow('IMG2',dst)

        # black 
        img3 = base.copy()
        cv2.circle(img3, (x,y), 5,(255),-1)
        dst =   cv2.warpPerspective(np.float32(img3), m, (300,300))
        dst = np.array(dst, dtype='uint8')
        cv2.imshow('IMG3',dst)


cv2.namedWindow('IMG')
cv2.setMouseCallback("IMG",processMouse)
cv2.imshow('IMG',img)

cv2.waitKey(0)
cv2.destroyAllWindows()
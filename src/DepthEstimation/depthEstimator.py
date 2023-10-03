import cv2 as cv
import torch
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

from transformers import DPTFeatureExtractor, DPTForDepthEstimation

feature_extractor = DPTFeatureExtractor.from_pretrained("Intel/dpt-large")
model = DPTForDepthEstimation.from_pretrained("Intel/dpt-large")


# import requests

# url = 'http://images.cocodataset.org/val2017/000000039769.jpg'
# image = Image.open(requests.get(url, stream=True).raw)



# if frame is read correctly ret is True
# if not ret:
#     print("Can't receive frame (stream end?). Exiting ...")
#     break
# Our operations on the frame come here
# gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
# Display the resulting frame

# im_np = np.asarray(depth)
# im_np2 = np.asarray(image)
# cv.imshow('frame', im_np)
# cv.imshow("base", im_np2)

# plt.imshow(output)

# plt.show()

# res = cv.waitKey(0)



cap = cv.VideoCapture(0)
cap.set(cv.CAP_PROP_FRAME_WIDTH, 320)
cap.set(cv.CAP_PROP_FRAME_HEIGHT, 240)

if not cap.isOpened():
    print("Cannot open camera")
    exit()
while True:
    # Capture frame-by-frame
    ret, frame = cap.read()


    
    image = Image.fromarray(frame)
    pixel_values = feature_extractor(image, return_tensors="pt").pixel_values

    with torch.no_grad():
        outputs = model(pixel_values)
        predicted_depth = outputs.predicted_depth

    # print(image.shape)

    prediction = torch.nn.functional.interpolate(
                    predicted_depth.unsqueeze(1),
                    size=image.size[::-1],
                    mode="bicubic",
                    align_corners=False,
                ).squeeze()
    output = prediction.cpu().numpy()
    formatted = (output * 255 / np.max(output)).astype('uint8')
    depth = Image.fromarray(formatted)



    # if frame is read correctly ret is True
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break
    # Our operations on the frame come here
    # gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    # Display the resulting frame
    
    im_np = np.asarray(depth)
    # im_np2 = np.asarray(image)
    cv.imshow('frame', im_np)
    # cv.imshow("base", im_np2)


    if cv.waitKey(1) == ord('q'):
        break
# When everything done, release the capture
cap.release()
cv.destroyAllWindows()
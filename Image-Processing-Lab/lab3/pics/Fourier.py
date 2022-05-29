
import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('index.jpg',0)

f = np.fft.fft2(img)
fshift = np.fft.fftshift(f)
magnitude_spectrum = 20*np.log(np.abs(fshift))


mag = np.abs(fshift)

print(mag)
ang = np.angle(fshift)



combined = np.multiply(mag, np.exp(1j*ang))

imgCombined = np.real(np.fft.ifft2(np.fft.ifftshift(combined)))


plt.subplot(121),plt.imshow(img, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])

plt.subplot(122),plt.imshow(imgCombined, cmap = 'gray')
plt.title('Output image'), plt.xticks([]), plt.yticks([])

#plt.imshow(imgCombined, cmap='gray')


plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()



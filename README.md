# image_filter
Implementation of a function that takes as input an image (as a pointer to an array of doubles) and its dimension and performs it's convolution with a constant kernel in order to apply average filter.
Kernel convolution usually requires values from pixels outside of the image boundaries. There are a variety of methods for handling image edges. Implemented method does not take them into account, which is equal to set
required pixels outside of the image as zeros. This programs runs in O(n^2) (two inner loops consist of constant number of operation).

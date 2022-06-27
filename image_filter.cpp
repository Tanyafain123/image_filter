
//Home assignment, Tanya Fainstein, 28,06,2022//

/**
 * function initialize_kernel, initializes kernel(as an array) of size size*size.
 * @param array
 * @param size
 */
void initialize_kernel (double *array, double size)
{
  for (int i = 0; i < size; i++)
    {
      array[i] = 1.0 / size;
    }
}
/**
 * function copy_image changes the initian picture to the changed one.
 * @param array_old
 * @param array_new
 * @param size
 */
void copy_image (double *array_old, const double *array_new, int size)
{
  for (int i = 0; i < size; i++)
    {
      array_old[i] = array_new[i];
    }
}

/**
 * function image_filter takes as input matrix(as an array) N*N and it size and performs its 2-dimensional convolution
 * with a constant kernel.
 * @param input_image
 * @param N
 * @return input_image
 */

double *image_filter (double *input_image, int N)
{
  double kernel[25];
  int kernel_size = 5;
  int ker_center_x = kernel_size / 2; //implicit casts to int.
  int ker_center_y = kernel_size / 2;
  double output_image[
      N * N]; // we can not just change the input_image, new picture pixels depend on the old picture pixels.
  initialize_kernel (kernel, kernel_size * kernel_size);
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        {
          double cell_value = 0;
          for (int k = 0; k < kernel_size; k++) // we use k as row index to go over the kernel matrix
            // while performing convolution
            {
              for (int l = 0; l < kernel_size; l++) // we use l as column index to go over the kernel matrix
                // while performing convolution
                {
                  int image_index_x =
                      i + (k - ker_center_x); //  row index we use to go over the input_image
                  // while performing convolution
                  int image_index_y =
                      j + (l - ker_center_y); //  column index we use to go over the input_image
                  // while performing convolution
                  if (image_index_x >= 0 && image_index_x < N && image_index_y >= 0 && image_index_y < N) //  Kernel
                    // convolution requires values from pixels outside of the image boundaries.
                    // The implemented method does not take them into account, which is equal to set
                    // required pixels outside of the image as zeros;
                    {
                      cell_value += input_image[(image_index_x) * N + (image_index_y)] * kernel[(k * kernel_size) + l];
                    }
                }
            }
          output_image[i * (N) + j] = cell_value;
        }

    }
  copy_image (input_image, output_image, N * N);
  // we created a pointer to local variable and we should not return it, so we will change the input image

  return input_image;
}


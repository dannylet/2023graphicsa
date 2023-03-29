#include <opencv/highgui.h>

int main()
{
    IplImage * img = cvLoadImage("img.jpg");
    cvShowImage("week07",img);
    cvWaitKey(0);
}

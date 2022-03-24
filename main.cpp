#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{

    Mat image;
    //image = imread("C:/Users/rajav/OneDrive/Desktop/game night/originals/3.jpeg");
    image = imread("C:/Users/rajav/OpenCVFolder/Test/Test01.jpg");
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    
    medianBlur(gray, gray, 5);

    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
                 gray.rows/16,  // change this value to detect circles with different distances to each other
                 100, 30, 1, 30 // change the last two parameters
            // (min_radius & max_radius) to detect larger circles

    );
    
    
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     Vec3i c = circles[i];
    //     Point center = Point(c[0], c[1]);
    //     // circle center
    //     circle( image, center, 1, Scalar(0,100,100), 3, LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     circle( image, center, radius, Scalar(255,0,255), 3, LINE_AA);
    // }

    Vec3i c = circles[1];
    Point center = Point(c[0], c[1]);
    cout << c[0] << "," << c[1]<< std::endl;
    
    Mat_<Vec3b>bgr;
    bgr=image;
    //cout<<image.at<char>(49,39);
    Vec3b pixel =bgr.at(c[0],c[1]);
    //int x = bgr.at<Vec3b>(c[0],c[1])[0];
    //int y = bgr.at<Vec3b>(c[0],c[1])[1];
    //int z = bgr.at<Vec3b>(c[0],c[1])[2];
    
    //Vec3b bgrPixel = image.at<Vec3b>(c[0], c[1]);
    //cout<<image.at<Vec3b>(c[0], c[1])<<endl;
    // circle center
    circle( image, center, 1, Scalar(0,100,100), 3, LINE_AA);
    // circle outline
    int radius = c[2];
    circle( image, center, radius, Scalar(255,0,255), 3, LINE_AA);

    //imshow("detected circles", image);
    //namedWindow("Display Image", WINDOW_AUTOSIZE );
    //imshow("Display Image", gray);
    
    waitKey(0);
    return 0;
}
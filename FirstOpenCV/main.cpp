//
//  main.cpp
//  FirstOpenCV
//
//  Created by Keyman Kim on 12/23/13.
//  Copyright (c) 2013 Keyman Kim. All rights reserved.
//
// Example showing how to read and write images
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv/cvaux.hpp> //why compile error in this case?
#include <opencv/cvaux.h>

int main(int argc, char** argv)
{
    IplImage * pInpImg = 0;
    
    // Load an image from file - change this based on your image name
    pInpImg = cvLoadImage("my_image.jpg", CV_LOAD_IMAGE_UNCHANGED);
    if(!pInpImg)
    {
        fprintf(stderr, "failed to load input image\n");
        return -1;
    }
    
    //=========================================
    //test 1
    //=========================================
    // Write the image to a file with a different name,
    // using a different image format -- .png instead of .jpg
    if( !cvSaveImage("my_image_copy.png", pInpImg) )
    {
        fprintf(stderr, "failed to write image file\n");
    }
    
    //=========================================
    // test2 widnow create
    //=========================================
    cvNamedWindow("Viewer");
    cvShowImage("Viewer", pInpImg);
    cvWaitKey(0);
    cvDestroyWindow("Viewer");

    // Remember to free image memory after using it!
    cvReleaseImage(&pInpImg);

    //=========================================
    // test3. cam
    //=========================================
    CvCapture* capture = cvCaptureFromCAM(0);
    cvNamedWindow("camera",0);
    cvResizeWindow("camera", 320, 240);
    
    while (1) {
        cvGrabFrame(capture);
        pInpImg = cvRetrieveFrame(capture);
        cvShowImage("camera", pInpImg);
        
        if(cvWaitKey(10) >= 0)
            break;
    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("camera");
    
    // Remember to free image memory after using it!
    cvReleaseImage(&pInpImg);
    
    
    
    
    
    
    
    
    
    
    return 0;
}

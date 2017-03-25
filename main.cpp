#include <iostream>
#include <opencv.hpp>
#include <highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap("safari.mp4"); /*Using default camera is 0 second camera 1 third 2*/

    if(!cap.isOpened()){ /*if video not opened*/

        cout << "Error:could not open file "<< endl;
        return -1;   /* Exit */
    }

    namedWindow("Video",CV_WINDOW_AUTOSIZE);

    for(;;){  /*infinite loop to play the frame*/

        Mat frame;

        bool isDone = cap.read(frame);/*Read from source*/

        if(!isDone){
            cout << "Error:invalid video format" << endl;
            break; /*We have to break the loop because it will run infinite*/
        }
        imshow("Video",frame); //
        if(waitKey(30)==27){ /*wait for 30 seconds and press Esc 27 is Ascii for Esc*/
            cout << "Program closed "<< endl;
            break;
        }
    }
}

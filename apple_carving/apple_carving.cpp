// apple_carving.cpp: определяет точку входа для приложения.
//

#include "apple_carving.hpp"

//using namespace cv;
//using namespace std;

int main() {
    cv::Mat img = cv::Mat::zeros(600, 700, CV_8UC3);
    std::vector<cv::Point> points1 = {
        cv::Point(100, 100),
        cv::Point(100, 200),
        cv::Point(100, 300),
        cv::Point(100, 150),
        cv::Point(100, 250),
        cv::Point(100, 350),
        cv::Point(100, 400),
        //

        cv::Point(100, 100),
        cv::Point(140, 100),
        cv::Point(180, 100),
        cv::Point(220, 100),
        cv::Point(260, 100),
        //

        cv::Point(100, 200),
        cv::Point(130, 200),
        cv::Point(160, 200),
        cv::Point(190, 200),
        cv::Point(210, 200),
        //

        cv::Point(240, 210),
        //

        cv::Point(100, 450),
        cv::Point(130, 450),
        cv::Point(160, 450),
        cv::Point(190, 450),
        cv::Point(210, 450),
        //

        cv::Point(240, 440),
        //

        cv::Point(260, 250),
        cv::Point(260, 300),
        cv::Point(260, 350),
        cv::Point(260, 400)
    };
    for (const auto& point : points1) {
        cv::circle(img, point, 3, cv::Scalar(255, 0, 0), -1);
    }



    std::vector<cv::Point> points2 = {
    cv::Point(350, 450),
    cv::Point(370, 420),
    cv::Point(390, 390),
    cv::Point(410, 360),
    cv::Point(430, 330),
    cv::Point(450, 300),
    cv::Point(470, 270),
    cv::Point(490, 240),
    cv::Point(510, 210),
    cv::Point(530, 180),
    cv::Point(550, 150),
    cv::Point(570, 120),
    cv::Point(580, 100),
    //

    cv::Point(570, 450),
    cv::Point(550, 420),
    cv::Point(530, 390),
    cv::Point(510, 360),
    cv::Point(490, 330),
    cv::Point(470, 300),
    cv::Point(450, 270),
    cv::Point(430, 240),
    cv::Point(410, 210),
    cv::Point(390, 180),
    cv::Point(370, 150),
    cv::Point(350, 120),
    cv::Point(340, 100),
    //

    cv::Point(460, 285),
    cv::Point(460, 235),
    cv::Point(460, 185),
    cv::Point(460, 135),
    cv::Point(460, 100),
    cv::Point(460, 315),
    cv::Point(460, 365),
    cv::Point(460, 415),
    cv::Point(460, 450),
    };
    for (const auto& point : points2) {
        cv::circle(img, point, 3, cv::Scalar(255, 0, 0), -1);
    }
    cv::imshow("bulka'", img);
    cv::waitKey(0);
    return 0;
}

//1-lenght
//2-high


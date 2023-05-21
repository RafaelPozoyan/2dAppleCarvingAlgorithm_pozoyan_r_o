// apple_carving.cpp: определяет точку входа для приложения.
//

#include "apple_carving.hpp"

//using namespace cv;
//using namespace std;

//int main() {
//    cv::Mat img (600, 700, CV_8UC3, cv::Scalar(0, 0, 0));
//    std::vector<cv::Point> points1 = {
//        cv::Point(100, 100),
//        cv::Point(100, 200),
//        cv::Point(100, 300),
//        cv::Point(100, 150),
//        cv::Point(100, 250),
//        cv::Point(100, 350),
//        cv::Point(100, 400),
//        //
//
//        cv::Point(100, 100),
//        cv::Point(140, 100),
//        cv::Point(180, 100),
//        cv::Point(220, 100),
//        cv::Point(260, 100),
//        //
//
//        cv::Point(100, 200),
//        cv::Point(130, 200),
//        cv::Point(160, 200),
//        cv::Point(190, 200),
//        cv::Point(210, 200),
//        //
//
//        cv::Point(240, 210),
//        //
//
//        cv::Point(100, 450),
//        cv::Point(130, 450),
//        cv::Point(160, 450),
//        cv::Point(190, 450),
//        cv::Point(210, 450),
//        //
//
//        cv::Point(240, 440),
//        //
//
//        cv::Point(260, 250),
//        cv::Point(260, 300),
//        cv::Point(260, 350),
//        cv::Point(260, 400)
//    };
//    for (const auto& point : points1) {
//        cv::circle(img, point, 3, cv::Scalar(255, 0, 0), -1);
//    }
//
//
//
//    std::vector<cv::Point> points2 = {
//    cv::Point(350, 450),
//    cv::Point(370, 420),
//    cv::Point(390, 390),
//    cv::Point(410, 360),
//    cv::Point(430, 330),
//    cv::Point(450, 300),
//    cv::Point(470, 270),
//    cv::Point(490, 240),
//    cv::Point(510, 210),
//    cv::Point(530, 180),
//    cv::Point(550, 150),
//    cv::Point(570, 120),
//    cv::Point(580, 100),
//    //
//
//    cv::Point(570, 450),
//    cv::Point(550, 420),
//    cv::Point(530, 390),
//    cv::Point(510, 360),
//    cv::Point(490, 330),
//    cv::Point(470, 300),
//    cv::Point(450, 270),
//    cv::Point(430, 240),
//    cv::Point(410, 210),
//    cv::Point(390, 180),
//    cv::Point(370, 150),
//    cv::Point(350, 120),
//    cv::Point(340, 100),
//    //
//
//    cv::Point(460, 285),
//    cv::Point(460, 235),
//    cv::Point(460, 185),
//    cv::Point(460, 135),
//    cv::Point(460, 100),
//    cv::Point(460, 315),
//    cv::Point(460, 365),
//    cv::Point(460, 415),
//    cv::Point(460, 450),
//    };
//    for (const auto& point : points2) {
//        cv::circle(img, point, 3, cv::Scalar(255, 0, 0), -1);
//    }
//
//
// //////////////////////////////////////////////////////////////////////////////////////
//
//
//    cv::Point p1(100, 100);
//    cv::Point p2(100, 450);
//
//    cv::line(img, p1, p2, cv::Scalar(0, 0, 255), 2);
//
//    
//    cv::Point p3(100, 100);
//    cv::Point p4(260, 100);
//
//    cv::line(img, p3, p4, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p5(100, 200);
//    cv::Point p6(210, 200);
//
//    cv::line(img, p5, p6, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p7(100, 450);
//    cv::Point p8(210, 450);
//
//    cv::line(img, p7, p8, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p9(260, 250);
//    cv::Point p10(260, 400);
//
//    cv::line(img, p9, p10, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p11(210, 200);
//    cv::Point p12(240, 210);
//
//    cv::line(img, p11, p12, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p13(240, 210);
//    cv::Point p14(260, 250);
//
//    cv::line(img, p13, p14, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p15(210, 450);
//    cv::Point p16(240, 440);
//
//    cv::line(img, p15, p16, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p17(240, 440);
//    cv::Point p18(260, 400);
//
//    cv::line(img, p17, p18, cv::Scalar(0, 0, 255), 2);
//
//
//
//    cv::Point p19(350, 450);
//    cv::Point p20(570, 120);
//
//    cv::line(img, p19, p20, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p21(580, 100);
//
//    cv::line(img, p20, p21, cv::Scalar(0, 0, 255), 2);
//
//
//    cv::Point p22(570, 450);
//    cv::Point p23(350, 120);
//
//    cv::line(img, p22, p23, cv::Scalar(0, 0, 255), 2);
//
//    cv::Point p24(340, 100);
//
//    cv::line(img, p23, p24, cv::Scalar(0, 0, 255), 2);
//
//    cv::Point p25(460, 450);
//    cv::Point p26(460, 100);
//
//    cv::line(img, p25, p26, cv::Scalar(0, 0, 255), 2);
//
//    cv::imshow("bulka'", img);
//    cv::waitKey(0);
//    
//    return 0;
//}


int main() {
    // Создаем изображение и набор точек
    cv::Mat image(500, 500, CV_8UC3, cv::Scalar(255, 255, 255));
    std::vector<cv::Point2f> points = { {100, 100}, {400, 100}, {250, 400}, {50, 250}, {450, 250} };

    // Создаем объект класса Subdiv2D и добавляем точки
    cv::Subdiv2D subdiv(cv::Rect(0, 0, image.cols, image.rows));
    for (const auto& p : points) {
        subdiv.insert(p);
    }

    // Получаем список треугольников и рисуем их на изображении
    std::vector<cv::Vec6f> triangles;
    subdiv.getTriangleList(triangles);
    for (const auto& t : triangles) {
        cv::line(image, cv::Point(t[0], t[1]), cv::Point(t[2], t[3]), cv::Scalar(0, 0, 0), 1, cv::LINE_AA);
        cv::line(image, cv::Point(t[0], t[1]), cv::Point(t[4], t[5]), cv::Scalar(0, 0, 0), 1, cv::LINE_AA);
        cv::line(image, cv::Point(t[2], t[3]), cv::Point(t[4], t[5]), cv::Scalar(0, 0, 0), 1, cv::LINE_AA);
    }

    // Отображаем изображение и ждем нажатия клавиши
    cv::imshow("Triangulation", image);
    cv::waitKey(0);
    return 0;
}

//1-lenght
//2-high


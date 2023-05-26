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



int main(){
/////////////////////////////////////////////////////////рандом

    ///////////////////////////////////////////////////////////

    int point_del = 10000; //для удаления прямых
    auto x = 1000; // размер окна
    auto y = 1000; // размер окна
    int num = 100; // количество точек
    int point_size = 3;

    ///////////////////////////////////////////////////////////

    // Generate num random points
    std::vector<cv::Point2f> points; // point2f - тип для точек в 2д
    cv::RNG rng; // 
    for (int i = 0; i < num; i++) {
        points.push_back(cv::Point2f(rng.uniform(0, x+50), rng.uniform(0, y+25))); // в каком диапозоне подбираются точки
    }



    // Perform Delaunay triangulation
    cv::Subdiv2D subdiv(cv::Rect(0, 0, point_del, point_del));
    for (const auto& p : points) {
        subdiv.insert(p);
    }



    // Draw Delaunay triangles
    cv::Mat img(y + 100, x + 100, CV_8UC3, cv::Scalar(0, 0, 0));
    std::vector<cv::Vec6f> triangles;
    subdiv.getTriangleList(triangles);
    std::vector<int> list; // массив для LaTex



    for (std::vector<cv::Vec6f>::iterator it = triangles.begin(); it != triangles.end(); it++) {
        cv::Vec6f t = *it;
        int arr[] = { point_del*3, -point_del*3 };
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (std::count(std::begin(arr), std::end(arr), t[i]) == 0) {
                cnt ++;
            }
        }
        if (cnt == 6) {
            /*std::cout << "Triangle: (" << t[0] << ", " << t[1] << "), (" << t[2] << ", " << t[3] << "), (" << t[4] << ", " << t[5] << ")" << std::endl;*/
            for (int l = 0; l < 6; l++) {
                list.push_back(t[l]);
            }
        }
    }



    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << std::endl;
    }



    for (const auto& t : triangles) {
        int arr[] = { point_del*3, -point_del*3 };
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (std::count(std::begin(arr), std::end(arr), t[i]) == 0) {
                cnt++;
            }
        }
        if (cnt == 6) {
            cv::line(img, cv::Point(t[0], t[1]), cv::Point(t[2], t[3]), cv::Scalar(255, 255, 255), 0.5);
            cv::line(img, cv::Point(t[2], t[3]), cv::Point(t[4], t[5]), cv::Scalar(255, 255, 255), 0.5);
            cv::line(img, cv::Point(t[4], t[5]), cv::Point(t[0], t[1]), cv::Scalar(255, 255, 255), 0.5);

            for (const auto& p : points) {
                cv::circle(img, p, point_size, cv::Scalar(0, 0, 255), -1);
            }
            cv::imshow("Delaunay Triangulation", img);
            cv::waitKey(150);
        }
    }

    // Display image
    //cv::imshow("Delaunay Triangulation", img);
    /*cv::waitKey(0);*/
}
//
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/objdetect.hpp>
//#include <opencv2/features2d.hpp>
//#include <opencv2/calib3d.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//    // Загрузка изображения
//    Mat img = imread("C:/Users/pozoy/Pictures/photo_2023-05-24_15-30-48.jpg");
//
//    // Преобразование изображения в серый цвет
//    Mat gray;
//    cvtColor(img, gray, COLOR_BGR2GRAY);
//
//    // Создание вектора точек
//    vector<Point2f> points;
//    for (int y = 0; y < img.rows; y += 10)
//    {
//        for (int x = 0; x < img.cols; x += 10)
//        {
//            points.push_back(Point2f(x, y));
//        }
//    }
//
//    // Выполнение алгоритма Делоне для триангуляции
//    vector<Vec6f> triangles;
//    Subdiv2D subdiv(Rect(0, 0, img.cols, img.rows));
//    subdiv.insert(points);
//    subdiv.getTriangleList(triangles);
//
//    // Отображение каждого треугольника на изображении
//    for (int i = 0; i < triangles.size(); i++)
//    {
//        vector<Point> triangle;
//        for (int j = 0; j < 3; j++)
//        {
//            Point2f pt = Point2f(triangles[i][j * 2], triangles[i][j * 2 + 1]);
//            triangle.push_back(pt);
//        }
//        polylines(img, triangle, true, Scalar(0, 0, 255), 1);
//        imshow("Triangulation", img);
//        waitKey(100);
//    }
//
//    // Ожидание нажатия клавиши
//    waitKey(0);
//
//    return 0;
//}

//////////////////////////////////////////////////////по точкам
//int main()
//{
//    // Создание набора точек
//    std::vector<cv::Point2f> points;
//    points.push_back(cv::Point2f(100, 100));
//    points.push_back(cv::Point2f(300, 100));
//    points.push_back(cv::Point2f(100, 300));
//    points.push_back(cv::Point2f(300, 300));
//    points.push_back(cv::Point2f(250, 350));
//    points.push_back(cv::Point2f(200, 200));
//
//    // Создание объекта Subdiv2D и вставка точек
//    cv::Subdiv2D subdiv(cv::Rect(0, 0, 400, 400));
//    for (std::vector<cv::Point2f>::iterator it = points.begin(); it != points.end(); it++)
//    {
//        subdiv.insert(*it);
//    }
//
//    // Получение списка ребер и треугольников
//    std::vector<cv::Vec6f> triangleList;
//    subdiv.getTriangleList(triangleList);
//
//    // Отрисовка треугольников
//    cv::Mat img = cv::Mat::zeros(400, 400, CV_8UC3);
//    for (size_t i = 0; i < triangleList.size(); i++)
//    {
//        cv::Vec6f t = triangleList[i];
//        cv::Point2f pt1(t[0], t[1]);
//        cv::Point2f pt2(t[2], t[3]);
//        cv::Point2f pt3(t[4], t[5]);
//        cv::line(img, pt1, pt2, cv::Scalar(0, 255, 0), 1);
//        cv::line(img, pt2, pt3, cv::Scalar(0, 255, 0), 1);
//        cv::line(img, pt3, pt1, cv::Scalar(0, 255, 0), 1);
//    }
//
//    // Отображение изображения
//    cv::imshow("Delaunay Triangulation", img);
//    cv::waitKey(0);
//
//    return 0;
//}

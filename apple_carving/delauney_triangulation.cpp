#include "apple_carving.hpp"



int main(){
/////////////////////////////////////////////////////////рандом

    ///////////////////////////////////////////////////////////

    int point_del = 10000; //для удаления прямых
    auto x = 1000; // размер окна
    auto y = 1000; // размер окна
    int num = 100; // количество точек
    int point_size = 1;

    ///////////////////////////////////////////////////////////

     //Generate num random points
    std::vector<int> points_one_len; // point2f - тип для точек в 2д


    std::string str;
    //в тестах приведены числа в диапазоне от 100 до 1000
 //   std::ifstream file("C:/Users/pozoy/Desktop/TestFiles/test_3(100).txt"); // 100 чисел
    std::ifstream file("D:/apple_carving_pozoyan_r_o-master/apple_carving_pozoyan_r_o-master/apple_carving/test/test_2(500).txt");  // 500 чисел

    if (!file.is_open()) {
        std::cout << "The file can't be opened!\n";
    }
    else {
        while (file) {
            getline(file, str);
            int int_number_translate = atoi(str.c_str());
            points_one_len.push_back(int_number_translate);
        }
    }

    file.close();

    std::vector<cv::Point2i> points;
    for (int i = 0; i < points_one_len.size(); i += 2) {
        cv::Point2i new_point(points_one_len[i], points_one_len[i+1]);
        points.push_back(new_point);
    }

    //for (int t = 0; t < points.size(); t++) {
    //    std::cout << points[t];
    //}



     ////Perform Delaunay triangulation
    cv::Subdiv2D subdiv(cv::Rect(0, 0, point_del, point_del));
    for (const auto& p : points) {
        subdiv.insert(p);
    }



     ////Draw Delaunay triangles
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
            //std::cout << "Triangle: (" << t[0] << ", " << t[1] << "), (" << t[2] << ", " << t[3] << "), (" << t[4] << ", " << t[5] << ")" << std::endl;
            for (int l = 0; l < 6; l++) {
                list.push_back(t[l]);
            }
        }
    }



    //for (int i = 0; i < list.size(); i++) {
    //    std::cout << list[i] << std::endl;
    //}



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
            if (num > 100) {
                cv::waitKey(25);
            }
            else {
                cv::waitKey(75);
            }
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

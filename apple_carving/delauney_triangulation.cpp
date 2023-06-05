#include "apple_carving.hpp"

//typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
//typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
//typedef K::Point_2 Point;
//
//int main(){
//    
    //std::vector<Point> points;
    //points.push_back(Point(0, 0));
    //points.push_back(Point(1, 0));
    //points.push_back(Point(0, 1));
    //points.push_back(Point(1, 1));

    //Delaunay dt;
    //dt.insert(points.begin(), points.end());

    //std::cout << "Number of vertices: " << dt.number_of_vertices() << std::endl;
    //std::cout << "Number of edges: " << dt.number_of_edges() << std::endl;
    //std::cout << "Number of faces: " << dt.number_of_faces() << std::endl;

    //for (const auto& i : dt) {
    //    std::cout << dt[i] << std::endl;
    //    std::cout << "                     " << std::endl;
    //}

////////////////////////////////////////    int point_del = 10000; //для удаления прямых
////////////////////////////////////////    auto x = 1000; // размер окна
////////////////////////////////////////    auto y = 1000; // размер окна
/////////////////////////////////////////*    int num = 100; */// количество точек
////////////////////////////////////////    int point_size = 1;
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////    std::vector<int> points_one_len; // point2f - тип для точек в 2д ( строка 34)
////////////////////////////////////////
////////////////////////////////////////    std::string str;
////////////////////////////////////////    //в тестах приведены числа в диапазоне от 100 до 1000
////////////////////////////////////////    std::ifstream file("D:/apple_carving_pozoyan_r_o-master/apple_carving_pozoyan_r_o-master/apple_carving/test/test_2(500).txt"); 
////////////////////////////////////////
////////////////////////////////////////    if (!file.is_open()) {
////////////////////////////////////////        std::cout << "The file can't be opened!\n";
////////////////////////////////////////    }
////////////////////////////////////////    else {
////////////////////////////////////////        while (file) {
////////////////////////////////////////            getline(file, str);
////////////////////////////////////////            int int_number_translate = atoi(str.c_str());
////////////////////////////////////////            points_one_len.push_back(int_number_translate);
////////////////////////////////////////        }
////////////////////////////////////////    }
////////////////////////////////////////
////////////////////////////////////////    file.close();
////////////////////////////////////////
////////////////////////////////////////    std::vector<cv::Point2i> points;
////////////////////////////////////////    for (int i = 0; i < points_one_len.size(); i += 2) {
////////////////////////////////////////        cv::Point2i new_point(points_one_len[i], points_one_len[i+1]);
////////////////////////////////////////        points.push_back(new_point);
////////////////////////////////////////    }
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////    //Perform Delaunay triangulation
////////////////////////////////////////    cv::Subdiv2D subdiv(cv::Rect(0, 0, point_del, point_del));
////////////////////////////////////////    for (const auto& p : points) {
////////////////////////////////////////        subdiv.insert(p);
////////////////////////////////////////    }
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////    //Draw Delaunay triangles
////////////////////////////////////////    cv::Mat img(y + 100, x + 100, CV_8UC3, cv::Scalar(0, 0, 0));
////////////////////////////////////////    std::vector<cv::Vec6f> triangles; // массив для координат точек треугольников
////////////////////////////////////////    subdiv.getTriangleList(triangles);
////////////////////////////////////////    std::vector<float> list; // массив для latex
////////////////////////////////////////
////////////////////////////////////////    for (std::vector<cv::Vec6f>::iterator it = triangles.begin(); it != triangles.end(); it++) {
////////////////////////////////////////        cv::Vec6f t = *it;
////////////////////////////////////////        int arr[] = { point_del*3, -point_del*3 };
////////////////////////////////////////        int cnt = 0;
////////////////////////////////////////        for (int i = 0; i < 6; i++) {
////////////////////////////////////////            if (std::count(std::begin(arr), std::end(arr), t[i]) == 0) {
////////////////////////////////////////                cnt ++;
////////////////////////////////////////            }
////////////////////////////////////////        }
////////////////////////////////////////        if (cnt == 6) {
////////////////////////////////////////            //std::cout << "Triangle: (" << t[0] << ", " << t[1] << "), (" << t[2] << ", " << t[3] << "), (" << t[4] << ", " << t[5] << ")" << std::endl;
////////////////////////////////////////            for (int l = 0; l < 6; l++) {
////////////////////////////////////////                list.push_back(t[l]);
////////////////////////////////////////            }
////////////////////////////////////////        }
////////////////////////////////////////    }
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////    for (const auto& t : triangles) {
////////////////////////////////////////        int arr[] = { point_del * 3, -point_del * 3 };
////////////////////////////////////////        int cnt = 0;
////////////////////////////////////////        for (int i = 0; i < 6; i++) {
////////////////////////////////////////            if (std::count(std::begin(arr), std::end(arr), t[i]) == 0) {
////////////////////////////////////////                cnt++;
////////////////////////////////////////            }
////////////////////////////////////////        }
////////////////////////////////////////        if (cnt == 6) {
////////////////////////////////////////            cv::line(img, cv::Point(t[0], t[1]), cv::Point(t[2], t[3]), cv::Scalar(255, 255, 255), 0.5);
////////////////////////////////////////            cv::line(img, cv::Point(t[2], t[3]), cv::Point(t[4], t[5]), cv::Scalar(255, 255, 255), 0.5);
////////////////////////////////////////            cv::line(img, cv::Point(t[4], t[5]), cv::Point(t[0], t[1]), cv::Scalar(255, 255, 255), 0.5);
////////////////////////////////////////
////////////////////////////////////////            for (const auto& p : points) {
////////////////////////////////////////                cv::circle(img, p, point_size, cv::Scalar(0, 0, 255), -1);
////////////////////////////////////////            }
////////////////////////////////////////            //cv::imshow("Delaunay Triangulation", img);
////////////////////////////////////////            //cv::waitKey(1);
////////////////////////////////////////        }
////////////////////////////////////////    }


    
    //const std::string filename = "points.csv"; // запись координат треугольника в файл point.csv
    //std::ofstream outputFile(filename);

    //if (outputFile.is_open()) {
    //    //for (int i = 0; i < triangles.size()-1; i += 2) {
    //    //    outputFile << triangles[i] << "," << triangles[i+1] << std::endl;
    //    //}
    //    for (int i = 0; i < list.size(); i += 6) {
    //        outputFile << list[i] << "," << list[i + 1] << "," << list[i + 2] << "," << list[i + 3] << "," << list[i + 4] << "," << list[i + 5] << std::endl;
    //    }
    //    outputFile.close();
    //    std::cout << "Data saved to points.cvs successfully" << std::endl;
    //}
    //else {
    //    std::cout << "Unable to open file: " << filename << std::endl;
    //}



    //const std::string aa = "coordinates.txt"; // запись координат треугольника в файл point.csv 2 значения
    //std::ofstream a(aa);

    //if (a.is_open()) {
    //    //for (int i = 0; i < triangles.size()-1; i += 2) {
    //    //    outputFile << triangles[i] << "," << triangles[i+1] << std::endl;
    //    //}
    //    for (int i = 0; i < list.size(); i += 5) {
    //        a << list[i] << " " << list[i + 1] << std::endl;
    //    }
    //    a.close();
    //    std::cout << "Data saved to points.cvs successfully" << std::endl;
    //}
    //else {
    //    std::cout << "Unable to open file: " << aa << std::endl;
    //}



    //const std::string bb = "triangles.txt"; // запись координат треугольника в файл point.csv  6 значений
    //std::ofstream b(bb);

    //if (b.is_open()) {
    //    //for (int i = 0; i < triangles.size()-1; i += 2) {
    //    //    outputFile << triangles[i] << "," << triangles[i+1] << std::endl;
    //    //}
    //    for (int i = 0; i < list.size(); i += 5) {
    //        b << list[i] << " " << list[i + 1] << " " << list[i + 2] << " " << list[i + 3] << " " << list[i + 4] << " " << list[i + 5] << std::endl;
    //    }
    //    b.close();
    //    std::cout << "Data saved to points.cvs successfully" << std::endl;
    //}
    //else {
    //    std::cout << "Unable to open file: " << bb << std::endl;
    //}



    //////////////////////////////////////std::ofstream fout; // Создание файла, запись кода LaTex и визуализация
    //////////////////////////////////////fout.open("visualisation.tex", std::ofstream::out | std::ofstream::trunc);

    //////////////////////////////////////fout << R"(\documentclass[a4paper]{article})" << std::endl;
    //////////////////////////////////////fout << R"(\usepackage{pgfplots})" << std::endl;
    //////////////////////////////////////fout << R"(\usepackage{tikz})" << std::endl;
    //////////////////////////////////////fout << R"(\usepackage{tkz-euclide})" << std::endl;
    //////////////////////////////////////fout << R"(\usepackage[english, russian]{babel})" << std::endl;
    //////////////////////////////////////fout << R"(\usepackage[T2A]{fontenc})" << std::endl;
    //////////////////////////////////////fout << R"(\usepackage[utf8]{inputenc})" << std::endl;


    //////////////////////////////////////fout << R"(\usepackage{geometry})" << std::endl;
    //////////////////////////////////////fout << R"(\geometry{top = 20mm})" << std::endl;
    //////////////////////////////////////fout << R"(\geometry{bottom = 25mm})" << std::endl;
    //////////////////////////////////////fout << R"(\geometry{left = 20mm})" << std::endl;
    //////////////////////////////////////fout << R"(\geometry{right = 25mm})" << std::endl;

    //////////////////////////////////////fout << R"(\title{Visualisation of the triangulation.})" << std::endl;
    //////////////////////////////////////fout << R"(\author{B.J. Koritsina})";

    //////////////////////////////////////fout << R"(\begin{document})" << std::endl;\
    //////////////////////////////////////fout << R"(\maketitle)" << std::endl;
    //////////////////////////////////////fout << R"(\begin{tikzpicture})" << std::endl;
    ////////////////////////////////////////fout << R"(\begin{axis}[)" << std::endl;
    //////////////////////////////////////for (int i = 0; i < list.size(); i+=6) {
    //////////////////////////////////////    fout << R"(\tkzDefPoints{)" << list[i] / 100 << "/" << list[i+1] / 100 << "/A,"
    //////////////////////////////////////        << list[i+2]/100 << "/" << list[i+3]/100 << "/B,"
    //////////////////////////////////////        << list[i+4]/100 << "/" << list[i+5]/100 << "/C}" << std::endl;
    //////////////////////////////////////    fout << R"(\tkzDrawPolygon[black](A,B,C))" << std::endl;
    //////////////////////////////////////    fout << R"(\tkzDrawPoints[red](A,B,C))" << std::endl;
    //////////////////////////////////////}
    ////////////////////////////////////////fout << R"(\tkzDrawPolygon[black](A,B,C))" << std::endl;
    ////////////////////////////////////////fout << R"(\tkzDrawPoints[red](A,B,C))" << std::endl;
    ////////////////////////////////////////fout << R"(\end{axis})" << std::endl;
    //////////////////////////////////////fout << R"(\end{tikzpicture})" << std::endl;
    //////////////////////////////////////fout << R"(\end{document})" << std::endl;

    //////////////////////////////////////std::system("pdflatex visualisation.tex");










//    std::vector<std::vector<float>> triangles = {
//    {1.0, 1.0, 2.0, 2.0, 3.0, 3.0},
//    {4.0, 4.0, 3.0, 3.0, 5.0, 5.0},
//    {4.0, 4.0, 7.0, 7.0, 10.0, 10.0},
//    };
//
//
//    //std::vector<float> start = { list.begin(), list.begin() + 1 };
//    //std::vector<float> finish = { list.end(), list.end() - 1 };
//    std::vector<float> start = { 1.0, 1.0 };
//    std::vector<float> goal = { 3.0, 3.0 };
//
//
//    auto distance = [](const std::vector<float>& p1, const std::vector<float>& p2) {
//        return std::sqrt(std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2));
//    };
//
//
//    auto heuristic = [&distance](const std::vector<float>& p1, const std::vector<float>& p2) {
//        return distance(p1, p2);
//    };
//
//    auto find_neighbors = [&triangles](const std::vector<float>& current) {
//    std::vector<std::vector<float>> neighbors;
//    for (const auto& t : triangles) {
//        int shared_vertices = 0;
//        if (t[0] == current[0] || t[0] == current[2] || t[0] == current[4]) shared_vertices++;
//        if (t[2] == current[0] || t[2] == current[2] || t[2] == current[4]) shared_vertices++;
//        if (t[4] == current[0] || t[4] == current[2] || t[4] == current[4]) shared_vertices++;
//
//        if (shared_vertices == 2) {
//            neighbors.push_back(t);
//            }
//        }
//    return neighbors;
//    };
//
//    std::vector<std::vector<float>> path;
//    std::priority_queue<std::pair<float, std::vector<float>>> open_set;
//    std::vector<std::vector<float>> came_from(triangles.size(), std::vector<float>(6.0, -1.0));
//    std::vector<float> g_score(triangles.size(), std::numeric_limits<float>::max());
//
//    size_t start_triangle_idx = 0; // Индекс начального треугольника
//    size_t goal_triangle_idx = 2; // Индекс конечного треугольника
//
//    open_set.push({ 0, triangles[start_triangle_idx] });
//    g_score[start_triangle_idx] = 0.0;
//
//    while (!open_set.empty()) {
//        std::vector<float> current = open_set.top().second;
//        open_set.pop();
//
//        if (current == triangles[goal_triangle_idx]) {
//            // Восстановление пути
//            size_t current_idx = goal_triangle_idx;
//            while (came_from[current_idx] != std::vector<float>(6.0, -1.0)) {
//                path.push_back(triangles[current_idx]);
//                current_idx = std::distance(triangles.begin(), std::find(triangles.begin(), triangles.end(), came_from[current_idx]));
//            }
//            std::reverse(path.begin(), path.end());
//            break;
//        }
//
//        size_t current_idx = std::distance(triangles.begin(), std::find(triangles.begin(), triangles.end(), current));
//        for (const auto& neighbor : find_neighbors(current)) {
//            size_t neighbor_idx = std::distance(triangles.begin(), std::find(triangles.begin(), triangles.end(), neighbor));
//            float tentative_g_score = g_score[current_idx] + distance(current, neighbor);
//
//            if (tentative_g_score < g_score[neighbor_idx]) {
//                came_from[neighbor_idx] = current;
//                g_score[neighbor_idx] = tentative_g_score;
//                float f_score = tentative_g_score + heuristic(neighbor, triangles[goal_triangle_idx]);
//                open_set.push({ -f_score, neighbor });
//            }
//        }
//    };
//
//    for (const auto& p : path) {
//        std::cout << "(" << p[0] << ", " << p[1] << "), (" << p[2] << ", " << p[3] << "), (" << p[4] << ", " << p[5] << ")" << std::endl;
//    };
// 
//}


#include "apple_carving.hpp"



int main() {

    int point_del = 10000; //для удаления прямых
    auto x = 1000; // размер окна
    auto y = 1000; // размер окна
    //int num = 100; // количество точек
    int point_size = 1;




    std::vector<int> points_one_len; // point2f - тип для точек в 2д

    std::string str;
    //в тестах приведены числа в диапазоне от 100 до 1000
    std::ifstream file("D:/apple_carving_pozoyan_r_o-master/apple_carving_pozoyan_r_o-master/apple_carving/test/test_1(100).txt");

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
        cv::Point2i new_point(points_one_len[i], points_one_len[i + 1]);
        points.push_back(new_point);
    }

    //for (int t = 0; t < points.size(); t++) { // вывод точек в формате x|y
    //    std::cout << points[t] << std::endl;
    //}



    //Perform Delaunay triangulation
    cv::Subdiv2D subdiv(cv::Rect(0, 0, point_del, point_del));
    for (const auto& p : points) {
        subdiv.insert(p);
    }



    //Draw Delaunay triangles
    cv::Mat img(y + 100, x + 100, CV_8UC3, cv::Scalar(0, 0, 0));
    std::vector<cv::Vec6f> triangles;
    subdiv.getTriangleList(triangles);
    std::vector<float> list; // массив для LaTex



    for (std::vector<cv::Vec6f>::iterator it = triangles.begin(); it != triangles.end(); it++) {
        cv::Vec6f t = *it;
        int arr[] = { point_del * 3, -point_del * 3 };
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (std::count(std::begin(arr), std::end(arr), t[i]) == 0) {
                cnt++;
            }
        }
        if (cnt == 6) {
            //std::cout << "Triangle: (" << t[0] << ", " << t[1] << "), (" << t[2] << ", " << t[3] << "), (" << t[4] << ", " << t[5] << ")" << std::endl;
            for (int l = 0; l < 6; l++) {
                list.push_back(t[l]);
            }
        }
    }

    for (const auto& t : triangles) {
        int arr[] = { point_del * 3, -point_del * 3 };
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
            cv::waitKey(1);
        }
    }



    std::ofstream fout; // Создание файла, запись кода LaTex и визуализация
    fout.open("visualisation.tex", std::ofstream::out | std::ofstream::trunc);

    fout << R"(\documentclass[a4paper]{article})" << std::endl;
    fout << R"(\usepackage{pgfplots})" << std::endl;
    fout << R"(\usepackage{tikz})" << std::endl;
    fout << R"(\usepackage{tkz-euclide})" << std::endl;
    fout << R"(\usepackage[english, russian]{babel})" << std::endl;
    fout << R"(\usepackage[T2A]{fontenc})" << std::endl;
    fout << R"(\usepackage[utf8]{inputenc})" << std::endl;


    fout << R"(\usepackage{geometry})" << std::endl;
    fout << R"(\geometry{top = 20mm})" << std::endl;
    fout << R"(\geometry{bottom = 25mm})" << std::endl;
    fout << R"(\geometry{left = 20mm})" << std::endl;
    fout << R"(\geometry{right = 25mm})" << std::endl;

    fout << R"(\title{Visualisation of the triangulation.})" << std::endl;
    fout << R"(\author{B.J. Koritsina})";

    fout << R"(\begin{document})" << std::endl;\
    fout << R"(\maketitle)" << std::endl;
    fout << R"(\begin{tikzpicture})" << std::endl;
    //fout << R"(\begin{axis}[)" << std::endl;
    for (int i = 0; i < list.size(); i+=6) {
        fout << R"(\tkzDefPoints{)" << list[i] / 100 << "/" << list[i+1] / 100 << "/A,"
            << list[i+2]/100 << "/" << list[i+3]/100 << "/B,"
            << list[i+4]/100 << "/" << list[i+5]/100 << "/C}" << std::endl;
        fout << R"(\tkzDrawPolygon[black](A,B,C))" << std::endl;
        fout << R"(\tkzDrawPoints[red](A,B,C))" << std::endl;
    }
    //fout << R"(\tkzDrawPolygon[black](A,B,C))" << std::endl;
    //fout << R"(\tkzDrawPoints[red](A,B,C))" << std::endl;
    //fout << R"(\end{axis})" << std::endl;
    fout << R"(\end{tikzpicture})" << std::endl;
    fout << R"(\end{document})" << std::endl;

    std::system("pdflatex visualisation.tex");
}






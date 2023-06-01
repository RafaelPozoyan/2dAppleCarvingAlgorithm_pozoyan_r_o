#include "apple_carving.hpp"



int main(){
    
    int point_del = 10000; //для удаления прямых
    auto x = 1000; // размер окна
    auto y = 1000; // размер окна
    int num = 100; // количество точек
    int point_size = 1;




    std::vector<int> points_one_len; // point2f - тип для точек в 2д

    std::string str;
    //в тестах приведены числа в диапазоне от 100 до 1000
    std::ifstream file("D:/apple_carving_pozoyan_r_o-master/apple_carving_pozoyan_r_o-master/apple_carving/test/test_3(100).txt"); 

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

    for (int l = 0; l < list.size(); l+=5) {
        std::cout << list[l] << std::endl;
        std::cout << list[l+1] << std::endl;
        std::cout << list[l+2] << std::endl;
        std::cout << list[l+3] << std::endl;
        std::cout << list[l+4] << std::endl;
        std::cout << list[l+5] << std::endl;
    }
    
    
    
    const std::string filename = "points.csv"; // запись координат треугольника в файл point.csv
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (int i = 0; i < points_one_len.size(); i+= 2) {
            outputFile << points_one_len[i] << "," << points_one_len[i+1] << std::endl;
        }

        outputFile.close();
        std::cout << "Data saved to points.cvs successfully" << std::endl;
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
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

    fout << R"(\begin{document})" << std::endl;
    fout << R"(\maketitle)" << std::endl;
    
    fout << R"(\begin{tikzpicture})" << std::endl;
    fout << R"(\begin{axis}[)" << std::endl;
    fout << R"(xlabel={$x$},)" << std::endl;
    fout << R"(ylabel={$y$},)" << std::endl;
    fout << R"(])" << std::endl;
    fout << R"(\addplot table [col sep=comma] {points.csv};)" << std::endl;
    fout << R"(\end{axis})" << std::endl;
    fout << R"(\end{tikzpicture})" << std::endl;
    fout << R"(\item By triangulating using the OpenCV library, we get the coordinates of each triangle and visualize them, creating a LaTex file.)" << std::endl;
    fout << R"(\end{document})" << std::endl;

    //std::ofstream latexFile("latex.tex");

    //if (latexFile.is_open()) {
    //    latexFile << "\documentclass{article}" << std::endl;
    //    latexFile << "\usepackage{pgfplots}" << std::endl;
    //    latexFile << "" << std::endl;
    //    latexFile << "\title{Visualization of the Bowyer-Watson triangulation algorithm.}";
    //    latexFile << "\begin{document}" << std::endl;
    //    latexFile << "\begin{tikzpicture}" << std::endl;
    //    latexFile << "\begin{axis}[" << std::endl;
    //    latexFile << "xlabel={$x$}," << std::endl;
    //    latexFile << "ylabel={$y$}," << std::endl;
    //    latexFile << "]" << std::endl;
    //    latexFile << "" << std::endl;
    //    latexFile << "\addplot table [col sep=comma] {points.csv};" << std::endl;
    //    latexFile << "" << std::endl;
    //    latexFile << "\end{axis}" << std::endl;
    //    latexFile << "\end{tikzpicture}" << std::endl;
    //    latexFile << "\end{document}" << std::endl;
    //}

    std::system("pdflatex visualisation.tex");



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
            //if (num > 100) {
                cv::waitKey(1);
            //}
            //else {
            //    cv::waitKey(2); // заменить на 70
            //}
        }
    }
}




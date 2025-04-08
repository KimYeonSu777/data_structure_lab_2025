#include <iostream>
#include <opencv2/opencv.hpp>

int main() {


    // uchar= unsigned char = 1 byte = 8bit = 2^8개의 data 저장 가능 = 0 ~ 255 
    // = RGB Pixel 표현에 유리한 data type
    uchar maxBrightness = 0;
    uchar pixel;
    int i;
    int j;

    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    // Purpose: image loading 여부 확인
    if (img.empty()) {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    // Purpose: image의 (0,0) 부터 (255,255)까지 최대값 찾기
    for (i = 0; i < img.rows; i++) {
        for (j = 0; j < img.cols; j++) {
            uchar pixel = img.at<uchar>(i, j);
            if (pixel > maxBrightness) {
                maxBrightness = pixel;
            }
        }
    }

    std::cout << "Maximum Pixel Brightness: "
        << static_cast<int>(maxBrightness) << std::endl;

    return 0;
}
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Server.cpp"

using namespace std;
using namespace cv;

class Methods{
public:
    bool DivideImage_(const Mat& img, const int blockWidth, vector<cv::Mat>& blocks){
        int dividestatus = divideImage(img, blockWidth, blocks);
    }
    bool Load_(cv::Mat & mat, const char * data_str){
        load(mat, data_str);
    }
};

class tryDivideImage{
public:
    bool getDivideImage(Methods& Method1, const Mat& img, const int blockWidth, vector<cv::Mat>& blocks){

        if (img.empty()){
            return false;
        }
        else {
            Method1.DivideImage_(img, blockWidth, blocks);
            return true;
        }
    }
};

class tryLoad{
public:
    bool getLoad(Methods& Method2, cv::Mat & img, const char * data_str){
        if (data_str == NULL){
            return false;
        }
        else{
            Method2.Load_(img, data_str);
            return true;
        }
    }
};

class MockDivideImage: public Methods{
public:
    MOCK_METHOD(bool, DivideImage_, (const cv::Mat& img, const int blockWidth, std::vector<cv::Mat>& blocks));
};

class MockLoad: public Methods{
public:
    MOCK_METHOD(bool, Load_, (cv::Mat & mat, const char * data_str));
};

//image to be used for the tests
const Mat image = imread("/home/albert/Documentos/GitHub/Unit-Test-Ejemplo/Prueba.jpeg", IMREAD_COLOR);

TEST(PruebaDivideImage, Prueba1){
    vector<Mat> blocks;
    MockDivideImage mockDivideImage;
    tryDivideImage divideImage;
    EXPECT_TRUE(divideImage.getDivideImage(mockDivideImage,image, 50, blocks));
}

TEST(PruebaLoad, prueba2){

    string serialized = save(image);
    MockLoad mockLoad;
    tryLoad Load;
    Mat imagecontainer;
    EXPECT_TRUE(Load.getLoad(mockLoad,imagecontainer,serialized.c_str()));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

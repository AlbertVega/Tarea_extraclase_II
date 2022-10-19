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

class MockDivideImage: public Methods{
public:
    MOCK_METHOD(bool, DivideImage_, (const cv::Mat& img, const int blockWidth, std::vector<cv::Mat>& blocks));
};

TEST(PruebaDivideImage, Prueba1){
    vector<Mat> blocks;
    const Mat image = imread("/home/albert/Documentos/GitHub/Unit-Test-Ejemplo/Prueba.jpeg", IMREAD_COLOR);

    MockDivideImage mockDivideImage;
    tryDivideImage Image;
    EXPECT_TRUE(Image.getDivideImage(mockDivideImage,image, 50, blocks));
}

/**
 * ejemplo de Uriza
 */

class ExchangeCalculator
{
public:
    int Buy(int amount)
    {
        return amount * 628;
    }

    int Sell(int amount)
    {
        return amount * 642;
    }
};

/**
 * Clase cliente con valores de dinero en colones y dolares
 */

class Client
{
private:
    int colones = 70000;
    int dollars = 200;

public:
    int GetColones(ExchangeCalculator& dollarCalc, int amount) // Obtiene colones y paga su equivalente en dolares, segun tipo de cambio
    {
        colones += amount;
        dollars -= dollarCalc.Sell(amount);

        return colones;
    }

    int GetDollars(ExchangeCalculator& dollarCalc, int amount) // Obtiene dolares y paga su equivalente en colones, segun tipo de cambio
    {
        dollars += amount;
        colones -= dollarCalc.Buy(amount);

        return dollars;
    }
};

/**
 * Clase mock para ExchangeCalculator
 */
class MockCalculator: public ExchangeCalculator
{
public:
    MOCK_METHOD(int, Buy, (int amount));
    MOCK_METHOD(int, Sell, (int amount));
};

/**
 * Prueba para comprobar si el metodo getdollars en client1 con 800, retorna que el cliente tiene 1000 colones
 */
TEST(PruebaCalculadora1, compra1)
{
    MockCalculator mockCalculator;
    Client client1;

    EXPECT_EQ(client1.GetDollars(mockCalculator, 800), 1000);
}

/**
 * Prueba para comprobar si el metodo getcolones en client1 con 100, retorna que el cliente tiene 70100 colones
 */
TEST(ExchangeTest, selling) {
    MockCalculator mockCalculator;
    Client client1;

    EXPECT_EQ(client1.GetColones(mockCalculator, 100), 70100);
}

/**
 *
 * Main siempre es este
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

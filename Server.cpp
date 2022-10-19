#include <iostream>
#include <fstream>
#include <boost/asio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/filesystem.hpp>

#include <opencv2/core.hpp>
#include <boost/serialization/split_free.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

#include <string>
#include <utility>
#include <vector>
using namespace std;
using namespace cv;
/**
 * Function that divide the image in blocks of Mat
 * @param img
 * @param blockWidth
 * @param blocks
 * @return
 */
int divideImage(const cv::Mat& img, const int blockWidth, std::vector<cv::Mat>& blocks){
    // Checking if the image was passed correctly
    if (!img.data || img.empty())
    {
        std::cout << "Image Error: Cannot load image to divide." << std::endl;
        return EXIT_FAILURE;
    }

    // init image dimensions
    int imgWidth = img.cols;
    int imgHeight = img.rows;
    std::cout << "IMAGE SIZE: " << "(" << imgWidth << "," << imgHeight << ")" << std::endl;

    // init block dimensions
    int bwSize;
    int bhSize = img.rows;

    int y0 = 0;
    int x0 = 0;
    while (x0 < imgWidth)
    {
        bwSize = ((x0 + blockWidth) > imgWidth) * (blockWidth - (x0 + blockWidth - imgWidth)) + ((x0 + blockWidth) <= imgWidth) * blockWidth;

        blocks.push_back(img(cv::Rect(x0, y0, bwSize, bhSize)).clone());

        x0 = x0 + blockWidth;

    }
    return EXIT_SUCCESS;
}

/**
 * function that serialize the image, convert the Mat image to serialized string and viceversa
 */
BOOST_SERIALIZATION_SPLIT_FREE( cv::Mat )

namespace boost {
    namespace serialization {
        template <class Archive>
        void save( Archive & ar, const cv::Mat & m, const unsigned int version )
        {
            size_t elemSize = m.elemSize();
            size_t elemType = m.type();

            ar & m.cols;
            ar & m.rows;
            ar & elemSize;
            ar & elemType;

            const size_t dataSize = m.cols * m.rows * m.elemSize();
            for ( size_t i = 0; i < dataSize; ++i )
                ar & m.data[ i ];
        }
        template <class Archive>
        void load( Archive & ar, cv::Mat& m, const unsigned int version )
        {
            int cols, rows;
            size_t elemSize, elemType;

            ar & cols;
            ar & rows;
            ar & elemSize;
            ar & elemType;

            m.create( rows, cols, static_cast< int >( elemType ) );
            const size_t dataSize = m.cols * m.rows * elemSize;
            for (size_t i = 0; i < dataSize; ++i)
                ar & m.data[ i ];
        }
    }
}
/**
 * function that convert the Mat image to serialized string
 * @param mat
 * @return
 */
std::string save( const cv::Mat & mat )
{
    std::ostringstream oss;
    boost::archive::text_oarchive toa( oss );
    toa << mat;

    return oss.str();
}

/**
 * function that convert serialized string to Mat image
 * @param mat
 * @param data_str
 */
void load( cv::Mat & mat, const char * data_str )
{
    std::stringstream ss;
    ss << data_str;

    boost::archive::text_iarchive tia( ss );
    tia >> mat;
}

#include <opencv2/opencv.hpp>
using namespace cv; //cv命名空间

int main(){
	Mat srcImage=imread("1.jpg");//图像载入
	imshow("【原始图】", srcImage);//显示图像
	waitKey(0);//等待任意键按下
	return 0;
}

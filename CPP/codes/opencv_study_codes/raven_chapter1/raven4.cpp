#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(){
		//载入以及展示原始图
		Mat srcImage=imread("3.jpg");
		imshow("【原始图】Canny边缘检测", srcImage);
		Mat dstImage, edge, grayImage; //参数定义
		
		//【1】创建与src图像同类型和大小的矩阵(dst)
		dstImage.create(srcImage.size(), srcImage.type());
		
		//【2】将原图像转化为灰度图像
		//opencv2版本代码：
		cvtColor(srcImage, grayImage, CV_BGR2GRAY);
		//opencv3版本代码：
		//cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
		
		//【3】使用3x3内核进行降噪
		blur(grayImage, edge, Size(3,3));
		
		//【4】运行Canny算子
		Canny(edge, edge, 3,9,3);
		
		//【5】显示效果图
		imshow("【效果图】Canny边缘检测", edge);
		
		waitKey(0);
		
		return 0;		
	
}

#include<opencv2/highgui/highgui.hpp>//加载opencv highgui的模块头文件
#include<opencv2/imgproc/imgproc.hpp>//opencv图像处理的头文件

using namespace cv;

int main(){
	//载入原图
	Mat srcImage=imread("3.jpg");
	//显示原图
	imshow("【原图】腐蚀操作", srcImage);
	//进行腐蚀
	Mat element=getStructuringElement(MORPH_RECT, Size(15,15));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	//显示效果图
	imshow("【效果图】腐蚀操作", dstImage);
	waitKey(0);
	
	return 0;
}

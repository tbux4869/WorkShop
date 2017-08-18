//-----------------【头文件， 命名空间包含部分】-------------------------
// 			描述：包含了程序所使用的头文件和命名空间
//------------------------------------------------------------------
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(){
	//------【一、图像的载入和显示】---------------
	//	描述：以下三行代码用于完成图像的载入和显示
	//-----------------------------------------
	Mat girl=imread("dina.jpg"); //载入图像到Mat
	namedWindow("【1】女神"); //创建一个名为“【1】女神”的窗口
	imshow("【1】女神", girl); //显示一个名为“【1】女神”的窗口
	
	//-----【二、初级图像混合】-------------------
	//	描述：初级图像混合
	//----------------------------------------
	//载入图片
	Mat image=imread("3.jpg", 199);
	Mat logo= imread("logo.jpg");
	
	//载入后先显示
	namedWindow("【2】原画图");
	imshow("【2】原画图", image);
	
	namedWindow("【3】logo");
	imshow("【3】logo", logo);
	
	//定义一个Mat去存放图像的ROI
	Mat imageROI;
	
	//方法一：
	imageROI=image(Rect(800,350,logo.cols,logo.rows));
	//方法二：
	//imgaeROI=image(Range(350,350+logo.rows), Range(800, 800+logo.cols));
	
	//将logo加到原图上
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);
	
	//显示结果
	namedWindow("【4】原画+logo");
	imshow("【4】原画+logo", image);
	
	//--------------【三、 图像的输出】-------------------
	//		描述：将一个Mat图像输出到图像文件
	//------------------------------------------------
	//输出一张jpg图片到工程目录下
	imwrite("由imwrite生成的图片.jpg", image);
	waitKey();
	return 0;
}



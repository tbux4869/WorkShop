#include<opencv2/opencv.hpp>

using namespace cv;

int main(){
	//【1】读入视频
	VideoCapture capture("1.avi");
	
	//【2】循环显示每一帧
	while(1){
		Mat frame; //定义一个Mat来储存每一帧的图像
		capture>>frame; //读取当前帧
		imshow("读取视频", frame);
		waitKey(30); //延时30s
	}
	return 0;
}

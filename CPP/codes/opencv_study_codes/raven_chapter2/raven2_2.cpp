#include<opencv2/opencv.hpp>

using namespace cv;

int main(){
	//【1】从摄像头读入视频
	VideoCapture capture(1); //把内容改为0，即是使用摄像头
	
	//【2】循环显示每一帧
	while(1){
		Mat frame;
		capture>>frame;
		imshow("读取视频", frame);
		waitKey(30);
	}
	return 0;
}

#include<opencv2/opencv.hpp>

using namespace cv;

int main(){
	//【1】从摄像头读入视频
	VideoCapture capture(1); //把内容改为0，即是使用摄像头
	Mat edges;
	
	//【2】循环显示每一帧
	while(1){
		Mat frame;
		capture>>frame;
		
		//【1】将原图像转化为灰度图像
		cvtColor(frame, edges, CV_BGR2GRAY);
		
		//【2】使用3x3内核来降噪（2x3+1=7）
		blur(frame, edges, Size(7,7));
		
		//【3】使用Canny边缘检测
		Canny(edges, edges, 0, 30, 3);
		
		
		imshow("读取视频【Canny边缘检测】", edges);
		if(waitKey(30) >=0) break;
	}
	return 0;
}

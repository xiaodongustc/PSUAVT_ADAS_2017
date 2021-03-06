#pragma once
#include <opencv2\opencv.hpp>
#include "../VehicleDetectionTracking/objects.h"

class CPUDetector
{
public:
	CPUDetector();
	CPUDetector(char * fileName);
	CPUDetector(char * fileName, double scaleFactor, int mergeThreshold);
	~CPUDetector();

	void setMergeThreshold(int mergeThreshold);
	void setScaleFactor(double scaleFactor);
	void loadFile(char * fileName);

	int multiScaleDetection(cv::Mat image, std::vector<cv::Rect>* objects);
	void multiScaleDetection(cv::Mat image, objectTracker* tracker);
	void multiScaleDetection(cv::Mat image, std::vector<object> objects);
private:
	double scaleFactor1;
	int minNeighbors1;
	char * fileName1;
};

class HOGDescriptor
{
public:
	void get_svm_detector(const cv::Ptr<cv::SVM>& svm, std::vector< float > & hog_detector);
};


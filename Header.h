#pragma once
#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include <stdint.h>
#include "opencv2/video/tracking.hpp" 
#include <sstream>
#include <fstream>

extern std::string name;
extern bool byGradient;

std::array <cv::Mat, 4> findGradients(const cv::Mat& image);
void otsu(const cv::Mat& image, int& threshold1);
void emptyHandle(int, void*);
void trackbar(void(*functocall)(int, void*), std::string windowName);
cv::Mat cannyUsingOtsu(cv::Mat& image);
void drawCirclesInSelectedContours(cv::Mat& image, std::vector< std::vector<cv::Point> >& contours, cv::Scalar color);
void eraseContours(std::vector< std::vector<cv::Point> >& contours, int limit);
void findCentroids(std::vector< std::vector<cv::Point> >& contours, std::vector<cv::Point>& centroids);
void drawCentroids(cv::Mat& image, std::vector<cv::Point>& centroids);
void selectContours(std::vector< std::vector<cv::Point> >& contours, std::vector<cv::Point>& centroids, cv::Point& landmark, int maxDistance, int desiredNbCentroids);
void mouseCallback(int  event, int  x, int  y, int  flag, void* param);
void pauseProgram(cv::Mat& image, std::vector< std::vector<cv::Point> > contours, std::vector<cv::Point> centroids, std::string name);
void cannyPause(cv::Mat preProcImage, cv::Mat& segmentedImage, std::vector< std::vector<cv::Point> > contours, std::vector<cv::Point> centroids, std::string name);
void calculateMeanDistances(std::vector< std::vector<cv::Point> >& points, std::vector<cv::Point>& centroids, std::vector <double>& distances);
void getPoints(std::vector< std::vector<cv::Point> >& contours, std::vector< std::vector<cv::Point> >& vecPoints, int nbPoints);
void validationOfCentroid(std::vector< std::vector<cv::Point> >& contours, std::vector <cv::Point>& centroids, int nbCent, int paramPos, double paramSize, double paramDist, std::vector <cv::Point>& trackPoint, std::vector <std::vector  < cv::Point >>& trackedContour, cv::Point& pt, int& sizes, double& dist);
void drawResults(cv::Mat& preProcImage, cv::Mat& image, cv::Mat& selectedContours, std::vector < std::vector<cv::Point> > contours, std::vector< cv::Point > centroids, cv::Point pt);
cv::Mat segmentByAdaptThreshold(cv::Mat preProcImage, cv::Mat selectedContoursImage);
cv::Mat segmentByCanny(cv::Mat preProcImage, cv::Mat selectedContoursImage);
cv::Mat preProcess(cv::Mat frame);
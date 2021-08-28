#include <iostream>
#include <string>
#include <vector>
#include <memory>
// using namespace std;

#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
// using namespace cv;

int main(int argc, char** argv)
{
  /**
   * @ref https://www.cnblogs.com/urglyfish/p/12460057.html
   */

  cv::Mat img_src = cv::imread("../image/pikachu.jpg", 1);
  cv::Mat img_sub = cv::imread("../image/pikachu-sub.jpg", 1);
  cv::namedWindow("src", 0);
  cv::namedWindow("sub", 0);
  cv::imshow("src", img_src);
  cv::imshow("sub", img_sub);
  cv::waitKey(500);

  cv::Mat img_gray_src;
  cv::Mat img_gray_sub;
  cv::cvtColor(img_src, img_gray_src, cv::COLOR_BGR2GRAY);
  cv::cvtColor(img_sub, img_gray_sub, cv::COLOR_BGR2GRAY);
  cv::imshow("src", img_gray_src);
  cv::imshow("sub", img_gray_sub);
  cv::waitKey(500);

  // 特征点提取方法
  // cv::SIFT::create()
  int               nfeatures = 60; // 特征点数量
  cv::Ptr<cv::SIFT> sift      = cv::SIFT::create(nfeatures);
  // 特征点提取
  std::vector<cv::KeyPoint> keypoints_src, keypoints_sub;
  sift->detect(img_src, keypoints_src, cv::Mat());
  sift->detect(img_sub, keypoints_sub, cv::Mat());
  {
    std::cout << "Total keypoints from src\t" << keypoints_src.size() << std::endl;
    std::cout << "Total keypoints from sub\t" << keypoints_sub.size() << std::endl;
  }

  // 画特征点
  cv::Mat img_src_keypoints, img_sub_keypoints;
  cv::drawKeypoints(img_src, keypoints_src, img_src_keypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
  cv::drawKeypoints(img_sub, keypoints_sub, img_sub_keypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
  {
    cv::imshow("src", img_src_keypoints);
    cv::imshow("sub", img_sub_keypoints);
    cv::waitKey(3000);
  }

  cv::Mat match_point_l, match_point_r;
  sift->detectAndCompute(img_src, cv::Mat(), keypoints_src, match_point_l);
  sift->detectAndCompute(img_sub, cv::Mat(), keypoints_sub, match_point_r);
  if (match_point_l.type() != CV_32F || match_point_r.type() != CV_32F)
  {
    match_point_l.convertTo(match_point_l, CV_32F);
    match_point_r.convertTo(match_point_r, CV_32F);
  }

  std::vector<cv::DMatch>        matches;
  cv::Ptr<cv::DescriptorMatcher> desc_matcher = cv::DescriptorMatcher::create("FlannBased");
  desc_matcher->match(match_point_l, match_point_r, matches);

  double maxDist = 10;
  for (int i = 0; i < match_point_l.rows; i++)
  {
    double dist = matches[i].distance;
    if (dist > maxDist)
      maxDist = dist;
  }

  std::vector<cv::DMatch> goodMatches, needMatches;
  std::vector<float>      distance;
  for (int i = 0; i < match_point_l.rows; i++)
  {
    if (matches[i].distance < 0.1 * maxDist)
    {
      goodMatches.push_back(matches[i]);
      distance.push_back(matches[i].distance);
    }
  }

  cv::Mat imageOutput;
  cv::drawMatches(img_src, keypoints_src, img_sub, keypoints_sub, goodMatches, imageOutput);

  std::vector<cv::Point> first_img, second_img;
  for (int i = 0; i < needMatches.size(); i++)
  {
    first_img.push_back(keypoints_src[needMatches[i].queryIdx].pt);
    second_img.push_back(keypoints_sub[needMatches[i].trainIdx].pt);
  }
  cv::imshow("match image", imageOutput);
  cv::waitKey(5000);

  return 0;
}

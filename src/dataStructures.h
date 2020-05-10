#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <opencv2/core.hpp>
#include <queue>

struct DataFrame
{ // represents the available sensor information at the same time instance

    cv::Mat cameraImg; // camera image
    
    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> kptMatches; // keypoint matches between previous and current frame
};

// Implement RingBuffer through inheritance from std::queue and slightly modyfing the push method.
template <typename T, std::size_t maxSize, typename Container = std::deque<T>>
class RingBuffer : public std::queue<T>
{
public:
    void push(const T& element)
    {
        if (Fifo::size() == maxSize) 
        {
            Fifo::c.pop_front();
        }
        Fifo::push(element);
    }

    typename Container::iterator begin() { return Fifo::c.begin(); }
    typename Container::iterator end() { return Fifo::c.end(); }
    typename Container::const_iterator begin() const { return Fifo::c.begin(); }
    typename Container::const_iterator end() const { return Fifo::c.end(); }

private:
    typedef std::queue<T> Fifo;
};

#endif /* dataStructures_h */

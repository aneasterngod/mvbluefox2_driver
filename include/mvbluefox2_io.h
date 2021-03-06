#ifndef MVBLUEFOX2_IO
#define MVBLUEFOX2_IO

#include "mvbluefox2_common.h"
#include "ImageData.h"

class mvbluefox2_io
{
  public:
	mvbluefox2_io();
	~mvbluefox2_io();
	bool init(const char *serial);
	void setExposure(int v);
	void setForcetoGray();
	void setDefaultRequestCount(int dc);
	void startCapture();
	void acquisition();
	void raw2cv(const Request* pRequest, cv::Mat& img );

  public:
	deque<ImageData> m_data;
	DeviceManager m_devMgr;
	Device *m_pDev;
	std::thread m_captureThread;	
};

#endif

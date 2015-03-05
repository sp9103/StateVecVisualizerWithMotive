#include <stdlib.h>
#include <sys/stat.h>

//#include "stdafx.h"

//#define DEFAULT_FILE_PATH "C:\\Users\\Pa9301\\Desktop\\Kinect Project\\NMsgrSvr\\NMsgrSvr\\"

#define DEFAULT_FILE_PATH "BinaryData\\."

class StateVecRecord
{
public:
	StateVecRecord(void);
	~StateVecRecord(void);

	void OpenFile(char *Path, char *filename, char mode);					//mode 'r' = read, mode 'w' = write	
	void CloseFile();

	void WriteState(StateVector src);
	bool ReadState(StateVector *dst);

	void WriteAver(SkeletonInfo src);
	bool ReadAver(StateVector *dst);

	void WriteCenter(SkeletonInfo src);
	bool ReadCenter(StateVector *dst);

	bool isOpened();

	bool ReadAll(StateVector *dst);
	int GetTotalFrame();
	void MoveFrame(int TargetFrame);

private:
	FILE *m_fp;																//file pointer;
	FILE *m_aver;
	FILE *m_center;
	FILE *m_all;

	bool isOpen;
	int m_Totalframe;
};


#ifndef AVCODEC_AVENCODER_H
#define AVCODEC_AVENCODER_H

extern "C"
{
#include "avcodec.h"
}

class AVEncoder
{
public:
	AVEncoder();
	~AVEncoder();

public:
	BOOL	Open(enum AVCodecID id, int width, int height, int frame_rate, int bit_rate, int gop);
	BOOL	Close();
	int		Encode(const BYTE * pYUY2, int nLength);
	BYTE *	GetEncodedData() const { return _pOutBuffer; }

private:
	AVCodecContext *	_pContext;
	AVFrame *			_pFrame;
	BYTE *				_pOutBuffer;
	int					_nOutLength;
	BYTE *				_pData;
};

#endif //AVCODEC_AVENCODER_H